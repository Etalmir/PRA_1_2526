bin/testListArray: testListArray.cpp ListArray.o List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.o

ListArray.o: ListArray.cpp List.h
	g++ -c ListArray.cpp

clean:
	rm -f *.o *.gch bin 

