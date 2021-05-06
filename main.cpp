#include "MyVector.h"


int main() {

	MyVector a(3,1);
	MyVector a1;
	a1 = a;
	a1.popBack();
	a1.print();

}