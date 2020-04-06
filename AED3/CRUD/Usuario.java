import java.io.*;
import java.util.Scanner;
 
public class Usuario implements Entidade
{
	private int id;
	private String nome, email, senha;

	public void set_info(int id)
	{
		Scanner in =  new Scanner(System.in);
		this.set_id(id);

		System.out.println("Digite seu nome: ");
		String nome  = in.nextLine();
		this.set_nome(nome);

		System.out.println("Digite seu email: ");
		String email = in.nextLine();
		this.set_email(email);

		System.out.println("Digite sua senha: ");
		String senha = in.nextLine();
		this.set_senha(senha);
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

	public void print_entity()
	{
		System.out.println( "ID........ " + this.get_id()    + 
						    "\nNome.... " + this.get_nome()  + 
							"\nEmail... " + this.get_email() + 
							"\nSenha... " + this.get_senha()
							);
	}
}