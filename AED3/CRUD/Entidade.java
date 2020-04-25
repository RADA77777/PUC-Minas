import java.util.Scanner;

public interface Entidade
{
	public int get_id();
	public void set_id(int id);

	public String get_chave_secundaria();

    public byte[] to_byte_array() throws java.io.IOException;
	public void from_byte_array(byte[] bytes) throws java.io.IOException;
	
	public int set_info(int id, Scanner in);
	
	public void print_entity();
}