import java.io.*;
import java.util.Scanner;
 
public class Usuario implements Entidade
{
	private int id;
	private String nome, email, senha;


	public int get_id()
	{
		return this.id;
	}

	public String get_chave_secundaria()
	{
		return this.email;
	}

	public String get_senha()
	{
		return this.senha;
	}

	public void set_info(int id)
	{
		Scanner in =  new Scanner(System.in);
		this.id = id;

		System.out.println("Digite seu nome: ");
		String nome  = in.nextLine();
		this.nome    = nome;

		System.out.println("Digite seu email: ");
		String email = in.nextLine();
		this.email   = email;

		System.out.println("Digite sua senha: ");
		String senha = in.nextLine();
		this.senha   = senha;
		
		in.close();
	}

	public void set_info(String email)
	{
		Scanner in = new Scanner(System.in);
		this.email = email;
		
		System.out.println("Digite seu nome: ");
		String nome  = in.nextLine();
		this.nome    = nome;

		System.out.println("Digite sua senha: ");
		String senha = in.nextLine();
		this.senha   = senha;

		in.close();
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
		
		this.id     = (entrada.readInt());
		this.nome   = (entrada.readUTF());
		this.email  = (entrada.readUTF());
		this.senha  = (entrada.readUTF());
	}

	public void print_entity()
	{
		System.out.println( "ID...... " + this.id    + 
						  "\nNome.... " + this.nome  + 
						  "\nEmail... " + this.email + 
						  "\nSenha... " + this.senha
							);
	}
}