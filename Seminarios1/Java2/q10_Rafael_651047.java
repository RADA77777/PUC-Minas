// Questão: 10
// Nome completo do aluno: Rafael Amauri Diniz Augusto
// Número de matrícula: 651047
// Turno: Manhã
// Nome do professor: João Caram Santos de Oliveira Adriano

import java.util.Scanner;

public class q10_Rafael_651047
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
		int somaNota, maiorNota = Integer.MIN_VALUE, alunoMaiorNota = 0;
		Double somaNotasProva = 0.0;
		for(int i = 0; i < quantAlunos; i++)
		{
			somaNota = 0; //A variavel somaNota é resetada para 0 a cada novo aluno cuja nota vai ser somada
			for(int j = 0; j < 4; j++)
			{
				// É acrescentada à variavel somaNota o valor presente na matriz[i][j]
				somaNota += notasAlunos[i][j];
			}
			// Aqui é selecionada a maior nota da sala, e o aluno que tirou tal nota tem seu
			// index guardado na variavel alunoMaiorNota
			if(somaNota >= maiorNota)
			{
				maiorNota = somaNota;
				alunoMaiorNota = i;
			}
                }
                
                for(int i = 0; i < 4; i++)
                {
                        somaNotasProva = 0.0;
                        for(int j = 0; j < quantAlunos; j++)
                        {
                                somaNotasProva += notasAlunos[j][i];
                        }
                        //Printado a media da sala em cada prova
                        String mediaFormatada = String.format("%.2f",somaNotasProva / quantAlunos);
                        mediaFormatada = mediaFormatada.replace(",", ".");
			System.out.printf("PROVA %d %s\n", (i + 1), mediaFormatada);
                }
		//Printado nome e nota do aluno com maior nota
		System.out.println(nomesAlunos[alunoMaiorNota] + " " + maiorNota);
	}
}
