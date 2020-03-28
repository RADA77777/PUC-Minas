import java.util.Scanner;

public class main
{
	public static void main(String[] args)
	{
		CRUD crud = new CRUD();
		Usuario u = new Usuario();

		menu();
		Scanner in = new Scanner(System.in);

		
		int selection = in.nextInt();
		
		switch(selection)
		{
			case 1: crud.create();
			case 2: crud.read();
			case 3: crud.update();
			case 4: crud.delete();
		}
	}

	public static void menu()
	{
		System.out.println("Digite... [1] para criar novo usuario\n" +
						   "\t  [2] para pesquisar um usuario\n" +
						   "\t  [3] para atualizar informacoes de um usuario\n" +
						   "\t  [4] para deletar um usuario\n"
						   );
		
	}
}