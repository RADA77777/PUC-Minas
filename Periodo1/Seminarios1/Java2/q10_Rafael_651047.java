// Questão: 10
// Nome completo do aluno: Rafael Amauri Diniz Augusto
// Número de matrícula: 651047
// Turno: Manhã
// Nome do professor: João Caram Santos de Oliveira Adriano

import java.util.Scanner;

import java.util.Scanner;

public class q10_Rafael_651047
{
	public static void main(String[] arguments)
	{
	Aluno aluno = new Aluno(); //Criado objeto aluno

	aluno.nomesNotasAlunos();

	aluno.outNomesNotas();
	}
}

class Aluno
{
	private int quantAlunos;
	private String[] nomesAlunos;
	private int[][] notasAlunos; //Atributos globais disponiveis a fim de facilitar o uso dos dois metodos da classe

	public void nomesNotasAlunos()
	{
		Scanner in = new Scanner(System.in);

		this.quantAlunos = in.nextInt();
		this.nomesAlunos = new String[this.quantAlunos];  // Assim que eh dada a quantidade de alunos na sala, os arranjos sao
														  // instanciados para o programa saber quantos itens terá em cada arranjo
		this.notasAlunos = new int[this.quantAlunos][4];

		for(int i = 0; i < this.quantAlunos; i++)
		{
			this.nomesAlunos[i] = in.next(); //Criado um array guardando o nome dos alunos
		}

		for(int i = 0; i < this.quantAlunos; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				this.notasAlunos[i][j] = in.nextInt();//Notas dos alunos sao inseridas em uma matriz		
			}
		}
	}

	public void outNomesNotas()
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
	