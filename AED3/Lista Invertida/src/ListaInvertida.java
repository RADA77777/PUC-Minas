package src;

import java.io.RandomAccessFile;
import java.text.Normalizer;
import java.util.ArrayList;


public class ListaInvertida
{
    private String save_location;           // path para o arquivo dessa lista invertida
    private RandomAccessFile reverse_list;  // ponteiro para essa lista invertida
    private ArquivoSequencial index;        // arquivo sequencial com os termos e enderecos. É um indice indireto
    private ArquivoSequencial database;     // arquivo com dados de usuarios. Armazena <ID> <Nome>
    private int last_id;                    // int representando o ultimo id que foi inserido


    public ListaInvertida(String save_file)
    {
        this.save_location  =  save_file + ".idx.direto";
        this.index          =  new ArquivoSequencial(save_file + ".idx.indireto");
        this.database       =  new ArquivoSequencial(save_file + ".db");

        try
        {
            this.open_file();

            // verifica se o arquivo esta vazio (length == 0).
            // Se estiver, escreve o ultimo ID como sendo 1. 
            if(this.reverse_list.length() == 0)
            {
                this.reverse_list.writeInt(1);
                this.last_id = 1;
            }
            // Caso contrario, le o ultimo ID inserido 
            else
                this.last_id = this.reverse_list.readInt();

            this.close_file();
        }
        catch(Exception error)
        {
            error.printStackTrace();
            System.exit(1);
        }
    }


    public void create(String name)
    {
        String cleared_name  =  this.clear_string(name); // limpando string de acentos, caracteres especiais...

        try
        {
            this.open_file();

            // para cada string <s> no array apos o split(" ")
            for(String s: cleared_name.split(" "))
            {
                long pos_insertion_reverse_list = this.index.read(s);
                int quant_ids; // armazena a quantidade de IDs ja armazenados naquela posicao da lista

                // Se retornar -1, eh pq o termo <s> **NAO** existe no indice de termos.
                // Por causa disso, vamos criar ele no indice e depois inserir na lista invertida
                if(pos_insertion_reverse_list == -1)
                {
                    // criando entrada no indice de termos
                    this.index.create(this.reverse_list.length(), s);

                    // pulando para final da lista invertida
                    this.reverse_list.seek(this.reverse_list.length());

                    this.reverse_list.writeInt(1); // so existe 1 ID inserido na lista

                    // inserindo o ID do usuario criado
                    this.reverse_list.writeInt(last_id);

                    // pulando as casas dos outros ints para inserir -1 no ponteiro para proximo
                    this.reverse_list.seek( this.reverse_list.getFilePointer() + (Integer.SIZE/8)*(9) );
                    this.reverse_list.writeLong(-1);
                }

                // se nao retornar -1, pular para a posicao retornada pelo arquivo de termos
                else
                {
                    this.reverse_list.seek(pos_insertion_reverse_list);
                    quant_ids = this.reverse_list.readInt();

                    // se for igual a 10, vai estourar a capacidade maxima
                    if(quant_ids == 10)
                    {
                        // pular para a posicao do ponteiro para o proximo e inserir o valor do final do arquivo
                        this.reverse_list.seek( this.reverse_list.getFilePointer() + (Integer.SIZE/8)*10);
                        this.reverse_list.writeLong(this.reverse_list.length());

                        this.reverse_list.seek(this.reverse_list.length());
                        this.reverse_list.writeInt(1);
                        
                        // inserindo o ID do usuario criado
                        this.reverse_list.writeInt(this.last_id);

                        // pulando as casas dos outros ints para inserir -1 no ponteiro para proximo
                        this.reverse_list.seek( this.reverse_list.getFilePointer() + (Integer.SIZE/8)*(9) );
                        this.reverse_list.writeLong(-1);
                    }

                    else
                    {
                        // reescrever a quantidade de IDs inseridos, pois vai ser inserido outro
                        this.reverse_list.seek(pos_insertion_reverse_list);
                        this.reverse_list.writeInt(quant_ids+1);
                        
                        // pular <quant> ints para fazer a nova insercao no espaco vazio
                        this.reverse_list.seek(this.reverse_list.getFilePointer() + (Integer.SIZE/8)*quant_ids);
                        this.reverse_list.writeInt(this.last_id);
                    }
                }
            }
            this.close_file();
        }
        catch(Exception error)
        {
            error.printStackTrace();
            System.exit(1);
        }

        // escrevendo o par <ID> <Nome> no arquivo de dados
        this.database.create((long)this.last_id, name);

        // reescrevendo o ultimo id inserido
        this.rewrite_last_id();
    }
    

    public int[] read(String search_str)
    {
        int quant_ids;

        String[] array_terms          =  this.clear_string(search_str).split(" ");
        ArrayList<Integer> array_ids  =  new ArrayList<Integer>();
        ArrayList<Integer> aux_array  =  new ArrayList<Integer>();

        for(int i = 0; i < this.last_id; i++)
            array_ids.add(i);

        try
        {
            this.open_file();

            // para cada termo em array_terms, procurar o termo
            // no arquivo sequencial
            for(String s: array_terms)
            {
                long position = this.index.read(s);
                if(position != -1)
                {
                    this.reverse_list.seek(position);

                    quant_ids  =  this.reverse_list.readInt();
                    for(int i = 0; i < quant_ids; i++)
                    {
                        aux_array.add(this.reverse_list.readInt());

                        if(quant_ids == 10)
                            if(this.reverse_list.readLong() != -1)
                            {
                                i = 0;
                                quant_ids = this.reverse_list.readInt();
                            }
                    }
                }
                array_ids.retainAll(aux_array);
                aux_array.clear();
            }

            this.close_file();
        }
        catch(Exception error)
        {
            error.printStackTrace();
            System.exit(1);
        }

        // converte o ArrayList para uma stream;
        // mapeia cada <i> para si mesmo, no tipo primitivo int;
        // converte tudo para um array de ints
        return array_ids.stream().mapToInt(i -> i).toArray();
    }


    // usar apenas para debug.
    // Printa os valores inseridos na lista
    public void status()
    {
        try
        {
            this.open_file();

            int quant_ids, id;
            long next;


            // se a lista nao estiver vazia, printar o primeiro int dela.
            // O primeiro int se refere ao last_id
            if(this.reverse_list.getFilePointer() != this.reverse_list.length())
                System.out.println(this.reverse_list.readInt());

            
            // enquanto nao chegar no fim da lista, printar
            // <quantidade_ids> <lista dos ids> <proximo>
            while(this.reverse_list.getFilePointer() != this.reverse_list.length())
            {
                quant_ids = this.reverse_list.readInt();
                System.out.printf("%d ", quant_ids);

                for(int i = 0; i < quant_ids; i++)
                {
                    id = this.reverse_list.readInt();
                    System.out.printf("%d ", id);
                }

                this.reverse_list.seek(this.reverse_list.getFilePointer() + (Integer.SIZE/8)*(10-quant_ids));
                next = this.reverse_list.readLong();

                System.out.println(next);
            }
            this.close_file();
        }
        catch(Exception error)
        {
            error.printStackTrace();
            System.exit(1);
        }
    }


    // abre o arquivo da lista invertida para leitura/escrita
    private void open_file() throws Exception
    {
        try
        {
            this.reverse_list = new RandomAccessFile(this.save_location, "rw");
        }
        catch(Exception error)
        {
            error.printStackTrace();
            throw error;
        }
    }


    // fecha o arquivo da lista invertida
    private void close_file() throws Exception
    {
        try
        {
            this.reverse_list.close();
        }
        catch(Exception error)
        {
            error.printStackTrace();
            throw error;
        }
    }


    // O primeiro int do arquivo da lista invertida eh o ultimo ID inserido
    private void rewrite_last_id()
    {
        try
        {
            this.open_file();
            
            this.reverse_list.writeInt(++this.last_id);

            this.close_file();
        }
        catch(Exception error)
        {
            error.printStackTrace();
            System.exit(1);
        }

    }


    // limpar a string de caracteres especiais. Todo o texto
    // deve ser em ASCII para inserir no arquivo sequencial de termos
    private String clear_string(String str)
    {
        String cleared_str = Normalizer.normalize(str, Normalizer.Form.NFD);
        cleared_str = cleared_str.replaceAll("[^\\p{ASCII}]", "");

        return cleared_str;
    }
}