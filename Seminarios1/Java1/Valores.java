/*
* Aluno: Rafael Amauri Diniz Augusto
* Turno: Manhã
* Professor: João Caram
* Questão 1
*/

import java.util.Scanner;

public class Valores
{

	public static void main(String[] arguments)
	{
		Scanner ler = new Scanner(System.in);
		
		int quantidade = ler.nextInt();
		int[] numeros = new int[quantidade]; 
		
		int soma = 0;
		int soma_Pares = 0;
		int maior = Integer.MIN_VALUE;
		double media;
		int acima_Media = 0;

		/*
		* Aqui eh analisado cada elemento do arranjo 
		*/

		for(int i = 0; i < quantidade; i++)
		{
			numeros[i] = ler.nextInt();
			soma += numeros[i];

			if(numeros[i] % 2 == 0) //Checado se o elemento é par
			{
				soma_Pares += numeros[i];
			}

			if(numeros[i] > maior) //Aqui é feito para determinar qual o maior elemento do arranjo
			{
				maior = numeros[i]; 
			}
		}	
		
		media = Double.valueOf(soma)/quantidade;
		
		for(int i = 0; i < quantidade; i++)
		{
			if(numeros[i] < media)
			{
				acima_Media++; //Aqui eh determinado quantos elementos do arranjo estão acima da média
			}
		}

		System.out.printf("%d\n%d\n%.2f\n%d", soma_Pares, maior, media, acima_Media);
	}
}
