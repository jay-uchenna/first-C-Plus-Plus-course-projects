all: drug

drug: main.o dosage_check.o
	g++ -std=c++14 -Wall -o drug main.o dosage_check.o

main.o: main.cpp
	g++ -std=c++14 -c -Wall main.cpp

dosage_check.o: dosage_check.cpp
	g++ -std=c++14 -c -Wall dosage_check.cpp

clean: 
	rm main.o
	rm dosage_check.o 