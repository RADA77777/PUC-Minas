from telegram.ext import CommandHandler, Filters, MessageHandler, Updater


json = []

def start(bot, update):
    msg_introducao = "Olá! Eu seu bot de agenda! Pense em mim como um assistente pessoal. Digite /add para adicionar um novo compromisso, /del para deletar e /lista para listar todos existentes. Mas não se preocupe! Você pode sempre digitar /ajuda para eu te lembrar os comandos!"
    
    bot.send_message(
            chat_id = update.message.chat_id,
            text = msg_introducao
            )
    
    return 0


def get(bot, update):
    
    global json

    # Verificando se lista esta vazia
    if not json:
        bot.send_message(
                chat_id = update.message.chat_id,
                text = "Opa! Parece que não existem compromissos. Digite /add para adicionar um!"
                )


    json.sort(key=lambda s: s['mes'])
    
    agenda = ""
    for compromisso in json:
        agenda += f"Data: {compromisso['dia']}/{compromisso['mes']}\nCompromisso:  {agenda['descricao']}\n\n"
    
    bot.send_message(
            chat_id = update.message.chat_id,
            text = agenda
            )

    return 0

def inserir(bot, update):

    global json
    
    reply_keyboard = [['Boy', 'Girl', 'Other']]

    update.message.reply_text(
        'Hi! My name is Professor Bot. I will hold a conversation with you. '
        'Send /cancel to stop talking to me.\n\n'
        'Are you a boy or a girl?',
        reply_markup=ReplyKeyboardMarkup(reply_keyboard, one_time_keyboard=True))

    return GENDER 



###################################
#
#
# Funcao deleta o elemento do json baseado no valor que recebe pela URL 
#
#
###################################

#def deletar(bot, update):

 #   global json
  #  matriculas = []
     
   # for aluno in json:
    #    matriculas.append(aluno['matricula'])
    

  #  try:
   #     assert(ex_matricula in matriculas)

  #  except AssertionError:
    #    return f"O codigo de matricula {ex_matricula} nao foi encontrado; Insira apenas um valor valido!"

    #for i in range(0, len(matriculas)):
      #  if(matriculas[i] == ex_matricula):
      #      del json[i]
      #      break

    #return "Deletado!"

def main():
    updater = Updater(token="962672071:AAELT0qlHLi7a1qKxHjLQqixeYealG1rouY")

    dispatcher = updater.dispatcher

    dispatcher.add_handler(
        CommandHandler('start', start)
        )
    
    dispatcher.add_handler(
            CommandHandler('add', inserir)
            )

    updater.start_polling()
    updater.idle()

if __name__ == '__main__':
    print("press CTRL + C to cancel.")
    main()
