import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;
 
public class LerURL {
    public static void main(String[] args) throws Exception {
	MyIO.setCharset("ISO-8859-1");
	String nome;
        String endereco;
	String pagina = "", linha = "";
	boolean notFim;
	
        do
	{
		nome = MyIO.readLine();
		notFim = notFim(nome); // Se string for diferente de FIM, a execucao continua
		if(notFim)
		{
			endereco = "file:///home/mint/Downloads/a.html";
			URL url = new URL(endereco);
			BufferedReader br = new BufferedReader(new InputStreamReader(url.openStream()));
			while(linha != null)
			{
				pagina += linha;
				linha = br.readLine();
			}
		
			contarValores(pagina, nome);
		}
	} while(notFim);
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

	/*
	 * Usar a funcao isConso da questao Is pra pegar consoantes, depois usar charAt() pra descobrir as letras. Para <br> e <table>, pensar em ideia
	 */
	public static void contarValores(String pagina, String nomePagina)
	{
		MyIO.setCharset("ISO-8859-1");
		int[] arrayValores = new int[25];
		char[] arrayLetras = { 'a','e','i','o','u','á','é','í','ó','ú','à','è','ì','ò','ù','ã','õ','â','ê','î','ô','û' };
			
		int isLineBreak, isTable;
		for(int i = 0; i < pagina.length(); i++)
		{
			for(int j = 0; j < arrayLetras.length; j++)
			{
				if(pagina.charAt(i) == arrayLetras[j])
				{
					arrayValores[j]++;
					j = arrayLetras.length;
				}
			}
			// A funcao isLineBreak retorna codigo -1 se nao for um <br>, e o numero da 
			// posicao de '>' - o numero da posicao de '<', para assim saber quantas casas pular no contador i.
			// IsTable() funciona da mesma maneira
			isLineBreak = isLineBreak(pagina, i);
			isTable = isTable(pagina, i);
			
			if(isLineBreak != -1)
			{
				arrayValores[23]++;
				i += isLineBreak;
			}
			else if(isTable != -1)
			{
				arrayValores[24]++;
			}
			else if(isConso(pagina.charAt(i)))
			{
				arrayValores[22]++;
			}
		}
		

		// MUDAR O METODO DE SAIDA PRA IMPRIMIR AS LETRAS (VER ENUNCIADO DO TP1)

		for(int i = 0; i < arrayValores.length; i++)
		{
			MyIO.print(arrayValores[i] + " ");
		}
		MyIO.println("");
	}

	public static boolean isConso(char entrada)
        {
		char[] consoantes = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
                boolean isConso = true;
                int naoConsoante = 0;
                for(int j = 0; j < consoantes.length; j++)
		{
		// Percore o entrada.charAt(i) por todo array de consoantes. A cada consoante diferente do char, a variavel
		// naoConsoante aumenta em 1. Se seu valor for igual ao do tamanho do array de consoantes, sabemos que a
		// letra nao eh consoante (pois foi diferente de todas).
                	if(entrada != consoantes[j])
			{
				naoConsoante++;
			}
		}

		if(naoConsoante == consoantes.length)
		{
			isConso = false;
		}
                return isConso;
	}

	public static int isLineBreak(String entrada, int indexOpenTag)
	{
		int isLineBreak = -1;
		if(entrada.charAt(indexOpenTag) == '<')
		{	
			for(int i = indexOpenTag; i < entrada.length(); i++)
			{
				if(entrada.charAt(i) == '>')
				{
					isLineBreak = i - indexOpenTag;	
					for(int j = indexOpenTag+1; j < i; j++)
					{
						if(
						entrada.charAt(j) != ' ' &&
						entrada.charAt(j) != 'b' && 
						entrada.charAt(j) != 'r')
			
						{
							isLineBreak = -1;
						}
			
						if(entrada.charAt(j) == 'b' && entrada.charAt(j+1) != 'r')
						{
							isLineBreak = -1;
						}	
					}
					i = entrada.length();
				}
			}
		}
	return isLineBreak;	
	}

	public static int isTable(String entrada, int indexOpenTag)
	{
		int isTable = -1;
         	if(entrada.charAt(indexOpenTag) == '<')
         	{
                        for(int i = indexOpenTag; i < entrada.length(); i++)
                        {
                                if(entrada.charAt(i) == '>')
                                {
                                        isLineBreak = i - indexOpenTag;
                                        for(int j = indexOpenTag+1; j < i; j++)
                                        {
                                                if(										// CRIAR METODO PRA CHECAR SE EH 'TABLE'
                                                entrada.charAt(j) != ' ' &&
                                                entrada.charAt(j) != 't' &&
                                                entrada.charAt(j) != 'a' &&	
                                                entrada.charAt(j) != 'b' &&
                                                entrada.charAt(j) != 'l' &&
                                                entrada.charAt(j) != 'e'
						)	
                                                {
                                                        isLineBreak = -1;
                                                }

                                                if(entrada.charAt(j) == 'b' && entrada.charAt(j+1) != 'r')
                                                {
                                                        isLineBreak = -1;
                                                }
                                        }
                                        i = entrada.length();
                                }
                        }
                }
        return isTable;
}
}

