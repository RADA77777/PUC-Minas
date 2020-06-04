package utils;

import java.text.Normalizer;
import java.io.RandomAccessFile;


public class utils
{
    // limpar a string de caracteres especiais. Todo o texto
    // deve ser em ASCII para inserir no arquivo sequencial de termos
    public static String clear_string(String str)
    {
        String cleared_str = Normalizer.normalize(str, Normalizer.Form.NFD);
        cleared_str = cleared_str.replaceAll("[^\\p{ASCII}]", "");

        return cleared_str;
    }


    // recebe um caminho para arquivo e retorna um RandomAccessFile para lida e escrita
    public static RandomAccessFile open_file(String filepath) throws Exception
    {
        try
        {
            RandomAccessFile file = new RandomAccessFile(filepath, "rw");
            return file;
        }
        catch(Exception error)
        {
            error.printStackTrace();
            throw error;
        }
    }


    // recebe um ponteiro para RandomAccessFile e fecha a stream de dados
    public static void close_file(RandomAccessFile file) throws Exception
    {
        try
        {
            file.close();
        }
        catch(Exception error)
        {
            error.printStackTrace();
            throw error;
        }
    }
}