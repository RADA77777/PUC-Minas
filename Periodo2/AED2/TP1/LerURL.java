import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;
 
public class LerURL {
    public static void main(String[] args) throws Exception {
	String nome;
        String endereco;
	String pagina = "", linha;
	boolean notFim;

        do
	{
		nome = MyIO.readLine();
		notFim = notFim(nome); // Se string for diferente de FIM, a execucao continua
		if(notFim)
		{
			endereco = MyIO.readString();
			URL url = new URL(endereco);
			BufferedReader br = new BufferedReader(new InputStreamReader(url.openStream()));
			do
			{
			line = br.readLine();
			pagina += line;
			} while(line != null);
		}
		String formatada = new String(pagina.getBytes("UTF-8"), "ISO-8859-1");
		contarValores(formatada, nome);
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
	contarValores(String pagina, String nomePagina)
	{
		int quantA, quantE, quantI, quantO, quantU, quantÁ, quantÉ, quantÍ, quantÓ, quantÚ, quantÀ, quantÈ, quantÌ, quantÒ, quantÙ, quantÃ, quantÕ;
		int quantÂ, quantÊ, quantÎ, quantÔ, quantÛ, quantConso, quantBR, quantTable;

	}

}
