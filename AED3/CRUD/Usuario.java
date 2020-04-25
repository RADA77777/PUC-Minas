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

	public void set_id(int id)
	{
		this.id = id;
	} 

	public String get_chave_secundaria()
	{
		return this.email;
	}

	public String get_senha()
	{
		return this.senha;
	}

	public int set_info(int id, Scanner in)
	{
		set_id(id);

		System.out.println("Seu nome: ");
		String nome  = in.nextLine();
		if(nome.equals(""))
			return -1;
		this.nome    = nome;

		System.out.println("Seu email: ");
		String email = in.nextLine();
		if(email.equals(""))
			return -1;
		this.email   = email;

		System.out.println("Senha: ");
		String senha = in.nextLine();
		if(senha.equals(""))
			return -1;
		this.senha   = senha;

		return 0;
	}

	public int set_info(String email, Scanner in)
	{
		set_id(-1);

		System.out.println("Nome: ");
		String nome  = in.nextLine();
		if(nome.equals(""))
			return -1;	
		this.nome    = nome;

		this.email   = email;

		System.out.println("Senha: ");
		String senha = in.nextLine();
		if(senha.equals(""))
			return -1;
		this.senha   = senha;

		return 0;
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