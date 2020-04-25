import java.util.Scanner;
import java.io.*;
import java.lang.reflect.Constructor;

// Implementacao generica do CRUD. Pode ser aplicado a qualquer tipo, desde que
// o tipo implemente a classe Entidade
public class CRUD<Template extends Entidade>
{
	public int id_logado = -1;
	public int last_inserted_id;
	public int percentage_for_overwrite = 80;

	String db_file_location, diretorio_hashtable_location, cesto_hashtable_location;
	String arvore_str_int_location, arvore_int_int_location = "", index_empty_spaces;
	RandomAccessFile db_file;
	Scanner in;
	Constructor<Template> constructor;


	public CRUD(Constructor<Template> constructor, String db_file_location, Scanner in)
	{
		this.in = in;
		this.constructor = constructor;
		this.db_file_location = db_file_location;

		if(db_file_location.equals("./dados/usuarios.db"))
		{
			this.diretorio_hashtable_location  =  "./dados/diretorio_usuarios.db";
			this.cesto_hashtable_location      =  "./dados/cestos_usuarios.db";
			this.arvore_str_int_location       =  "./dados/arvore_usuarios.db";
			this.index_empty_spaces            =  "./dados/espacos_usuarios.db";
		}

		else if(db_file_location.equals("./dados/sugestoes.db"))
		{
			this.diretorio_hashtable_location  =  "./dados/diretorio_sugestoes.db";
			this.cesto_hashtable_location      =  "./dados/cestos_sugestoes.db";
			this.arvore_str_int_location       =  "./dados/arvore_srt_int_sugestoes.db";
			this.arvore_int_int_location       =  "./dados/arvore_int_int_sugestoes.db";
			this.index_empty_spaces            =  "./dados/espacos_sugestoes.db";
		}
		
		else if(db_file_location.equals("./dados/grupos.db"))
		{
			this.diretorio_hashtable_location  =  "./dados/diretorio_grupos.db";
			this.cesto_hashtable_location      =  "./dados/cestos_grupos.db";
			this.arvore_str_int_location       =  "./dados/arvore_srt_int_grupos.db";
			this.arvore_int_int_location       =  "./dados/arvore_int_int_grupos.db";
			this.index_empty_spaces            =  "./dados/espacos_grupos.db";
		}
		
		else if(db_file_location.equals("./dados/convites.db"))
		{
			this.diretorio_hashtable_location  =  "./dados/diretorio_convites.db";
			this.cesto_hashtable_location      =  "./dados/cestos_convites.db";
			this.arvore_str_int_location       =  "./dados/arvore_srt_int_convites.db";
			this.arvore_int_int_location       =  "./dados/arvore_int_int_convites.db";
			this.index_empty_spaces            =  "./dados/espacos_convites.db";
		}


		// Tentando abrir arquivo pela primeira vez
		open_db_file();
		
		// Caso aberto, ler o 1 numero, que indica o ultimo ID usado
		try
		{
			this.last_inserted_id = this.db_file.readInt();
		}
		catch(IOException error)
		{
			// Se nao retornar IOException, eh pq nao tem nada escrito. Logo, escrevemos 0 nele
			try
			{
				this.db_file.writeInt(-1);
				this.last_inserted_id = -1;
			}
			catch(java.io.IOException io_error)
			{
				io_error.printStackTrace();
			}
		}

		close_db_file();
	}


	// Cria um usuario novo do zero e armazena suas informacoes em um arquivo chamado dados.db
	public int create(Template new_entity)
	{
		int return_value = -1;
		try
		{
			open_db_file();		
			rewrite_last_inserted_id();

			new_entity.set_id(this.last_inserted_id);

			byte[] entity_in_bytes = new_entity.to_byte_array();

			// O Arquivo Espacos Livres eh um indice indireto sequencial denso que funciona em pares...
			// Ele tem um par de longs: Um tamanho e um endereco. Esses longs indicam
			// os usuarios marcados como lapide(*) no arquivo dados.db - O primeiro fala quantos bytes estao vazios, e
			// o outro fala a posicao do inicio desses bytes em dados.db
			Indice_Lapides arq_sequencial = new Indice_Lapides(percentage_for_overwrite, index_empty_spaces);

			// A funcao search_empty_space recebe um long - qual o tamanho do novo usuario em bytes - e procura
			// em seu arquivo se existe algume espaco vazio (algum campo lapide) em dados.db que tenha esse mesmo
			// tamanho ou que a sobreescrita gere, no minimo, <percentage_for_overwrite>% de ocupacao.
			long address_in_file = arq_sequencial.search_empty_space(entity_in_bytes.length);

			// A funcao retorna -1 caso nao tenham usuarios deletados (marcados como lapide)
			// em dados.db. Nesse caso, a variavel so vai ser mudada para db_file.length(), para os dados
			// serem inseridos no final do arquivo dados.db
			if(address_in_file == -1)
				address_in_file = db_file.length();
			

			db_file.seek(address_in_file);
			
			// Se o arquivo tiver um char ' ' na frente, significa que o campo é valido. Se o char for '*', o
			// campo denomina uma lapide - Ja teve um arquivo ali antes, mas nao tem mais.
			this.db_file.writeChar(' ');
			this.db_file.writeInt(entity_in_bytes.length);

			this.db_file.write(entity_in_bytes);
			
			close_db_file();

			// HashExtensivel eh um indice direto que armazena um par de chaves. Muito parecido com o Arquvo_Espacos_Livres,
			// esse arquivo armazena os pares ID - Local do ID em dados.db
			
			//HashExtensivel he = new HashExtensivel(4, "diretorio.usuarios.db", "cestos.usuarios.db");
			HashExtensivel he = new HashExtensivel(4, diretorio_hashtable_location, cesto_hashtable_location);
			he.create(last_inserted_id, address_in_file);

			// A ArvoreBMais_String_Int armazena outro par de informacoes. Email - ID. Retornando o ID, pode-se jogar ele
			// na HashExtensivel para obter o local no arquivo dados.db
			ArvoreBMais_String_Int arvore_str_int = new ArvoreBMais_String_Int(10, arvore_str_int_location);
			arvore_str_int.create(new_entity.get_chave_secundaria(), new_entity.get_id());


			if(! this.arvore_int_int_location.equals(""))
			{
				ArvoreBMais_Int_Int arvore_int_int = new ArvoreBMais_Int_Int(10, this.arvore_int_int_location);
				arvore_int_int.create(new_entity.get_id(), this.last_inserted_id);
			}

			return_value = this.last_inserted_id;
		}
		catch(Exception error)
		{
			error.printStackTrace();
		}

		return return_value;
	}


	// A funcao read recebe um ID e realiza uma busca na tabela hash extensivel para obter a localizacao do
	// registro de usuario em dados.db
	public Template read(int search_id)
	{
		Template read_entity;
		try
		{
			// Como eh preciso retornar um usuario, eh preciso criar um novo
			read_entity = this.constructor.newInstance();
			open_db_file();
			
			HashExtensivel he = new HashExtensivel(4, diretorio_hashtable_location, cesto_hashtable_location);
			long id_location = he.read(search_id);

			db_file.seek(id_location);
			
			// Verificando se o campo eh uma lapide para saber se o usuario existe
			char is_lapide = db_file.readChar();

			if(is_lapide == ' ')
			{
				byte[] user_in_bytes = new byte[db_file.readInt()];
				db_file.read(user_in_bytes);
				
				read_entity.from_byte_array(user_in_bytes);
			}

			close_db_file();
		}

		catch(Exception error)
		{
			read_entity = null;
		}
		return read_entity;
	}



	// Recebe um email ao inves de um indice. Esse tipo de busca nao muda muito.
	// A unica diferenca eh que eh obtido o ID usando o indice indireto ArvoreBMais_String_Int, e
	// depois esse ID eh jogado para a funcao read que recebe um int. Usuario eh retornado
	// da mesma forma
	public Template read(String search_string)
	{
		Template read_entity;
		try
		{
			read_entity = this.constructor.newInstance();
			ArvoreBMais_String_Int arvore = new ArvoreBMais_String_Int(10, arvore_str_int_location);
			int user_id = arvore.read(search_string);

			read_entity = read(user_id);
		}
		catch(Exception error)
		{
			read_entity = null;
		}

		return read_entity;
	}


	// Essa funcao recebe um int e usa ele para sobreescrever os dados de um usuario, caso ele seja achado.
	// Se nao for executada corretamente, retorna -1. Caso contrario, retorna a ID do usuario
	public int update(Template update_entity, int update_id)
	{
		int return_value = -1;
		try
		{
			open_db_file();

			HashExtensivel he = new HashExtensivel(4, diretorio_hashtable_location, cesto_hashtable_location);
			long id_location = he.read(update_id);

			db_file.seek(id_location);

			// Criando nova instancia de um objeto Usuario

			char is_lapide = db_file.readChar();
			byte[] update_entity_in_bytes = update_entity.to_byte_array();

			// Verificando novamente se o campo eh uma lapide, como medida de seguranca
			if(is_lapide == ' ')
			{
				int tam = db_file.readInt();
				
				// Se o tamanho da ocupacao ja for maior que <percentage_for_overwrite>, eh desnecessario
				// fazer uma busca no indice de espacos vazios. Essa busca so vai ser feita se cair no else
				if(( 100*update_entity_in_bytes.length/tam >= percentage_for_overwrite) && (update_entity_in_bytes.length <= tam) )
				{
					db_file.seek(id_location + 2);
					db_file.writeInt(update_entity_in_bytes.length);
					db_file.write(update_entity_in_bytes);
				}
				else
				{		
					db_file.seek(id_location);
					db_file.writeChar('*');

					// Procurando por espacos vazios. Se a funcao retornar -1, eh pq nao existem espacos 
					// vazios, logo, o novo usuario vai ser inserido no final de dados.db. Caso contrario, vai
					// ser inserido no espaco retornado por essa funcao
					Indice_Lapides arq = new Indice_Lapides(percentage_for_overwrite, index_empty_spaces);
					long address = arq.search_empty_space(update_entity_in_bytes.length);
					if(address == -1)
					{
						long new_id_location = db_file.length();
						db_file.seek(new_id_location);
						he.update(update_id, new_id_location);

						arq.create_entry_grave((long)tam, id_location);
					}
					else
					{
						db_file.seek(address);
						he.update(update_id, address);
					}

					// Escrevendo usuario no arquivo
					db_file.writeChar(' ');
					db_file.writeInt(update_entity_in_bytes.length);
					db_file.write(update_entity_in_bytes);

					ArvoreBMais_String_Int arvore = new ArvoreBMais_String_Int(10, arvore_str_int_location);
					arvore.update(update_entity.get_chave_secundaria(), update_entity.get_id());
				}
			}
			close_db_file();
			return_value = update_id;
		}
		catch(Exception error)
		{
			System.out.println("Nao foi possivel atualizar informacoes desse usuario. Tem certeza de que ele existe?");
		}

		return return_value;
	}


	// Mesma ideia da funcao read... Buscar o ID no indice indireto ArvoreBMais e 
	// chamar a funcao update usando o ID
	int update(String update_email)
	{
		int update_id = -1;
		try
		{
			ArvoreBMais_String_Int arvore = new ArvoreBMais_String_Int(10, arvore_str_int_location);
			update_id = arvore.read(update_email);
			//update(update_id);
		}
		catch(Exception error)
		{
			error.printStackTrace();
		}
		return update_id;
	}


	// Recebe um ID e deleta ele do arquivo dados.db
	// Essa funcao tambem eh responsavel por criar entradas no indice indireto de
	// espacos vazios.
	int delete(int delete_id)
	{
		try
		{
			HashExtensivel he = new HashExtensivel(4, diretorio_hashtable_location, cesto_hashtable_location);
			long location_id  = he.read(delete_id);

			open_db_file();
			
			db_file.seek(location_id);
			
			// Marcando usuario como lapide em dados.db
			db_file.writeChar('*');

			// Lendo o usuario no arquivo de dados para poder pegar o email dele. O email
			// eh necessario para remover ele do indice indireto (arvore B+)
			int len = db_file.readInt();
			byte[] deleted_entity_in_bytes = new byte[len];
			db_file.read(deleted_entity_in_bytes);

			Template deleted_entity = this.constructor.newInstance();
			deleted_entity.from_byte_array(deleted_entity_in_bytes);

			// Deletando informacao desse usuario dos indices direto (Hash Extensivel) e indireto (Arvore B+)
			he.delete(delete_id);
			ArvoreBMais_String_Int arvore = new ArvoreBMais_String_Int(10, arvore_str_int_location);
			arvore.delete(deleted_entity.get_chave_secundaria());

			// Indicando para o indice de lapides que um usuario foi deletado de dados.db
			// Com a chamada da funcao create_entry_grave, o indice de lapides vai armazenar o 
			// tamanho da nova lapide, e tambem a sua localizacao
			Indice_Lapides arq = new Indice_Lapides(percentage_for_overwrite, index_empty_spaces);
			arq.create_entry_grave((long)len, location_id);

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
			this.db_file = new RandomAccessFile(this.db_file_location, "rw");	
		} 
		catch(Exception error){
			error.printStackTrace();
		}
	}


	public void close_db_file()
	{
		try{
			this.db_file.close();
		}
		catch(Exception error){
			error.printStackTrace();
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
			error.printStackTrace();
		}
	}
}
