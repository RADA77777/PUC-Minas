import java.util.Scanner;

public class main
{
	public static void main(String[] args)
	{
		try
		{
			CRUD<Usuario> crud = new CRUD<>(Usuario.class.getConstructor());
			Scanner in = new Scanner(System.in);
			boolean flag = true;

			while(flag)
			{
				menu();

				int selection = in.nextInt();
				while(selection < 0 || selection > 4)
				{
					System.out.println("Selecao nao valida");
					menu();
					selection = in.nextInt();
				}

				switch(selection)
				{
					case 1: select_create(crud, in);  break;
					case 2: select_read(crud, in);    break;
					case 3: select_update(crud, in);  break;
					case 4: select_delete(crud, in);  break;
					case 0: flag = false;
				}
				System.out.println("\n\n");
			}
			in.close();
		}
		catch(Exception error)
		{
			error.printStackTrace();
		}
	}

	
	public static void menu()
	{
		System.out.println("Digite... [1] para criar novo usuario\n" +
						   "\t  [2] para pesquisar um usuario\n" +
						   "\t  [3] para atualizar inputformacoes de um usuario\n" +
						   "\t  [4] para deletar um usuario\n" +
						   "\t  [0] para sair"
						   );
		
	}

	public static void select_create(CRUD<Usuario> crud, Scanner input)
	{
		System.out.println("Bem vindo ao menu de criacao de usuarios!");

		crud.create();
	}


	public static void select_read(CRUD<Usuario> crud, Scanner input)
	{
		System.out.println("Bem vindo ao menu de busca!");
		
		System.out.println("Digite... [1] para buscar por ID\n" +
						   "\t  [2] para buscar por e-mail"
							);

		int search_option = input.nextInt();

		while(search_option < 1 || search_option > 2)
		{
			System.out.println("Selecao invalida.");

			System.out.println("Digite... [1] para buscar por ID\n" +
							   "\t  [2] para buscar por e-mail"
		 					   );
		}

		Usuario searched_user = new Usuario();

		if(search_option == 1)
		{
			System.out.println("Digite o ID a ser buscado");
			int search_id = input.nextInt();
			searched_user = crud.read(search_id);
		}
		else if(search_option == 2)
		{
			System.out.println("Digite o email para busca");
			String search_email = input.next();
			searched_user = crud.read(search_email);
		}

		if(searched_user == null)
			System.out.println("Nao foi possivel encontrar esse usuario!");
		else
			searched_user.print_entity();
	}


	public static void select_update(CRUD<Usuario> crud, Scanner input)
	{
		System.out.println("Bem vindo ao menu de atualizacao!");

		System.out.println("Digite... [1] para atualizar por ID\n" +
						   "\t  [2] para atualizar por e-mail"
							);

		int search_option = input.nextInt();

		while(search_option < 1 || search_option > 2)
		{
			System.out.println("Selecao invalida.");

			System.out.println("Digite... [1] para atualizar por ID\n" +
							   "\t  [2] para atualizar por e-mail"
		 					   );
		}

		if(search_option == 1)
		{
			System.out.println("Digite o ID a ser atualizado");
			int update_id = input.nextInt();
			System.out.println(update_id);
			crud.update(update_id);
		}
		else if(search_option == 2)
		{
			System.out.println("Digite o email para atualizacao");
			String update_email = input.next();
			crud.update(update_email);
		}
	}

	public static void select_delete(CRUD<Usuario> crud, Scanner input)
	{
		System.out.println("Bem vindo ao menu de remocao de usuarios!");
		System.out.println("Digite o ID do usuario a ser deletado... ");

		int delete_id = input.nextInt();

		crud.delete(delete_id);
	}
}