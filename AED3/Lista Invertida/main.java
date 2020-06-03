import src.ArquivoSequencial;
import src.ListaInvertida;


public class main
{
    public static void main(String[] args)
    {
        String save_file = "./dados_usuarios";

        ListaInvertida l = new ListaInvertida(save_file);
        ArquivoSequencial database = new ArquivoSequencial(save_file + ".db");
        
        /*
        l.create("João da Silva");
        l.create("João Silva");
        l.create("joao silva");
        l.create("joao da silva");
        */

        l.status();
        int array_ids[] = l.read("joao");

        for(int i: array_ids)
            System.out.printf("ID = %d -- Nome = %s\n", i, database.read(i));
    }
}