OBJs =  Media.o main.o

project2: $(OBJs)
	g++ $(OBJs) -o project2

main.o: main.cpp
	g++ -c main.cpp

Media.o: Media.cpp Media.h
	g++ -c Media.cpp

clean:
	rm -f *.o
	rm -fr project2.dSYM

run:    clean project2 
	./project2.exe
