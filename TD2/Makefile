CFLAGS = -c -Wall -Werror -std=c++11

all: main_td2a main_td2b main_td2c

OBJS_a = main_td2a.o 

OBJS_b = main_td2b.o timespec.o

OBJS_c = main_td2c.o timespec.o

main_td2a: $(OBJS_a)
	g++ $(OBJS_a) -o main_td2a -lpthread -lrt 

main_td2b: $(OBJS_b)
	g++ $(OBJS_b) -o main_td2b -lpthread -lrt 

main_td2c: $(OBJS_c)
	g++ $(OBJS_c) -o main_td2c -lpthread -lrt 

main_td2a.o: main_td2a.cpp 
	g++ $(CFLAGS) main_td2a.cpp -o main_td2a.o

main_td2b.o: main_td2b.cpp timespec.h
	g++ $(CFLAGS) main_td2b.cpp -o main_td2b.o

main_td2c.o: main_td2c.cpp timespec.h
	g++ $(CFLAGS) main_td2c.cpp -o main_td2c.o	

timespec.o: timespec.cpp timespec.h
	g++ $(CFLAGS) timespec.cpp -o timespec.o

clean:
	rm -rf *.o main_td2a main_td2b main_td2c