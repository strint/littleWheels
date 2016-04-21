#include <iostream>
using namespace std;

class Base 
{
public:
    virtual void f() {cout<<"Base::f()"<<endl;}

};

class Derive: public Base
{
public:
    virtual  void f() {cout<<"Derive::f()"<<endl;}
    virtual  void f2() {cout<<"Derive::f1()"<<endl;}

};


int main()
{
	//static_cast
    Base *pbase1  = new Derive();
    Derive* pderive1 = static_cast<Derive *>(pbase1);
    pderive1->f(); // Derive::f()
    
    Base* pbase2 = new Base();
    Derive * pderive2 = static_cast<Derive *>(pbase2);
    pderive2->f();  // Base::f()
    //pderive2->f2(); // throw exception "Access violation reading"

    delete pbase1;
    delete pbase2;

	cout << "_____" << endl;
	//dynamic_cast
	Base *pbase3 = new Derive();
	//down-cast : converting a base-class pointer (reference) to a derived-class pointer (reference)
	Derive* pderive3 = dynamic_cast<Derive *>(pbase3); 
	pderive3->f(); // Derive::f()

	Base* pbase4 = new Base();
	//up-cast : converting a derived-class reference or pointer to a base-class，这里应该还是一个down-cast
	Derive * pderive4 = dynamic_cast<Derive *>(pbase4); 

	if ( pderive4 ) // NULL
	{
		pderive4->f();
		pderive4->f2();
	}

	delete pbase3;
	delete pbase4;

	system("pause");
	return 0;
}