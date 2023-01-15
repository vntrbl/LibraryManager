lib: main.o patron.o patrons.o book.o loan.o loans.o libraryitem.o libraryitems.o audio.o dvd.o
	g++ main.o patron.o patrons.o book.o loan.o loans.o libraryitem.o libraryitems.o audio.o dvd.o -o lib

main.o: main.cpp patrons.h loan.h loans.h libraryitems.h
	g++ -c main.cpp

patron.o: patron.cpp patron.h
	g++ -c patron.cpp

patrons.o: patrons.cpp patrons.h patron.h libraryitem.h
	g++ -c patrons.cpp

loan.o: loan.cpp loan.h
	g++ -c loan.cpp

loans.o: loans.cpp loans.h patrons.h loan.h libraryitems.h
	g++ -c loans.cpp

libraryitem.o: libraryitem.cpp libraryitem.h
	g++ -c libraryitem.cpp

libraryitems.o: libraryitems.cpp libraryitem.h book.h audio.h dvd.h libraryitems.h
	g++ -c libraryitems.cpp

book.o: book.cpp book.h libraryitem.h
	g++ -c book.cpp

audio.o: audio.cpp audio.h libraryitem.h
	g++ -c audio.cpp

dvd.o: dvd.cpp dvd.h libraryitem.h
	g++ -c dvd.cpp

clean:
	rm *.o lib