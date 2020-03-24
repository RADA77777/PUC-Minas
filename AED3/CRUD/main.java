public class main
{
	public static void main(String[] args)
	{
		CRUD crud = new CRUD();
		//crud.create();
		Usuario u = crud.read("email@email");
		u.print_user();
		
		u = crud.read(-1);
		u.print_user();
	}
}