import java.util.Scanner;

public class main
{
	public static void main(String[] args)
	{
		try
		{
			final Scanner in              =  new Scanner(System.in);
			CRUD<Usuario>  crud_usuarios  =  new CRUD<>(Usuario.class.getConstructor(),  "./dados/usuarios.db",  in);
			CRUD<Sugestao> crud_sugestao  =  new CRUD<>(Sugestao.class.getConstructor(), "./dados/sugestoes.db", in);
			CRUD<Grupo>    crud_grupo     =  new CRUD<>(Grupo.class.getConstructor(),    "./dados/grupos.db",    in);    

			boolean flag   =  true;
			int logged_in  =  0;

			// Implementacao do menu
			while(flag)
			{
				if(logged_in == 0)
					logged_in = Interface_Crud.menu_inicial(crud_usuarios, in);
				
				if(logged_in == 1)
				{
					int selecao = Interface_Crud.menu_opcoes(in);
					switch(selecao)
					{
						case 1: 
							Interface_Crud.menu_sugestoes(crud_sugestao, in);
							break;
					

						case 2:
							int selecao2 = Interface_Crud.menu_grupos(in);
							switch(selecao2)
							{
								case 1:
									Interface_Crud.gerenciamento_grupos(crud_grupo, in);
									break;
								
								case 2:
									break;
							}
							break;


						case 0:
							logged_in = 0;
							break;
					}
				}
				else
					flag = false;
			}
		}
		catch(Exception error)
		{
			error.printStackTrace();
		}
		
		System.out.println("Obrigado por usar!");
	}
}
