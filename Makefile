CC = g++ -g
exe_file = a.out
$(exe_file): driver.o bees.o ants.o user.o insect.o no_class.o
	$(CC) driver.o bees.o ants.o user.o insect.o no_class.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c driver.cpp
bees.o: bees.cpp
	$(CC) -c bees.cpp
ants.o: ants.cpp
	$(CC) -c ants.cpp
user.o: user.cpp
	$(CC) -c user.cpp
insect.o: insect.cpp
	$(CC) -c insect.cpp
no_class.o: no_class.cpp
	$(CC) -c no_class.cpp
clean:
	rm -f *.out *.o $(exe_file)
