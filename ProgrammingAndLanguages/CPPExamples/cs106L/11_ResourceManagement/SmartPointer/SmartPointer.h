#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

/***********************
 * 一个C++智能指针的实现 *
 ***********************/
template <typename T> class SmartPointer
{
public:
	// Conversion constructor
	explicit SmartPointer(T* memory);
	// Copy constructor
	SmartPointer(const SmartPointer& other);
	// Assignment operator
	SmartPointer<T>& operator = (const SmartPointer<T>& other);	
	// Destructor
	~SmartPointer(void);
	// delete operator
	static void operator delete(void* p);

	T& operator * () const;
	T* operator -> () const;
	T* get() const;
	size_t getShareCount() const;

	void reset(T* newres);
	 void del();

private:
	struct rc {
		T* resource;
		size_t refCount;
	};
	rc* data;

	void detach();
	void attach(rc* other);
};


//模板类需要使用内含的include方式，把实现和原型放在一起
template <typename T> SmartPointer<T>::SmartPointer(T* res) {
	data = new rc;
	data->resource = res;
	data->refCount = 1;
}

template <typename T> SmartPointer<T>::~SmartPointer() {
	detach();
}

template <typename T> void SmartPointer<T>::del() {
	detach();
}

template <typename T> T& SmartPointer<T>::operator * () const {
	return *data->resource; //*(data->resource)
}

template <typename T> T* SmartPointer<T>::operator -> () const {
	return data->resource; //指向T类型数据的地址
}

template <typename T> T* SmartPointer<T>::get() const {
	return data->resource;
}

template <typename T> size_t SmartPointer<T>::getShareCount() const {
	return data->refCount;
}

template <typename T> void SmartPointer<T>::detach() {
	if(data) {
		--data->refCount;
    	if(data->refCount == 0) {
			delete data->resource;
			delete data;
		}
		data = 0;
	}
}

template <typename T> void SmartPointer<T>::attach(rc* to) {
	data = to;
	++data->refCount;
}

template <typename T> void SmartPointer<T>::reset(T* newres) {
	detach();
	data = new rc;
	data->resource = newres;
	data->refCount = 1;
}

template <typename T> SmartPointer<T> ::SmartPointer(const SmartPointer& other) {
	attach(other.data); //sibling access
}

template <typename T>
SmartPointer<T>& SmartPointer<T>::operator = (const SmartPointer& other) {
	//check for self-assignment
	if(this != &other) {
		detach();
		attach(other.data);	
	}
	return *this;
}

#endif
