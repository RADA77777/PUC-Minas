import java.util.Scanner;

// Questão: 6
// Nome completo do aluno: Rafael Amauri Diniz Augusto
// Número de matrícula: 651047
// Turno: Manhã
// Nome do professor: João Caram Santos de Oliveira Adriano


public class q6_Rafael_651047
{
	public static void main(String[] arguments)
	{
		Scanner in = new Scanner(System.in);
        	int quantBotas = in.nextInt();
        	char[] peBota = new char[quantBotas];
        	int[] tamanhoBota = new int[quantBotas];
        	
		for(int i = 0; i < quantBotas; i++)
        	{
            		tamanhoBota[i] = in.nextInt();
        		peBota[i] = in.next().charAt(0); //Como so sera digitado 'D' ou 'E' para o pé da bota, basta pegar o 1 elemento da string
        	}

        	somarParesBotas(quantBotas, tamanhoBota, peBota);

        	in.close();
    	}

	public static void somarParesBotas(int quantBotas, int[] tamanhoBota, char[] peBota)
	{
		int paresDeBota = 0;
		for(int i = 0; i < quantBotas; i++)
		{
                        if(peBota[i] == 'D')
                        {
                                for(int j = 0; j < quantBotas; j++)
                                {       
                                        /*
                                        * Aqui é verificado se as botas sao do
                                        * mesmo tamanho e pes opostos
                                        */
                                        if(peBota[j] == 'E' && 
                                           tamanhoBota[j] == tamanhoBota[i])
                                        {
                                                paresDeBota++;
                                                peBota[i] = 'x';
                                                peBota[j] = 'x'; // As botas que ja possuem um par declarado sao marcadas com um 'x' para nao serem
                                                                 // contadas de novo 
                                        }
                                }
                        }
		}
		System.out.println(paresDeBota);		
	}
}
