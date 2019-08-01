import java.util.Scanner;

public class Valores
{

	public static void main(String[] arguments)
	{
		Scanner ler = new Scanner(System.in);
		
		int quantidade = ler.nextInt();
		int[] numeros = new int[quantidade];
		
		int soma = 0;
		int soma_Pares = 0;
		int maior = Integer.MIN_VALUE;
		double media;
		String media_Formatada;
		int acima_Media = 0;

		for(int i = 0; i < quantidade; i++)
		{
			numeros[i] = ler.nextInt();
			soma += numeros[i];

			if(numeros[i] % 2 == 0)
			{
				soma_Pares += numeros[i];
			}

			if(numeros[i] > maior)
			{
				maior = numeros[i]; 
			}
		}	
		
		media = Double.valueOf(soma)/quantidade;
		
		for(int i = 0; i < quantidade; i++)
		{
			if(numeros[i] < media)
			{
				acima_Media++;
			}
		}
		
		media_Formatada = Double.toString(media);
		media_Formatada = media_Formatada.replace(".", ",");

		System.out.printf("%d\n%d\n%s\n%d", soma_Pares, maior, media_Formatada, acima_Media);
	}
}