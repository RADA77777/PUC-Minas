from sqlalchemy import *

def verificarTabelaExiste(tabelaNome, meta, engine):
    # Esse if retorna se a tabela já existe
    nomesColunas = []

    if not engine.dialect.has_table(engine, tabelaNome):
        desejaCriar = input("A tabela de nome " + tabelaNome + " nao existe. Deseja criar uma? [S/N]\n")
        
        if(desejaCriar.upper() == "S"):
            tabela, nomesColunas = criarTabela(tabelaNome, meta, engine)

        # Caso nao queira criar a tabela
        else:
            print("Obrigado por usar!\n")
            exit()
    
    else:
        print("A tabela ja existe!\n")
        tabela, nomesColunas = returnInfoTabela(tabelaNome, meta, engine)

    print("Acessando tabela...\n")
    return tabela, nomesColunas
    

def returnInfoTabela(tabelaNome, meta, engine):
    nomesColunas = []
    tabela = Table(tabelaNome, meta, autoload = True, autoload_with = engine)
    
    for coluna in tabela.columns:
        nomeColuna = str(coluna)
        nomesColunas.append(nomeColuna[nomeColuna.find(".") + 1 :])
    
    return tabela, nomesColunas

def criarTabela(tabelaNome, meta, engine):
    nomesColunas = []
    tiposColunas = []
    quantCampos = int(input("Quantas colunas a tabela deve ter?\n"))
    
    for i in range(0, quantCampos):
        nomeColuna = input("Qual o nome da coluna " + str(i+1) + "?\n")
        nomesColunas.append(nomeColuna)
        tiposColunas.append(String)

    tabela = Table(tabelaNome, meta, *(Column(nomeColuna, tipoColuna) for nomeColuna, tipoColuna in zip(nomesColunas, tiposColunas)))
    
    meta.create_all(engine)
    print("A tabela " + tabelaNome + " foi criada\n")
    return tabela, nomesColunas
        

def connect(usuario, senha, bancoDados, host='172.17.0.2', port='5432'):
    url = 'postgresql://{}:{}@{}:{}/{}'
    url = url.format(usuario, senha, host, port, bancoDados)
    engine = create_engine(url)
    meta = MetaData(bind = engine, reflect = True)

    return engine, meta


usuario = 'rafael'
senha = '123'
db = 'db'

engine, meta = connect(usuario, senha, db)
tabelaNome = input("Digite o nome da tabela: ")
tabela, nomesColunas = verificarTabelaExiste(tabelaNome, meta, engine)
valores = []


while(input("Deseja inserir um dado na tabela? [N] para sair ou outra tecla para continuar: ").upper() != "N"):
    
    valoresCampos = []
    for i in range(0, len(nomesColunas)):
        valoresCampos.append(input("Digite um valor para o campo '%s': " % nomesColunas[i]))

    valores.append(dict(zip(nomesColunas, valoresCampos)))

engine.execute(tabela.insert(), valores)
