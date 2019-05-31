import java.util.Scanner;
import java.util.Arrays;

public class Invictos
{
	public static void main(String[] arguments)
	{
		Scanner leitor = new Scanner(System.in);
		
		int quantidade_Jogos = leitor.nextInt();
		int[] posicao_Jogo_Inicial = new int[2];
		int[] posicao_Jogo_Final = new int[2];
		int[] maior_Sequencia_Vitorias = new int[2];
		posicao_Jogo_Inicial[1] = -1;	
	
		String placar;
		String[] placar_Formatado = new String[2];
			
		for(int i = 0; i < quantidade_Jogos; i++)
		{
			placar = leitor.next();
			placar_Formatado = placar.split("x");

			if( Integer.parseInt(placar_Formatado[0]) >= Integer.parseInt(placar_Formatado[1]) )
			{	
				maior_Sequencia_Vitorias[1]++;
				posicao_Jogo_Final[1] = i;

				if(posicao_Jogo_Inicial[1] == -1)
				{
					posicao_Jogo_Inicial[1] = i;
				}

				if(maior_Sequencia_Vitorias[1] > maior_Sequencia_Vitorias[0])
				{	
				maior_Sequencia_Vitorias[0] = maior_Sequencia_Vitorias[1];
				posicao_Jogo_Inicial[0] = posicao_Jogo_Inicial[1];
				posicao_Jogo_Final[0] = posicao_Jogo_Final[1];
				}
			}
			
			else
			{
				maior_Sequencia_Vitorias[1] = 0;
				posicao_Jogo_Inicial[1] = -1;
			}
		}

		posicao_Jogo_Inicial[0]++;
		posicao_Jogo_Final[0]++;

		System.out.printf("%d\n%d %d",maior_Sequencia_Vitorias[0], posicao_Jogo_Inicial[0], posicao_Jogo_Final[0]);
	}
}
