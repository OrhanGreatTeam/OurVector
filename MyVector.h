#pragma once
#include "VectorIterator.h"


// ��������� ��������� capacity ..
enum class ResizeStrategy {
    Additive,//+
    Multiplicative//*
};

// ��� �������� � �������
// ����� ����� ������� �� ������
using ValueType = double;

class MyVector
{
public:
    // ����������� ���������
    //9
    class VectorIterator I;
    class ConstVectorIterator;

    // ��������� ������ ���������� ValueType()
    //3
    MyVector(size_t size = 0,
        ResizeStrategy = ResizeStrategy::Multiplicative,
        float coef = 1.5f);

    // ��������� ������ ���������� value 
    //1
    MyVector(size_t size,
        ValueType value,
        ResizeStrategy = ResizeStrategy::Multiplicative,
        float coef = 1.5f);
    //2
    MyVector(const MyVector& copy);
    //11
    MyVector& operator=(const MyVector& copy);

    MyVector(MyVector&& other) noexcept;
    //15
    MyVector& operator=(MyVector&& other) noexcept;
    //4
    ~MyVector();

    size_t capacity() const;
    size_t size() const;
    //5
    float loadFactor() const;
    //10
    VectorIterator begin();
    ConstVectorIterator begin() const;
    //11
    VectorIterator end();
    ConstVectorIterator end() const;

    // ������ � ��������, 
    // ������ �������� �� O(1)
    //11
    ValueType& operator[](const size_t i);
    const ValueType& operator[](const size_t i) const;

    // �������� � �����,
    // ������ �������� �� amort(O(1))
    
    void pushBack(const ValueType& value);
    // ��������,
    // ������ �������� �� O(n)
    void insert(const size_t i, const ValueType& value);     // ������ ��� ������ ��������
    void insert(const size_t i, const MyVector& value);      // ������ ��� �������
    void insert(ConstVectorIterator it, const ValueType& value);  // ������ ��� ������ ��������
    void insert(ConstVectorIterator it, const MyVector& value);   // ������ ��� �������

    // ������� � �����,
    // ������ �������� �� amort(O(1))
    // 7
    void popBack();
    // �������
    // ������ �������� �� O(n)
    void erase(const size_t i);
    void erase(const size_t i, const size_t len);            // ������� len ��������� ������� � i

    // ����� �������,
    // ������ �������� �� O(n)
    // ���� isBegin == true, ����� ������ ������� ��������, ������� value, ����� ����������
    // ���� �������� �������� ���, ������� end
    VectorIterator find(const ValueType& value, bool isBegin = true) const;

    // ��������������� ������ (������������� ������ capacity)
    void reserve(const size_t capacity);

    // �������� ������
    // ���� ����� ������ ������ ��������, �� ����� �������� ���������� value
    // ���� ������ - �������� ������
    //
    void resize(const size_t size, const ValueType& value = ValueType());

    // ������� �������, ��� ��������� capacity
    //14
    void clear();


    //6
    void print();
private:
    ValueType* _data;
    size_t _size;
    size_t _capacity;
    ResizeStrategy  _strategy = ResizeStrategy::Multiplicative;
    float _coef;
};


