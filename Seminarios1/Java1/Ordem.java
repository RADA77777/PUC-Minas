/*
* Aluno: Rafael Amauri Diniz Augusto
* Turno: Manhã
* Professor: João Caram
* Questão 4
*/

import java.util.Scanner;

public class Ordem
{
	public static void main(String[] arguments)
	{	
		Scanner leitor = new Scanner(System.in);

		int quantidade = leitor.nextInt();
		int[] numeros = new int[quantidade];
		boolean emOrdem;                            

		for(int i = 0; i < quantidade; i++)
		{
			numeros[i] = leitor.nextInt(); //Todo elemento da lista eh preenchido com um inteiro
		}

		int vezes = leitor.nextInt();

		for(int i = 0; i < vezes; i++) 
		{
			int n1 = leitor.nextInt();
			int n2 = leitor.nextInt();
			
			/*
			* A funcao em_Ordem retorna o valor boolean true caso os numeros estejam em ordem, e
			* false caso não estejam. 
			*/
			emOrdem = em_Ordem(numeros, n1, n2);

			if( emOrdem == true )
			{
				System.out.println("SIM"); 
			}
			
			else
			{
				System.out.println("NAO");
			}
		}
		
	}


	/* 
	* em_Ordem é uma funcao recursiva que roda enquanto numero[posicao_Cima] seja menor que
	* numero[posicao_Cima - 1]. Caso numero[posicao_Cima] seja maior ou igual que o outro, 
	* a função se chama e passa como parametros os mesmos limites de antes, diminuindo em 1 
	* o parâmetro posicao_Cima.
	*/
	public static boolean em_Ordem(int[] numeros, int posicao_Baixo, int posicao_Cima)
	{	
		boolean emOrdem = true;

		if(posicao_Cima > posicao_Baixo)
		{
			if(numeros[posicao_Cima] < numeros[posicao_Cima-1])
			{
				emOrdem = false; // numeros[posicao_Cima] representa um elemento, e numeros[posicao_Cima - 1]
								 // é o numero anterior a este elemento. Se numeros[posicao_Cima - 1]
								 // for maior, é porque a sequencia nao esta em ordem
			}

			else
			{
				emOrdem = em_Ordem(numeros, posicao_Baixo, (posicao_Cima - 1));
			}
		}
		
		return emOrdem;
	}
}