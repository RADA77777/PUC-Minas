git add $1
echo Qual mensagem devo colocar?
read msg
git commit -m "$msg"
git push 
