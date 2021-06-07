#include "MyVector.h"
#include <iostream>

using namespace std;


int main() {

	MyVector a1(10, 5);
	//VectorIterator Ib;
	//Ib = a1.begin();
	//std::cout << *Ib;
	//VectorIterator Ie;
	//Ie = a1.end();
	//std::cout << *Ie;

	/*VectorIterator I = a1.begin();
	++I*/;

	/*std::cout << std::endl;
	int i = 0;
	for (VectorIterator Ib = a1.begin(); Ib <  a1.end();++Ib)
	{
		auto v = *Ib;
		std::cout << v;
		std::cout << std::endl;
	}*/
	MyVector a2(4, 3);
	for (int i = 0;i < 10;i++) {
		a2.pushBack(8);
		i++;
	}
	//a2.print();

	/* a1.print(); // проверка вставки вектора в вектор;
	cout << endl;
	a2.print();

	a2.insert(2, a1);
	a2.print(); */
	a2.print();

	//a2.reserve(20);
	/*a2.print();
	a2.erase(0, 3);
	a2.print();*/


}