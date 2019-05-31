import java.util.Scanner;

public class Ordem
{
	public static void main(String[] arguments)
	{	
		Scanner leitor = new Scanner(System.in);

		int quantidade = leitor.nextInt();
		int[] numeros = new int[quantidade];
		int resposta;

		for(int i = 0; i < quantidade; i++)
		{
			numeros[i] = leitor.nextInt();
		}

		int vezes = leitor.nextInt();

		for(int i = 0; i < vezes; i++)
		{
			int n1 = leitor.nextInt();
			int n2 = leitor.nextInt();
			
			if(n1 < n2)
			{
				resposta = em_Ordem(numeros, n1, n2);
			}

			else
			{
				resposta = (em_Ordem(numeros, n2, n1) -1);
			}

			if( (resposta == 1 || resposta == -1) )
			{
				System.out.println("SIM");
			}
			
			else
			{
				System.out.println("NAO");
			}
		}
		
	}

	public static int em_Ordem(int[] numeros, int posicao_Baixo, int posicao_Cima)
	{	
		int valido = 1;

		if(posicao_Cima > posicao_Baixo)
		{
			if(numeros[posicao_Cima] < numeros[posicao_Cima-1])
			{
				valido = 0;
			}

			else
			{
				valido = em_Ordem(numeros, posicao_Baixo, (posicao_Cima - 1));
			}
		}
		
		return valido;
	}
}
