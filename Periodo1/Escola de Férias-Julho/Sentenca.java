import java.util.Scanner;

public class Sentenca
{
    public static void main(String[] arguments)
    {
        Scanner in = new Scanner(System.in);
        // Checando por EOF
        while(in.hasNextLine())
        {
            char[] sentenca = in.nextLine().toCharArray();
            
            for(int i = 0; i < sentenca.length; i+=2)
            {
                // Aqui eh avancado 1 espaco caso a casa seja um espaço
                if(sentenca[i] == ' ')
                {
                    i++;
                }
                // Os caracteres sao convertidos em maiuscula de 2 em 2
                sentenca[i] = Character.toUpperCase(sentenca[i]);
            }
            System.out.println(sentenca);
        }
        in.close();
    }
}