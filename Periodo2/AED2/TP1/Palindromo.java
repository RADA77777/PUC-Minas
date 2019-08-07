public class Palindromo
{
	public static void main(String[] args)
	{
		char[] entrada = new char[100];
		String str = MyIO.readLine();
		int tam = str.length();
		

		char[] entradaReversa = new char[100];
		entrada = str2char(str);
		entrada = removeEspaco(entrada);
		entradaReversa = reverterPalavra(entrada);

	}


	/*
	 * Converte de String para array de caracteres
	 */
	public static char[] str2char(String str)
	{
		char[] entrada = new char[100];
		for(int i = 0; i < str.length(); i++)
		{
			entrada[i] = str.charAt(i);
		}
		return entrada;
	}
	

	/*
	 * Recebe um char[] e remove todos espacos dele 
	 */
	public static char[] removeEspaco(char[] entrada)
	{
		for(int i = 0; i < entrada.length; i++)
		{
			if(entrada[i] == ' ')
			{
				for(int j = 0; j < (entrada.length - 1); j++)
				{
					entrada[j] = entrada[j+1];
				}
				entrada = removeEspaco(entrada);
			}
		}
		return entrada;
	}

	public static char[] reverterPalavra(char[] entrada)
	{
		char aux;
		int cont = 0;
		for(int i = entrada.length - 1; i > (entrada.length/2); i--)
		{
			aux = entrada[cont];
			entrada[cont] = entrada[i];
			entrada[i] = aux;
			cont++;
		}
		return entrada;
	}
}
