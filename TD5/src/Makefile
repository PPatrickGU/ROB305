CFLAGS = -c -Wall -Werror -Wextra -std=c++11

all: main_td5

OBJS =  main_td5.o timespec.o Chrono.o Calibrator.o PosixThread.o Thread.o Looper.o  CpuLoop.o Mutex.o CpuLoopMutex.o Timer.o PeriodicTimer.o

main_td5: $(OBJS)
	g++ $(OBJS) -o main_td5 -lpthread -lrt 
	rm -rf *.o 

main_td5.o: main_td5.cpp 
	g++ $(CFLAGS) main_td5.cpp -o main_td5.o

timespec.o: timespec.cpp timespec.h
	g++ $(CFLAGS) timespec.cpp -o timespec.o

Timer.o: Timer.cpp Timer.h
	g++ $(CFLAGS) Timer.cpp -o Timer.o

PeriodicTimer.o: PeriodicTimer.cpp PeriodicTimer.h
	g++ $(CFLAGS) PeriodicTimer.cpp -o PeriodicTimer.o

Chrono.o: Chrono.cpp Chrono.h
	g++ $(CFLAGS) Chrono.cpp -o Chrono.o

Calibrator.o: Calibrator.cpp Calibrator.h
	g++ $(CFLAGS) Calibrator.cpp -o Calibrator.o

PosixThread.o: PosixThread.cpp PosixThread.h
	g++ $(CFLAGS) PosixThread.cpp -o PosixThread.o

Thread.o: Thread.cpp Thread.h
	g++ $(CFLAGS) Thread.cpp -o Thread.o

Looper.o: Looper.cpp Looper.h
	g++ $(CFLAGS) Looper.cpp -o Looper.o

CpuLoop.o: CpuLoop.cpp CpuLoop.h
	g++ $(CFLAGS) CpuLoop.cpp -o CpuLoop.o	

Mutex.o: Mutex.cpp Mutex.h
	g++ $(CFLAGS) Mutex.cpp -o Mutex.o	

CpuLoopMutex.o: CpuLoopMutex.cpp CpuLoopMutex.h
	g++ $(CFLAGS) CpuLoopMutex.cpp -o CpuLoopMutex.o		

	

clean:
	rm -rf *.o main_td5
# 	rm -rf *.o 