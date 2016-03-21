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
 * MPI_Init()
 * MPI_Finalize()
 * MPI_Comm_size()
 * MPI_Comm_rank()

* 点对点通信
  * MPI_Send()
  * MPI_Recv()

