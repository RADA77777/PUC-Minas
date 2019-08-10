import java.util.Random;
public class Alteracao
{
	public static void main(String[] args)
	{	
		char[] entradaChar = new char[1000];
		int tam;
		boolean notFim;
		int quantEspacos;
		String entradaString = new String();

		do{
			entradaString = MyIO.readLine();
			notFim = notFim(entradaString);
			if(notFim)
			{
				str2char(entradaString, entradaChar);
        			tam = entradaString.length();
		
				alterar(entradaChar, tam);
			}
		} while(notFim);
	}


	/*
	 * Converte de String para array de caracteres
	 */
	public static void str2char(String entradaString, char[] entradaChar)
	{
		for(int i = 0; i < entradaString.length(); i++)
		{
			entradaChar[i] = entradaString.charAt(i);
		}
	}
	


    /*
    * Retorna a mensagem encriptada com a cifra de césar
    * somar 0x0 a um valor inteiro pega o valor char referente a 
    * tal inteiro na tabela ASCII
    */
	public static void alterar(char[] entradaChar, int tam)
	{
		Random gerador = new Random();
		gerador.setSeed(4);
		char char1 = (char)('a' + (Math.abs(gerador.nextInt()) % 26));
		char char2 = (char)('a' + (Math.abs(gerador.nextInt()) % 26));
		MyIO.println(char1 + "  " + char2);	
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

                if(entradaString.charAt(0) != 'F' || entradaString.charAt(1) != 'I' || entradaString.charAt(2) != 'M')
                {
                        notFim = true;
                }

                return notFim;
        }

}
