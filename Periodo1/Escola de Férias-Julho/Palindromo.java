import java.util.Scanner;
import java.io.EOFException;
import java.lang.StringBuilder;
import java.util.ArrayList;

public class Palindromo
{
    public static void main(String[] arguments)
    {
        Scanner in = new Scanner(System.in);
        // Checando por EOF
        while(in.hasNextLine())
        {
            int quantPalavras = in.nextInt(), maiorPalindromo = 0;
            in.nextLine();
            ArrayList<String> palindromos = new ArrayList<String>();
            ArrayList<String> listaTodasPalavras = new ArrayList<String>();

            // Recebe uma palavra do console, adiciona ela à ArrayList listaTodasPalavras
            // e a separa em varias substrings. Depois disso, verifica quais delas sao 
            // palindromos. As substrings que forem palindromos sao adicionadas à ArrayList palindromos
            for(int i = 0; i < quantPalavras; i++)
            {
                String palavra = in.nextLine();
                listaTodasPalavras.add(palavra);
                for(int j = 0; j < palavra.length(); j++)
                {
                    for(int k = j; k < palavra.length(); k++)
                    {
                        if(ehPalindromo(palavra.substring(j, k + 1)))
                        {
                            palindromos.add(palavra.substring(j, k + 1));
                        }
                    }
                }
            }

            // Aqui todos palindromos que foram adicionados à ArrayList palindromos sao testados
            // para ver quantas ocorrencias deles existem em cada string de listaTodasPalavras.
            // No final, eh printado o maior palindromo comum encontrado
            for(String palindromo : palindromos)
            {
                int estaContidoEm = estaContidoEm(listaTodasPalavras, palindromo);
                if(estaContidoEm == quantPalavras && estaContidoEm > maiorPalindromo)
                {
                    maiorPalindromo = palindromo.length();
                }
            }
            System.out.println(maiorPalindromo);
        }
        in.close();
    }

    // Essa funcao checa se uma string é palindromo ao remover os espacos, reverte-la e comparar com a original
    public static boolean ehPalindromo(String palavra)
    {
        palavra = palavra.replace(" ", "");
        String palavraInvertida = new StringBuilder(palavra).reverse().toString();

        boolean ehPalindromo = palavra.equals(palavraInvertida);
        
        return ehPalindromo;
    }

    // Checa quantas vezes palindromo aparece como substring em cada uma das strings na 
    // ArrayList listaTodasPalavras 
    public static int estaContidoEm(ArrayList<String> listaTodasPalavras, String palindromo)
    {
        int contidoEm = 0;
        for(String palavra : listaTodasPalavras)
        {
            if(palavra.contains(palindromo))
            {
                contidoEm++;
            }
        }
        return contidoEm;
    }
}