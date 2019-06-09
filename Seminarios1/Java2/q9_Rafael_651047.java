// Questão: 9
// Nome completo do aluno: Rafael Amauri Diniz Augusto
// Número de matrícula: 651047
// Turno: Manhã
// Nome do professor: João Caram Santos de Oliveira Adriano

import java.util.Scanner;

public class q9_Rafael_651047
{
	public static void main(String[] arguments)
	{
        Scanner in = new Scanner(System.in);
	int quantAlunos = in.nextInt();
        String[] nomesAlunos = new String[quantAlunos];
        //Criado um array guardando o nome dos alunos
	for(int i = 0; i < quantAlunos; i++)
	{
		nomesAlunos[i] = in.next(); 
	}

        int[][] notasAlunos = new int[quantAlunos][4];
        //Notas dos alunos sao inseridas em uma matriz
	for(int i = 0; i < quantAlunos; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			notasAlunos[i][j] = in.nextInt();		
		}
	}
	outNomesNotas(nomesAlunos, notasAlunos, quantAlunos);
	in.close();
	}
	
	public static void outNomesNotas(String[] nomesAlunos, int[][] notasAlunos, int quantAlunos)
	{
		int somaNota, aprovados = 0, reprovados = 0;
		Double media;
		for(int i = 0; i < quantAlunos; i++)
		{
                        //A variavel somaNota é resetada para 0 a cada novo aluno cuja nota vai ser somada
			somaNota = 0; 
                        
                        // É acrescentada à variavel somaNota o valor presente na matriz[i][j]
                        for(int j = 0; j < 4; j++)
			{
				somaNota += notasAlunos[i][j]; 
                        }

                        // Nome do aluno é printado
                        System.out.printf("%s ", nomesAlunos[i]); 
                        
                        //Se aprovado, o nome é seguido de "APROVADO"
			if(somaNota >= 60)
			{
				System.out.println("APROVADO"); 
				aprovados++;
                        }
                        
                        //Se reprovado, o nome é seguido de "REPROVADO"
			else
			{
				System.out.println("REPROVADO");
				reprovados++;
			}
		}
                media = (aprovados/Double.valueOf(quantAlunos)) * 100;
                /*
		* Printado a quantidade de aprovados, de
		* reprovados e a média
		*/ 
		System.out.println(aprovados + " APROVADOS\n" + 
						   reprovados + " REPROVADOS\n" + 
						   media.intValue() + "%");
	}
}
