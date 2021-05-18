#include "MyVector.h"
#include <iostream>
#include "VectorIterator.h"
using namespace std;



MyVector::MyVector(size_t size, ResizeStrategy ResizeStrategy, float coef)
{
	_size = size;
	_strategy = ResizeStrategy;
	_capacity = (_strategy == ResizeStrategy::Multiplicative) ? (size * 2) : (size + 2);
	_capacity = (_capacity == 0) ? (1) : (_capacity);
	_data = new ValueType[_capacity];
	for (size_t i = 0; i < _capacity;i++) {
		_data[i] = ValueType();
	}
	_coef = coef;
}

MyVector::MyVector(size_t size, ValueType value, ResizeStrategy ResizeStrategy, float coef)
{

	_size = size;
	_strategy = ResizeStrategy;
	_capacity = (_strategy == ResizeStrategy::Multiplicative) ? (size * 2) : (size + 2);
	_capacity = (_capacity == 0) ? (1) : (_capacity);
	_data = new ValueType[_capacity];
	for (size_t i = 0; i < _capacity;i++) {
		_data[i] = value;
	}
	_coef = coef;
}

MyVector::MyVector(const MyVector& copy)
{

	_size = copy._size;
	_capacity = copy._capacity ;
	_data = new ValueType[_capacity];
	memcpy(_data, copy._data, sizeof(ValueType)*(_size) );
	_strategy = copy._strategy;
	_coef = copy._coef;
}

MyVector::MyVector(MyVector&& other) noexcept:
	_size(other._size), _capacity(other._capacity),
	_strategy(other._strategy)
{

	other._data = nullptr;
	other._size = 0;
	other._capacity = 0;
}



ValueType& MyVector::operator[](const size_t i)
{

	return _data[i];
}

void MyVector::pushBack(const ValueType& value)
{
	if (loadFactor() == 1) {
		if (_strategy == ResizeStrategy::Additive) {
			_capacity = _size + _coef;
		}
		if (_strategy == ResizeStrategy::Multiplicative) {
			_capacity = _size * _coef;
		}
		_data = new ValueType[_capacity];
		delete[] _data;

	}

	this->_data[_size] = value;
	_size++;
}


MyVector& MyVector::operator=(MyVector&& other) noexcept
{
	if (other._size > _size) {
		delete[] _data;
		_capacity = other._size + 5;
		_data = new ValueType[_capacity];
	}
	for (size_t i = 0; i < other._size; i++)
	{
		_data[i] = other._data[i];
	}
	_size = other._size;
	return *this;
}

MyVector::~MyVector()
{
	delete[] _data;
}

float MyVector::loadFactor() const
{
	float s = (float)(_size);
	float c = (float)(_capacity);
	return s/c;
}

VectorIterator MyVector::begin()
{
	return VectorIterator(_data);
}

VectorIterator MyVector::end()
{
	return VectorIterator(_data +_size);
}






void MyVector::clear()
{
	delete[] _data;
	_size = 0;
	_capacity = 0;
}

void MyVector::print()
{
	for ( size_t i = 0; i < _size ; i++) {
		std::cout << _data[i];

	}
	std::cout << std::endl;
}

void MyVector::popBack()
{
	this->_data[_size];
	_size--;
	
}

