public class Palindromo
{
	public static void main(String[] arguments)
	{
		String entrada = MyIO.readLine();
		entrada = removeEspacos(entrada);
		System.out.println(entrada);
	}
	
	public static String removeEspacos(String string)
	{
		for(int i = 0; i < string.length(); i++)
		{
			if(string.charAt(i) == ' ')
			{
				string = string.toCharArray();
			       	string[i] = string.charAt(i+i);
				string = string.toString();
				string = removeEspacos(string);
			}
		}
		return string;
	}
}
