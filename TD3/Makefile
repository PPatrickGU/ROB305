CFLAGS = -c -Wall -Werror -Wextra -std=c++11

all: main_td3a main_td3b main_td3c


OBJS_a = main_td3a.o timespec.o Chrono.o

OBJS_b = main_td3b.o timespec.o Timer.o PeriodicTimer.o CountDown.o

OBJS_c = main_td3c.o timespec.o Timer.o PeriodicTimer.o Looper.o Calibrator.o CpuLoop.o


main_td3a: $(OBJS_a)
	g++ $(OBJS_a) -o main_td3a -lpthread -lrt 

main_td3b: $(OBJS_b)
	g++ $(OBJS_b) -o main_td3b -lpthread -lrt 

main_td3c: $(OBJS_c)
	g++ $(OBJS_c) -o main_td3c -lpthread -lrt 

main_td3a.o: main_td3a.cpp 
	g++ $(CFLAGS) main_td3a.cpp -o main_td3a.o

main_td3b.o: main_td3b.cpp 
	g++ $(CFLAGS) main_td3b.cpp -o main_td3b.o

main_td3c.o: main_td3c.cpp 
	g++ $(CFLAGS) main_td3c.cpp -o main_td3c.o

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
	rm -rf *.o main_td3a main_td3b main_td3c
# 	rm -rf *.o 