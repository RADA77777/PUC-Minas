// Questão: 8
// Nome completo do aluno: Rafael Amauri Diniz Augusto
// Número de matrícula: 651047
// Turno: Manhã
// Nome do professor: João Caram Santos de Oliveira Adriano

import java.util.Scanner;

public class q8_Rafael_651047
{
	public static void main(String[] arguments)
	{
        Scanner in = new Scanner(System.in);
	int quantAlunos = in.nextInt();
	String[] nomesAlunos = new String[quantAlunos];
	for(int i = 0; i < quantAlunos; i++)
	{
		nomesAlunos[i] = in.next(); //Criado um array guardando o nome dos alunos
	}

	int[][] notasAlunos = new int[quantAlunos][4];
	for(int i = 0; i < quantAlunos; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			notasAlunos[i][j] = in.nextInt();//Notas dos alunos sao inseridas em uma matriz		
		}
	}
	outNomesNotas(nomesAlunos, notasAlunos, quantAlunos);
	in.close();
	}
	
	public static void outNomesNotas(String[] nomesAlunos, int[][] notasAlunos, int quantAlunos)
	{
		int somaNota;
		for(int i = 0; i < quantAlunos; i++)
		{
			somaNota = 0; //A variavel somaNota é resetada para 0 a cada novo aluno cuja nota vai ser somada
			for(int j = 0; j < 4; j++)
			{
				somaNota += notasAlunos[i][j]; // É acrescentada à variavel somaNota o valor presente na matriz
			}
			System.out.printf("%s %d\n", nomesAlunos[i], somaNota);
		}
	}
}
