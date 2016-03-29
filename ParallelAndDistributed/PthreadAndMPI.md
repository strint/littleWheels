## Pthread
共享内存，主要解决同步问题
* 线程
 * pthread_create() //创建线程
 * pthread_jion() //结束线程

* 互斥量
 * pthread_mutex_init()
 * pthread_mutex_destory()
 * pthread_mutex_lock() //获得锁
 * pthread_mutex_unlock() //释放锁

* 信号量 
 * sem_init() //初始化，设定信号量的数量
 * sem_destory()
 * sem_wait() //获得一个信号量
 * sem_post() //释放一个信号量

 
* 条件变量
 * pthread_cond_init() 
 * pthread_cond_destory()
 * pthread_cond_wait() //等待一个条件变量
 * pthread_cond_signal() //释放一个等待条件变量的线程
 * pthread_cond_broadcast() //释放所有等待条件变量的线程
 * 需要和互斥量配合使用，这个互斥量用来对条件进行同步，即修改条件时要加锁

 
* 路障
 * pthread_barrier_init() //初始化时，设定一个的数量
 * pthread_barrier_destory()
 * pthread_barrier_wait() //路障，当到达路障的线程的数量达到设定数量后，通过路障，否则等待

* 读写锁
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
* 初始化
 * MPI_Init() //初始化
 * MPI_Finalize() //结束
 * MPI_Comm_size() //进程的数量
 * MPI_Comm_rank() //进程的编号

* 点对点通信
  * MPI_Send() //发送，阻塞的或者缓冲的
  * MPI_Recv() //接收，阻塞的
  * MPI_Ssend() //阻塞式发送，用于测试缓冲机制是否安全
  * MPI_Sendrecv() //解决某个进程同时发收的问题时可能产生的死锁问题
 
* 集合通信
 * MPI_Bcast() //广播（不分块），一到多，一种数据发到多个进程
 * MPI_Rduce() //汇集并合并，多对一，多个进程的数据汇集到一个进程，汇集时使用某种操作进行合并
 * MPI_Allreduce() //汇集并合并，多对多，多个进程的数据汇集到多个进程，汇集时使用某种操作进行合并，每个进程都有一份汇集的数据
 * -
 * MPI_Scatter() //散射（分块），一到多，一种数据，分成多块，发到多个进程
 * MPI_Gather() //汇集并拼接，多对一，多个进程的数据汇集到一个进程，汇集时对数据进行拼接，比如拼接成一个数列
 * MPI_Allgather()//汇集并，多对多，多个进程的数据汇集到多个进程，汇集时对数据进行拼接 ，每个进程都有一份汇集的数据
 * -
 * MPI_Barrier() //路障

* 计时
 * GET_TIME() in time.h
 * MPI_Wtime()


* 基于进程
* 分布式的CPU和内存，多CPU，多内存
* 使用进程间的消息传递进行通信
* 适合不同的计算机间进行并行，在节点间进行进程并行
* 也可以单机多进程并行


* 数据划分
 * 块划分
 * 循环划分
 * 块-循环划分

* 参考资料
 * 教程：http://mpitutorial.com/
 * [使用ssh在多个机器上运行](http://stackoverflow.com/questions/15903408/specify-the-machines-running-program-using-mpi#)

## 例子
https://computing.llnl.gov/tutorials/pthreads/samples/mpithreads_both.c

```cpp
/*****************************************************************************
* FILE: mpithreads_both.c
* DESCRIPTION:
*   This program illustrates the simultaneous use of MPI and Pthreads. 
*   It is essentially a simple combination of a code that implements a dot 
*   product using threads, and a code that uses MPI for the same purpose. 
*   It is the last of four codes used to show the progression from a serial 
*   program to a hybrid MPI/Pthreads program. The other relevant codes are:
*      - mpithreads_serial.c   - The serial version
*      - mpithreads_threads.c  - A shared memory programming model using
*          Pthreads
*      - mpithreads_mpi.c - A distributed memory programming model with MPI
*   All the internode MPI communication is done by the main thread on each 
*   node - the other threads within that node need not even be aware that 
*   internode communication is being performed. Use of the SPMD model for 
*   MPI was chosen for convenience, with replication of the main data on 
*   all nodes. A more memory efficient implementation would be advisable 
*   for larger data sets.  This is the simplest model for mixed MPI/Pthreads 
*   programming. 
* SOURCE: Vijay Sonnad, IBM
* LAST REVISED:  01/29/09 Blaise Barney
******************************************************************************/
#include "mpi.h" //MPI头文件
#include <pthread.h> //pthread头文件
#include <stdio.h>
#include <stdlib.h>
 
/*  
This structure has been changed slightly from the previous cases
to include the number of threads per node. 
*/
 
typedef struct
 {
   double      *a; //数组指针
   double      *b; //数组指针
   double     sum; //点积
   int     veclen; //数组的长度
   int   numthrds; //线程的数
 } DOTDATA;
 
/* Define globally accessible variables and a mutex */
//进程内、线程间共享的全局变量
#define MAXTHRDS 8 //最大线程数
#define VECLEN 100 //数组的长度
DOTDATA dotstr; //定义一个DOTDATA
pthread_t callThd[MAXTHRDS]; //定义一组线程句柄
pthread_mutex_t mutexsum; //给sum定义一个互斥量
 
/*
The function dotprod has only minor changes from the code 
that used threads or MPI.  
*/
//线程函数 
void *dotprod(void *arg)
{
 
   /* Define and use local variables for convenience */
 
   int i, start, end, len, numthrds, myid;
   long mythrd;
   double mysum, *x, *y;
 
   /*
   The number of threads and nodes defines the beginning 
   and ending for the dot product; each  thread does work 
   on a vector of length VECLENGTH.
   */
 
   mythrd = (long)arg;
   MPI_Comm_rank (MPI_COMM_WORLD, &myid);
 
   numthrds = dotstr.numthrds;
   len = dotstr.veclen;
   start = myid*numthrds*len + mythrd*len;
   end   = start + len;
   x = dotstr.a;
   y = dotstr.b;
 
   /*
   Perform the dot product and assign result
   to the appropriate variable in the structure. 
   */
 
   mysum = 0;
   for (i=start; i<end ; i++) 
    {
      mysum += (x[i] * y[i]);
    }
 
   /*
   Lock a mutex prior to updating the value in the structure, and unlock it 
   upon updating.
   */
   pthread_mutex_lock (&mutexsum);
   printf("Task %d thread %ld adding partial sum of %f to node sum of %f\n",
           myid, mythrd, mysum, dotstr.sum);
   dotstr.sum += mysum;
   pthread_mutex_unlock (&mutexsum);
 
   pthread_exit((void*)0);
}
 
/* 
As before,the main program does very little computation. It creates
threads on each node and the main thread does all the MPI calls. 
*/
//一个进程的main函数 
int main(int argc, char* argv[])
{
int len=VECLEN, myid, numprocs; 
long i;
int nump1, numthrds;
double *a, *b;
double nodesum, allsum;
void *status;
pthread_attr_t attr;
 
/* MPI Initialization */
MPI_Init (&argc, &argv);
MPI_Comm_size (MPI_COMM_WORLD, &numprocs); //进程数
MPI_Comm_rank (MPI_COMM_WORLD, &myid); //进程id
 
/* Assign storage and initialize values */
numthrds=MAXTHRDS; //设定线程的数量
a = (double*) malloc (numprocs*numthrds*len*sizeof(double)); //分配数组的存储空间
b = (double*) malloc (numprocs*numthrds*len*sizeof(double)); //分配数组的存储空间

//将数组存储空间初始化   
for (i=0; i<len*numprocs*numthrds; i++) {
  a[i]=1;
  b[i]=a[i];
  }
 
dotstr.veclen = len; 
dotstr.a = a; 
dotstr.b = b; 
dotstr.sum=0;
dotstr.numthrds=MAXTHRDS;
   
/* 
Create thread attribute to specify that the main thread needs
to join with the threads it creates.
*/
pthread_attr_init(&attr );
pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
 
/* Create a mutex */
pthread_mutex_init (&mutexsum, NULL);
 
/* Create threads within this node to perform the dotproduct  */
for(i=0;i<numthrds;i++) {
  pthread_create( &callThd[i], &attr, dotprod, (void *)i); 
  }
 
/* Release the thread attribute handle as it is no longer needed */
pthread_attr_destroy(&attr );
 
/* Wait on the other threads within this node */
for(i=0;i<numthrds;i++) {
  pthread_join( callThd[i], &status);
  }
 
nodesum = dotstr.sum;
printf("Task %d node sum is %f\n",myid, nodesum);
 
/* After the dot product, perform a summation of results on each node */
MPI_Reduce (&nodesum, &allsum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
 
if (myid == 0)  
printf ("Done. MPI with threads version: sum  =  %f \n", allsum);
MPI_Finalize();
free (a);
free (b);
pthread_mutex_destroy(&mutexsum);
exit (0);
}   
```
