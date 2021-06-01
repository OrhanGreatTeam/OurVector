#include "MyVector.h"
#include <iostream>
#include "VectorIterator.h"

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

const ValueType& MyVector::operator[](const size_t i) const
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

void MyVector::insert(const size_t i, const ValueType& value)
{
	_size = _size + 1;

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

	memcpy(&_data[1 + (i - 1)], &_data[i - 1], (_size - i) * sizeof(ValueType));
	memcpy(&_data[i - 1], &value, 1 * sizeof(ValueType));
}

void MyVector::insert(const size_t i, const MyVector& value)
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

	_size = _size + value.size();

	memcpy(&_data[value.size() + (i - 1)], &_data[i - 1], (_size - (i)) * sizeof(ValueType));
	memcpy(&_data[i - 1], value._data, value.size() * sizeof(ValueType));
}

MyVector& MyVector::operator=(const MyVector& copy)
{

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

size_t MyVector::capacity() const
{
	return _capacity;
}

size_t MyVector::size() const
{
	return _size;
}

void MyVector::reserve(const size_t capacity)
{
	if (capacity < _size) { 
        return;
	}

    else {
		
		_capacity = capacity;
        ValueType *newData = new ValueType[_capacity];
        memcpy(newData, _data, _size * sizeof(ValueType));
        delete[] _data;
        _data = newData;
    }
}

void MyVector::resize(const size_t size, const ValueType& value)
{
	if (size > _capacity) {
        reserve(size*_coef);

		for (size_t i = _size; i < size; i++)
        {
            _data[i] = value;
        }

		_size = size;
    }

    if (size == _capacity) {
        return;
	}

    if (size < _capacity)
    {
		ValueType *newData = new ValueType[_capacity];
        memcpy(newData, _data, _size * sizeof(ValueType));
        delete[] _data;
        _data = newData;

        _size = size;
    }
    return;
}

void MyVector::erase(size_t i)
{
	if (i > _size) {

		return;
	}

	for (size_t k = i; k < size() - 1; k++) {
    
        this->_data[k] = this->_data[k+1];
    }

	_size--;
}

void MyVector::erase(const size_t i, const size_t len)
{
	if (i > len) {

		return;
	}

	if (i > _size) {

		return;
	}

	if (len > _size) {

		return;
	}

	for (size_t k = i; k < size() - len; k++) {

        this->_data[k] = this->_data[k+len];
    }
    _size -= len;
}

VectorIterator MyVector::begin()
{
	return VectorIterator(_data);
}

VectorIterator MyVector::end()
{
	return VectorIterator(_data +_size);
}

VectorIterator MyVector::find(const ValueType& value, bool isBegin = true) const
{
	for (int i = 0; i < _size; i++) {

		if (_data[i] == value) {

			return /*сдесь нужно вернуть итератор на этот элемент*/;
		}
	}
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
