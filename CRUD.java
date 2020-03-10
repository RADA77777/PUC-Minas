import java.io.*;
import java.util.logging.*;

public class CRUD
{
	final Logger logger = Logger.getLogger(CRUD.class.getName());
	public int last_inserted_id;
	RandomAccessFile db_file;

	CRUD()
	{
		logger.info("Abrindo o arquivo ./dados/dados.db\n");
		// Tentando abrir arquivo pela primeira vez
		open_db_file();
		
		// Caso aberto, ler o 1 numero, que indica o ultimo ID usado
		try{
			this.last_inserted_id = this.db_file.readInt();
			logger.info("Ultimo id inserido = " + this.last_inserted_id);
		}
		catch(IOException error){
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
	

	// TODO Armazenar nos indices direto e indireto
	public int create()
	{
		try
		{
			open_db_file();
			
			Usuario new_user = new Usuario(++this.last_inserted_id);
			
			rewrite_last_inserted_id();

			//try
			//{
			
			long address = db_file.length();
			db_file.seek(address);

			//}
			//catch(IOException error)
			//{
			//	logger.log(Level.WARNING, "Nao consegui ir para o final do arquivo... Erro: " + error);
			//}


			logger.info("Escrevendo novo usuario em dados.db ---- email = " + new_user.get_email() + "\n");
			//try	
			//{
			
			byte[] user_in_bytes = new_user.to_byte_array();
			int user_size_bytes = user_in_bytes.length;
			
			this.db_file.writeChar(' ');
			this.db_file.writeInt(user_size_bytes);
			this.db_file.write(user_in_bytes);

			//}
			//catch(IOException error)
			//{
			//	logger.log(Level.WARNING, "Nao consegui escrever info do usuario no arquivo. Erro: " + error);
			//}

			

			logger.info("Novo usuario escrito com sucesso!\n");
			close_db_file();

			HashExtensivel he = new HashExtensivel(4, "diretorio.hash.db", "cestos.hash.db");
			he.create(last_inserted_id, address);
		}
		catch(Exception error)
		{
			System.out.println("Erro na funcao create: " + error);
		}

		return this.last_inserted_id;
	}

	// TODO: Funcao read
	public void read()
	{
		try
		{
			open_db_file();
			
			db_file.seek(4);
			char is_lapide = db_file.readChar();
			if(is_lapide == ' ')
			{
				db_file.readInt();
				int id = db_file.readInt();
				String nome = db_file.readUTF();
				String email = db_file.readUTF();
				String senha = db_file.readUTF();

				System.out.println("id = " + id + " nome = " + nome + " email = " + email + " senha = " + senha);
			}

			close_db_file();
		}

		catch(Exception error)
		{
			System.out.println("Erro na funcao read. Erro: " + error);
		}
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
			db_file.writeInt(this.last_inserted_id);
		}
		catch(IOException error)
		{
			logger.log(Level.WARNING, "Nao foi possivel reescrever o ID inicial... Erro: " + error);
		}
	}
}
