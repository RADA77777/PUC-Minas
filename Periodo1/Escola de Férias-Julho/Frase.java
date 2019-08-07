import java.util.Scanner;

public class Frase
{
    public static void main(String[] arguments)
    {
        Scanner in = new Scanner(System.in);
        int quantFrases = in.nextInt(), letrasDiferentes = 0;
        char[] frase;
        in.nextLine(); // Aqui limpa o buffer do console, pq ele tava pegando o "\n" como caractere

        for(int i = 0; i < quantFrases; i++)
        {  
            frase = in.nextLine().toCharArray();
            // A ideia eh pegar o valor numerico de cada caractere ascII minusculo (97 eh o 'a' e 122 eh o 'z')
            // e comparar na string inteira, pra ver quantas vezes o caractere aparece
            for(int j = 97; j <= 122; j++)
            {
                for(int k = 0; k < frase.length; k++)
                {
                    if(frase[k] == (char) j)
                    {
                        letrasDiferentes++;
                        break;
                    }
                }
            }
            if(letrasDiferentes == 25)
            {
                System.out.println("frase completa");
            }
            else if(letrasDiferentes > 13)
            {
                System.out.println("frase quase completa");
            }
            else
            {
                System.out.println("frase mal elaborada");
            }
            letrasDiferentes = 0;
        }
        in.close();
    }
}