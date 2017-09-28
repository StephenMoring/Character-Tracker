#Stephen Moring

main.x : proj1.o stat.o
	g++ -o main.x proj1.o stat.o

proj1.o : proj1.cpp stat.o
	g++ -c proj1.cpp

stat.o : stat.cpp
	g++ -c stat.cpp

make clean:
	rm *.o
	rm main.x
