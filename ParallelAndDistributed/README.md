
## Pthreads
共享内存，主要解决同步问题
### 线程
 * pthread_create() //创建线程
 * pthread_jion() //结束线程

### 互斥量
 * pthread_mutex_init()
 * pthread_mutex_destory()
 * pthread_mutex_lock() //获得锁
 * pthread_mutex_unlock() //释放锁

### 信号量 
 * sem_init() //初始化，设定信号量的数量
 * sem_destory()
 * sem_wait() //获得一个信号量
 * sem_post() //释放一个信号量

 
### 条件变量
 * pthread_cond_init() 
 * pthread_cond_destory()
 * pthread_cond_wait() //等待一个条件变量
 * pthread_cond_signal() //释放一个等待条件变量的线程
 * pthread_cond_broadcast() //释放所有等待条件变量的线程
 * 需要和互斥量配合使用，这个互斥量用来对条件进行同步，即修改条件时要加锁

 
### 路障
 * pthread_barrier_init() //初始化时，设定一个的数量
 * pthread_barrier_destory()
 * pthread_barrier_wait() //路障，当到达路障的线程的数量达到设定数量后，通过路障，否则等待

### 读写锁
 * pthread_rwlock_init()
 * pthread_rwlock_destory()
 * pthread_rwlock_rdloock() //获得一个读锁，其它线程还可以获得读锁，但是不可以获得写锁
 * pthread_rwlock_wrlock() //获得一个写锁，其它线程既不能获得读锁，也不能获得写锁
 * pthread_rwlock_unlock() //释放锁

* 基于线程，一个进程，多个线程
* 共享内存（通信的方式）
* 多CPU实现并行
* 适合一台计算机上的多核进行并行，在节点内的多核上使用线程级并行
（目前基于GPU的并行使用的是基于线程的并行，即共享内存，GPU中包含几百上千的ALU）
* 线程共享进程的上下文，包括虚拟地址空间和文件
* 私有逻辑寄存器、栈、指令寄存器PC
* 线程在多个核上的分布是由OS完成的


## MPI
分布式内存，主要解决通信问题，生成多个进程，每个进程都有自己独立的地址空间（进程与进程之间不存在全局变量）

### 初始化
 * MPI_Init() //初始化
 * MPI_Finalize() //结束
 * MPI_Comm_size() //进程的数量
 * MPI_Comm_rank() //进程的编号

### 点对点通信
  * MPI_Send() //发送，阻塞的或者缓冲的
  * MPI_Recv() //接收，阻塞的
  * MPI_Ssend() //阻塞式发送，用于测试缓冲机制是否安全
  * MPI_Sendrecv() //解决某个进程同时发收的问题时可能产生的死锁问题
 
### 集合通信
 * MPI_Bcast() //广播（不分块），一到多，一种数据发到多个进程
 * MPI_Rduce() //汇集并合并，多对一，多个进程的数据汇集到一个进程，汇集时使用某种操作进行合并
 * MPI_Allreduce() //汇集并合并，多对多，多个进程的数据汇集到多个进程，汇集时使用某种操作进行合并，每个进程都有一份汇集的数据
 * -
 * MPI_Scatter() //散射（分块），一到多，一种数据，分成多块，发到多个进程
 * MPI_Gather() //汇集并拼接，多对一，多个进程的数据汇集到一个进程，汇集时对数据进行拼接，比如拼接成一个数列
 * MPI_Allgather()//汇集并，多对多，多个进程的数据汇集到多个进程，汇集时对数据进行拼接 ，每个进程都有一份汇集的数据
 * -
 * MPI_Barrier() //路障

### 计时
 * GET_TIME() in time.h
 * MPI_Wtime()


* 基于进程
* 分布式的CPU和内存，多CPU，多内存
* 使用进程间的消息传递进行通信
* 适合不同的计算机间进行并行，在节点间进行进程并行
* 也可以单机多进程并行

### 参考资料
 * 教程：http://mpitutorial.com/
 * [使用ssh在多个机器上运行](http://stackoverflow.com/questions/15903408/specify-the-machines-running-program-using-mpi#)

## 并行编程
* 阻塞和非阻塞

一个操作对一个流程的影响，一个操作未完成是否会导致一个该操作所在的流程等待该操作完成，需要等待的是阻塞式的操作，不需要等待的是非阻塞式的操作。

* 同步和异步

多个流程之前的关系，某个流程需要其它流程达到某个节点后才能接着进行，这样的是需要同步的，否则是异步的。

* 数据划分
 * 块划分
 * 循环划分
 * 块-循环划分（按块进行循环，一个块包括多个数据单元）

* Foster方法
 * 划分计算任务单元，包括函数的划分和数据的划分，主要在于识别出可以并行的任务
 * 通信，确定任务间需要哪些通信
 * 聚合，根据需要，将一些小的计算任务单元聚合到一起，组合成一个大的任务单元
 * 分配，将设计好的计算任务分配到进程/线程中进行计算

## 《并行程序设计导论》
 * （美）Peter S. Pacheco，上海交大译
 * 介绍了并行编程的基础概念
 * 介绍了共享内存（多线程）编程接口Pthreads
 * 介绍了分布式内存（多进程）编程接口MPI
 * 介绍了OpenMP编程
 * 并行和分布式系统主要要解决的问题是通信和同步。

