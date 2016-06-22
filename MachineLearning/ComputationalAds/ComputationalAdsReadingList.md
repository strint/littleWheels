## 阅读清单

### 熟悉朴素贝叶斯、最大熵等模型在文本分类上的应用，了解优缺点
#### 朴素贝叶斯分类
##### 贝叶斯分类
* ci表示类别i
* W代表特征向量(w0, ..., wn)
* 先验概率：p(ci)
* 似然概率：p(W | ci)
* 后验概率：p(ci | W)
* p(ci | W) = p(W | ci) * p(ci) / p(W)
* 后验概率 = 先验概率 * 似然概率 / 证据
* Naive Bayes
 * 假设特征之间互相独立
 * p(W | ci) = p(w0, ..., wn | ci) = p(w0 | ci) * ... * p(wn | ci)
* p(W)的问题，与类别标签无关，所有类别的p(W)都相同，因为时比较p(ci | W)的大小，所以不需要求

##### 文本分类
* 将文本根据特征词典处理成特征向量
* [naiveBayes](./naiveBayes)文件夹包含了使用朴素贝叶斯进行文本分类的例子
 * `bayes.py`包括了朴素贝叶斯分类的实现和使用
 * 在ipython下运行 `%run bayes.py`，然后运行`testingNB()`

##### 最大熵模型
* http://icl.pku.edu.cn/ICLseminars/2003spring/%E6%9C%80%E5%A4%A7%E7%86%B5%E6%A8%A1%E5%9E%8B.pdf
* http://jiangtanghu.com/docs/cn/maxEnt.pdf
* file:///C:/Users/think/Downloads/%E4%BD%BF%E7%94%A8%E6%9C%80%E5%A4%A7%E7%86%B5%E6%A8%A1%E5%9E%8B%E8%BF%9B%E8%A1%8C%E4%B8%AD%E6%96%87%E6%96%87%E6%9C%AC%E5%88%86%E7%B1%BB.pdf




### 了解 audience selection, look alike 相关的论文


### 了解 Google, media6degree, mediagamma 等公司近年在顶级会议发表的广告投放相关的论文


### 了解 程序化交易、RTB、Ad exchange、DSP、DMP的进展与未来趋势


### 了解Spark的scala或者python开发
#### python
* https://github.com/strint/AliMusicTrendPredict

#### Scala on Spark
##### Spark
* paper [RDD: A Fault-Tolerant Abstraction for In-Memory Cluster Computing](https://people.csail.mit.edu/matei/papers/2012/nsdi_spark.pdf)

##### Scala programming on Spark
###### Spark
* MapReduce
 * 有向无环的数据流
 * 在内存中没有working set，将数据写到磁盘，然后再加载到内存
* Spark
 * 有向无环的数据流 和 有环的数据流
 * 在内存中有working set，可以方便做内存计算
 * 基于RDD，便于创建working set
 * 支持fault tolerant, locality-aware scheduling, load balancing
 * Fault-Tolerant: checkpointing the data or log the ops on data，Spark使用的是后者，记录了lineage（数据的家谱）
 * 适合数据并行、批处理模式

###### RDD
 * 弹性的分布式的数据集合
 * 一种分布式的内存抽象
 * 用于内存计算
 * 只可以批量创建，不能增量创建
 * 可读，不可修改

###### Operations
* ![](operationsOnRDD.png)


### 学习李航的《统计学习方法》、PRML等机器学习相关的书
#### 李航的《统计学习方法》
#### PRML
#### 西瓜书
