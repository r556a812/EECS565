project1: main.o VigenereCipher.o Node.o
	g++ -std=c++11 -g -Wall main.o VigenereCipher.o Node.o -o project1
main.o: main.cpp VigenereCipher.h Node.h
	g++ -std=c++11 -g -Wall -c main.cpp
VigenereCipher.o: VigenereCipher.h VigenereCipher.cpp
	g++ -std=c++11 -g -Wall -c VigenereCipher.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
clean:
	rm *.o project1
	echo clean done
