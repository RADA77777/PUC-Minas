import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.lang.Math;
import java.lang.StringBuilder;

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
class Questao1 implements Runnable
{
	private int base, numero, resto;
	private String numConvertido = new String();
	Scanner in = new Scanner(System.in);
	
	public void run()
	{
		System.out.println("Comecando exercicio 1...\n");
		setBase();
		setNumero();
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

	/*
	* Para converter de base 10 para uma base N, basta pegar o resto da divisao e concatena-lo 
	* a uma string ate que o numero decimal fique menor que a base N. Ex.: numero = 6; base = 2
	* 6 / 2 = resto 0 -> Numero vira 3 -> 3/2 = resto 1 -> numero vira 1.5 -> 1.5 / 2 = resto 1;
	* Com isso, nosso numero convertido sera 011. Mas a resposta certa pede que a string seja revertida.
	* Por isso usamos a expressao numConvertido = new StringBuilder(numConvertido).reverse().toString()
	* para reverte-la
	*/
	public void converter(int base, int numero)
	{
		if(numero < base)
		{
			numConvertido = numConvertido.concat(Integer.toString(numero));
			numConvertido = new StringBuilder(numConvertido).reverse().toString();
			return;
		}
		resto = numero % base;
		numConvertido = numConvertido.concat(Integer.toString(resto));
		converter(base, numero/base);
		return;
	}

	public void resultado()
	{
		System.out.println("O numero " + this.numero +
						   " na base " + this.base +
						   " vale " + this.numConvertido);
	}
}

/**
 * Classe para resolucao do problema 2
 * 
 * @author Rafael Amauri Diniz Augusto
 *
 */

class Questao2 implements Runnable
{
	int multiplicado, dividendo;
	Scanner in = new Scanner(System.in);

	public void run()
	{
		System.out.println("\nComecando exercicio 2...\n");
		setMult();
		setDiv();
		System.out.println(multiplicado + " * 2 = " + multiplicar(multiplicado, 2));
		System.out.println(dividendo + " / 2 = " + dividir(dividendo));
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
	
	public int dividir(int dividendo)
	{
		int resposta;
		if(dividendo % 2 != 0)
		{
			System.out.println("Como o dividendo nao eh par, a divisao nao sera exata!");
		}
		resposta = dividendo >> 1;
		return resposta;
	}
}

/**
 * Classe para resolucao do problema 3
 * 
 * @author Rafael Amauri Diniz Augusto
 *
 */

class Extra1 implements Runnable
{
	Scanner in = new Scanner(System.in);
	String numHexOctal = new String() , numeroBinario = new String();
	int numeroDecimal;

	public void run()
	{
		System.out.println("\nComecando exercicio 3...\n");
		setBinario();
		converterParaDecimal(numeroBinario);
		converterParaHex(this.numeroDecimal);

		System.out.println("\nO numero " + numeroBinario + 
						   "\nEm decimal vale " + this.numeroDecimal +
						   "\nEm hexadecimal vale " + numHexOctal);	
		
		resetarStringHexOctal();				
		converterParaOctal(this.numeroDecimal);
		System.out.println("Em octal vale " + numHexOctal);
	}

	public void setBinario()
	{
		System.out.println("Digite um numero em binario");
		numeroBinario = in.next();
	}

	/*
	* Esse codigo serve para devolver uma lista de strings, que contem a string numero binario
	* divida em partes de 3, para ficar mais facil fazer a conta com octais. Ela tambem teve que ser revertida
	* para fazer a conta com expoentes na funcao devolverDecimal()
	*/
	public List<String> pegarPartes(String string, int tamanhoParticao){
		List<String> partes = new ArrayList<String>();
		string = new StringBuilder(string).reverse().toString();
		int tam = string.length();

        for (int i = 0; i < tam; i += tamanhoParticao)
        {
            partes.add(string.substring(i, Math.min(tam, i + tamanhoParticao)));
        }
        return partes;
	}
	
	/*
	* A ideia aqui é converter binario para decimal usando octais. Octais sao conjuntos de 3 numeros binarios
	* juntos, logo é possivel converter para decimal. Como entrada usando o numero 101100: A funcao
	* pegarPartes manda listas strings de tamanho maximo 3 (octal = 3 bits). A logica eh fazer para a 1 parte
	* (1 x numero x pow(8, expoente)) + (2 x numero x pow(8, expoente) + (4 x numero x pow(8, expoente)). 
	* O expoente aumenta a cada conjunto de numeros. No primeiro conjunto
	* (no exemplo: 100), expoente = 0, e no segundo conjunto(101), expoente = 1 
	*/
	public void converterParaDecimal(String numeroBinario)
	{
		int expoente = 0, soma = 0;
		for(String parte : pegarPartes(numeroBinario, 3))
		{
			for(int j = 0; j < parte.length(); j++)
			{
				if(parte.toCharArray()[j] == '1')
				{
					soma += Math.pow(2,j) * Math.pow(8, expoente);
				}
			}
			expoente++;
		}
		this.numeroDecimal = soma;
		return;
	}

	/*
	* A logica é a mesma da funcao converter() da classe Questao 1
	*/
	public void converterParaOctal(int numero)
	{
		if(numero < 8)
		{
			numHexOctal = numHexOctal.concat(Integer.toString(numero));
			numHexOctal = new StringBuilder(numHexOctal).reverse().toString();
			return;
		}
		int resto = numero % 8;

		numHexOctal = numHexOctal.concat(Integer.toString((int)resto));
		converterParaOctal(numero/8);
		return;
	}

	public void converterParaHex(int numero)
	{
		if(numero < 16)
		{
			numHexOctal = numHexOctal.concat(Integer.toString(numero));
			numHexOctal = new StringBuilder(numHexOctal).reverse().toString();
			return;
		}
		int resto = numero % 16;
		boolean restoMenor10 = true;

		if(resto >= 10)
		{
			restoMenor10 = false;
			switch (resto)
			{
				case 10:
					numHexOctal = numHexOctal.concat("A");
					break;
				case 11:
					numHexOctal = numHexOctal.concat("B");
					break;
				case 12:
					numHexOctal = numHexOctal.concat("C");
					break;
				case 13:
					numHexOctal = numHexOctal.concat("D");
					break;
				case 14:
					numHexOctal = numHexOctal.concat("E");
					break;
				case 15:
					numHexOctal = numHexOctal.concat("F");
					break;
				default:
					break;
			}
		}
		if(restoMenor10)
		{
			numHexOctal = numHexOctal.concat(Integer.toString(resto));
		}
		converterParaHex(numero/16);
		return;
	}

	public void resetarStringHexOctal()
	{
		numHexOctal = "";
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
		Runnable[] listaExercicios = new Runnable[3];
		Exercicios exercicios = new Exercicios();
		listaExercicios[0] = new Questao1();
		listaExercicios[1] = new Questao2();
		listaExercicios[2] = new Extra1();

		exercicios.runExercicio(listaExercicios);
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

