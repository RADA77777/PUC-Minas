import java.io.*;

class Filme
{
	String name, director;
	float box_office;
	short release_year;

	
	Filme(String name, String director, float box_office, short release_year)
	{
		this.name          =  name;
		this.director      =  director;
		this.box_office    =  box_office;
		this.release_year  =  release_year;
	}


	Filme()
	{
		this.name          =  "";
        this.director      =  "";
        this.box_office    =  0;
        this.release_year  =  0;

	}


	String info_pretty()
	{
		String str = ("Name..........: " + this.name         + "\n" +
					  "Director......: " + this.director     + "\n" +
					  "Box office....: " + this.box_office   + "\n" +
					  "Release year..: " + this.release_year + "\n" 
				     );

		return str;
	}

	
	void write_object(String filename);
	{
		try
		{
			RandomAccessFile file = new RandomAccessFile(filename, "a");
			
			String movie_info = this.info_pretty();
			file.writeUTF(movie_info);
		}
		catch(IOException error)
		{
			System.out.println(error);
		}
	}

}


public class aed3_projeto
{
	public static void main(String[] args)
	{
		Filme inception = new Filme("Interestelar", "Nolan", 99999, (short)2014);
		inception.write_object("./meu_arq.dat");
	}
}
