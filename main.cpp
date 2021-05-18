#include "MyVector.h"
#include <iostream>


int main() {

	MyVector a1(4,5);
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
	MyVector a2(4, 5);
	a2.pushBack(8);
	a2.print();


}