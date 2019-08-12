import java.util.Random;
public class Alteracao
{
	public static void main(String[] args)
	{	
		char[] entradaChar = new char[1000];
		boolean notFim;
		String entradaString = new String();
		Random gerador = new Random(); // Gerador
                gerador.setSeed(4);

		do{
			entradaString = MyIO.readLine();
			int tam = entradaString.length();
			notFim = notFim(entradaString);
			if(notFim)
			{
				str2char(entradaString, entradaChar);
        			tam = entradaString.length();	
				alterar(entradaChar, tam, gerador);
			}	
		} while(notFim);
	}


	/*
	 * Converte de String para array de caracteres para que eu possa editar os chars
	 */
	public static void str2char(String entradaString, char[] entradaChar)
	{
		for(int i = 0; i < entradaString.length(); i++)
		{
			entradaChar[i] = entradaString.charAt(i);
		}
	}
	


    	/*
    	*	gera um numero com a seed e troca um pelo outro
    	*/
	public static void alterar(char[] entradaChar, int tam, Random gerador)
	{
		char char1 = (char)('a' + (Math.abs(gerador.nextInt()) % 26));
		char char2 = (char)('a' + (Math.abs(gerador.nextInt()) % 26));	
		for(int i = 0; i < tam; i++)
		{
			if(entradaChar[i] == char1)
			{
				entradaChar[i] = char2;
			}
			else if(entradaChar[i] == char2)
			{
				entradaChar[i] = char1;
			}
		MyIO.print(entradaChar[i]);
		}
		MyIO.println("");	
		return;
    	}
        
    	/*
         * Verifica se a palavra inserida pelo usuario eh igual a FIM. Se for diferente, retorna True
         */
	public static boolean notFim(String entradaString)
	{
		boolean notFim = false;
		if(entradaString.length() >= 3)
		{
                	if(entradaString.charAt(0) != 'F' || entradaString.charAt(1) != 'I' || entradaString.charAt(2) != 'M')
                	{
                	        notFim = true;
                	}
		}
		else
		{
			notFim = true;
		}
                return notFim;
        }
}
