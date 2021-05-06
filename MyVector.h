#pragma once

// ��������� ��������� capacity
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
    class VectorIterator;
    class ConstVectorIterator;

    // ��������� ������ ���������� ValueType()
    MyVector(size_t size = 0,
        ResizeStrategy = ResizeStrategy::Multiplicative,
        float coef = 1.5f);

    // ��������� ������ ���������� value
    MyVector(size_t size,
        ValueType value,
        ResizeStrategy = ResizeStrategy::Multiplicative,
        float coef = 1.5f);

    MyVector(const MyVector& copy);
    MyVector& operator=(const MyVector& copy);

    MyVector(MyVector&& other) noexcept;
    MyVector& operator=(MyVector&& other) noexcept;
    ~MyVector();

    size_t capacity() const;
    size_t size() const;
    float loadFactor() const;

    VectorIterator begin();
    ConstVectorIterator begin() const;
    VectorIterator end();
    ConstVectorIterator end() const;

    // ������ � ��������, 
    // ������ �������� �� O(1)
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
    void resize(const size_t size, const ValueType& value = ValueType());

    // ������� �������, ��� ��������� capacity
    void clear();



    void print();
private:
    ValueType* _data;
    size_t _size;
    size_t _capacity;
    ResizeStrategy  _strategy = ResizeStrategy::Multiplicative;
    float _coef;
};


