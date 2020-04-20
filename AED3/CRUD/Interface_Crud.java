import java.util.Scanner;

public class Interface_Crud
{
    static Scanner input = new Scanner(System.in);
    public static void menu_inicial(CRUD<Usuario> crud)
    {
        boolean flag = true;
        int selecao;
        Usuario usuario_login = new Usuario();
        while(flag)
        {
            System.out.println("ACESSO:\n1) Acesso ao sistema\n2) Novo usuario\n\n0)Sair");
            System.out.println("Selecao: ");
        
            selecao = input.nextInt();
            while(selecao != 1 && selecao != 2 && selecao != 0)
            {
                System.out.println("\nSelecione apenas um dos valores apresentados!\nSelecao: ");
                selecao = input.nextInt();
            }
        
            switch(selecao)
            {
                case 1:
                    System.out.println("Menu de Acesso\n==============");
                    usuario_login = menu_acesso(crud);
                    if(usuario_login == null)
                        System.out.println("Nenhum usuario foi encontrado com essas credenciais\n");
                    else
                        flag = false;

                    break;

                case 2: 
                    System.out.println("Menu de Cadastro\n==============");
                    if(menu_cadastro(crud) == -1)
                        System.out.println("Esse usuario ja esta cadastrado!\n");

                    break;

                case 0: System.out.println("Obrigado por usar!\n"); System.exit(0);
            }
        }
        input.close();

        //usuario_login.print_entity();
    }

    public static Usuario menu_acesso(CRUD<Usuario> crud)
    {
        Usuario usuario_login = new Usuario();
        input.nextLine();
        System.out.println("Email: ");
        String email = input.nextLine();

        System.out.println("Senha: ");
        String senha = input.nextLine();

        usuario_login = crud.read(email);
        if(usuario_login == null || !usuario_login.get_senha().equals(senha))
            return null;
        
        return usuario_login;
    }

    public static int menu_cadastro(CRUD<Usuario> crud)
    {
        System.out.println("Novo Usuario\n=================\n");
        
        if(crud.create() == -1)
        {
            return -1;
        }

        return 0;
    }
}