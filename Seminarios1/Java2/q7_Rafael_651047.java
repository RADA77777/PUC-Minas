// Questão: 7
// Nome completo do aluno: Rafael Amauri Diniz Augusto
// Número de matrícula: 651047
// Turno: Manhã
// Nome do professor: João Caram Santos de Oliveira Adriano

import java.util.Scanner;

public class q7_Rafael_651047
{
    public static void main(String[] arguments)
    {
         Scanner in = new Scanner(System.in);
	 int ordem = in.nextInt();
	 int[][] quadradoMagico = new int[ordem][ordem]; 
	 
	 // A matriz quadradoMagico[][] é preenchida com os numeros
	 for(int i = 0; i < ordem; i++)
	 {
	     for(int j = 0; j < ordem; j++)
	     {
	         quadradoMagico[i][j] = in.nextInt();
	     }
	 } 
	 
	 int[] somaLinhas = new int[ordem];
	 int[] somaColunas = new int[ordem];
	 int somaDiagonal = somarEixos(quadradoMagico, ordem, somaLinhas, somaColunas); /* 
											* Como Java nao aceita passagem por referencia para 
	 										* tipos primitivos, a funcao somaEixos retorna um inteiro
											* que representa a soma da diagonal principal para ser
											* armazenado em somaDiagonal, para que essa variavel
											* depois possa ser facilmente passada para a funcao
											* verificarSeIgual()
											*/
	 verificarSeIgual(ordem, somaLinhas, somaColunas, somaDiagonal);
	
	 in.close();
    }

    public static int somarEixos(int[][] quadradoMagico, int ordem, int[] somaLinhas, int[] somaColunas)
    {
	int somaDiagonal = 0;
	for(int i = 0; i < ordem; i++)
	{
	    somaDiagonal += quadradoMagico[i][i]; /* 
						  * A diagonal de uma matriz quadrada sempre sera composta pela ligacao dos pontos
	    					  * matriz[i][i]. A variavel somaDiagonal se aproveita dessa propriedade para
						  * armazenar a soma dos valores da diagonal
						  */

	    for(int j = 0; j < ordem; j++)
	    {
    	        somaLinhas[i] += quadradoMagico[i][j]; /* 
						       * Como existe mais de 1 linha e mais de 1 coluna, foi criado um arranjo para
						       * armazenar o valor da soma de cada linha e outro para o da soma de cada coluna,
						       * por isso somaLinhas[i] e somaColuna[i]
						       */
		somaColunas[i] += quadradoMagico[j][i];		
            }
	}
	return somaDiagonal;
    }

    public static void verificarSeIgual(int ordem, int[] somaLinhas, int[] somaColunas, int somaDiagonal)
    {
	boolean somasIguais = true;
	for(int i = 0; i < ordem; i++)
	{
	    if( (somaLinhas[i] != somaDiagonal) || (somaColunas[i] != somaDiagonal)) /* 
										     * Se a soma de diagonais, colunas e linhas deve ser igual,
										     * pode-se verificar mais rapido se o quadrado é magico
										     * ao comparar apenas a soma de linhas e colunas à diagonal
										     */
	    {
		somasIguais = false;
		break;
	    } 
	}

	if(somasIguais)
	{
	    System.out.println(somaDiagonal);
	}
	else
	{
	    System.out.println(0);
	}
    }
}
	
