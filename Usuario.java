import java.io.*;
import java.util.Scanner;
 
public class Usuario
{
	private int id;
	private String nome, email, senha;
	Scanner in =  new Scanner(System.in);

	Usuario(int new_id, String new_nome, String new_email, String new_senha)
	{
		set_id(new_id);
		set_nome(new_nome);
		set_email(new_email);
		set_senha(new_senha);
	}

	Usuario(int new_id)
	{
		set_id(new_id);
		
		System.out.println("\nNome: ");
		set_nome(in.nextLine());
		
		System.out.println("\nEmail: ");
		set_email(in.nextLine());

		System.out.println("\nSenha: ");
		set_senha(in.nextLine());
	}

	Usuario()
	{
		set_id(-1);
		set_nome("-1");
		set_email("-1");
		set_senha("-1");
	}	

	public int get_id()
	{
		return this.id;
	}

	public void set_id(int new_id)
	{
		this.id = new_id;
	}

	public String get_nome()
	{
		return this.nome;
	}

	public void set_nome(String new_nome)
	{
		this.nome = new_nome;
	}

	public String get_email()
	{
		return this.email;
	}

	public void set_email(String new_email)
	{
		this.email = new_email;
	}

	public String get_senha()
	{
		return this.senha;
	}

	public void set_senha(String new_senha)
	{
		this.senha = new_senha;
	}

	public String chave_secundaria()
	{
		return this.email;
	}

	public byte[] to_byte_array() throws IOException
	{
		ByteArrayOutputStream dados = new ByteArrayOutputStream();
		DataOutputStream saida = new DataOutputStream(dados);
		
		saida.writeInt(this.id);
		saida.writeUTF(this.nome);
		saida.writeUTF(this.email);
		saida.writeUTF(this.senha);

		return dados.toByteArray();
	}

	public void from_byte_array(byte[] bytes) throws IOException
	{
		ByteArrayInputStream dados = new ByteArrayInputStream(bytes);
		DataInputStream entrada = new DataInputStream(dados);
		
		set_id(entrada.readInt());
		set_nome(entrada.readUTF());
		set_email(entrada.readUTF());
		set_senha(entrada.readUTF());
	}

	public void print_user()
	{
		if(this.get_id() == -1)
			System.out.println("Esse usuario nao foi iniciado corretamente! Confira os dados da busca!\n");

		System.out.println( "ID... " + this.get_id() + 
							"\nNome... " + this.get_nome() + 
							"\nEmail... " + this.get_email() + 
							"\nSenha... " + this.get_senha()
							);
	}
}