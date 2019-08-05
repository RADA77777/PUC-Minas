class Aquecimento
{
	public static void main(String[] args)
	{
		int quantMaiusculas = 0;
		boolean notFim;
		String entrada = new String();
		do
		{
			entrada = MyIO.readLine();
			notFim = notFim(entrada); // Se string for diferente de FIM, a execucao continua
			if(notFim)
			{	
				// Percorre toda string e conta a quantidade de maiusculas
				for(int i = 0; i < entrada.length(); i++)
				{
					if(ehMaiuscula(entrada.charAt(i)))
					{
						quantMaiusculas += 1;
					}
				}
		
				MyIO.println(quantMaiusculas);
				quantMaiusculas = 0;
			}
		} while(notFim);
	}
	
	
	/* 
	 * Pega o valor decimal de cada caractere e avalia se eh maiusculo. Se for, retorna True
	 */
  	public static boolean ehMaiuscula(char letra)
	{
		boolean ehMaiuscula = false;
		if( (int)letra >= 65 && (int)letra <= 90)
		{
			ehMaiuscula = true;
		}
		return ehMaiuscula;	
	}
	
	/*
	 * Verifica se a palavra inserida pelo usuario eh igual a FIM. Se for diferente, retorna True
	 */
	public static boolean notFim(String string)
	{
		boolean notFim = false;

		if(string.charAt(0) != 'F' || string.charAt(1) != 'I' || string.charAt(2) != 'M')
		{
			notFim = true;
		}

		return notFim;
	}
}
