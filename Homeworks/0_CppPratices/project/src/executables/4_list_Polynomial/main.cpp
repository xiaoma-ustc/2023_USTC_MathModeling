#include "PolynomialList.cpp"

#include <list>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	PolynomialList p1("Homeworks\\0_CppPratices\\samples\\data\\P3.txt");
	PolynomialList p2("Homeworks\\0_CppPratices\\samples\\data\\P4.txt");
	PolynomialList p3;
	p1.Print();
	p2.Print();

	p3 = p1 + p2;
	p3.Print();
	p3 = p1 - p2;
	p3.Print();

	p3 = p1 * p2;
	p3.Print();

	return 0;
}