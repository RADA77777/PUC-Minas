import java.io.RandomAccessFile; 

public class Arquivo
{
	public static void main(String[] args)
	{
		try
		{
			int quantNumeros = MyIO.readInt();
			RandomAccessFile arq = new RandomAccessFile("resposta.txt", "rw");
			
			
			
			for(int i = 0; i < quantNumeros*4; i+=4)
			{
				arq.seek(i);	
				arq.writeFloat(MyIO.readFloat());
			}
			arq.close();
			
			arq = new RandomAccessFile("resposta.txt", "r");

			for(int i = (quantNumeros-1)*4; i >= 0; i-=4)
			{
				arq.seek(i);
				MyIO.println(arq.readFloat());
			}
			
			arq.close();
		} 
      		catch (Exception ex)
		{
        		ex.printStackTrace();
      		}
	}
}
