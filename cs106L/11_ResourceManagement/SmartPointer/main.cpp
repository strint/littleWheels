#include "SmartPointer.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream test_log;
	test_log.open("test_log.txt");

	SmartPointer<string> p1(new string);
	*p1 = "hello template class";

	test_log << "p1 content:" << *p1 << endl; //*p1 = *(data->resource)
	test_log << "p1 length:" << p1->length() << endl; //p1-> = (data->resource)
	test_log << "p1 refCount:" << p1.getShareCount() << endl;
	test_log << "p1 content address:" << p1.get() << endl; //*p1 = *(data->resource)
	test_log << "p1 operator->():" << p1.operator->() << endl; //operator按成员函数的形式来使用 
	test_log << "p1 operator*():" << p1.operator*() << endl; 
	test_log << endl;

	SmartPointer<string> p2(p1);
	test_log << "p2 content:" << *p2 << endl; 
	test_log << "p1 refCount:" << p1.getShareCount() << endl;
	test_log << endl;

	SmartPointer<string> p3(new string);
	*p3 = "hello template class 3";
	test_log << "p3 content:" << *p3 << endl; 
	p3 = p1;
	test_log << "p3 content:" << *p3 << endl; 
	test_log << "p1 refCount:" << p1.getShareCount() << endl;
	test_log << endl;

	*p2 = "new content";
	test_log << "p1 content:" << *p1 << endl; 
	test_log << "p2 content:" << *p2 << endl; 
	test_log << "p3 content:" << *p3 << endl; 
	test_log << "p1 refCount:" << p1.getShareCount() << endl;
	test_log << endl;


	p3.reset(new string);
	*p3 = "new pointer";
	test_log << "p1 content:" << *p1 << endl; 
	test_log << "p2 content:" << *p2 << endl; 
	test_log << "p3 content:" << *p3 << endl; 
	test_log << "p1 refCount:" << p1.getShareCount() << endl;
	test_log << "p3 refCount:" << p3.getShareCount() << endl;
	test_log << endl;

	test_log.close();
	return 0;
}