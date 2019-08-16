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
			endereco = "file:///home/rafael/Downloads/a.html";
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
			if(isLineBreak(pagina, i))
			{
				arrayValores[23]++;
			}
			else if(isTable(pagina, i))
			{
				arrayValores[24]++;
			}
			else if(isConso(pagina.charAt(i)))
			{
				arrayValores[22]++;
			}
		}

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

	public static boolean isLineBreak(String entrada, int indexOpenTag)
	{
		boolean isLineBreak = false;
		if(entrada.charAt(indexOpenTag) == '<')
		{	
			isLineBreak = true;
			for(int i = indexOpenTag; i < entrada.length(); i++)
			{
				if(entrada.charAt(i) == '>')
				{
					for(int j = indexOpenTag+1; j < i; j++)
					{
						if(entrada.charAt(j) != ' ' && 
						entrada.charAt(j) != 'b' && 
						entrada.charAt(j) != 'r')
			
						{
							isLineBreak = false;
						}
			
						if(entrada.charAt(j) == 'b' && entrada.charAt(j+1) != 'r')
						{
							isLineBreak = false;
						}	
					}
				}
			}
		}
	return isLineBreak;	
	}

	public static boolean isTable(String entrada, int indexOpenTag)
	{
		return false;
	}
}
