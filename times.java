import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
 
public class times {
    public static void main(String[] args) throws Exception {
	    
	    Scanner in = new Scanner(System.in);
	    String linha;
	    boolean notFim;
	    String nomeTime = new String();
            
	    //do{
                        nomeTime = in.nextLine();
                        notFim = notFim(nomeTime); // Se nome do time for diferente de FIM, a execucao continua
                        if(notFim)
                        {
	    			BufferedReader reader = new BufferedReader(new FileReader(nomeTime));
               			
				while ((linha = reader.readLine()) != null)
                		{
                        		if(linha.contains("infobox vcard"))
					{	
                                		//linha = removerEntreTags(linha, "Full name", "Nicknames");
                                		//linha = removerEntreTags(linha, "&", ";");
                                		System.out.println(linha);
						break;
                        		}

                		}
                		reader.close();
            		}

		//}while(notFim);
    }
    public static String removerEntreTags(String linha, String tag1, String tag2)
    {
	linha = linha.matches("(?s)" + tag1 + ".*?" + tag2);
	return linha;
    }


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
