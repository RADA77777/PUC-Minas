package utils;

import java.text.Normalizer;


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
}