#include "../src/Matrix.h"
#include <cstdlib>

int main()
{
	Matrix A(3, 3);
	Matrix B(3, 3);

	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
		{
			A(i, j) = 5;
			B(i, j) = 2;
		}

	std::cout << "A:\n"	    << A 				<< std::endl
			  << "B:\n"		<< B 				<< std::endl
			  << "BT:\n"	<< B.transpose() 	<< std::endl
			  << "A + B:\n"	<< A + B 			<< std::endl
			  << "A - B:\n" << A - B 			<< std::endl
			  << "A * B:\n" << A * B 			<< std::endl;

	Matrix C(5, 3);

	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 3; j++)
			C(i, j) = std::rand() % 100;

	std::cout << "C:\n"		<< C 				<< std::endl
			  << "CT:\n"	<< C.transpose()	<< std::endl;

}			  
