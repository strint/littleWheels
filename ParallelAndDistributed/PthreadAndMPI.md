## Pthread
共享内存，主要解决同步问题
* 线程
 * pthread_create()
 * pthread_jion()

* 互斥量
 * pthread_mutex_init()
 * _destory()
 * _post()
 * _wait()
 
* 条件变量
 * pthread_cond_init()
 * _destory()
 * _signal()
 * _broadcast()
 * _wait()
 
* 路障
 * pthread_barrier_init()
 * _destory()
 * _wait()

* 读写锁
 * pthread_rwlock_init()
 * _destory()
 * rdloock()
 * wrlock()
 * unlock()

## MPI
分布式内存，主要解决通信问题
* 初始化
 * MPI_Init() //初始化
 * MPI_Finalize() //结束
 * MPI_Comm_size() //进程的数量
 * MPI_Comm_rank() //进程的编号

* 点对点通信
  * MPI_Send() //阻塞的或者缓冲的，发送
  * MPI_Recv() //阻塞的，接收
 
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

