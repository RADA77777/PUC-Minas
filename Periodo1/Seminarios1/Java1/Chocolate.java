/*
* Aluno: Rafael Amauri Diniz Augusto
* Turno: Manhã
* Professor: João Caram
* Questão 3
*/

import java.util.Scanner;

public class Chocolate
{
	public static void main(String[] arguments)
	{
		Scanner ler = new Scanner(System.in);

		int quantidadeDivisoes = ler.nextInt();
		int divisao;
		int pedacos = 0;
		
		for(int i = 0; i < quantidadeDivisoes; i++) 
		{
			divisao = ler.nextInt();				
			pedacos += (divisao - 1);				/*
												* O numero de pedacos que sobram vai ser igual
												* ao numero de divisoes -1. Por exemplo: 
												* se um pedaco for dividido em 4 partes, 3 delas 
												* serao guardadas e apenas uma continuará a ser 
												* dividida. Portanto, no código é somada ao numero de
												* pedacos o valor de (divisao - 1)
												*/
		}										

	System.out.println(pedacos);	
	}
}
