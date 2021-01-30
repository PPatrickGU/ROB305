CFLAGS = -g -Wall -Werror -std=c++11

OBJS_a = main_a.o timespec.o

main_a: $(OBJS_a)
	gcc $(OBJS_a) -o main_a

main_a.o: main_a.cpp timespec.o
	g++ $(CFLAGS) main_a.cpp timespec.h -o main_a.o

timespec.o : timespec.cpp timespec.h
	g++ $(CFLAGS) timespec.cpp timespec.h -o timespec.o

clean:
	rm irf *.o main_a


