# C++的对象模型、RTTI、显式类型转换

## 说明
* `static_dynamic_cast_RTTI.cpp` 中包含对RTTI、static_cast、dynamic_cast的测试

## 对象模型和RTTI
* 对象模型（object model）是指对象（class）在内存中的布局（layout），所以更准确的说法可以是对象的内存模型。
* 对象的内存模型存储的信息主要包括成员变量、成员函数、类型信息、继承关系。其中类型信息即对应RTTI。
* RTTI（Run-time Type Identification 或者 Run-time type information）是指对象在运行时的类型信息

### 一个实例
定义如下三个类A、B、C
```cpp
class A {
  private:
    int a1;
  public:
    virtual int A_virt1();
    virtual int A_virt2();
    static void A_static1();
    void A_simple1();
};

class B {
  private:
    int b1;
    int b2;
  public:
    virtual int B_virt1();
    virtual int B_virt2();
};

class C: public A, public B {
  private: 
    int c1;
  public: 
    virtual int A_virt2();
    virtual int B_virt2();
};

```
那么A、B、C的内存模型如下图：
![](object_model_abc.gif)
* 每个对象中依次包含`vfptr`、非静态成员变量，其中`vfptr`是指向虚函数表的指针
* 虚函数表中包含本指向各个虚函数代码段的指针，`vfptr`指向的是第一个虚函数的指针，`vfptr - 1`处是一个指针，指向的是`RTTICompleteObjectLocator`
* `RTTICompleteObjectLocator`中存储的是RTTI信息相关的指针，其中第四个指针`pTypeDescriptor`指向的是`RTTITypeDescriptor`
* `RTTITypeDescriptor`中第三个位置存储的是的类型

`RTTICompleteObjectLocator` 和 `RTTITypeDescriptor`可以定义如下结构来解析：
```cpp
typedef unsigned long DWORD;

//定义RTTITypeDescriptor结构体来得到RTTITypeDescriptor的内容
struct RTTITypeDescriptor
{
    DWORD ptrToVTable;
    DWORD spare;
    char name[];
};

//定义RTTICompleteObjectLocator结构体来得到的RTTICompleteObjectLocator内容
struct RTTICompleteObjectLocator
{
    DWORD signature; //always zero ?

    DWORD offset;    //offset of this vtable in the complete class

    DWORD cdOffset;  //constructor displacement offset

    struct TypeDescriptor* pTypeDescriptor; //TypeDescriptor of the complete class

    int * ptr; //struct RTTIClassHierarchyDescriptor* pClassDescriptor; //describes inheritance hierarchy
};
```

利用上面的定义，对于一个类，可以用一下的过程得到类型信息：
```cpp
	//Derive的一个对象的指针
	Base *pbase7 = new Derive();

	//将指向对象的指针类型转成指向整数的指针类型
	int *objptr = (int *)pbase7;

	//从对象地址指向的内存中得到虚函数表的指针
    int *vftptr = (int *)(*objptr);

	//得到RTTICompleteObjectLocator的指针
    RTTICompleteObjectLocator * rttiObjLoc = (RTTICompleteObjectLocator *)(*((int*)(vftptr - 1)));

	//得到RTTITypeDescriptor的指针
	RTTITypeDescriptor * rttiTypeDes = (RTTITypeDescriptor *) rttiObjLoc->pTypeDescriptor;

	//根据RTTITypeDescriptor输出该类的raw_name
    cout<< "typeinfo rawname by pointer: " << rttiTypeDes->name <<endl;
```
可以看到，C++的内存模型中存储着完整的成员变量、函数、类型、继承关系信息。

## static_cast 和 dynamic_cast 的区别
* 类型转换（type cast）是指将一个对象从一种类型转换成另一种类型，其中C++的显示类型转换包括static_cast、dynamic_cast、const_cast、reinterpret_cast四种
* static_cast 是编译时确定下来，程序无法判定类型转换是否安全，需要进行类型转换的程序员来保证类型转换的安全
* dynamic_cast 是在运行时确定的，程序可以推断类型转换是否安全
* dynamic_cast 依赖 RTTI 中的类型信息来判断类型转换是否安全

### 对static_cast 和 dynamic_cast进行测试
* 先定义三个类，`Base`是基类，`Derive`和`Derive2`分别是`Base`的子类

```cpp
class Base
{
	int a;
public:
    virtual void f() {cout<<"Base::f()"<<endl;}

};

class Derive: public Base
{
	int a1;
public:
    virtual  void f() {cout<<"Derive::f()"<<endl;}
    virtual  void f2() {cout<<"Derive::f1()"<<endl;}

};

class Derive2: public Base {
	int a2;
};
```

* 使用static_cast 和 dynamic_cast

```cpp
	//static_cast
    Base *pbase1  = new Derive();
    Derive* pderive1 = static_cast<Derive *>(pbase1);
    pderive1->f(); // Derive::f()

    Base* pbase2 = new Base();
	//这个做静态类型转换不会报错
    Derive * pderive2 = static_cast<Derive *>(pbase2);
    pderive2->f();  // Base::f()
	//在调用时出错
    pderive2->f2(); // throw exception "Access violation reading"

	//dynamic_cast
	Base *pbase3 = new Derive();
	Derive* pderive3 = dynamic_cast<Derive *>(pbase3);
	pderive3->f(); // Derive::f()

	Base* pbase4 = new Base();
	//down-cast
	//这里做动态类型转换时，dynamic_cast会做类型检查，发现不能转换，就返回null
	Derive * pderive4 = dynamic_cast<Derive *>(pbase4);

	if ( pderive4 ) // NULL
	{
		//因为pderive4是NULL，所以这里不会执行
		pderive4->f();
		pderive4->f2();
	}
```

## 参考文档
* Static_cast 与 Dynamic_cast的区别，http://www.cnblogs.com/zhyg6516/archive/2011/03/07/1971898.html
* Reversing Microsoft Visual C++ Part II: Classes, Methods and RTTI，http://www.openrce.org/articles/full_view/23
* C++:Under the Hood, Jan Gray, http://www.openrce.org/articles/files/jangrayhood.pdf
* Inside the C++ Object Model, Stanley B. Lippman
