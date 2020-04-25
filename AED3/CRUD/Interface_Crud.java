import java.util.Scanner;

public class Interface_Crud
{
    static int id_logged_usr = -1;
    static String email_logged_usr, nome_logged_usr;
    static Scanner in;

    public static int menu_inicial(CRUD<Usuario> crud, Scanner input)
    {
        boolean flag = true;
        int selecao;
        Usuario usuario_login = new Usuario();
        int return_value = 1;
        in = input;

        while(flag)
        {
            System.out.println("ACESSO:\n1) Acesso ao sistema\n2) Novo usuario\n\n0) Sair");
            System.out.print("Selecao: ");
        
            selecao = in.nextInt();
            System.out.println("\n");
            while(selecao < 0 || selecao > 2)
            {
                System.out.print("\nSelecione apenas um dos valores apresentados!\nSelecao: ");
                selecao = in.nextInt();
            }
        
            switch(selecao)
            {
                case 1:
                    System.out.println("Menu de Acesso\n==============");
                    usuario_login = menu_acesso(crud);
                    if(usuario_login == null)
                        System.out.println("Nenhum usuario foi encontrado com essas credenciais\n");
                    else
                    {
                        id_logged_usr     =  usuario_login.get_id();
                        email_logged_usr  =  usuario_login.get_chave_secundaria();
                        nome_logged_usr   =  usuario_login.get_nome();

                        flag = false;
                    }
                    break;

                case 2: 
                    System.out.println("Menu de Cadastro\n=================");
                    int return_value_cadastro = menu_cadastro(crud);
                    if(return_value_cadastro == -1)
                        System.out.println("Esse usuario ja esta cadastrado!\n");

                    else if(return_value_cadastro == -2)
                        System.out.println("O email nao pode ser um texto vazio!");

                    break;

                case 0: 
                    flag = false;
                    return_value = 0;
                    break;
            }
        }
        System.out.println("\n");

        return return_value;
    }

    public static Usuario menu_acesso(CRUD<Usuario> crud)
    {
        Usuario usuario_login = new Usuario();
        in.nextLine();
        System.out.print("Email: ");
        String email = in.nextLine();

        System.out.print("Senha: ");
        String senha = in.nextLine();

        usuario_login = crud.read(email);
        if(usuario_login == null || !usuario_login.get_senha().equals(senha))
            return null;
        
        return usuario_login;
    }

    public static int menu_cadastro(CRUD<Usuario> crud)
    {
        int return_value = 0;
        System.out.println("Novo Usuario\n=================\n");
        
        in.nextLine();
        System.out.printf("Email: ");
        String email = in.nextLine();
        if(email.equals(""))
            return -2;

        Usuario user = crud.read(email);
        if(user == null)
        {
            user = new Usuario();
            if(user.set_info(email, in) == 0)
                crud.create(user);
            else
                System.out.println("Os campos nao podem ser vazios!");
        }
        else
            return_value = -1;

        return return_value;
    }

    public static int menu_opcoes(Scanner in)
    {
        boolean flag = true;
        int selecao = -1;
    
        int quant_convites = 0;
        try
        {
            ArvoreBMais_ChaveComposta_String_Int lista_invertida = new ArvoreBMais_ChaveComposta_String_Int(4, "./dados/lista_invertida.db");
            quant_convites = lista_invertida.read(email_logged_usr).length;
        }
        catch(Exception error)
        {
            error.printStackTrace();
        }

        while(flag)
        {
            System.out.println("ACESSO:\n1) Sugestao de presentes\n2) Grupos\n3) Convites novos: " + quant_convites +"\n0) Voltar");
            System.out.print("Selecao: ");
            selecao = in.nextInt();
            System.out.println("\n");

            while(selecao < 0 || selecao > 3)
            {
                System.out.println("\nSelecione apenas um dos valores apresentados!\nSelecao: ");
                selecao = in.nextInt();
            }
            flag = false;
        }
        
        
        return selecao;
    }

    public static void menu_sugestoes(CRUD<Sugestao> crud, Scanner in)
    {
        boolean flag = true;
        int selecao;
        Sugestao sugestao;

        while(flag)
        {
            System.out.println("Menu de Sugestoes:\n1) Listar\n2) Adicionar\n3) Alterar\n4) Excluir\n0) Voltar");
            System.out.print("Selecao: ");
            selecao = in.nextInt();
            System.out.println("\n");

            while(selecao < 0 || selecao > 4)
            {
                System.out.println("\nSelecione apenas um dos valores apresentados!\nSelecao: ");
                selecao = in.nextInt();
                System.out.println("\n");
            }
        
            switch(selecao)
            {
                // Listar sugestoes
                case 1:
                    try
                    {
				        ArvoreBMais_Int_Int arvore_int_int = new ArvoreBMais_Int_Int(10, "./dados/arvore_int_int_sugestoes.db");
                        int[] id_sugestoes = arvore_int_int.read(id_logged_usr);
                        for(int i = 0; i < id_sugestoes.length; i++)
                        {
                            System.out.println("[" + (i+1) + "]");
                            sugestao = crud.read(id_sugestoes[i]);
                            sugestao.print_entity();
                            System.out.println("\n");
                        }
                    }
                    catch(Exception error)
                    {
                        error.printStackTrace();
                    }

                    break;


                // Adicionar sugestao
                case 2:
                    Sugestao new_sugestao = new Sugestao();
                    if(new_sugestao.set_info(id_logged_usr, in) == 0)
                    {
                        crud.create(new_sugestao);
                        System.out.println("Nova sugestao inserida!");
                    }
                    System.out.println("\n");

                    break;

                
                // Alterar sugestao
                case 3:
                    try
                    {
                        // Listando sugestoes existentes
                        ArvoreBMais_Int_Int arvore_int_int = new ArvoreBMais_Int_Int(10, "./dados/arvore_int_int_sugestoes.db");
                        int[] id_sugestoes = arvore_int_int.read(id_logged_usr);
                        
                        for(int i = 0; i < id_sugestoes.length; i++)
                        {
                            System.out.println("[" + (i+1) + "]");
                            sugestao = crud.read(id_sugestoes[i]);
                            sugestao.print_entity();
                            System.out.println("\n");
                        }

                        System.out.printf("Qual o ID da sugestao que voce quer atualizar?\nSelecao: ");
                        int selected_id = in.nextInt()-1;
                        System.out.println("\n");

                        Sugestao existing_sugestao = new Sugestao();
                        existing_sugestao.set_info(id_logged_usr, in);

                        crud.update(existing_sugestao, id_sugestoes[selected_id]);
                    }
                    catch(Exception error)
                    {
                        error.printStackTrace();
                    }

                    break;


                // Excluir sugestao
                case 4:
                    try
                    {
                        // Listando sugestoes existentes
                        ArvoreBMais_Int_Int arvore_int_int = new ArvoreBMais_Int_Int(10, "./dados/arvore_int_int_sugestoes.db");
                        int[] id_sugestoes = arvore_int_int.read(id_logged_usr);
                        
                        for(int i = 0; i < id_sugestoes.length; i++)
                        {
                            System.out.println("[" + (i+1) + "]");
                            sugestao = crud.read(id_sugestoes[i]);
                            sugestao.print_entity();
                            System.out.println("\n");
                        }

                        System.out.printf("Qual o ID da sugestao que voce quer deletar?\nSelecao: ");
                        int selected_id = in.nextInt()-1;
                        System.out.println("\n");


                        sugestao = crud.read(id_sugestoes[selected_id]);
                        sugestao.print_entity();

                        // Confirmacao de delecao da sugestao
                        in.nextLine();
                        System.out.printf("Deseja deletar essa sugestao? [s/n]");
                        String delete = in.nextLine();

                        while(!delete.toLowerCase().equals("s") && !delete.toLowerCase().equals("n"))
                        {
                            System.out.printf("Deseja mesmo excluir essa sugestao? [s/n]");
                            System.out.printf("Responda com [s/n] !");
                            delete = in.nextLine();
                        }
                        if(delete.equals("s"))
                        {
                            arvore_int_int.delete(id_logged_usr, id_sugestoes[selected_id]);
                            crud.delete(id_sugestoes[selected_id]);
                        }
                    }
                    catch(Exception error)
                    {
                        error.printStackTrace();
                    }
                    break;

                
                // Voltar
                case 0: flag = false; break;
            }
        }

        return ;
    }



    public static int menu_grupos(Scanner in)
    {
        boolean flag = true;
        int selecao = -1;
    
        while(flag)
        {
            System.out.println("GRUPOS:\n1) Criação e gerenciamento de grupos\n2) Participação nos grupos\n0) Voltar");
            System.out.print("Selecao: ");
            selecao = in.nextInt();
            System.out.println("\n");

            while(selecao < 0 || selecao > 2)
            {
                System.out.print("\nSelecione apenas um dos valores apresentados!\nSelecao: ");
                selecao = in.nextInt();
            }
            flag = false;
        }
        
        
        return selecao;
    }

    
    public static int gerenciamento_grupos(CRUD<Grupo> crud, Scanner in)
    {
        boolean flag = true;
        int selecao = -1;
    
        while(flag)
        {
            System.out.println("GRUPOS:\n1) Grupos\n2) Convites\n3) Participantes\n4) Sorteio\n0) Voltar");
            System.out.print("Selecao: ");
            selecao = in.nextInt();
            System.out.println("\n");

            while(selecao < 0 || selecao > 4)
            {
                System.out.print("\nSelecione apenas um dos valores apresentados!\nSelecao: ");
                selecao = in.nextInt();
            }
            flag = false;
        }
        
        
        return selecao;
    }


    public static void administracao_grupos(CRUD<Grupo> crud, Scanner in)
    {
        boolean flag = true;
        int selecao;
        Grupo grupo;

        while(flag)
        {
            System.out.println("Menu de Grupos:\n1) Listar\n2) Adicionar\n3) Alterar\n4) Desativar\n0) Voltar");
            System.out.print("Selecao: ");
            selecao = in.nextInt();
            System.out.println("\n");

            while(selecao < 0 || selecao > 4)
            {
                System.out.println("\nSelecione apenas um dos valores apresentados!\nSelecao: ");
                selecao = in.nextInt();
                System.out.println("\n");
            }
        
            switch(selecao)
            {
                // Listar grupos
                case 1:
                    try
                    {
				        ArvoreBMais_Int_Int arvore_int_int = new ArvoreBMais_Int_Int(10, "./dados/arvore_int_int_grupos.db");
                        int[] id_grupos = arvore_int_int.read(id_logged_usr);
                        for(int i = 0; i < id_grupos.length; i++)
                        {
                            grupo = crud.read(id_grupos[i]);
                            if(grupo.is_ativo())
                            {
                                System.out.println("[" + (i+1) + "]");
                                grupo.print_entity();
                                System.out.println("\n");
                            }
                        }
                    }
                    catch(Exception error)
                    {
                        error.printStackTrace();
                    }

                    break;

                // Criar novo grupo
                case 2:
                    Grupo new_grupo = new Grupo();
                    if(new_grupo.set_info(id_logged_usr, in) == 0)
                    {
                        new_grupo.set_ativo(true);
                        new_grupo.set_sorteado(false);
                
                        crud.create(new_grupo);
                        System.out.println("Grupo inserido!");
                    }
                    System.out.println("\n");

                    break;

                
                // Atualizar grupo
                case 3:
                try
                    {
                        // Listando grupos existentes
                        ArvoreBMais_Int_Int arvore_int_int = new ArvoreBMais_Int_Int(10, "./dados/arvore_int_int_grupos.db");
                        int[] id_grupos = arvore_int_int.read(id_logged_usr);
                        
                        for(int i = 0; i < id_grupos.length; i++)
                        {
                            grupo = crud.read(id_grupos[i]);
                            if(grupo.is_ativo())
                            {
                                System.out.println("[" + (i+1) + "]");
                                grupo.print_entity();
                                System.out.println("\n");
                            }
                        }
                        System.out.println("[0] Voltar");

                        System.out.printf("Qual o grupo do que voce quer atualizar?\nSelecao: ");
                        int selected_id = in.nextInt()-1;
                        System.out.println("\n");
                        if(selected_id != -1)
                        {
                            Grupo existing_grupo = new Grupo();
                            existing_grupo.set_info(id_logged_usr, in);

                            crud.update(existing_grupo, id_grupos[selected_id]);
                            System.out.println("Grupo atualizado!");
                        }
                    }
                    catch(Exception error)
                    {
                        error.printStackTrace();
                    }

                    break;


                // Excluir grupo
                case 4:
                    try
                    {
                        // Listando grupos existentes
                        ArvoreBMais_Int_Int arvore_int_int = new ArvoreBMais_Int_Int(10, "./dados/arvore_int_int_grupos.db");
                        int[] id_grupos = arvore_int_int.read(id_logged_usr);
                        
                        for(int i = 0; i < id_grupos.length; i++)
                        {
                            grupo = crud.read(id_grupos[i]);
                            if(grupo.is_ativo())
                            {
                                System.out.println("[" + (i+1) + "]");
                                grupo.print_entity();
                                System.out.println("\n");
                            }
                        }
                        System.out.println("[0] Voltar");

                        System.out.printf("Qual o ID do grupo que voce quer desativar?\nSelecao: ");
                        int selected_id = in.nextInt()-1;
                        System.out.println("\n");
                        
                        if(selected_id != -1)
                        {
                            grupo = crud.read(id_grupos[selected_id]);
                            grupo.print_entity();
                            System.out.println("\n");

                            // Confirmacao de desativacao do grupo
                            in.nextLine();
                            System.out.printf("Deseja mesmo excluir esse grupo? [s/n] ");
                            String delete = in.nextLine();
                            while(!delete.toLowerCase().equals("s") && !delete.toLowerCase().equals("n"))
                            {
                                System.out.printf("Deseja mesmo excluir esse grupo? [s/n] ");
                                System.out.printf("Responda com [s/n] !");
                                delete = in.nextLine();
                            }
                            if(delete.equals("s"))
                            {
                                grupo.set_ativo(false);
                                crud.update(grupo, id_grupos[selected_id]);
                            }
                        }
                    }
                    catch(Exception error)
                    {
                        error.printStackTrace();
                    }
                    break;


                // Voltar
                case 0: flag = false; break;
            }
        }
    }

    public static void gerenciamento_convites(CRUD<Grupo> crud_grupos, CRUD<Convite> crud_convites, Scanner in)
    {
        boolean flag = true;
        int selecao;

        Convite convite;
        Grupo grupo;

        while(flag)
        {
            System.out.println("Menu de Convites:\n1) Listar\n2) Emitir novo\n3) Cancelar convite\n0) Voltar");
            System.out.print("Selecao: ");
            selecao = in.nextInt();
            System.out.println("\n");

            while(selecao < 0 || selecao > 3)
            {
                System.out.println("\nSelecione apenas um dos valores apresentados!\nSelecao: ");
                selecao = in.nextInt();
                System.out.println("\n");
            }
        
            switch(selecao)
            {
                // Listar convites
                case 1:
                    try
                    {
                        ArvoreBMais_Int_Int arvore_int_int = new ArvoreBMais_Int_Int(10, "./dados/arvore_int_int_grupos.db");
                        int[] id_grupos = arvore_int_int.read(id_logged_usr);
                        for(int i = 0; i < id_grupos.length; i++)
                        {
                            grupo = crud_grupos.read(id_grupos[i]);
                            if(grupo.is_ativo())
                            {
                                System.out.println("[" + (i+1) + "]");
                                grupo.print_entity();
                                System.out.println("\n");
                            }
                        }
                        System.out.println("[0] Voltar");

                        System.out.printf("Ver convites de qual grupo?\nSelecao: ");
                        int selected_id = in.nextInt()-1;
                        System.out.println("\n");
                        
                        // Escolhendo grupo
                        if(selected_id != -1)
                        {
                            grupo = crud_grupos.read(id_grupos[selected_id]);
                            grupo.print_entity();
                            System.out.println("\n");

                            int id_group       =  grupo.get_id_grupo();
                            arvore_int_int     =  new ArvoreBMais_Int_Int(10, "./dados/arvore_int_int_convites.db");
                            int[] id_convites  =  arvore_int_int.read(id_group);

                            // Listando convites do grupo escolhido
                            for(int i = 0; i < id_convites.length; i++)
                            {
                                convite = crud_convites.read(id_convites[i]);
                                System.out.println("[" + (i+1) + "]");
                                convite.print_entity();
                                System.out.println("\n");
                            }
                        }
                    }
                    catch(Exception error)
                    {
                        error.printStackTrace();
                    }
                    break;


                // Criar novo convite
                case 2:
                    try
                    {
                        ArvoreBMais_String_Int arvore_convites = new ArvoreBMais_String_Int(10, "./dados/arvore_srt_int_convites.db");
                        ArvoreBMais_ChaveComposta_String_Int lista_invertida = new ArvoreBMais_ChaveComposta_String_Int(4, "./dados/lista_invertida.db");
                        ArvoreBMais_Int_Int arvore_int_int = new ArvoreBMais_Int_Int(10, "./dados/arvore_int_int_grupos.db");
                        
                        // Gerando lista de grupos para esse usuario
                        int[] id_grupos = arvore_int_int.read(id_logged_usr);
                        for(int i = 0; i < id_grupos.length; i++)
                        {
                            grupo = crud_grupos.read(id_grupos[i]);
                            if(grupo.is_ativo() && !grupo.is_sorteado())
                            {
                                System.out.println("[" + (i+1) + "]");
                                grupo.print_entity();
                                System.out.println("\n");
                            }
                        }
                        System.out.println("[0] Voltar");

                        System.out.printf("Emitir convites para qual grupo?\nSelecao: ");
                        int selected_id = in.nextInt()-1;
                        System.out.println("\n");
                        
                        if(selected_id != -1)
                        {
                            
                            grupo = crud_grupos.read(id_grupos[selected_id]);
                            int id_grupo = grupo.get_id_grupo();
                            grupo.print_entity();
                            System.out.println("\n");

                            // Confirmacao envio de convite
                            in.nextLine();
                            boolean inserindo_emails = true;
                            while(inserindo_emails)
                            {
                                System.out.printf("Email do convidado/[0] para sair: ");
                                String email = in.nextLine();

                                if(email.equals(""))
                                    System.out.println("O campo email nao pode ficar vazio!");
                                
                                else if(email.equals("0"))
                                    inserindo_emails = false;
                                
                                else if(crud_convites.read(arvore_convites.read(id_grupo + "|" + email)) != null)
                                    System.out.println("Esse usuario ja esta no grupo!");
                                
                                else
                                {
                                    convite = new Convite();
                                    convite.set_email(email);
                                    convite.set_emissor(nome_logged_usr + " - " + email_logged_usr);
                                    convite.set_info(id_grupo, in);
                                    crud_convites.create(convite);
                                    
                                    lista_invertida.create(email, id_grupo);    
                                }
                            }
                        }
                    }
                    catch(Exception error)
                    {
                        error.printStackTrace();
                    }
                    break;

                
                // Cancelar convite
                case 3:
                    try
                    {
                        // Listando grupos
                        ArvoreBMais_Int_Int arvore_int_int = new ArvoreBMais_Int_Int(10, "./dados/arvore_int_int_grupos.db");
                        int[] id_grupos = arvore_int_int.read(id_logged_usr);
                        for(int i = 0; i < id_grupos.length; i++)
                        {
                            grupo = crud_grupos.read(id_grupos[i]);
                            if(grupo.is_ativo())
                            {
                                System.out.println("[" + (i+1) + "]");
                                grupo.print_entity();
                                System.out.println("\n");
                            }
                        }
                        System.out.println("[0] Voltar");

                        System.out.printf("Cancelar convite de qual grupo?\nSelecao: ");
                        int selected_id = in.nextInt()-1;
                        System.out.println("\n");
                        
                        // Listando convites do grupo selecionado
                        if(selected_id != -1)
                        {
                            grupo = crud_grupos.read(id_grupos[selected_id]);
                            grupo.print_entity();
                            System.out.println("\n");

                            int id_group       =  grupo.get_id_grupo();
                            arvore_int_int     =  new ArvoreBMais_Int_Int(10, "./dados/arvore_int_int_convites.db");
                            int[] id_convites  =  arvore_int_int.read(id_group);
                            
                            for(int i = 0; i < id_convites.length; i++)
                            {
                                convite = crud_convites.read(id_convites[i]);
                                if(convite.is_pendente())
                                {
                                    System.out.println("[" + (i+1) + "]");
                                    convite.print_entity();
                                    System.out.println("\n");
                                }
                            }
                            System.out.println("[0] Voltar");
                            System.out.printf("Qual convite deseja cancelar?\nSelecao: ");

                            selected_id = in.nextInt()-1;
                            if(selected_id != -1)
                            {
                                convite     = crud_convites.read(id_convites[selected_id]);
                                convite.set_estado((byte)3);

                                crud_convites.update(convite, id_convites[selected_id]);
                                System.out.println("Convite cancelado!");
                            }
                        }
                    }
                    catch(Exception error)
                    {
                        error.printStackTrace();
                    }
                    System.out.println("\n");
                    break;


                // Voltar
                case 0:
                    flag = false;
                    break;
            }
        }
    }

    public static void ver_convites(CRUD<Grupo> crud_grupos, CRUD<Convite> crud_convites, Scanner in)
    {
        try
        {
            ArvoreBMais_ChaveComposta_String_Int lista_invertida = new ArvoreBMais_ChaveComposta_String_Int(4, "./dados/lista_invertida.db");
            int[] id_convites = lista_invertida.read(email_logged_usr);
            
            Grupo grupo;
            Convite convite;

            System.out.println("Convites pendentes\n\n");
            for(int i = 0; i < id_convites.length; i++)
            {
                System.out.println("[" + (i+1) + "]");
                convite        =  crud_convites.read(id_convites[i]);
                grupo          =  crud_grupos.read(convite.get_id());

                System.out.printf("Grupo: %s\nConvidado em: %s\nEmitido por: %s\n\n", grupo.get_nome(), convite.get_data_formatada(), convite.get_emissor());
            }

            System.out.println("[0] Voltar");

            System.out.println("Deseja aceitar/recusar qual convite?");
            System.out.println("\n");
            int selected_id = in.nextInt()-1;
            if(selected_id != -1)
            {
                convite = crud_convites.read(id_convites[selected_id]);
                convite.print_entity();
                
                System.out.println("Digite: [1] para aceitar -- [2] para recusar");
                int selected_state = in.nextInt();
                while(selected_state != 1 && selected_state != 2)
                {
                    System.out.println("Digite apenas um dos valores apresentados!");
                    selected_state = in.nextInt();
                }
                
                convite.set_estado((byte)selected_state);
                crud_convites.update(convite, id_convites[selected_id]);
                lista_invertida.delete(email_logged_usr, convite.get_id());
            }
        }
        catch(Exception error)
        {
            error.printStackTrace();
        }
    }
    
}