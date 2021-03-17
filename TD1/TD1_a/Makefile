CFLAGS = -c -Wall -Werror -std=c++11

all: main_a main_b main_c main_d

OBJS_a = main_a.o timespec.o

OBJS_b = main_b.o 

OBJS_c = main_c.o timespec.o

OBJS_d = main_d.o timespec.o

main_a: $(OBJS_a)
	g++ $(OBJS_a) -o main_a -lpthread -lrt 

main_b: $(OBJS_b)
	g++ $(OBJS_b) -o main_b -lpthread -lrt 

main_c: $(OBJS_c)
	g++ $(OBJS_c) -o main_c 

main_d: $(OBJS_d)
	g++ $(OBJS_d) -o main_d -lpthread -lrt 

main_a.o: main_a.cpp timespec.h
	g++ $(CFLAGS) main_a.cpp -o main_a.o

main_c.o: main_c.cpp timespec.h
	g++ $(CFLAGS) main_c.cpp -o main_c.o

main_d.o: main_d.cpp timespec.h
	g++ $(CFLAGS) main_d.cpp -o main_d.o

timespec.o: timespec.cpp timespec.h
	g++ $(CFLAGS) timespec.cpp -o timespec.o

clean:
	rm -rf *.o main_a main_b main_c main_d