import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class Convite implements Entidade{
    private int id, id_grupo;
    private String email, emissor;
    private long momento_envio;
    private byte estado; // 0 = Pendente || 1 = Aceito || 2 = Recusado || 3 = Cancelado

    public int get_id()
    {
        return this.id_grupo;
    }

    public int get_id_convite()
    {
        return this.id;
    }

    public String get_emissor()
    {
        return this.emissor;
    }

    public String get_data_formatada()
    {   
        Date d = new Date(this.momento_envio);
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        String momento_envio = sdf.format(d);
        
        return momento_envio;
    }

    public void set_id(int id)
    {
        this.id = id;
    }

    public String get_chave_secundaria()
    {
        return this.id_grupo + "|" + this.email; 
    }


	public byte[] to_byte_array() throws IOException
	{
		ByteArrayOutputStream dados = new ByteArrayOutputStream();
		DataOutputStream saida = new DataOutputStream(dados);
		
		saida.writeInt(this.id);
        saida.writeInt(this.id_grupo);
        saida.writeUTF(this.email);
        saida.writeUTF(this.emissor);
        saida.writeLong(this.momento_envio);
        saida.writeByte(estado);

		return dados.toByteArray();
	}

	public void from_byte_array(byte[] bytes) throws IOException
	{
		ByteArrayInputStream dados = new ByteArrayInputStream(bytes);
		DataInputStream entrada = new DataInputStream(dados);
		
        this.id                =  entrada.readInt();
        this.id_grupo          =  entrada.readInt();
        this.email             =  entrada.readUTF();
        this.emissor           =  entrada.readUTF();
        this.momento_envio     =  entrada.readLong();
        this.estado            =  entrada.readByte();
	}

    public void print_entity()
    {
        Date d = new Date(this.momento_envio);
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy hh:mm");
        String momento_convite = sdf.format(d);

        String estado = " ";
        switch(this.estado)
        {
            case 0:
                estado = "Pendente";
                break;

            case 1:
                estado = "Aceito";
                break;
            
            case 2:
                estado = "Recusado";
                break;
            
            case 3:
                estado = "Cancelado";
                break;
        }

        System.out.printf("Enviado para: %s no dia %s // Status - %s)\n", this.email, momento_convite, estado);
    }
    
    public void set_email(String email)
    {
        this.email = email;
    }

	public int set_info(int id_grupo, Scanner in)
	{
        this.id_grupo = id_grupo;
        
        Date now = new Date();
        this.momento_envio = now.getTime();

		this.estado = 0;

        return 0;
    }

    public void set_estado(byte estado)
    {
        this.estado = estado;
    }

    public void set_emissor(String emissor)
    {
        this.emissor = emissor;
    }

    public boolean is_pendente()
    {
        boolean return_value = false;

        if(this.estado == 0)
            return_value = true;
        
        return return_value;
    }
}