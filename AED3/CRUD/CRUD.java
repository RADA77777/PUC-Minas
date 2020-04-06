import java.io.*;
import java.lang.reflect.Constructor;
import java.util.logging.*;

// Implementacao generica do CRUD. Pode ser aplicado a qualquer tipo, desde que
// o tipo implemente a classe Entidade
public class CRUD<Template extends Entidade>
{
	Logger logger = Logger.getLogger(CRUD.class.getName());
	public int last_inserted_id;
	public int percentage_for_overwrite = 80;
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
			try
			{
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


	// Cria um usuario novo do zero e armazena suas informacoes em um arquivo chamado dados.db
	public int create()
	{
		int return_value = -1;
		try
		{
			open_db_file();
			rewrite_last_inserted_id();

			Template new_user = this.constructor.newInstance();
			new_user.set_info(this.last_inserted_id);
			byte[] user_in_bytes = new_user.to_byte_array();

			// O Arquivo Espacos Livres eh um indice indireto sequencial denso que funciona em pares...
			// Ele tem um par de longs: Um tamanho e um endereco. Esses longs indicam
			// os usuarios marcados como lapide(*) no arquivo dados.db - O primeiro fala quantos bytes estao vazios, e
			// o outro fala a posicao do inicio desses bytes em dados.db
			Indice_Lapides arq_sequencial = new Indice_Lapides(percentage_for_overwrite);

			// A funcao search_empty_space recebe um long - qual o tamanho do novo usuario em bytes - e procura
			// em seu arquivo se existe algume espaco vazio (algum campo lapide) em dados.db que tenha esse mesmo
			// tamanho ou que a sobreescrita gere, no minimo, <percentage_for_overwrite>% de ocupacao.
			long empty_space_address = arq_sequencial.search_empty_space(user_in_bytes.length);
			arq_sequencial.como_estas();

			// A funcao retorna -1 caso nao tenham usuarios deletados (marcados como lapide)
			// em dados.db. Nesse caso, a variavel so vai ser mudada para db_file.length(), para os dados
			// serem inseridos no final do arquivo dados.db
			if(empty_space_address == -1)
				empty_space_address = db_file.length();
			

			db_file.seek(empty_space_address);

			logger.info("Escrevendo novo usuario em dados.db\n#email = " + new_user.get_email() + "\n#ID = " + new_user.get_id() + "\n");
			
			
			// Se o arquivo tiver um char ' ' na frente, significa que o campo é valido. Se o char for '*', o
			// campo denomina uma lapide - Ja teve um arquivo ali antes, mas nao tem mais.
			this.db_file.writeChar(' ');
			this.db_file.writeInt(user_in_bytes.length);

			this.db_file.write(user_in_bytes);
			
			logger.info("Novo usuario escrito com sucesso!\n");
			close_db_file();

			// HashExtensivel eh um indice direto que armazena um par de chaves. Muito parecido com o Arquvo_Espacos_Livres,
			// esse arquivo armazena os pares ID - Local do ID em dados.db
			HashExtensivel he = new HashExtensivel(4, "diretorio.hash.db", "cestos.hash.db");
			he.create(last_inserted_id, empty_space_address);

			// A ArvoreBMais_String_Int armazena outro par de informacoes. Email - ID. Retornando o ID, pode-se jogar ele
			// na HashExtensivel para obter o local no arquivo dados.db
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


	// A funcao read recebe um ID e realiza uma busca na tabela hash extensivel para obter a localizacao do
	// registro de usuario em dados.db
	public Template read(int search_id)
	{
		Template read_user;
		try
		{
			// Como eh preciso retornar um usuario, eh preciso criar um novo
			read_user = this.constructor.newInstance();
			open_db_file();
			
			HashExtensivel he = new HashExtensivel(4, "diretorio.hash.db", "cestos.hash.db");
			long id_location = he.read(search_id);

			db_file.seek(id_location);
			
			// Verificando se o campo eh uma lapide para saber se o usuario existe
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
			read_user = null;
		}

		return read_user;
	}



	// Recebe um email ao inves de um indice. Esse tipo de busca nao muda muito.
	// A unica diferenca eh que eh obtido o ID usando o indice indireto ArvoreBMais_String_Int, e
	// depois esse ID eh jogado para a funcao read que recebe um int. Usuario eh retornado
	// da mesma forma
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


	// Essa funcao recebe um int e usa ele para sobreescrever os dados de um usuario, caso ele seja achado.
	// Se nao for executada corretamente, retorna -1. Caso contrario, retorna a ID do usuario
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

			// Criando nova instancia de um objeto Usuario
			new_user = this.constructor.newInstance();
			new_user.set_info(update_id);

			char is_lapide = db_file.readChar();
			byte[] new_user_in_bytes = new_user.to_byte_array();

			// Verificando novamente se o campo eh uma lapide, como medida de seguranca
			if(is_lapide == ' ')
			{
				int tam = db_file.readInt();
				
				// Se o tamanho da ocupacao ja for maior que <percentage_for_overwrite>, eh desnecessario
				// fazer uma busca no indice de espacos vazios. Essa busca so vai ser feita se cair no else
				if(( 100*new_user_in_bytes.length/tam >= percentage_for_overwrite) && (new_user_in_bytes.length <= tam) )
				{
					db_file.seek(id_location + 2);
					db_file.writeInt(new_user_in_bytes.length);
					db_file.write(new_user_in_bytes);
				}
				else
				{		
					db_file.seek(id_location);
					db_file.writeChar('*');

					// Procurando por espacos vazios. Se a funcao retornar -1, eh pq nao existem espacos 
					// vazios, logo, o novo usuario vai ser inserido no final de dados.db. Caso contrario, vai
					// ser inserido no espaco retornado por essa funcao
					Indice_Lapides arq = new Indice_Lapides(percentage_for_overwrite);
					long address = arq.search_empty_space(new_user_in_bytes.length);
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
					db_file.writeInt(new_user_in_bytes.length);
					db_file.write(new_user_in_bytes);

					arq.como_estas();

					ArvoreBMais_String_Int arvore = new ArvoreBMais_String_Int(10, "./dados/index_indireto.db");
					arvore.update(new_user.get_email(), new_user.get_id());
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


	// Recebe um ID e deleta ele do arquivo dados.db
	// Essa funcao tambem eh responsavel por criar entradas no indice indireto de
	// espacos vazios.
	int delete(int delete_id)
	{
		try
		{
			HashExtensivel he = new HashExtensivel(4, "diretorio.hash.db", "cestos.hash.db");
			long location_id  = he.read(delete_id);

			open_db_file();
			
			db_file.seek(location_id);
			
			// Marcando usuario como lapide em dados.db
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

			// Indicando para o indice de lapides que um usuario foi deletado de dados.db
			// Com a chamada da funcao create_entry_grave, o indice de lapides vai armazenar o 
			// tamanho da nova lapide, e tambem a sua localizacao
			Indice_Lapides arq = new Indice_Lapides(percentage_for_overwrite);
			arq.create_entry_grave((long)len, location_id);
			arq.como_estas();

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
