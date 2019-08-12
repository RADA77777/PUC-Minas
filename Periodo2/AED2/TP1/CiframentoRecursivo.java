public class CiframentoRecursivo
{
	public static void main(String[] args)
	{	
		char[] entradaChar = new char[1000];
		boolean notFim;
		String entradaString = new String();

		do{
			entradaString = MyIO.readLine();
			notFim = notFim(entradaString); // Verifica se a string eh igual a "FIM"
			if(notFim)
			{
				str2char(entradaString, entradaChar);
        			encriptar(entradaChar, 0);
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
	public static void encriptar(char[] entradaChar, int index)
	{
		if(index < entradaChar.length)
		{
			MyIO.print((char)(entradaChar[index] + 3 + 0x0));
			encriptar(entradaChar, index+1);
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
