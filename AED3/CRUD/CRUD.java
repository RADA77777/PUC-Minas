import java.io.*;
import java.lang.reflect.Constructor;
import java.util.logging.*;

// Implementacao generica do CRUD. Pode ser aplicado a qualquer tipo, desde que
// o tipo implemente a classe Entidade
public class CRUD<Template extends Entidade>
{
	final Logger logger = Logger.getLogger(CRUD.class.getName());
	public int last_inserted_id;
	RandomAccessFile db_file;
	Constructor<Template> constructor;

	public CRUD(Constructor<Template> constructor)
	{
		this.constructor = constructor;

		logger.info("Abrindo o arquivo ./dados/dados.db\n");
		// Tentando abrir arquivo pela primeira vez
		open_db_file();
		
		// Caso aberto, ler o 1 numero, que indica o ultimo ID usado
		try
		{
			this.last_inserted_id = this.db_file.readInt();
			logger.info("Ultimo id inserido = " + this.last_inserted_id);
		}
		catch(IOException error)
		{
			logger.info("Nada escrito no arquivo... Colocando ID inicial como 0...\n");
			// Se nao retornar IOException, eh pq nao tem nada escrito. Logo, escrevemos 0 nele
			try{
				this.db_file.writeInt(-1);
				this.last_inserted_id = -1;
			}
			catch(java.io.IOException io_error)
			{
				logger.log(Level.WARNING, "Nao consegui escrever ID inicial em ./dados.db --- Por favor, cheque o stack de erros\n" + io_error);
			}
		}

		close_db_file();
	}


	public int create()
	{
		int return_value = -1;
		try
		{
			open_db_file();
			rewrite_last_inserted_id();

			Template new_user = this.constructor.newInstance();
			new_user.set_info(this.last_inserted_id);

			long address = db_file.length();
			db_file.seek(address);

			logger.info("Escrevendo novo usuario em dados.db\n#email = " + new_user.get_email() + "\n#ID = " + new_user.get_id() + "\n");
			
			byte[] user_in_bytes = new_user.to_byte_array();
			
			this.db_file.writeChar(' ');
			this.db_file.writeInt(user_in_bytes.length);
			this.db_file.write(user_in_bytes);
			
			logger.info("Novo usuario escrito com sucesso!\n");
			close_db_file();

			HashExtensivel he = new HashExtensivel(4, "diretorio.hash.db", "cestos.hash.db");
			he.create(last_inserted_id, address);

			ArvoreBMais_String_Int arvore = new ArvoreBMais_String_Int(10, "./dados/index_indireto.db");
			arvore.create(new_user.get_email(), new_user.get_id());

			return_value = this.last_inserted_id;
		}
		catch(Exception error)
		{
			System.out.println("Erro na funcao create: " + error);
			error.printStackTrace();
		}

		return return_value;
	}


	public Template read(int search_id)
	{
		Template read_user;
		try
		{
			read_user = this.constructor.newInstance();
			open_db_file();
			
			HashExtensivel he = new HashExtensivel(4, "diretorio.hash.db", "cestos.hash.db");
			long id_location = he.read(search_id);

			db_file.seek(id_location);
			char is_lapide = db_file.readChar();

			if(is_lapide == ' ')
			{
				byte[] user_in_bytes = new byte[db_file.readInt()];
				db_file.read(user_in_bytes);
				
				read_user.from_byte_array(user_in_bytes);
			}

			close_db_file();
		}

		catch(Exception error)
		{
			System.out.println("Erro na funcao read. Erro: " + error);
			read_user = null;
		}

		return read_user;
	}



	public Template read(String search_email)
	{
		Template read_user;
		try
		{
			read_user = this.constructor.newInstance();
			ArvoreBMais_String_Int arvore = new ArvoreBMais_String_Int(10, "./dados/index_indireto.db");
			int user_id = arvore.read(search_email);

			read_user = read(user_id);
		}
		catch(Exception error)
		{
			System.out.println(error);
			read_user = null;
		}

		return read_user;
	}

	public int update(int update_id)
	{
		Template new_user;
		int return_value = -1;
		try
		{
			open_db_file();

			HashExtensivel he = new HashExtensivel(4, "diretorio.hash.db", "cestos.hash.db");
			long id_location = he.read(update_id);

			db_file.seek(id_location);

			new_user = this.constructor.newInstance();
			new_user.set_info(update_id);

			char is_lapide = db_file.readChar();

			byte[] new_user_in_bytes = new_user.to_byte_array();

			if(is_lapide == ' ')
			{
				int tam = db_file.readInt();
				
				if(new_user_in_bytes.length <= tam)
				{
					db_file.seek(id_location + 2);
					db_file.writeInt(new_user_in_bytes.length);
					db_file.write(new_user_in_bytes);
				}
				else
				{
					db_file.seek(id_location);
					db_file.writeChar('*');

					long new_id_location = db_file.length();
					
					db_file.seek(new_id_location);
					db_file.writeChar(' ');
					db_file.writeInt(new_user_in_bytes.length);
					db_file.write(new_user_in_bytes);

					he.update(update_id, new_id_location);
					ArvoreBMais_String_Int arvore = new ArvoreBMais_String_Int(10, "./dados/index_indireto.db");
					arvore.update(new_user.get_email(), new_user.get_id());
				}
			}
			close_db_file();
			return_value = update_id;
		}
		catch(Exception error)
		{
			System.out.println(error);
		}

		return return_value;
	}


	int update(String update_email)
	{
		int update_id = -1;
		try
		{
			ArvoreBMais_String_Int arvore = new ArvoreBMais_String_Int(10, "./dados/index_indireto.db");
			update_id = arvore.read(update_email);
			update(update_id);
		}
		catch(Exception error)
		{
			error.printStackTrace();
		}
		return update_id;
	}


	int delete(int delete_id)
	{
		try
		{
			HashExtensivel he = new HashExtensivel(4, "diretorio.hash.db", "cestos.hash.db");
			long location_id  = he.read(delete_id);

			open_db_file();
			
			db_file.seek(location_id);
			
			// Marcando como lapide
			db_file.writeChar('*');

			// Lendo o usuario no arquivo de dados para poder pegar o email dele. O email
			// eh necessario para remover ele do indice indireto (arvore B+)
			int len = db_file.readInt();
			byte[] deleted_user_in_bytes = new byte[len];
			db_file.read(deleted_user_in_bytes);
			Template deleted_user = this.constructor.newInstance();
			deleted_user.from_byte_array(deleted_user_in_bytes);

			// Deletando informacao desse usuario dos indices direto (Hash Extensivel) e indireto (Arvore B+)
			he.delete(delete_id);
			ArvoreBMais_String_Int arvore = new ArvoreBMais_String_Int(10, "./dados/index_indireto.db");
			arvore.delete(deleted_user.get_email());

			close_db_file();
		}
		catch(Exception error)
		{
			error.printStackTrace();
		}
		return delete_id;
	}


	public void open_db_file()
	{
		try{
			this.db_file = new RandomAccessFile("./dados/dados.db", "rw");	
		} 
		catch(Exception error){
			logger.log(Level.WARNING, "Arquivo nao pode ser aberto. Erro: " + error);
		}
	}


	public void close_db_file()
	{
		try{
			this.db_file.close();
		}
		catch(Exception error){
			logger.log(Level.WARNING, "Nao consegui fechar o arquivo... Erro: " + error);
		}
	}


	public void rewrite_last_inserted_id()
	{
		try
		{
			db_file.seek(0);
			db_file.writeInt(++this.last_inserted_id);
		}
		catch(IOException error)
		{
			logger.log(Level.WARNING, "Nao foi possivel reescrever o ID inicial... Erro: " + error);
		}
	}
}
