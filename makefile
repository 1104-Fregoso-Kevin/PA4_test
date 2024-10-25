bank_simulation: main.o node.o customer.o event.o
	g++ -o bank_simulation main.o node.o customer.o event.o

main.o: main.cpp
	g++ -c main.cpp

node.o: node.cpp node.h
	g++ -c node.cpp

customer.o: customer.cpp customer.h
	g++ -c customer.cpp

event.o: event.cpp event.h
	g++ -c event.cpp

clean:
	rm -f *.o bank_simulation