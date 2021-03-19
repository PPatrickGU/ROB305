CFLAGS = -c -Wall -Werror -Wextra -std=c++11

all: main_td1a main_td1b main_td1c main_td1d

OBJS_a = main_td1a.o timespec.o

OBJS_b = main_td1b.o 

OBJS_c = main_td1c.o timespec.o

OBJS_d = main_td1d.o timespec.o

main_td1a: $(OBJS_a)
	g++ $(OBJS_a) -o main_td1a -lpthread -lrt 

main_td1b: $(OBJS_b)
	g++ $(OBJS_b) -o main_td1b -lpthread -lrt 

main_td1c: $(OBJS_c)
	g++ $(OBJS_c) -o main_td1c -lpthread -lrt 

main_td1d: $(OBJS_d)
	g++ $(OBJS_d) -o main_td1d -lpthread -lrt 

main_td1a.o: main_td1a.cpp timespec.h
	g++ $(CFLAGS) main_td1a.cpp -o main_td1a.o

main_td1c.o: main_td1c.cpp timespec.h
	g++ $(CFLAGS) main_td1c.cpp -o main_td1c.o

main_td1d.o: main_td1d.cpp timespec.h
	g++ $(CFLAGS) main_td1d.cpp -o main_td1d.o

timespec.o: timespec.cpp timespec.h
	g++ $(CFLAGS) timespec.cpp -o timespec.o

clean:
	rm -rf *.o main_td1a main_td1b main_td1c main_td1d