#include <fstream>
#include <cstdlib>
#include "PolyApprox.h"

int main(int argc, char** argv)
{
	if(argc != 3)
	{
		std::cout << "Usage: polyDriver [degree] [points file]" << std::endl;
		return 0;
	}
	
	std::ifstream finPoints(argv[2]);

	PolyApprox approximation;
	approximation.setDegree(atoi(argv[1]));
	approximation.loadPoints(finPoints);
	approximation.polyDriver();


	std::cout << approximation << std::endl;
}
