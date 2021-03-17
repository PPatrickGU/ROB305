CFLAGS = -c -Wall -Werror -std=c++11

all: main_a 


OBJS_a = main_a.o timespec.o Chrono.o PosixThread.o Thread.o IncrThread.o 

main_a: $(OBJS_a)
	g++ $(OBJS_a) -o main_a -lpthread -lrt 

main_a.o: main_a.cpp 
	g++ $(CFLAGS) main_a.cpp -o main_a.o

timespec.o: timespec.cpp timespec.h
	g++ $(CFLAGS) timespec.cpp -o timespec.o

Chrono.o: Chrono.cpp Chrono.h
	g++ $(CFLAGS) Chrono.cpp -o Chrono.o

PosixThread.o: PosixThread.cpp PosixThread.h
	g++ $(CFLAGS) PosixThread.cpp -o PosixThread.o

Thread.o: Thread.cpp Thread.h
	g++ $(CFLAGS) Thread.cpp -o Thread.o

IncrThread.o: IncrThread.cpp IncrThread.h
	g++ $(CFLAGS) IncrThread.cpp -o IncrThread.o	

clean:
	rm -rf *.o main_a 
# 	rm -rf *.o 