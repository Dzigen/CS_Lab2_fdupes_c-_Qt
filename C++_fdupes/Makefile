OBJECTS=fdupes_realisation_main.o dir_iterator.o file_size_hash.o insert_in_data.o comparing_files.o insert_in_duplicats.o user_interface.o

HEADER=dir_iterator_size_hash_insert.h

fdupes: $(OBJECTS) 
	g++ -o fdupes $(OBJECTS) -lstdc++fs

fdupes_realisation_main.o: fdupes_realisation_main.cpp $(HEADER)
	g++ -c fdupes_realisation_main.cpp $(HEADER)

dir_iterator.o: dir_iterator.cpp $(HEADER)
	g++ -std=c++17 -c dir_iterator.cpp $(HEADER) -lstdc++fs

file_size_hash.o: file_size_hash.cpp $(HEADER)
	g++ -c file_size_hash.cpp $(HEADER)

insert_in_data.o: insert_in_data.cpp $(HEADER)
	g++ -c insert_in_data.cpp $(HEADER)

comparing_files: comparing_files.cpp $(HEADER)
	g++ -c comparing_files.cpp $(HEADER)

comparing_files.o: comparing_files.cpp $(HEADER)
	g++ -c comparing_files.cpp $(HEADER)

insert_in_duplicats.o: insert_in_duplicats.cpp $(HEADER)
	g++ -c insert_in_duplicats.cpp $(HEADER)

user_interface.o: user_interface.cpp $(HEADER)
	g++ -std=c++17 -c user_interface.cpp $(HEADER) -lstdc++fs

clean :
	rm fdupes *.o
