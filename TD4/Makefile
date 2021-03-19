CFLAGS = -c -Wall -Werror -Wextra -std=c++11

all: main_td4a main_td4b main_td4c main_td4d


OBJS_a = main_td4a.o timespec.o Chrono.o PosixThread.o Thread.o IncrThread.o 

OBJS_b = main_td4b.o timespec.o Chrono.o PosixThread.o Thread.o IncrThread.o Mutex.o IncrMutexThread.o

OBJS_c = main_td4c.o timespec.o Chrono.o PosixThread.o Thread.o Mutex.o Semaphore.o SemaProducer.o SemaConsumer.o

OBJS_d = main_td4d.o timespec.o Chrono.o PosixThread.o Thread.o Mutex.o Fifo.o FifoProducer.o FifoConsumer.o

main_td4a: $(OBJS_a)
	g++ $(OBJS_a) -o main_td4a -lpthread -lrt 

main_td4b: $(OBJS_b)
	g++ $(OBJS_b) -o main_td4b -lpthread -lrt 

main_td4c: $(OBJS_c)
	g++ $(OBJS_c) -o main_td4c -lpthread -lrt 

main_td4d: $(OBJS_c)
	g++ $(OBJS_c) -o main_td4d -lpthread -lrt 

main_td4a.o: main_td4a.cpp 
	g++ $(CFLAGS) main_td4a.cpp -o main_td4a.o

main_td4b.o: main_td4b.cpp 
	g++ $(CFLAGS) main_td4b.cpp -o main_td4b.o

main_td4c.o: main_td4c.cpp 
	g++ $(CFLAGS) main_td4c.cpp -o main_td4c.o

main_td4d.o: main_td4d.cpp 
	g++ $(CFLAGS) main_td4d.cpp -o main_td4d.o

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

Mutex.o: Mutex.cpp Mutex.h
	g++ $(CFLAGS) Mutex.cpp -o Mutex.o	

IncrMutexThread.o: IncrMutexThread.cpp IncrMutexThread.h
	g++ $(CFLAGS) IncrMutexThread.cpp -o IncrMutexThread.o	

Semaphore.o: Semaphore.cpp Semaphore.h
	g++ $(CFLAGS) Semaphore.cpp -o Semaphore.o	

SemaProducer.o: SemaProducer.cpp SemaProducer.h
	g++ $(CFLAGS) SemaProducer.cpp -o SemaProducer.o	

SemaConsumer.o: SemaConsumer.cpp SemaConsumer.h
	g++ $(CFLAGS) SemaConsumer.cpp -o SemaConsumer.o	

Fifo.o: Fifo.hpp
	g++ $(CFLAGS) Fifo.hpp -o Fifo.o	

FifoProducer.o: FifoProducer.cpp FifoProducer.h
	g++ $(CFLAGS) FifoProducer.cpp -o FifoProducer.o	

FifoConsumer.o: FifoConsumer.cpp FifoConsumer.h
	g++ $(CFLAGS) FifoConsumer.cpp -o FifoConsumer.o	

clean:
	rm -rf *.o main_td4a main_td4b main_td4c main_td4d
# 	rm -rf *.o 