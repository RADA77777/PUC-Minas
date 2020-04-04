public interface Entidade
{
    public int get_id();
	public void set_id(int new_id);

	public String get_nome();
	public void set_nome(String new_nome);

	public String get_email();
	public void set_email(String new_email);

	public String get_senha();
	public void set_senha(String new_senha);

	public String chave_secundaria();

    public byte[] to_byte_array() throws java.io.IOException;
	public void from_byte_array(byte[] bytes) throws java.io.IOException;
	
	public void set_info(int some_int);
	
	public void print_entity();
}