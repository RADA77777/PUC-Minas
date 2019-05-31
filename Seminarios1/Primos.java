import java.util.Scanner;

public class Primos
{
	public static void main(String[] arguments)
	{
		Scanner leitor = new Scanner(System.in);
		int vezes = leitor.nextInt();
		for(int j = 0; j < vezes; j++)
		{
			int numero = leitor.nextInt();
		
			int primo = 1;
		
			for(int i = 2; i < numero; i++)
			{
				if(numero % i == 0)
				{
					primo = 0;
					break;
				}
			}

			if(primo == 1)
			{
				System.out.println("SIM");
			}
			else
			{
				System.out.println("NAO");
			}
	
		}

	}
}
