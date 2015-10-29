#include <iostream>
using namespace std;

// Operator overloading is simply syntax sugar, a way of rewriting one operation
// (in this case, function calls) using a different syntax (here, the built-in operators). 

// operator overloading is a double-edged sword.  
// When used correctly,  operator overloading can lead to intuitive,  template-friendly
// code that elegantly performs complex operations behind the scenes.
// However, incorrectly overloaded operators can lead to incredibly subtle bugs. 

// The Principle of Least Astonishment: A function's name should communicate its behavior
// and should be consistent with other naming conventions and idioms.

// when overloading operators, make sure that you adhere to existing conventions.
// If you don't, you will end up with code that is either incorrect, confusing, or both.

// operator overloading only lets you define what built-in operators mean 
// when applied to objects.

class RationalNumber {
public:
	const RationalNumber operator+ (const RationalNumber& rhs) const;
	//...
private:
	int n;
	int d;
};

const RationalNumber RationalNumber::operator+ (const RationalNumber& rhs) const {
	RationalNumber temp;
	temp.n = n * rhs.d + rhs.n * d;
	temp.d = d * rhs.d;
	return temp;
}

RationalNumber one, two;
RationalNumber three = one + two;
RationalNumber three2 = one.operator+(two);

const RationalNumber operator+ (const RationalNumber& lhs,
	                           const RationalNumber& rhs) {
	RationalNumber temp;
	temp.n = lhs.n * rhs.d + rhs.n * lhs.d;
	temp.d = lhs.d * rhs.d;
	return temp;
}

RationalNumber one_, two_;
RationalNumber three_ = one_ + two_;
RationalNumber three2_ = operator+ (one_, two_);


// if the function operates on two pieces of data, the compiler treats 
// operator- as the binary subtraction operator, and if the function 
// uses just one piece of data it's considered to be the unary negation 
// operator.  

// binary subtraction
const RationalNumber operator- (const RationalNumber& lhs, const RationalNumber& rhs);

// or

class RationalNumber {
public:
	// binary sub
	const RationalNumber operator- (const RationalNumber& rhs) const;
	//...
private:
	int n;
	int d;
};

// unary negation
const RationalNumber operator- (const RationalNumber& rhs) const;

// or

class RationalNumber {
public:
	// unary negation 
	const RationalNumber operator- () const;
private:
	int n;
	int d;
};

//*****************************************
// Lvalues and Rvalues
// an lvalue is a value that can be on the left-hand side of an 
// assignment, and an rvalue is a value that can only be on the 
// right-hand side of an assignment. 

// To make a function that returns an lvalue, have that function 
// return a non-const reference.  
string& LValueFunction();

// To have a function return an rvalue, have  that function 
// return a const object by value.
const string RValueFunction();

// Lvalues and Rvalues (end)
//*****************************************

//*************************************
// Overloading element selestion operator []
class string {
public:
	char& operator[] (size_t position);
	const char& operator[] (size_t position) const;
};
// Overloading element selestion operator [] (end)
//*************************************


//*******************************************
// Overloading Compound Assignment Operators
// op=: +=, *=

MyClass& operator+= (const ParameterType& param);

class Vector3D {
public:
	// ...
	Vector3D& operator+= (const Vector3D& other);
	Vector3D& operator-= (const Vector3D& other);

	Vector3D& operator*= (double scaleFactor);
	Vector3D& operator/= (double scaleFactor);

	const Vector3D& operator- () const;
private:
	static const int NUM_COORDINATES = 3;
	double coordinates[NUM_COORDINATES];
};

Vector3D& Vector3D::operator+= (const Vector3D& other){
	for(int i = 0; i < NUM_COORDINATES; ++i)
		coordinates[i] += other.coordinates[i];
	return *this; //a reference to the receiver object
}

Vector3D& Vector3D::operator-= (const Vector3D& other){
	*this += -other;
	return *this;
}

Vector3D& Vector3D::operator*= (double scaleFactor) {
	for(int i = 0; i < NUM_CORDILNATES; ++i)
		coordinates[i] *= scaleFactor;
	return *this;
}

Vector3D& Vector3D::operator/= (double scaleFactor) {
	*this *= 1.0 / scaleFactor;
	return *this;
}

const Vector3D& Vector3D::operator- const () {
	Vector3D result;
	for(int j = 0; j < NUM_CORDILNATES; ++j)
		result.coordinates[j] = -coordinates[j];
	return result;
}

Vector3D one, two, three, four;
(one += two) += (three += four);
//(one.operator+=(two)).operator+=(three.operator+=(four));

// Overloading Compound Assignment Operators (end)
//*******************************************

//*******************************************
// Overloading Mathmeticcal operators

class Vector3D {
public:
	// ...
	Vector3D& operator+= (const Vector3D& other);
	const Vector3D operator+ (const Vector3D& other);

	Vector3D& operator-= (const Vector3D& other);

	Vector3D& operator*= (double scaleFactor);
	Vector3D& operator/= (double scaleFactor);

	const Vector3D& operator- () const;
private:
	static const int NUM_COORDINATES = 3;
	double coordinates[NUM_COORDINATES];
};

const Vector3D Vector3D::operator+ (const Vector3D& other) {
	Vector3D result = *this; // make a deep copy of this Vector3D
	result += other; // use existing operator+=
	return result;
}

class Matrix {
public:
	Matrix& operator*= (double scalar);
private:
	static const int MATRIX_SIZE = 3;
	double entries[MATRIX_SIZE][MATRIX_SIZE];
}

const Matrix Matrix::operator* (double scalar) const {
	Matrix result = *this;
	result *= scalar;
	return result;
}
// Matrix * 2.0 is right; but 2.0 * Matrix is wrong

// Overloading Mathmeticcal operators (end)
//*******************************************


//********************************************
//Overloading ++ and --

// prefix and postfix
// In the postfix version of ++, since we have to return the value of the variable
// was before it was incremented, we'll need to make a full copy of the old version
// and then return it.  With the prefix ++, since we're returning the current value
// of the variable, we can simply return a reference to it. 

class MyClass {
public:
	MyClass& operator++(); // prefix
	const MyClass operator++(int dummy); //postfix

private:

}

// prefix
MyClass& MyClass::operator++() {
	*this += 1;
	return *this;
}

// postfix
const MyClass MyClass::operator++(int dummy) {
	MyClass oldValue = *this;
    ++*this;	
	return oldValue;
}

//Overloading ++ and -- (end)
//********************************************


// ********************************
// Overloading relational operator
// > < ==  >= <= !=

class MyClass {
public:
	bool operator< (const MyClass& other) const;

private:

}

class Point {
public:

private:

}

class Point {
public:

private:

}

class Point {
public:

private:

}

class Point {
public:

private:

}

class Point {
public:

private:

}

class Point {
public:

private:

}

class Point {
public:

private:

}

class Point {
public:

private:

}

class Point {
public:
	Point(double x, double y);

	double getX() const;
	void setX(double value);

	double getY() const;
	void setY(double value);

	bool operator< (const Point& other) const;
	
private:
	double x, y;
}



bool Point::operator< (const Point& other) const {
	if(this.getX() < other.getX())
		return true;
	return this.getY() < other.getY();
}

bool operator< (const Point& one, const Point& two) {
	if(one.getX() < two.getY())
		return true;
	return one.getY() < two.getY();
}

bool operator> (const Point& one, const Point& two) {
	return two < one;
}

bool operator>= (const Point& one, const Point& two) {
	return !(one < two);
}

// Overloading relational operator (end)
// ********************************

//***********************************************
// Overloading the stream insertion operator

class Point {
public:
	friend ostream& oprtator << (ostream& stream, const MyClass& mc);
private:
	int x;
	int y;
}

// a free function support the form "cout << PointX"
// to access x y directly, make the function a friend of Class Point
ostream& oprtator << (ostream& stream, const Point& pt) {
	stream << '(' << pt.x << "," << pt.y << ')';
	return stream;
}

/*
class MyClass {
public:
	friend ostream& oprtator << (ostream& stream, const MyClass& mc);
}

ostream& oprtator << (ostream& stream, const MyClass& mc) {
	return stream;
}
*/

/*
class MyClass {
public:
    ostream& operator << (ostream& input) const;
}
*/

//Overloading the stream insertion operator(end)
//***********************************************


//************************
//Overloading * and ->

template <typename T> class PointerClass {
public:
	T& oprtator * () const;
	size_t length() const;
private:
	T* x; //pointer class stores address
}

template <typename T> T& PointerClass<T>::operator * () const {
	return *x; //x the address will not change, so it's const
}

template <typename T> T* PointerClass<T>::length() const {
	return x;
}

PointerClass<int> p;
p.operator * () = 123;
*p = 123;

PointerClass<string> p1;
p1->length();
(p1.operator ->())->length();


//Overloading * and -> (end)
//************************


