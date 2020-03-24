if [ ! -d "dados" ]; then
	mkdir dados
fi

javac main.java
java main

rm *.class
