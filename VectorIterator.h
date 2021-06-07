#pragma once

using ValueType = double;

class VectorIterator
{
private:
	ValueType* ptr;


public:
	VectorIterator(ValueType* first);
	VectorIterator();

	ValueType& operator++();
	ValueType& operator--();



	ValueType& operator*();
	ValueType* operator->();


	bool operator==(const VectorIterator& r);
	bool operator!=(const VectorIterator& r);
	bool operator<(const VectorIterator& r);
	bool operator>(const VectorIterator& r);

	ValueType& operator[](const size_t i);

};

