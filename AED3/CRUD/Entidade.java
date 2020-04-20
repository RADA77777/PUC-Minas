public interface Entidade
{
    public int get_id();

	public String get_chave_secundaria();

    public byte[] to_byte_array() throws java.io.IOException;
	public void from_byte_array(byte[] bytes) throws java.io.IOException;
	
	public void set_info(int some_int);
	
	public void print_entity();
}