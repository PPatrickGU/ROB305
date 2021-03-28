# **ROB305: Multitask design and real time operating system**

***author: Zhaoyi Guan & Dajing Gu***

## TD1

### a
For the Computer:

```
cd TD1/src
make

```
For the Raspberry, after execution of the toolchain:
```
$CXX -Wall -Wextra main_td1a.cpp TimeSpec.cpp -lrt -o TD1a.out
sshpass -p root scp *.out root@192.168.50.42:TD1/
./TD1a.out
```

### b
For the Computer:
```
cd TD1/src
g++ main_td1b.cpp SignalHandler.cpp -o td1b -lrt -Wall -Wextra ---> normal compilation
g++ -O3 main_td1b.cpp SignalHandler.cpp -o td1b -lrt -Wall -Wextra    ---> optimized compilation
./td1b
```

For the Raspberry, after execution of the toolchain:
```
$CXX -Wall -Wextra main_td1b.cpp SignalHandler.cpp -lrt -lpthread -o TD1b.out
sshpass -p root scp *.out root@192.168.50.42:TD1/
./TD1b.out
```

### c
For the Computer:
```
cd TD1/src
g++ main_td1c.cpp TimeSpec.cpp -lrt -Wall -Wextra -o td1c
./td1c <nLoops>
``` 

For the Raspberry, after execution of the toolchain:
```
$CXX -Wall -Wextra main_td1c.cpp TimeSpec.cpp -lrt -lpthread -o TD1c.out
sshpass -p root scp *.out root@192.168.50.42:TD1/
./TD1c.out <nLoops>
```
### d
For the Computer:
```
cd TD1/src
g++ main_td1d.cpp TimeSpec.cpp SignalHandler2.cpp -lrt -Wall -Wextra -o td1d
./td1d
```

For the Raspberry, after execution of the toolchain:
```
$CXX -Wall -Wextra main_td1d.cpp TimeSpec.cpp SignalHandler2.cpp -lrt -lpthread -o TD1d.out
sshpass -p root scp *.out root@192.168.50.42:TD1/
./TD1d.out
```

### e
For the Computer:
```
cd TD1/src
g++ main_td1e.cpp TimeSpec.cpp SignalHandler2.cpp -lrt -Wall -Wextra -o td1e
./td1e
```
For the Raspberry, after execution of the toolchain:
```
$CXX -Wall -Wextra main_td1e.cpp TimeSpec.cpp SignalHandler2.cpp -lrt -lpthread -o TD1e.out
sshpass -p root scp *.out root@192.168.50.42:TD1/
./TD1e.out
```

## TD2

### a
For the Computer:
```
cd TD2/src
g++ main_td2a.cpp TimeSpec.cpp -lrt -lpthread -Wall -Wextra -o td2a
./td2a <nLoops> <nTasks>
```
For the Raspberry, after execution of the toolchain:
```
$CXX -Wall -Wextra main_td2a.cpp TimeSpec.cpp -lrt -lpthread -o TD2a.out
sshpass -p root scp *.out root@192.168.50.42:TD2/
./TD2a.out <nLoops> <nTasks>
```

### b
For the Computer:
```
cd TD2/src
g++ main_td2b.cpp TimeSpec.cpp -lrt -lpthread -Wall -Wextra -o td2b

example:
./td2b <nLoops> <nTasks> <policy>
./td2b 3 4 SCHED_OTHER
./td2b 3 4 SCHED_RR
./td2b 3 4 SCHED_FIFO
```
For the Raspberry, after execution of the toolchain:
```
$CXX -Wall -Wextra main_td2b.cpp TimeSpec.cpp -lrt -lpthread -o TD2b.out
sshpass -p root scp *.out root@192.168.50.42:TD2/
./td2b <nLoops> <nTasks> <policy>

example:
./td2b 3 4 SCHED_OTHER
./td2b 3 4 SCHED_RR
./td2b 3 4 SCHED_FIFO
```
### c
For the Computer:
```
cd TD2/src
g++ main_td2c.cpp TimeSpec.cpp -lrt -lpthread -Wall -Wextra -o td2c
./td2c <nLoop> <nTasks> <policy> <protected>

example:
./td2c 3 4 0 protected
./td2c 3 4 1 protected
./td2c 3 4 2 protected
```
For the Raspberry, after execution of the toolchain:
```
$CXX -Wall -Wextra main_td2c.cpp TimeSpec.cpp -lrt -lpthread -o TD2c.out
sshpass -p root scp *.out root@192.168.50.42:TD2/

example:
./TD2c.out <nLoop> <nTasks> <policy> <protected>
./TD2c.out 3 4 0 protected
./TD2c.out 3 4 1 protected
./TD2c.out 3 4 2 protected
```
## TD3

### a
For the Computer:
```
cd TD3/src
g++ main_td3a.cpp TimeSpec.cpp Chrono.cpp -lrt -lpthread -Wall -Wextra -o td3a
./td3a
```
For the Raspberry, after execution of the toolchain:
```
$CXX -Wall -Wextra main_td3a.cpp TimeSpec.cpp Chrono.cpp -lrt -lpthread -o TD3a.out
sshpass -p root scp *.out root@192.168.50.42:TD3/
./TD3a.out
```

### b
For the Computer:
```
cd TD3/src
g++ main_td3b.cpp TimeSpec.cpp Timer.cpp CountDown.cpp PeriodicTimer.cpp -lrt -lpthread -Wall -Wextra -o td3b
./td3b
```
For the Raspberry, after execution of the toolchain:
```
$CXX -Wall -Wextra main_td3b.cpp TimeSpec.cpp Timer.cpp CountDown.cpp PeriodicTimer.cpp -lrt -lpthread -o TD3b.out
sshpass -p root scp *.out root@192.168.50.42:TD3/
./TD3b.out
```
### c
For the Computer:
```
cd TD3/src
g++ main_td3c.cpp TimeSpec.cpp Timer.cpp PeriodicTimer.cpp Looper.cpp CpuLoop.cpp Chrono.cpp Calibrator.cpp -lrt -lpthread -Wall -Wextra -o td3c
./td3c
```
For the Raspberry, after execution of the toolchain:
```
$CXX -Wall -Wextra main_td3c.cpp TimeSpec.cpp Timer.cpp PeriodicTimer.cpp Looper.cpp CpuLoop.cpp Chrono.cpp Calibrator.cpp -lrt -lpthread -Wno-psabi -o TD3c.out
sshpass -p root scp *.out root@192.168.50.42:TD3/
./TD3c.out
```
## TD4

### a
For the Computer:
```
cd TD4/src
g++ main_td4a.cpp Chrono.cpp Incr.cpp PosixThread.cpp Thread.cpp TimeSpec.cpp -lrt -lpthread -Wall -Wextra -o td4a
./td4a <nLoop> <nThreads> <policy>
```
```
In order to make it work for SCHED_RR and SCHED_FIFO we have to add sudo at the beginning of the compilation and execution
```
For the Raspberry, after execution of the toolchain:
```
$CXX -Wall -Wextra main_td4a.cpp Chrono.cpp Incr.cpp PosixThread.cpp Thread.cpp TimeSpec.cpp -lrt -lpthread -o TD4a.out
sshpass -p root scp *.out root@192.168.50.42:TD4/
./TD4a.out <nLoop> <nThreads> <policy>
```
### b
For the Computer:
```
cd TD4/src
g++ main_td4b.cpp Mutex.cpp Chrono.cpp IncrMutex.cpp PosixThread.cpp Thread.cpp TimeSpec.cpp Mutex/*.cpp -lrt -lpthread -Wall -Wextra -o td4b
./td4b <nLoop> <nThreads> <policy>
```
```
In order to make it work for SCHED_RR and SCHED_FIFO we have to add sudo at the beginning of the compilation and execution
```
For the Raspberry, after execution of the toolchain:
```
$CXX -Wall -Wextra main_td4b.cpp Mutex.cpp Chrono.cpp IncrMutex.cpp PosixThread.cpp Thread.cpp TimeSpec.cpp Mutex/*.cpp -lrt -lpthread -o TD4b.out
sshpass -p root scp *.out root@192.168.50.42:TD4/
./TD4b.out <nLoop> <nThreads> <policy>
```
### c
For the Computer:
```
cd TD4/src
g++ main_td4c.cpp Mutex.cpp Chrono.cpp Semaphore.cpp Consumer.cpp Productor.cpp PosixThread.cpp Thread.cpp TimeSpec.cpp Mutex/*.cpp -lrt -lpthread -Wall -Wextra -o td4c
./td4c <nProd> <nCons> <nItems>
```
For the Raspberry, after execution of the toolchain:
```
$CXX -Wall -Wextra main_td4c.cpp Mutex.cpp Chrono.cpp Semaphore.cpp Consumer.cpp Productor.cpp PosixThread.cpp Thread.cpp TimeSpec.cpp Mutex/*.cpp -lrt -lpthread -o TD4c.out
sshpass -p root scp *.out root@192.168.50.42:TD4/
./TD4c.out <nProd> <nCons> <nItems>
```
### d
For the Computer:
```
cd TD4/src
g++ main_td4d.cpp Mutex.cpp Chrono.cpp Fifo.hpp FifoConsumer.cpp FifoProductor.cpp PosixThread.cpp Thread.cpp TimeSpec.cpp Mutex/*.cpp -lrt -lpthread -Wall -Wextra -o td4d
./td4d <nProd> <nCons> <nItems>
```
For the Raspberry, after execution of the toolchain:
```
$CXX -Wall -Wextra main_td4d.cpp Mutex.cpp Chrono.cpp Fifo.hpp FifoConsumer.cpp FifoProductor.cpp PosixThread.cpp Thread.cpp TimeSpec.cpp Mutex/*.cpp -lrt -lpthread -o TD4d.out
sshpass -p root scp *.out root@192.168.50.42:TD4/
./TD4d.out <nProd> <nCons> <nItems>
```
## TD5
For the Computer:
```
cd TD5
g++ *.cpp Mutex/*.cpp -lrt -lpthread -Wall -Wextra -o td5
./td5
```
For the Raspberry, after execution of the toolchain:
```
$CXX -Wall -Wextra *.cpp Mutex/*.cpp -lrt -lpthread -Wno-psabi -o TD5.out
sshpass -p root scp *.out root@192.168.50.42:TD5/
./TD5.out
```
# ROB305
