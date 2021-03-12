CFLAGS = -c -Wall -Werror -std=c++11

all: main_a main_b main_c


OBJS_a = main_a.o timespec.o Chrono.o

OBJS_b = main_b.o timespec.o Timer.o PeriodicTimer.o CountDown.o

OBJS_c = main_c.o timespec.o Timer.o PeriodicTimer.o Looper.o Calibrator.o CpuLoop.o


main_a: $(OBJS_a)
	g++ $(OBJS_a) -o main_a -lpthread -lrt 

main_b: $(OBJS_b)
	g++ $(OBJS_b) -o main_b -lpthread -lrt 

main_c: $(OBJS_c)
	g++ $(OBJS_c) -o main_c -lpthread -lrt 

main_a.o: main_a.cpp 
	g++ $(CFLAGS) main_a.cpp -o main_a.o

main_b.o: main_b.cpp 
	g++ $(CFLAGS) main_b.cpp -o main_b.o

main_c.o: main_c.cpp 
	g++ $(CFLAGS) main_c.cpp -o main_c.o

timespec.o: timespec.cpp timespec.h
	g++ $(CFLAGS) timespec.cpp -o timespec.o

Chrono.o: Chrono.cpp Chrono.h
	g++ $(CFLAGS) Chrono.cpp -o Chrono.o

Timer.o: Timer.cpp Timer.h
	g++ $(CFLAGS) Timer.cpp -o Timer.o

PeriodicTimer.o: PeriodicTimer.cpp PeriodicTimer.h
	g++ $(CFLAGS) PeriodicTimer.cpp -o PeriodicTimer.o

CountDown.o: CountDown.cpp CountDown.h
	g++ $(CFLAGS) CountDown.cpp -o CountDown.o	

Looper.o: Looper.cpp Looper.h
	g++ $(CFLAGS) Looper.cpp -o Looper.o	

Calibrator.o: Calibrator.cpp Calibrator.h
	g++ $(CFLAGS) Calibrator.cpp -o Calibrator.o	

CpuLooper.o: CpuLoop.cpp CpuLoop.h
	g++ $(CFLAGS) CpuLoop.cpp -o CpuLoop.o	

clean:
	rm -rf *.o main_a main_b main_c
# 	rm -rf *.o 