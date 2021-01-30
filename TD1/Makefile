CFLAGS = -c -Wall -Werror -std=c++11

all: main_a main_c
OBJS_a = main_a.o timespec.o

OBJS_c = main_c.o timespec.o

main_a: $(OBJS_a)
	g++ $(OBJS_a) -o main_a 

main_c: $(OBJS_c)
	g++ $(OBJS_c) -o main_c 

main_a.o: main_a.cpp timespec.h
	g++ $(CFLAGS) main_a.cpp -o main_a.o

main_c.o: main_a.cpp timespec.h
	g++ $(CFLAGS) main_c.cpp -o main_c.o

timespec.o: timespec.cpp timespec.h
	g++ $(CFLAGS) timespec.cpp -o timespec.o

clean:
	rm -rf *.o main_a main_b