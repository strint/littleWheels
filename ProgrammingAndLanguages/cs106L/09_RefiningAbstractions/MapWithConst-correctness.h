#pragma once
template <typename ValueType> class Map 
{
public:
	Map(int sizeHint = 101);
	~Map();

	int size() const;
	bool isEmpty() const;

	void put(const string& key, const ValueType& value);
	void remove(const string& key);
	bool containsKey(const string& key) const;

	const ValueType& get(const string& key) const;
	ValueType& operator[] (const string& key);

	void clear();

	void mapAll(void fn(const string& key, const ValueType& val)) const;

	template <typename ClientDataType>
	void mapAll(void fn(const string& key,	const ValueType& val, ClientDataType& data),
		        ClientDataType& data) const;

	Iterator iterator() const;

private:

};

