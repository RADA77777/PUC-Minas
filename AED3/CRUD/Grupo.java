import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Calendar;
import java.util.Scanner;

public class Grupo implements Entidade{
    private int id, id_usuario;
    private String nome, local_encontro, observacoes;
    private long momento_sorteio, momento_encontro;
    private float valor_medio;
    private boolean sorteado, ativo;

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
        return this.id_usuario + "|" + this.nome; 
    }

    public void set_ativo(boolean ativo)
    {
        this.ativo = ativo;
    }

    public void set_sorteado(boolean sorteado)
    {
        this.sorteado = sorteado;
    }
    
    public boolean get_ativo()
    {
        return this.ativo;
    }


	public byte[] to_byte_array() throws IOException
	{
		ByteArrayOutputStream dados = new ByteArrayOutputStream();
		DataOutputStream saida = new DataOutputStream(dados);
		
		saida.writeInt(this.id);
        saida.writeInt(this.id_usuario);
        saida.writeUTF(this.nome);
        saida.writeUTF(this.local_encontro);
        saida.writeUTF(this.observacoes);
        saida.writeLong(this.momento_sorteio);
        saida.writeLong(this.momento_encontro);
        saida.writeFloat(this.valor_medio);
        saida.writeBoolean(this.sorteado);
        saida.writeBoolean(this.ativo);

		return dados.toByteArray();
	}

	public void from_byte_array(byte[] bytes) throws IOException
	{
		ByteArrayInputStream dados = new ByteArrayInputStream(bytes);
		DataInputStream entrada = new DataInputStream(dados);
		
        this.id                =  entrada.readInt();
        this.id_usuario        =  entrada.readInt();
        this.nome              =  entrada.readUTF();
        this.local_encontro    =  entrada.readUTF();
        this.observacoes       =  entrada.readUTF();
        this.momento_sorteio   =  entrada.readLong();
        this.momento_encontro  =  entrada.readLong();
        this.valor_medio       =  entrada.readFloat();
        this.sorteado          =  entrada.readBoolean();
        this.ativo             =  entrada.readBoolean();
	}

    public void print_entity()
    {
        Date d = new Date(this.momento_sorteio);
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        String momento_sorteio = sdf.format(d);

        d.setTime(this.momento_encontro);
        String momento_encontro = sdf.format(d);

		System.out.println("Nome do grupo......... " + this.nome            + 
                         "\nLocal de Encontro..... " + this.local_encontro  +
                         "\nObservacoes........... " + this.observacoes     +
                         "\nMomento do sorteio.... " + momento_sorteio      +
                         "\nMomento do encontro... " + momento_encontro     +
                         "\nValor medio presentes. " + this.valor_medio
				     	 );
    }
    

	public int set_info(int id_usuario, Scanner in)
	{
		this.id_usuario = id_usuario;
        in.nextLine();
        
		System.out.printf("Nome do grupo: ");
        String nome  = in.nextLine();
        if(nome.equals(""))
            return -1;
		this.nome    = nome;

        long momento_sorteio   =  set_data(in, "Sorteio");
        if(momento_sorteio == -1)
        {
            System.out.println("A data do evento nao pode ser anterior a hoje !");
            return -1;
        }
		this.momento_sorteio   =  momento_sorteio;

		System.out.printf("Valor medio dos presentes: ");
		float valor_medio  = in.nextFloat();
		this.valor_medio   = valor_medio;

        long momento_encontro = set_data(in, "Encontro");
        if(momento_encontro == -1)
        {
            System.out.println("A data do evento nao pode ser anterior a hoje !");
            return -1;
        }
        this.momento_encontro = momento_encontro;

        in.nextLine();
        System.out.printf("Local do encontro: ");
        String local = in.nextLine();
        this.local_encontro = local;

        //in.nextLine();
        System.out.printf("Observacoes: ");
        String observacoes  =  in.nextLine();
        this.observacoes    =  observacoes;

        return 0;
    }

    
    /* Mexer com datas eh uma tarefa complicada o bastante 
    *  para receber uma funcao propria
    *
    *  1 - Pegar uma data e avaliar se ela eh possivel existir
    *  2 - Pegar o tempo epoch de agora (hora de criacao do grupo)
    *  3 - Comparar o tempo epoch de agora e o inserido pelo usuario
    */
    public long set_data(Scanner in, String evento)
    {
        long epoch_time_event_date = -1;

        System.out.printf("Dia do " + evento + ": ");
        int dia = in.nextInt();

        System.out.printf("Mes do " + evento + ": ");
        int mes = in.nextInt();

        System.out.printf("Ano do " + evento + ": ");
        int ano = in.nextInt();

        String event_date_str = dia + "-" + mes + "-" + ano;
        SimpleDateFormat event_date = new SimpleDateFormat("dd-MM-yyyy");
        
        try
        {
            epoch_time_event_date = event_date.parse(event_date_str).getTime();
        }
        catch(Exception error)
        {
            error.printStackTrace();
            System.exit(0);
        }

        Date d = new Date();
        long now = d.getTime();
        if(now > epoch_time_event_date)
            epoch_time_event_date = -1;
        

        return epoch_time_event_date;
    }
}