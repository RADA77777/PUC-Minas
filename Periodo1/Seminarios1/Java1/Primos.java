/*
* Aluno: Rafael Amauri Diniz Augusto
* Turno: Manhã
* Professor: João Caram
* Questão 2
*/


import java.util.Scanner;

public class Primos
{
	public static void main(String[] arguments)
	{
		Scanner leitor = new Scanner(System.in);
		int vezes = leitor.nextInt();

		for(int j = 0; j < vezes; j++) //A variavel 'vezes' determina quantos números serão verificados
		{
			int numero = leitor.nextInt();
		
			boolean primo = true;
		
			for(int i = 2; i < numero; i++)
			{
									/* 
									* O número começa como sendo primo, e seu valor booleano 
									* muda para falso se ele for divisivel por algum numero
									* de 2 até ele
									*/
				if(numero % i == 0) 
				{
					primo = false;
					break;
				}
			}

			if(primo == true)
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
