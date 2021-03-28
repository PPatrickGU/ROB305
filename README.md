# **ROB305: Multitask design and real time operating system**

*Author : Zhaoyi Guan & Dajing Gu*

## TD1
### TD1-a
For PC:

```
cd TD1/src
make
./main_td1a
```

For Raspberry PI:
```
$CXX -Wall -Wextra main_td1a.cpp timespec.cpp -lrt -o main_td1a.rpi2
sshpass -p root scp *.rpi2 root@192.168.50.47:TD1/
./main_td1a.rpi2
```

### TD1-b
For PC:
```
cd TD1/src
make
./main_td1b
```

For Raspberry PI:
```
$CXX -Wall -Wextra main_td1b.cpp -lrt -lpthread -o main_td1b.rpi2
sshpass -p root scp *.rpi2 root@192.168.50.47:TD1/
./main_td1b.rpi2
```

### TD1-c
For PC:
```
cd TD1/src
make
./main_td1c <nLoops>
``` 

For Raspberry PI:
```
$CXX -Wall -Wextra main_td1c.cpp timespec.cpp -lrt -lpthread -o main_td1c.rpi2
sshpass -p root scp *.rpi2 root@192.168.50.47:TD1/
./main_td1c.rpi2 <nLoops>
```
### TD1-d
For PC:
```
cd TD1/src
make
./main_td1d
```

For Raspberry PI:
```
$CXX -Wall -Wextra main_td1d.cpp timespec.cpp -lrt -lpthread -o main_td1d.rpi2
sshpass -p root scp *.rpi2 root@192.168.50.47:TD1/
./main_td1d.rpi2
```

### TD1-e
For PC:
```
cd TD1/src
make
./main_td1e
```

For Raspberry PI:
```
$CXX -Wall -Wextra main_td1e.cpp timespec.cpp -lrt -lpthread -o main_td1e.rpi2
sshpass -p root scp *.rpi2 root@192.168.50.47:TD1/
./main_td1e.rpi2
```

## TD2

### TD2-a
For PC:
```
cd TD2/src
make
./main_td2a <nLoops> <nTasks>
```
For Raspberry PI:
```
$CXX -Wall -Wextra main_td2a.cpp timespec.cpp -lrt -lpthread -o main_td2a.rpi2
sshpass -p root scp *.rpi2 root@192.168.50.47:TD2/
./main_td2a.rpi2 <nLoops> <nTasks>
```

### TD2-b
For PC:
```
cd TD2/src
make
./main_td2b <nLoops> <nTasks> <policy>
for example:
./main_td2b <nLoops> <nTasks> <policy>
./main_td2b 3 4 SCHED_OTHER
./main_td2b 3 4 SCHED_RR
./main_td2b 3 4 SCHED_FIFO
```
For Raspberry PI:
```
$CXX -Wall -Wextra main_td2b.cpp timespec.cpp -lrt -lpthread -o main_td2b.rpi2
sshpass -p root scp *.rpi2 root@192.168.50.47:TD2/
./main_td2b.rpi2 <nLoops> <nTasks> <policy>

example:
./main_td2b.rpi2 50 100 SCHED_OTHER
./main_td2b.rpi2 50 100 SCHED_RR
./main_td2b.rpi2 50 100 SCHED_FIFO
```
### TD2-c
For PC:
```
cd TD2/src
make
./main_td2c <nLoop> <nTasks> <policy> <ifProtected>

for example:
./main_td2c 50 100 0 1
./main_td2c 50 100 1 0
./main_td2c 50 100 2 1
```
For Raspberry PI:
```
$CXX -Wall -Wextra main_td2c.cpp timespec.cpp -lrt -lpthread -o main_td2c.rpi2
sshpass -p root scp *.rpi2 root@192.168.50.47:TD2/
./main_td2crpi2 <nLoop> <nTasks> <policy> <ifProtected>

example:
./main_td2c.rpi2 50 100 0 1
./main_td2c.rpi2 50 100 1 0
./main_td2c.rpi2 50 100 2 1
```

## TD3

### TD3-a
For PC:
```
cd TD3/src
make
./main_td3a
```
For Raspberry PI:
```
$CXX -Wall -Wextra main_td3a.cpp timespec.cpp Chrono.cpp -lrt -lpthread -o main_td3a.rpi2
sshpass -p root scp *.rpi2 root@192.168.50.47:TD3/
./main_td3a.rpi2
```

### TD3-b
For PC:
```
cd TD3/src
make
./main_td3b
```
For Raspberry PI:
```
$CXX -Wall -Wextra main_td3b.cpp timespec.cpp Timer.cpp CountDown.cpp PeriodicTimer.cpp -lrt -lpthread -o main_td3b.rpi2
sshpass -p root scp *.rpi2 root@192.168.50.47:TD3/
./main_td3a..rpi2
```
### TD3-c
For PC:
```
cd TD3/src
make
./main_td3c
```
For Raspberry PI:
```
$CXX -Wall -Wextra main_td3c.cpp timespec.cpp Timer.cpp PeriodicTimer.cpp Looper.cpp CpuLoop.cpp Chrono.cpp Calibrator.cpp -lrt -lpthread -Wno-psabi -o TD3c.rpi2
sshpass -p root scp *.rpi2 root@192.168.50.47:TD3/
./main_td3c.rpi2
```

## TD4
### TD4-a
For PC:
```
cd TD4/src
make
./main_td4a <nLoop> <nThreads> <policy>
```


For Raspberry PI:
```
$CXX -Wall -Wextra main_td4a.cpp Chrono.cpp Incr.cpp PosixThread.cpp Thread.cpp timespec.cpp -lrt -lpthread -o main_td4a.rpi2
sshpass -p root scp *.rpi2 root@192.168.50.47:TD4/
./main_td4a.rpi2.rpi2 <nLoop> <nThreads> <policy>
```
### TD4-b
For PC:
```
cd TD4/src
make
./main_td4b <nLoop> <nThreads> <policy>
```

For Raspberry PI:
```
$CXX -Wall -Wextra main_td4b.cpp Mutex.cpp Chrono.cpp IncrMutex.cpp PosixThread.cpp Thread.cpp timespec.cpp Mutex/*.cpp -lrt -lpthread -o main_td4b.rpi2
sshpass -p root scp *.rpi2 root@192.168.50.47:TD4/
./main_td4b.rpi2 <nLoop> <nThreads> <policy>
```
### TD4-c
For PC:
```
cd TD4/src
make
./main_td4c <nProd> <nCons> <nItems>
```

For Raspberry PI:
```
$CXX -Wall -Wextra main_td4c.cpp Mutex.cpp Chrono.cpp Semaphore.cpp Consumer.cpp Producer.cpp PosixThread.cpp Thread.cpp SemaProducer.cpp SemaConsumer.cpp timespec.cpp Mutex.cpp -lrt -lpthread -o main_td4c.rpi2
sshpass -p root scp *.rpi2 root@192.168.50.47:TD4/
./main_td4c.rpi2 <nProd> <nCons> <nItems>
```
### TD4-d
For PC:
```
cd TD4/src
make
./main_td4d <nProd> <nCons> <nItems>
```
For Raspberry PI:
```
$CXX -Wall -Wextra main_td4d.cpp Mutex.cpp Chrono.cpp Fifo.hpp FifoConsumer.cpp FifoProducer.cpp PosixThread.cpp Thread.cpp timespec.cpp Mutex.cpp -lrt -lpthread -o main_td4d.rpi2
sshpass -p root scp *.rpi2 root@192.168.50.47:TD4/
./main_td4.rpi2 <nProd> <nCons> <nItems>
```
## TD5
For PC:
```
cd TD5
make
./main_td5
```
For the Raspberry, after execution of the toolchain:
```
$CXX -Wall -Wextra *.cpp Mutex/*.cpp -lrt -lpthread -Wno-psabi -o main_td5.rpi2
sshpass -p root scp *.rpi2 root@192.168.50.47:TD5/
./main_td5.rpi2
```

