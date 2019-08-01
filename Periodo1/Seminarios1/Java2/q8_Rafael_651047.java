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
		int somaNota;
		for(int i = 0; i < this.quantAlunos; i++)
		{
			somaNota = 0; //A variavel somaNota é resetada para 0 a cada novo aluno cuja nota vai ser somada
			for(int j = 0; j < 4; j++)
			{
				somaNota += this.notasAlunos[i][j]; // É acrescentada à variavel somaNota o valor presente na matriz
			}
			System.out.printf("%s %d\n", this.nomesAlunos[i], somaNota);
		}
	}
}