CFLAGS = -c -Wall -Werror -std=c++11

all: main_a main_b

OBJS_a = main_a.o 

OBJS_b = main_b.o timespec.o


main_a: $(OBJS_a)
	g++ $(OBJS_a) -o main_a -lpthread -lrt 

main_b: $(OBJS_b)
	g++ $(OBJS_b) -o main_b -lpthread -lrt 

main_a.o: main_a.cpp 
	g++ $(CFLAGS) main_a.cpp -o main_a.o

main_b.o: main_b.cpp timespec.h
	g++ $(CFLAGS) main_b.cpp -o main_b.o

timespec.o: timespec.cpp timespec.h
	g++ $(CFLAGS) timespec.cpp -o timespec.o

clean:
	rm -rf *.o main_a main_b