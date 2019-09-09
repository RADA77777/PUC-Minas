import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.File;
import java.io.InputStreamReader;
import java.util.Scanner;

class Time
{
	private String nome, apelidos, tecnico, estadio;
	private String liga, nomeArquivo;
	private int dia, mes, ano, capacidade;
	private long tamPag;
	
	public Time()
	{
		return ;
	}

	public Time(String nome, String apelidos, String tecnico, String estadio, String liga, String nomeArquivo, int dia, int mes, int ano, int capacidade, long tamPag)
	{
		this.setNome         (nome);
		this.setApelido      (apelidos);
		this.setTecnico      (tecnico);
		this.setEstadio      (estadio);
		this.setLiga         (liga);
		this.setNomeArquivo  (nomeArquivo);
		this.setDia          (dia);
		this.setMes          (mes);
		this.setAno          (ano);
		this.setCapacidade   (capacidade);
		this.setTamPag       (tamPag);
	}

	public void setNome(String nome){
		this.nome = nome;
	}
	public String getNome(){
		return this.nome;
	}
	
	public void setApelido(String apelidos){
		this.apelidos = apelidos;
	}
	public String getApelidos(){
		return this.apelidos;
	}

	public void setTecnico(String tecnico){
		this.tecnico = tecnico;
	}
	public String getTecnico(){
		return this.tecnico;
	}

	public void setEstadio(String estadio){
		this.estadio = estadio;
	}
	public String getEstadio(){
		return this.estadio;
	}

	public void setLiga(String liga){
		this.liga = liga;
	}
	public String getLiga(){
		return this.liga;
	}

	public void setNomeArquivo(String nomeArquivo){
		this.nomeArquivo = nomeArquivo;
	}
	public String getNomeArquivo(){
		return this.nomeArquivo;
	}

	public void setDia(int dia){
		this.dia = dia;
	}
	public int getDia(){
		return this.dia;
	}

	public void setMes(int mes){
		this.mes = mes;
	}
	public int getMes(){
		return this.mes;
	}

	public void setAno(int ano){
		this.ano = ano;
	}
	public int getAno(){
		return this.mes;
	}

	public void setCapacidade(int capacidade){
		this.capacidade = capacidade;
	}
	public int getCapacidade(){
		return this.capacidade;
	}

	public void setTamPag(long tamPag){
		this.tamPag = tamPag;
	}
	public long getTamPag(){
		return this.tamPag;
	}

	public void imprimir(){
		System.out.printf("%s ## %s ## %02d/%02d/%02d ## %s ## %d ## %s ## %s ## %s ## %d ## \n", this.getNome(), this.getApelidos(), this.getDia(), this.getMes(), this.getAno(), this.getEstadio(), this.getCapacidade(), this.getTecnico(), this.getLiga(), this.getNomeArquivo(), this.getTamPag());
	}
}

public class javatimes
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		String linha, nome, apelidos, tecnico, estadio;
		String capacidadeString, data, liga, nomeArquivo;
		boolean notFim;
		int dia, mes, ano, capacidade;
		long tamPag;

		do{
			nomeArquivo = in.nextLine();
			notFim = notFim(nomeArquivo); // Se nome do time for diferente de FIM, a execucao continua
			
			if(notFim)
			{
				try
				{
					BufferedReader reader = new BufferedReader(new FileReader(nomeArquivo));
					File arquivo = new File(nomeArquivo);
					tamPag = arquivo.length();

					while ((linha = reader.readLine()) != null)
					{
						if(linha.contains("infobox vcard"))
						{
						linha = removerTags(linha, "<", ">");

						nome = retornarEntreTags(linha, "Full name", "</td>");
						nome = removerTags( nome, " &", ";");
						nome = removerTags( nome, "&", ";");
					
						apelidos = retornarEntreTags(linha, "Nickname(s)", "</td>");
						apelidos = removerTags(apelidos, "&", ";");
						
						estadio =  retornarEntreTags(linha, "Ground", "</td>");
						estadio = removerTags(estadio, "&", ";");
						
						capacidadeString = retornarEntreTags(linha, "Capacity", "</td>"); 
						
						capacidadeString = removerTags(capacidadeString, "&", ";");
						capacidadeString = removerCaracteres(capacidadeString, " ");
						capacidadeString = removerCaracteres(capacidadeString, ".");
						capacidadeString = removerCaracteres(capacidadeString, ",");
						capacidadeString = removerTags(capacidadeString, "(", ")");
						capacidadeString = removerCaracteres(capacidadeString, "/");
						capacidade = Integer.parseInt(capacidadeString);
					
						if(linha.contains("Coach"))
						{
							tecnico = retornarEntreTags(linha, "Coach", "</td>");
						}
						else if(linha.contains("General manager"))
						{
							tecnico = retornarEntreTags(linha, "General manager", "</td>");
						}
						else if(linha.contains("Head coach"))
						{
							tecnico = retornarEntreTags(linha, "Head coach", "</td>");
						}
						else
						{
							tecnico = retornarEntreTags(linha, "Manager", "</td>");
						}

						tecnico = removerTags(tecnico, "&", ";");

						liga = retornarEntreTags(linha, ">League", "</td>");
						liga = removerTags(liga, "&", ";");


						data = retornarEntreTags(linha, "Founde", "</td>");

						int[] dias = filtrarData(data);
						
						dia = dias[0];
						mes = dias[1];
						ano = dias[2];
						
						Time time = new Time(nome, apelidos, tecnico, estadio, liga, nomeArquivo, dia, mes, ano, capacidade, tamPag);
						time.imprimir();
						break;
						}
					}
				}
			
				catch(FileNotFoundException erro) 
				{
					System.out.println(erro);
				}
				catch(IOException erro)
				{
					System.out.println(erro);
				}
			}
		}while(notFim);
	}

	//Usada para achar as datas de fundacao dos times
	public static int[] filtrarData(String dataString)
	{
	
		/*
		* data[0] eh o dia
		* data[1] eh o mes
		* data[2] eh o ano
		*/
        int[] data = new int[3]; 
        char[] dataChar = dataString.toCharArray();
		String numeroChar;


		if(dataString.contains("&#59"))
		{
			dataString = retornarEntreTags(dataString, "d", "#59");
			dataString = removerTags(dataString, "#", ";");
	        dataString = removerCaracteres(dataString, ",");
            dataChar = dataString.toCharArray();
            
            for(int i = 0; i < dataChar.length; i++)
            {
                if(dataChar[i] == '&')
                {
					dataChar[i] = ' ';
                }
            }
            dataString = new String(dataChar).substring(0, dataChar.length-1);
            dataChar = dataString.toCharArray();
		}
		
		
		dataString = removerCaracteres(dataString, ",");
		dataString = removerCaracteres(dataString, "d");
		
		if(dataString.length() == 4)
		{
			data[0] = 0;
            data[1] = 0;
            data[2] = Integer.parseInt(dataString);
            
			return data;
		}
		
		dataChar = dataString.toCharArray();
		
		int index1 = 0, index2 = 0;
		for(int i = 0; i < dataString.length(); i++)	
			if(dataChar[i] == '-' || dataChar[i] == '/' || dataChar[i] == ' ')
			{
				index1 = i;
                for(int j = i+1; j < dataString.length(); j++)
                {
					if(dataChar[j] == '-' || dataChar[j] == '/' || dataChar[j] == ' ')
					{
						index2 = j;
						j = dataString.length();
						i = dataString.length();
                    }	
                }	
			}	

			// String antes do primeiro -

			numeroChar = dataString.substring(0, index1+1);
			numeroChar = removerCaracteres(numeroChar, " ");
			try
			{  
			data[0] = Integer.parseInt(numeroChar);
			}
			catch(NumberFormatException erro)
			{
				data[0] = 0;
			}
			// String entre as duas tags -
			numeroChar = dataString.substring(index1+1, index2+1);
			numeroChar = removerCaracteres(numeroChar, " ");
			try
			{
			data[1] = Integer.parseInt(numeroChar);
			}
			catch(NumberFormatException erro)
			{
				data[1] = 0;
			}

            // String depois do segundo -
			numeroChar = dataString.substring(index2+1, dataString.length());
			numeroChar = removerCaracteres(numeroChar, " ");
			try
			{
			data[2] = Integer.parseInt(numeroChar);
			}
			catch(NumberFormatException erro)
			{
				data[2] = 0;
			}
			


		/* Aqui confirmaremos que a data esta no formato dia/mes/ano.
		* A variavel <dataString> vai conter todo o conteudo que que esta entre "Founded" e "</td"
		* A logica eh ver se nomes de meses sao substrings de <numeroChar>
		* Se for, eh pq o mes que eh substring deve ser o valor numerico da variavel <data[1]>.
		* Caso o valor numerico de <mes> seja diferente do valor do mes no mundo real, ele
		* eh trocado com a variavel dia (Ex: <data[1]> = 3 e  subString(linha, "September") retorna True. Isso
		* nao pode acontecer, pois setembro eh o mes 9. Entao, concluimos que 3 so pode ser o dia! <data[0]> assume o valor
		* de <data[1]>, e <data[1]> vira 9)
		*/




		// Matriz com meses
		String[][] meses = {
					{"January"}, {"February"}, {"March"}, {"April"}, {"May"}, {"June"},
					{"July"}, {"August"}, {"September"}, {"October"}, {"November"}, {"December"}
					};


		for(int i = 0; i < 12; i++)
        {
			if(dataString.contains(meses[i][0]) && data[1] != i+1)
			{
				if(data[0] == i+1 && data[1] != 0)
				{	
					data[0] = data[1];
					data[1] = i+1;
				}
				else if(data[0] == 0 && data[1] != i+1)
				{
					data[0] = data[1];
					data[1] = i+1;
				}
				else
				{
					data[1] = i+1;
				}
			}
        }

		return data;
	}

	// Retorna todos as palavras da string que estao entre as strings st1 e str2
	public static String retornarEntreTags(String string, String str1, String str2)
	{

			boolean isStr1 = false, isStr2 = false;
			String stringEntreTags = new String();
        
            // Percorrer <string> inteira ate achar
            // o primeiro caractere de <str1>
			for(int i = 0; i < string.length(); i++)
			{ 
                if(string.charAt(i) == str1.charAt(0))
                {
                    isStr1 = true;
                    // Verificar se a primeira letra achada realmente corresponde a
                    // <str1>. Se nao corresponder, <isStr1> vira false, e voltamos para o for externo
                    for(int j = 0; j < str1.length(); j++)
                    {
                        if(string.charAt(i+j) != str1.charAt(j))
                        {
                            isStr1 = false;
                        }
                    }
                }	

                if(isStr1)
                {
                    // Caso aquela primeira letra achada seja de <str1>, 
                    // iniciamos outro for para achar a string <str2>. A mesma logica
                    // de procura será usada.
                    for(int j = i; j < string.length(); j++)
                    {
                        if(string.charAt(j) == str2.charAt(0))
                        {
                            isStr2 = true;
                            for(int k = 0; k < str2.length(); k++)
                            {
                                if(string.charAt(j+k) != str2.charAt(k))
                                {			
                                    isStr2 = false;			
                                }
                            }
                            
                            if(isStr1 && isStr2)
                            {
                                // Caso tenhamos achado <str1> e <str2>, vamos definir <stringEntreTags>
                                // como o que esta entre <i + str1.length()> 
                                // (primeira letra de <str1> + tamanho de <str1> = final de <str1>)
                                //  e o que esta em <j> (primeira letra de <str2>)
                                stringEntreTags = string.substring(
                                    i + str1.length(),
                                    j);
                                

                                // Deletando as aspas por causa de um problema com um time que tinha
                                // uma " fora de tags html                               
                                stringEntreTags = removerCaracteres(stringEntreTags, "\"");
                                
                                // Muitos times tem &#91 neles, inclusive entre varios atributos.
                                // Eu notei que sempre o que me interessa sempre está antes do &#91, entao
                                // passei a verificar se &#91 existe. Caso exista, <stringEntreTags>
                                // se torna o que esta entre <str> e &#91, ao inves de <str1> e <str2>
                                if(stringEntreTags.contains("&#91"))
                                {
                                    stringEntreTags = removerTags(stringEntreTags, "&#91;", "&#93;");
                                }
                                return stringEntreTags;
                            }
                        }
                    }
                }
            }
        // Caso nao exista <str1> e <str2>, será retornarnada a string recebida
		if(!isStr1 && !isStr2)
		{
			return string;
		}
		return stringEntreTags;
	}


	/*
	* Recebe duas strings. Remove todas ocorrencias da segunda 
	* string na primeira e retorna a primeira
	*/
	public static String removerCaracteres(String string, String parteRemovida)
	{
		boolean isParteRemovida;


        char[] stringChar = string.toCharArray(); 
        int tamanho = stringChar.length;

		for(int i = 0; i < string.length(); i++)
		{

			// Caso ache a primeira letra de parteRemovida, sera ativado um 
			// loop <for> para ver se aquela letra corresponde à parte a ser removida
			// ou se for apenas uma letra de outra palavra
			
			if(string.charAt(i) == parteRemovida.charAt(0))
			{
				isParteRemovida = true;
				for(int j = 0; j < parteRemovida.length(); j++)	
				{

					// Comparando com o resto da string. Se for diferente, a <isParteRemovida>
					// vira <false>, falhando no if que vem em seguida e voltando para o loop
					
					if(string.charAt(i+j) != parteRemovida.charAt(j))
					{
						isParteRemovida = false;
                    }
                }
				if(isParteRemovida)
				{	
                    // Como precisamos tirar <parteRemovida> por inteiro, temos
                    // um loop que roda uma vez pra cada caractere presente em
                    // <parteRemovida>
                    for(int x = 0; x < parteRemovida.length(); x++)
                    {
                        for(int j = i; j < string.length()-1; j++)
                        {	
                            stringChar[j] = stringChar[j+1];
                        }
                        string = new String(stringChar).substring(0, tamanho-1);
                        stringChar = string.toCharArray();
                        tamanho--;
                    }
                    
                    i--;
				}	
            }
        }

		return string;
	}

	/*
	* Recebe tres strings. Remove tudo que 
	* estiver entre str1 e str2 e retorna a string tratada
	*/
	public static String removerTags(String string, String tag1, String tag2)
	{

        char[] stringChar = string.toCharArray(); 
        int tamanho = stringChar.length;
        boolean isTag1 = false, isTag2 = false;
        
		for(int i = 0; i < string.length(); i++)
		{	 
			if( stringChar[i] == '<' &&
			    stringChar[i+1] == '/' &&
				stringChar[i+2] == 't' &&
				stringChar[i+3] == 'd' &&
				stringChar[i+4] == '>')
			{
				continue;
            }
            
			if(stringChar[i] == tag1.charAt(0))
			{
                isTag1 = true;
                for(int j = 0; j < tag1.length(); j++)
                {
                    if(tag1.charAt(j) != stringChar[i + j])
                    {
                        isTag1 = false;
                    }
                }
                if(isTag1)
                {
                    for(int j = i; j < stringChar.length; j++)
                    {
                        if(stringChar[j] == tag2.charAt(0))
                        {
                            isTag2 = true;
                            for(int k = 0; k < tag2.length(); k++)
                            {
                                if(tag2.charAt(k) != stringChar[j + k])
                                {
                                    isTag2 = false;
                                    k = tag2.length();
                                }
                            }
                            if(isTag2)
                            {
                                for(int k = 0; k < j-i +tag2.length(); k++)
                                {
                                    for(int x = i; x < string.length()-1; x++)
                                    {
                                        stringChar[x] = stringChar[x+1];
                                    }

                                    string = new String(stringChar).substring(0, tamanho-1);
                                    stringChar = string.toCharArray();
                                    tamanho--;
                                }
                                
                                i--;
                                j = string.length();
                            }	
                        }
                    }
                }
			}
		}

		return string;
	}

	// Verifica se a string recebida é igual a "FIM"
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
