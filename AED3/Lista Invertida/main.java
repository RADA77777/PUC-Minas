import src.ArquivoSequencial;
import src.ListaInvertida;

public class main
{
    public static void main(String[] args)
    {
        String save_file = "./dados_usuarios";

        ListaInvertida l = new ListaInvertida(save_file);
        ArquivoSequencial database = new ArquivoSequencial(save_file + ".db");
        
        l.status();
        l.create("Rafael");
        System.out.println("\nR inserido");
        l.status();
        l.create("Rafael Amauri");
        System.out.println("\nRA inserido");
        l.status();
        
        /*
        //l.status();
        int a[] = l.read("Amauri");

        //database.status();
        for(int i:a)
        {
            System.out.println(database.read(i));
        }

        */
    }
}