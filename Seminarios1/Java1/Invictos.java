/*
* Aluno: Rafael Amauri Diniz Augusto
* Turno: Manhã
* Professor: João Caram
* Questão 5
*/

import java.util.Scanner;

public class Invictos
{
	public static void main(String[] arguments)
	{
		Scanner leitor = new Scanner(System.in);
		
		int quantidade_Jogos = leitor.nextInt();
		int[] posicao_Jogo_Inicial = new int[2];
		int[] posicao_Jogo_Final = new int[2]; 
		int[] maior_Sequencia_Vitorias = new int[2]; /*
													 * A ideia é fazer com que o 2 elemento dos arrays
													 * funcionem como armazenamento temporario dos valores
													 * e o 1 armazene um valor definitivo, que sera impresso no final
													 */
		posicao_Jogo_Inicial[1] = -1;	
	
		String placar;
		String[] placar_Formatado = new String[2];
			
		for(int i = 0; i < quantidade_Jogos; i++)
		{
			placar = leitor.next();
			placar_Formatado = placar.split("x"); 
			/*
			* A string placar_Formatado divide a string placar no delimitador "x", de forma que
			* placar_Formatado[0] vai ser o 1 numero inserido, e placar_Formatado[1] vai ser o
			* 2 numero inserido
			*/

			if( Integer.parseInt(placar_Formatado[0]) >= Integer.parseInt(placar_Formatado[1]) )
			{	
				maior_Sequencia_Vitorias[1]++;
				posicao_Jogo_Final[1] = i; //Se o 1 numero for maior que o 2 (vitória do time de
										   // Joãozinho) , o temporario maior_Sequencia_Vitorias 
										   // aumenta em 1



				if(posicao_Jogo_Inicial[1] == -1)
				{
					posicao_Jogo_Inicial[1] = i; // O valor armazenado para a posicao do jogo
												 // inicial (Primeiro jogo ganho) so muda se seu valor original for
												 // -1 (ele so vai ser -1 caso seja o primeiro jogo de todos, ou caso
												 // um jogo seja perdido)
				}

				if(maior_Sequencia_Vitorias[1] > maior_Sequencia_Vitorias[0])
				{	
				/*
				* Caso o valor temporario seja maior que o definitivo, eh atribuido ao definitivo
				* o valor de temporario em todos arranjos. 
				*/
				maior_Sequencia_Vitorias[0] = maior_Sequencia_Vitorias[1];
				posicao_Jogo_Inicial[0] = posicao_Jogo_Inicial[1];
				posicao_Jogo_Final[0] = posicao_Jogo_Final[1];
				}
			}
			
			else
			{
				// Caso um jogo seja perdido, a maior sequencia de vitorias temporaria eh mudada para
				// 0, e a posicao de jogo inicial vira -1, para indicar que uma nova sequencia deve começar
				// a ser identificada
				maior_Sequencia_Vitorias[1] = 0;
				posicao_Jogo_Inicial[1] = -1;
			}
		}

		posicao_Jogo_Inicial[0]++;
		posicao_Jogo_Final[0]++;

		System.out.printf("%d\n%d %d",maior_Sequencia_Vitorias[0], posicao_Jogo_Inicial[0], posicao_Jogo_Final[0]);
	}
}
