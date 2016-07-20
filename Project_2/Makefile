OBJs =  Media.o main.o

project2: $(OBJs)
	g++ $(OBJs) -std=c++0x -o project22

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

Media.o: Media.cpp Media.h
	g++ -std=c++0x -c Media.cpp

clean:
	rm -f *.o
	rm -rf ./project2.exe
	rm -rf ./project2.dSYM

run:    clean project2 
	./project22
