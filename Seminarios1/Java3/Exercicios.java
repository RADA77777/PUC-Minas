import java.util.Scanner;

interface Runnable 
{
	void run();
}

/**
 * Classe para resolucao do problema 1
 * 
 * @author Rafael Amauri Diniz Augusto
 *
 */
class Exercicio1 implements Runnable
{
	private int base, numero;
	private double resto;
	private String numConvertido = new String();
	Scanner in = new Scanner(System.in);

	public void run()
	{
		setBase();
		setNumero();
		in.close();
		converter(base, numero);
		resultado();
	}

	public void setBase()
	{
		do
		{
		System.out.println("Digite a base(base < 10) que deseja converter:");
		this.base = in.nextInt();
		}while(this.base >= 10);
	}

	public void setNumero()
	{
		System.out.println("Digite um numero inteiro e positivo:");
		this.numero = in.nextInt();
	}

	public void converter(int base, int numero)
	{
		if(numero < base)
		{
			numConvertido = numConvertido.concat(Integer.toString(numero));
			return;
		}
		resto = numero % base;
		numConvertido = numConvertido.concat(Integer.toString((int)resto));
		converter(base, numero/base);
		return;
	}

	public void resultado()
	{
		StringBuilder numConvertidoFormatado = new StringBuilder();
		numConvertidoFormatado.append(numConvertido);
		numConvertidoFormatado = numConvertidoFormatado.reverse();

		System.out.println("O numero " + this.numero +
						   " na base " + this.base +
						   " vale " + numConvertidoFormatado);
	}
}

/**
 * Classe para resolucao do problema 2
 * 
 * @author Rafael Amauri Diniz Augusto
 *
 */

class Exercicio2 implements Runnable
{
	int multiplicado, dividendo;
	Scanner in = new Scanner(System.in);

	public void run()
	{
		setMult();
		setDiv();
		in.close();
		System.out.println(multiplicado + " * 2 = " + multiplicar(multiplicado, 2));
	}

	public void setMult()
	{
		System.out.println("Digite o numero que sera multiplicado por 2:");
		this.multiplicado = in.nextInt();
	}

	public void setDiv()
	{
		System.out.println("Digite o numero que sera dividido por 2:");
		this.dividendo = in.nextInt();
	}

	public int multiplicar(int multiplicado, int multiplicador) 
    {  
        int resposta = 0, contador = 0; 
        while (multiplicador > 0) 
        { 
			if (multiplicador % 2 == 1)
			{              
                resposta += multiplicado << contador; 
			}
            contador++; 
            multiplicador /= 2; 
        } 
        return resposta; 
    } 
}

/**
 * Esta classe exemplifica o poder dado pelas interfaces.
 * seus metodos trabalham com os metodos da interface Runnable
 * mas nao sabem nada sobre as classes "concretas":
 * 
 * qualquer classe que implementar Runnable pode ser processada pelos 
 * metodos "runExercicio"
 * 
 * @author saulo
 *
 */

public class Exercicios {


	/**
	 * Roda um exercio qualquer!
	 * @param ex
	 */
	public void runExercicio(Runnable ex)
	{
		ex.run();
	}
	
	public void runExercicio(Runnable[] exercicios)
	{
		for (Runnable r: exercicios)
			r.run();
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		Exercicios lista = new Exercicios();
		Exercicio2 exercicio1 = new Exercicio2();
		lista.runExercicio(exercicio1);
	}
	
}	// fim Exercicios

/*
  
   									TRABALHO PRATICO
 
 	Em cada exercicio, escreva uma classe que implementa a interface Runnable.
 	Ao terminar, use a classe Exercicios para rodar todas as tarefas do trabalho,
 	como foi feito no metodo main.
 	
 	Para facilitar, se achar conveniente, escreva todas as classes neste arquivo, 
 	como foi feito para as classes bufferCircular e aToa.
 	 
   	Exercicio 1)
   				Escreva um algoritmo que converta numeros inteiros positivos 
   				de um sistema de numeracao de base b, b < 10, para decimal e de decimal 
   				para o referido sistema.
   				
   				Encapsule seu algoritmo em uma classe que implementa a interface Runnable.

	Exercicio 2)
				Escreva uma classe que multiplica e divide numeros inteiros por 2 uilizando
				os operadores de deslocamento de bits "<<", ">>" e ">>>"  

	EXTRA 1)
	 			Utilizar os sistemas octal e/ou hexadecimal para converter de binario para 
	 			decimal e vice-versa.
	 			
	EXTRA 2)
	 			Utilizar o Sistema Eneario (base 9) para converter de ternario (base 3) para 
	 			decimal e vice-versa.
	 			
	EXTRA 3)
	 			Converter numeros decimais fracionarios para binario com precisao p, 
	 			fornecida pelo usuario.

 */

