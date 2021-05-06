#include "MyVector.h"
#include <iostream>

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


void MyVector::pushBack(const ValueType& value)
{
	if (_size > _capacity) {
		if (_strategy == ResizeStrategy::Additive) {
			_capacity = _size + 2;
		}
		if (_strategy == ResizeStrategy::Multiplicative) {
			_capacity = _size * 2;
		}
		_data = new ValueType[_capacity];
		delete[] _data;

	}

	this->_data[_size] = value;
	_size++;
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
