#include <iostream>
#include "../src/GaussElim.h"

int main()
{
	Matrix lhs(3, 2);
	Matrix rhs(3, 1);

	lhs(0, 0) = 1;
	lhs(0, 1) = 0;
	lhs(1, 0) = 1;
	lhs(1, 1) = 1;
	lhs(2, 0) = 1;
	lhs(2, 1) = 2;

	rhs(0, 0) = 0;
	rhs(1, 0) = -1;
	rhs(2, 0) = -4;

	std::cout << lhs << rhs;
		
	std::vector<double> c = gaussDriver(lhs, rhs);

	for(const double& d: c)
		std::cout << d << std::endl;
}
