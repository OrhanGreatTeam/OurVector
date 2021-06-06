#include "VectorIterator.h"

VectorIterator::VectorIterator(ValueType* first):ptr(first)
{
}

VectorIterator::VectorIterator():ptr(nullptr)
{
	
}

ValueType& VectorIterator::operator++()
{
	return *ptr++;
}

ValueType& VectorIterator::operator--()
{
	return *ptr--;
}

ValueType& VectorIterator::operator*()
{
	return *ptr;
}

ValueType* VectorIterator::operator->()
{
	return ptr;
}

bool VectorIterator::operator==(const VectorIterator& r)
{
	return	ptr == r.ptr;
}

bool VectorIterator::operator!=(const VectorIterator& r)
{
	return ptr != r.ptr;
}

bool VectorIterator::operator<(const VectorIterator& r)
{
	return ptr<r.ptr;
}

bool VectorIterator::operator>(const VectorIterator& r)
{
	return ptr>r.ptr;
}



