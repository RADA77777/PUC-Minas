public class main
{
	public static void main(String[] args)
	{
		CRUD crud = new CRUD();
		//crud.create();
		Usuario u = crud.read("email@email");
		u.print_user();
		
		u = crud.read(3);
		u.print_user();
	}
}