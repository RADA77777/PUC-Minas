import java.util.Scanner;

public class main
{
	public static void main(String[] args)
	{
		try
		{
			final Scanner in               =  new Scanner(System.in);
			CRUD<Usuario>  crud_usuarios   =  new CRUD<>(Usuario.class.getConstructor(),  "./dados/usuarios.db",  in);
			CRUD<Sugestao> crud_sugestoes  =  new CRUD<>(Sugestao.class.getConstructor(), "./dados/sugestoes.db", in);
			CRUD<Grupo>    crud_grupos     =  new CRUD<>(Grupo.class.getConstructor(),    "./dados/grupos.db",    in);
			CRUD<Convite>  crud_convites   =  new CRUD<>(Convite.class.getConstructor(),  "./dados/convites.db",  in);
		
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
							Interface_Crud.menu_sugestoes(crud_sugestoes, in);
							break;
					
							
						case 2:
							int selecao2  = Interface_Crud.menu_grupos(in);
							boolean flag2 = true;
							while(flag2)
							{
								switch(selecao2)
								{
									case 1:
										int selecao3  = Interface_Crud.gerenciamento_grupos(crud_grupos, in);
										boolean flag3 = true;
										while(flag3)
										{
											switch(selecao3)
											{
												case 1:
													Interface_Crud.administracao_grupos(crud_grupos, in);
													flag3 = false;
													break;

												case 2:
													Interface_Crud.gerenciamento_convites(crud_grupos, crud_convites, in);
													flag3 = false;
													break;

												case 0:
													flag2 = false;
													flag3 = false;
													break;
											}
										}
										break;

									case 2:
										flag2 = false;
										System.out.println("Ainda esta sendo feito!");
										break;
									
									case 0:
										flag2 = false;
										break;
								}
							}
							break;


						// Convites novos
						case 3:
							Interface_Crud.ver_convites(crud_grupos, crud_convites, in);
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
