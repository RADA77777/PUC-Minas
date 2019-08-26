import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
 
public class times {
    public static void main(String[] args) throws Exception {
	    
	    String filename = "/home/rafael/Downloads/htmltimes/1._FC_Nürnberg.html";
	    BufferedReader reader = new BufferedReader(new FileReader(filename));
	    String linha;
    	    while ((linha = reader.readLine()) != null)
    		{
			if(linha.contains("infobox vcard"))
			{
				linha = removerEntreTags(linha, '<', '>');
				System.out.println(linha);
			}
      	    
    		}
  	   reader.close();
	}

    public static String removerEntreTags(String linha, char tag1, char tag2)
    {
	   String linhaLimpa, parte1, parte2;

	   for(int i = 0; i < linha.length(); i++)
	   {
		if(linha[i] == tag2)
		{
			for(int j = i; j < linha.length(); j++)
			{
				if(linha[j] == tag1)
				{
					int i = 0;
					for(int x = j; x < i; x++)
					{
						linhaLimpa[i] = linha[x];
						i++;
					}	
					
				 		
					linhaLimpa = removerEntreTags(linha, tag1, tag2);			
				}
			}
		}
	   }
	   
	   return linhaLimpa;
    }
}
