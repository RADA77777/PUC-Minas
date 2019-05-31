import java.util.Scanner;

public class Chocolate
{
	public static void main(String[] arguments)
	{
		Scanner ler = new Scanner(System.in);

		int quantidade = ler.nextInt();
		int valor;
		int pedacos = 0;
		
		for(int i = 0; i < quantidade; i++)
		{
			valor = ler.nextInt();
			pedacos += (valor - 1);
		}

	System.out.println(pedacos);	
	}
}
