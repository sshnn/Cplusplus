derlecalistir:program calistir

program: data.o main.o fileReader.o node.o
	g++ -o ./bin/Program ./lib/data.o ./lib/fileReader.o ./lib/main.o ./lib/node.o 
	
data.o:
	g++ -I "./include" -c ./src/data.cpp -o ./lib/data.o
	
fileReader.o:
	g++ -I "./include" -c ./src/fileReader.cpp -o ./lib/fileReader.o

main.o:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o

node.o:
	g++ -I "./include" -c ./src/node.cpp -o ./lib/node.o
	
calistir:
	./bin/Program.exe
