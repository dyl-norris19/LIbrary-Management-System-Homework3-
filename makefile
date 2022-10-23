bruh.exe: main.o book.o books.o patron.o patrons.o loan.o loans.o
	g++ main.o book.o books.o patron.o patrons.o loan.o loans.o -o bruh.exe

main.o: main.cpp books.h patrons.h loans.h
	g++ -c main.cpp

books.o: books.cpp books.h
	g++ -c books.cpp

patrons.o: patrons.cpp patrons.h
	g++ -c patrons.cpp

loans.o: loans.cpp loans.h
	g++ -c loans.cpp

book.o: book.cpp book.h
	g++ -c book.cpp

patron.o: patron.cpp patron.h
	g++ -c patron.cpp

loan.o: loan.cpp loan.h patrons.h books.h
	g++ -c loan.cpp

clean:
	rm *.o bruh.exe