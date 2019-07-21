from sqlalchemy import *

class Entrada:
    def resposta(mensagem):
        resposta = input(mensagem)
        return resposta


class Tabela:
    def verificarTabelaExiste(tabela):
        if not con.dialect.has_table(con, tabela):
            desejaCriar = Entrada.resposta("A tabela de nome " + tabela + " nao existe. Deseja criar uma? [S/N]")
        
            if(desejaCriar.upper() == "S"):
                tabela = criarTabela(tabela)

            else:
                exit()
        else:
            tabela = Table(tabela, meta)

        return tabela
    
    def criarTabela(tabela):
        tabela = Table(tabela, meta,
                Column(campo1, String),
                Column(campo2, String)
                )
        return tabela
        

def connect(usuario, senha, bancoDados, host='localhost', port='5432'):
    url = 'postgresql://{}:{}@{}:{}/{}'
    url = url.format(usuario, senha, host, port, bancoDados)

    con = create_engine(url)

    meta = MetaData(bind = con, reflect = True)

    return con, meta

#usuario = input("Usuario:")
#senha = input("Senha:")
#db = input("Nome do banco de dados:")
con, meta = connect('rafael', '123', 'db')

tabela = Entrada.resposta("Digite o nome da tabela: ")
tabela, campos = verificarTabelaExiste(tabela) 

while(Entrada.resposta("Deseja inserir um dado na tabela? [N] para sair ou outra tecla para continuar: ").upper() != "N"):
    
    for i in range(0, len(campos)):
        inserir = tabela.insert(), valoresInseridos)
    
    con.execute(inserir)
