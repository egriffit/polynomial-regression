#include <cmath>
#include <utility>

#include "PolyApprox.h"

PolyApprox::PolyApprox()
{
	degree = 0;
}

PolyApprox::PolyApprox(int deg, std::vector<point> coords)
{
	degree = deg;
	points = coords;
}

PolyApprox::~PolyApprox()
{
}

void PolyApprox::buildXMatrix()
{
	//resize x matrix
	x = Matrix(points.size(), degree + 1);

	//fill in the values
	for(int i = 0; i < x.getNumRows(); i++)
		for(int j = 0; j < x.getNumCols(); j++)
		{
			//values in matrix are equal to x^col
			x(i, j) = std::pow(points[i].first, j);
		}
}

void PolyApprox::buildYMatrix()
{
	//resize y matrix
	y = Matrix(points.size(), 1);

	//fill in the values
	for(int i = 0; i < y.getNumRows(); i++)
	{
		//place values of y into matrix
		y(i, 0) = points[i].second;
	}
}

std::pair<Matrix, Matrix> PolyApprox::buildGaussMatrices()
{
	Matrix left = x.transpose() * x;
	
	Matrix right = x.transpose() * y;
	
	std::pair<Matrix, Matrix> result(left, right);

	return result;
}

void PolyApprox::polyDriver()
{
	this->buildXMatrix();
        // std::cerr << "Matrix X:\n" << x << std::endl;


	this->buildYMatrix();
        // std::cerr << "Matrix Y:\n" << y << std::endl;


	/*
	Matrix left = this->buildGaussMatrices().first;
	Matrix right = this->buildGaussMatrices().second;
	std::cerr << left << std::endl << right << std::endl;
	std::cerr << gaussDriver(left, right)[0] << std::endl;
	*/
	std::pair<Matrix, Matrix> gaussMatrices = buildGaussMatrices();

        // std::cerr << "Matrix XTX:\n" << gaussMatrices.first << std::endl
        //           << "Matrix XTY:\n" << gaussMatrices.second << std::endl;

	coefficients = gaussDriver(gaussMatrices.first, gaussMatrices.second);
	//std::cerr << coefficients[0] << std::endl << coefficients[1] << std::endl;
}

void PolyApprox::display(std::ostream& outs)
{
	//Output coefficients
	//set precision
	outs << std::endl
		 << std::fixed << std::setprecision(4)
		 << "Polynomial Approximation: f(x) = ";
	for(int i = 0; i < coefficients.size(); i++)
	{
		outs << "c" << i;
		if(i != 0 && i != coefficients.size() - 1)
			outs << "X^" << i << " + ";
		else if(i == 0)
			outs << " + ";
		else if(i == coefficients.size() - 1)
			outs << "X^" << i << std::endl << std::endl;
	}

	outs << "Coefficients of the Approximation of Degree " << degree << std::endl;

	for(int i = 0; i < coefficients.size(); i++)
	{
		outs << "c" << i << ": " << coefficients[i] << std::endl;
	}
	
	outs << std::endl;


	//Output function format
	/*outs << "The Polynomial Approximation of Degree " << degree << ":\n"
		 << "f(x) = ";
	//std::cerr << coefficients.size() << std::endl;
	for(int i = coefficients.size() - 1; i >= 0; i--)
	{
		if(i != 0)
			outs << coefficients[i] << "X^" << i << " + ";
		else
			outs << coefficients[i];
	}

	outs << std::endl;
	*/
}

void PolyApprox::loadPoints(std::ifstream& inf)
{
	double xPoint = 0.0;
	double yPoint = 0.0;

	while(inf >> xPoint >> yPoint)
	{
		point coord(xPoint, yPoint);
		points.push_back(coord);
	}
}
