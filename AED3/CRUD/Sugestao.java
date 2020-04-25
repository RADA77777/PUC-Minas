import java.io.*;
import java.util.Scanner;

public class Sugestao implements Entidade{
    private int id, id_usuario;
    private float valor;
    private String produto, loja, observacoes;


    public int get_id()
    {
        return this.id_usuario;
    }

    public int get_id_sugestao()
    {
        return this.id;
    }

    public void set_id(int id)
    {
        this.id = id;
    }

    public String get_chave_secundaria()
    {
        return this.id_usuario + "|" + this.produto; 
    }

	public byte[] to_byte_array() throws IOException
	{
		ByteArrayOutputStream dados = new ByteArrayOutputStream();
		DataOutputStream saida = new DataOutputStream(dados);
		
		saida.writeInt(this.id);
        saida.writeInt(this.id_usuario);
        saida.writeUTF(this.produto);
        saida.writeUTF(this.loja);
        saida.writeUTF(this.observacoes);
        saida.writeFloat(this.valor);

		return dados.toByteArray();
	}

	public void from_byte_array(byte[] bytes) throws IOException
	{
		ByteArrayInputStream dados = new ByteArrayInputStream(bytes);
		DataInputStream entrada = new DataInputStream(dados);
		
        this.id           =  entrada.readInt();
        this.id_usuario   =  entrada.readInt();
        this.produto      =  entrada.readUTF();
        this.loja         =  entrada.readUTF();
        this.observacoes  =  entrada.readUTF();
        this.valor        =  entrada.readFloat();
	}

    public void print_entity()
    {
		System.out.println("Produto....... " + this.produto      + 
                           "\nLoja.......... " + this.loja         +
                           "\nObservacoes... " + this.observacoes  +
                           "\nValor......... " + this.valor
						   );
    }
    

	public int set_info(int id_usuario, Scanner in)
	{
		this.id_usuario = id_usuario;
        in.nextLine();
        
        System.out.print("Nome do produto: ");
        String produto  = in.nextLine();
        if(produto.equals(""))
            return -1;
		this.produto    = produto;

		System.out.print("Loja do produto: ");
		String loja = in.nextLine();
		this.loja   = loja;

		System.out.print("Preco do produto: ");
		float valor  = in.nextFloat();
		this.valor   = valor;
        
        in.nextLine();
        System.out.print("Observacoes: ");
        String observacoes  =  in.nextLine();
        this.observacoes    =  observacoes;

        return 0;
	}
}