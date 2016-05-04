# 基于引用计数的智能指针的实现
## 智能指针
在多个指针指向同一对象的情况下：当新的指针指向一个已经存在的对象时，不应该在内存中生成新的对象，而是应该指向已经生成的对象就可以了；当某个指针的生命周期结束，或者要delete某个指针时，需要保证在没有指针指向该对象时才真正释放该对象的内存。能够达到这种指向一个对象、同时能智能生成和释放这个对象的指针叫做智能指针（Smart Pointer）。在 C++ 11 中，这种指针的名字是 [shared_ptr](http://en.cppreference.com/w/cpp/memory/shared_ptr).

实现这种智能生成、释放内存的机制的策略之一是引用计数（reference counting）。思路是记录有多少个指针指向了对象（即引用计数）：当新的指针指向一个已经存在的对象时，只是增加引用计数；当某个指针被要求释放时，先减少引用计数，然后判断引用计数是否为0，只有当引用计数为0时才释放该对象的内存。

## 引用计数的实现
对引用计数的实现是实现智能指针的主要工作。引用计数要包括两个部分：一是指向对象内存的真正指针；二是指向该对象的指针的个数。
```
T* resource;
size_t refCount;
```
这两个变量的特点是在多个智能指针间要共享，但是不是在类间共享（所以不能使用static），在第一个智能指针生成时生成，在最后一个指向相同资源的指针消亡后消灭。所以可以智能指针中定义如下结构，然后使用共享内存来共享这两个变量：

```
template <typename T> class SmartPointer
{
	...

private:
	struct rc {
		T* resource; //指向一个对象
		size_t refCount; //记录有多少个智能指针指向该对象
	};//一个引用计数的结构体
	rc* data;//指向引用计数结构体的指针
	...
}
```

管理引用计数结构体的逻辑如下：
* 当初始生成一个对象时，new一个T类型的对象，new一个引用计数结构体`rc`，让`rc`中的`resource`指向对象，让`data`指向这个`rc`，将`refCount`置为1；
* 当生成一个新的智能指针，该指针指向已经生成的对象时，只是让它的`data`指向引用计数结构体`rc`，然后让`rc`中的`refCount`加1；
* 当删除一个智能指针时，先让`rc`中的`refCount`减1，然后判断`refCount`是否为0，只有当`refCount`为0时才释放`resource`指向的内存。

## 智能指针的接口
```
template <typename T> class SmartPointer
{
public:
	// 构造函数
	explicit SmartPointer(T* memory);
	// 复制构造函数
	SmartPointer(const SmartPointer& other);
	// 赋值操作符
	SmartPointer<T>& operator = (const SmartPointer<T>& other);
	// 析构函数
	~SmartPointer(void);

	T& operator * () const; //解引用
	T* operator -> () const; //->操作符
	T* get() const; //获取对象指针
	size_t getShareCount() const; //获取引用计数的个数

	void reset(T* newres); //指向新的对象
	void del(); //删除指针

private:
	struct rc {
		T* resource; //指向一个对象
		size_t refCount; //记录有多少个智能指针指向该对象
	};//一个引用计数的结构体
	rc* data;//指向引用计数结构体的指针

	//内部资源管理函数
	void detach();
	void attach(rc* other);
};
```
实现见[GitHug文件夹](https://github.com/strint/littleWheels/tree/master/ProgrammingAndLanguages/CPPExamples/cs106L/11_ResourceManagement/SmartPointer)中的 `SmartPointer.h`

## 使用举例
* 构造一个指向string类型的智能指针`p1`，并初始化成`hello template class 1`
```
	SmartPointer<string> p1(new string);
	*p1 = "hello template class 1";
```
* 得到`p1`指向的string
```
	*p1
```
* 得到`p1`指向的string的长度
```
	p1->length()
```
* 得到指向string的引用计数的个数
```
	p1.getShareCount()
```
* 得到string在虚拟内存中的地址
```
	p1.get()
```
* 构造智能指针`p2`，使它指向与`p1`相同的内容
```
	SmartPointer<string> p2(p1)
```
* 构造一个指向string类型的智能指针`p3`，并初始化成`hello template class 3`
```
	SmartPointer<string> p3(new string)
	*p3 = "hello template class 3";
```
* 让`p3`指向与`p1`相同的内容
```
	p3 = p1;
```
* 让`p3`指向新的string，并赋值
```
	p3.reset(new string);
	*p3 = "new pointer";
```
* 删除`p2`指向的内容（p2变成空指针，其指向的string的内存要等到最后一个指向string的指针被删除后才会被释放）
```
	p2.del();
```

## 源代码及测试
见[GitHub文件夹](https://github.com/strint/littleWheels/tree/master/ProgrammingAndLanguages/CPPExamples/cs106L/11_ResourceManagement/SmartPointer)中的 `SmartPointer.h`、`main.cpp`、`test_log.txt`
* `SmartPointer.h` 是SmartPointer的实现
* `main.cpp` 是对SmartPointer的测试
* `test_log.txt` 是测试输出的结果

## 参考资料
* Stanford CS106L, Chapter 11, Resource Management.
