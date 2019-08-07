public class Palindromo
{
	public static void main(String[] args)
	{
		char[] entrada = new char[100];
		String str = MyIO.readLine();
		int tam = str.length();
        
        entrada = str2char(str);
        int quantEspacos = contaEspacos(entrada, tam);
        entrada = removeEspaco(entrada, tam);
        tam -= quantEspacos;
       	
		
        if(isPalindromo(entrada, tam))
        {
            MyIO.println("SIM");
        }
        else
        {
            MyIO.println("NAO");
        }
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
	public static char[] removeEspaco(char[] entrada, int tam)
	{
		for(int i = 0; i < tam; i++)
		{
			if(entrada[i] == ' ')
			{
				for(int j = i; j < (tam - 1); j++)
				{
					entrada[j] = entrada[j+1];
               			}
				entrada[tam-1] = '\0';
				entrada = removeEspaco(entrada, tam - 1);
			}
		}
		return entrada;
	}


    /*
    * Checa se uma palavra eh palindromo
    */
	public static boolean isPalindromo(char[] entrada, int tam)
	{
        boolean isPalindromo = true;
		int cont = 0;
		for(int i = tam; i > (tam/2); i--)
		{
            if(entrada[i - 1] != entrada[cont])
            {
                isPalindromo = false;
                break;
            }
			cont++;
        }
        
        return isPalindromo;
    }
    
    public static int contaEspacos(char[] entrada, int tam)
    {
        int quantEspacos = 0;
        for(int i = 0; i < tam; i++)
        {
            if(entrada[i] == ' ')
            {
                quantEspacos++;
            }
        }

        return quantEspacos;
    }
}
