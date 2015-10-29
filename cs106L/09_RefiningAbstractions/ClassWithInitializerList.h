#pragma once

#include <vector>
#include <string>
using namespace std;

/*
Initializer List
*/
class ClassWithInitializerList {
public:
	ClassWithInitializerList();
private:
	int myInt;
	string myString;
	vector<int> myVector;
};

// using Initializer List : we're telling C++ 
// to initialize the variables myInt and myString to 5 and ¡°C++!,¡±
// respectively, and to creates a  vector with ten elements
// before the class constructor is even called
ClassWithInitializerList::ClassWithInitializerList() : myInt(5), myString("C++!"), myVector(10) {
	// Empty constructor
}


/*
Parameters in Initializer Lists
*/
class RationalNumber
{
public:
	RationalNumber(int numerator = 0, int denominator = 1);
	/* ... */
private:
	int numerator, denominator;
};

RationalNumber::RationalNumber(int numerator, int denominator) :
	numerator(numerator), denominator(denominator)
{
	// Empty constructor
}

/*
RationalNumber fiveHalves(5, 2);
RationalNumber three(3); // Calls constructor with arguments (3, 1)
RationalNumber zero; // Calls constructor with arguments (0, 1)
*/

/*
void DoSomething(int x = 5, int y); // Problem: y needs a default
void DoSomething(int x, int y = 5); // Legal
*/


/*
When Initializer Lists are Mandatory
*/
class Counter {
public:
	Counter(int maxValue);
	void increment();
	void decrement();
	int getValue() const;
private:
	int value;
	const int maximum; 
	// In C++, it is mandatory to initialize all const primitive-type instance variables 
	// in an initializer list.  Otherwise, you'd have constants whose values were total garbage.
};

/*
// Even though we're in the constructor, we still cannot violate the sanctity of constness
Counter::Counter(int maxValue) {
	value = 0;
	maximum = maxValue; // Problem: Writing to a const value!
}
*/

Counter::Counter(int maxValue) : value(0), maximum(maxValue) {
	// Empty constructor
	// In C++, it is mandatory to initialize all const primitive-type instance variables 
	// in an initializer list.  Otherwise, you'd have constants whose values were total garbage.
}

/*
// Another case where initializer lists are mandatory arises 
// when a class contains objects with no legal or meaningful default constructor. 
class SetWrapperClass {
public:
	SetWrapperClass();
private:
	Set<customT> mySet(MyCallback); 
	// Problem: Set need a comparison function MyCallback 
	// to construct Set with type costomT
	// but put MyCallback in variable definition isn't legal C++ syntax
};
*/

class SetWrapperClass {
public:
	SetWrapperClass();
private:
	Set<customT> mySet; // Note: no parameters specified
};

SetWrapperClass::SetWrapperClass() : mySet(MyCallback) {
		// Yet another empty constructor!
}