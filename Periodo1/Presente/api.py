from flask import Flask, jsonify, request
from sqlalchemy import *
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker, relationship
import os

app = Flask(__name__)
json = []

@app.route("/")
def teste():
	return '''
    /get para retornar JSON de todos alunos inseridos
    /post para inserir novo aluno
    /del para deletar um aluno
    '''

@app.route("/get", defaults={'id': -1}, methods=['GET'])
@app.route("/get/<int:id>", methods=['GET'])
def get(id):
    
    global json

    # Verificando se lista esta vazia
    if not json:
        return "Não existem alunos ainda. Adicione um, por favor"


    if(id != -1):
        for aluno in json:
            if(aluno['matricula'] == id):
                return aluno['nome']

    json.sort(key=lambda s: s['matricula'])
    
    listaAlunos = ""
    for aluno in json:
        listaAlunos +="Nome:   {}\nIdade:   {}\nMatricula:   {}\n\n".format(aluno['nome'], aluno['idade'], aluno['matricula'])

    return listaAlunos



#################################### 
#
#
#  A funcao obtem qual a nova matricula chamando o metodo novaMatricula(), que itera por todos elementos do JSON e procura qual o primeiro 
#  numero de matricula que nao corresponde a ninguem
#
#
###################################
@app.route("/post", methods=['POST'])
def inserir():

    global json
    novos_alunos = request.json

    if(type(novos_alunos) == list):
        for aluno in novos_alunos:
            nome = aluno['nome']
            idade = int(aluno['idade'])
            matricula = int(novaMatricula())
            json.append({"nome": nome, "idade": idade, "matricula": matricula})

    else:
        nome = novos_alunos['nome']
        idade = int(novos_alunos['idade'])
        matricula = int(novaMatricula())
        json.append({"nome": nome, "idade": idade, "matricula": matricula})
        pass
    
    return "Inserido!"



def novaMatricula():

    global json 
    
    matriculas = []
    for aluno in json:
        matriculas.append(aluno['matricula'])
    
    nova_matricula = 0
    while nova_matricula in matriculas:
        nova_matricula += 1

    return nova_matricula


###################################
#
#
# Funcao deleta o elemento do json baseado no valor que recebe pela URL 
#
#
###################################

@app.route("/del/<int:ex_matricula>", methods=['GET'])
def deletar(ex_matricula):

    global json
    matriculas = []
     
    for aluno in json:
        matriculas.append(aluno['matricula'])
    

    try:
        assert(ex_matricula in matriculas)

    except AssertionError:
        return f"O codigo de matricula {ex_matricula} nao foi encontrado; Insira apenas um valor valido!"

    for i in range(0, len(matriculas)):
        if(matriculas[i] == ex_matricula):
            del json[i]
            break

    return "Deletado!"

if __name__ == '__main__':
    port = int(os.environ.get('PORT', 5000))
    app.run(debug = True, host = '0.0.0.0', port = port)

