#pragma once
#include <vector>
//using namespace std;

template <typename T> class grid {
public:
    /* Constructors, destructors. */
    grid();                               // Create empty grid
    grid(size_t rows, size_t cols);       // Construct to specified size
	~grid();
    /* Resizing operations. */
    void clear();                          // Empty the grid
    void resize(size_t rows, size_t cols); // Resize the grid
    /* Query operations. */   
    size_t numRows() const;              // Returns number of rows in the grid
    size_t numCols() const;              // Returns number of columns in the grid
    bool empty() const;                  // Returns whether the grid is empty
    size_t size() const;                 // Returns the number of elements
    /* Element access. */
    T& getAt(size_t row, size_t col);    // Access individual elements
    const T& getAt(size_t row, size_t col) const; // Same, but const, const-overloaded

	typedef typename std::vector<T>::iterator iterator;
	typedef typename std::vector<T>::const_iterator const_iterator;
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;

	//为了使用operator [][]，在内部新建了一个类来实现第二个[]
	class MutableReference {
	public:
		friend class grid;
		T& operator[] (size_t col);

	private:
		MutableReference(grid* owner, size_t row);

		grid* const owner;
		const size_t row;
	};
	MutableReference operator[] (int row);

	bool operator < (const grid& other) const;
	bool operator <= (const grid& other) const;
	bool operator == (const grid& other) const;
	bool operator != (const grid& other) const;
	bool operator > (const grid& other) const;
	bool operator >= (const grid& other) const;
private:
	std::vector<T> elems;
	size_t rows;
	size_t cols;
};

template <typename T> grid<T>::grid(void) : rows(0), cols(0)
{
}

template <typename T> grid<T>::grid(size_t rows, size_t cols)
	: elems(rows * cols), rows(rows), cols(cols)
{
}

template <typename T> void grid<T>::clear()
{
	resize(0,0);
}

template <typename T> grid<T>::~grid()
{
}

template <typename T> void grid<T>::resize(size_t rows, size_t cols) {
	elems.assign(rows * cols, ElemType());
	this->rows = rows;
	this->cols = cols;
}

template <typename T> size_t grid<T>::numRows() const {
	return rows;
}

template <typename T> size_t grid<T>::numCols() const {
	return cols;
}

template <typename T> bool grid<T>::empty() const {
	return (size() == 0);
}

template <typename T> size_t grid<T>::size() const {
	return rows * cols;
}

template <typename T> T& grid<T>::getAt(size_t row, size_t col) {
	return elems[col + row * cols];
}

template <typename T> const T& grid<T>::getAt(size_t row, size_t col) const {
	return elems[col + row * cols];
}

template <typename T> typename grid<T>::iterator grid<T>::begin() {
	return elems.begin();
}

template <typename T> typename grid<T>::const_iterator grid<T>::begin() const {
	return elems.begin();
}

template <typename T> typename grid<T>::iterator grid<T>::end() {
	return elems.end();
}

template <typename T> typename grid<T>::const_iterator grid<T>::end() const{
	return elems.end();
}

template <typename T>
grid<T>::MutableReference::MutableReference(grid* owner, size_t row) : 
owner(owner), row(row) {
}

template <typename T>
T& grid<T>::MutableReference::operator[] (size_t col) {
	return owner->getAt(row, col);
}

template <typename T>
typename grid<T>::MutableReference grid<T>::operator[] (int row) {
	return MutableReference(this, row);
}

template <typename T> bool grid<T>::operator < (const grid& other) const {
	if(rows != other.rows)
		return rows < other.rows;
	if(cols != other.cols)
		return cols < other.cols;
	return lexicographical_compare(begin(), end(), other.begin(), other.end());
}


template <typename T> bool grid<T>::operator > (const grid& other) const {
	return other < *this;
}

template <typename T> bool grid<T>::operator >= (const grid& other) const {
	return !(*this < other);
}

template <typename T> bool grid<T>::operator <= (const grid& other) const {
	return !(*this > other);
}

template <typename T> bool grid<T>::operator == (const grid& other) const {
	return !(*this < other) && !(*this > other);
}


template <typename T> bool grid<T>::operator != (const grid& other) const {
	return !(*this == other);
}
