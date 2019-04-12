#include "Matrix.h"
#include <iomanip>

Matrix::Matrix()
{
	numRows = numCols = 2;

	for(int i = 0; i < numRows; i++)
		for(int j = 0; j < numRows; j++)
			data.push_back(0.0);

}

Matrix::Matrix(int row, int col)
{

	numRows = row;
	numCols = col;

	for(int i = 0; i < numRows; i++)
		for(int j = 0; j < numCols; j++)
			data.push_back(0.0);
	
}

Matrix::Matrix(const Matrix& src)
{

	numRows = src.getNumRows();
	numCols = src.getNumCols();

	for(int i = 0; i < numRows; i++)
		for(int j = 0; j < numCols; j++)
			data.push_back(src(i, j));

}

Matrix::~Matrix()
{
}

void Matrix::read(std::istream& ins)
{
	double input = 0.0;

	for(int i = 0; i < numRows; i++)
		for(int j = 0; j < numCols; j++)
		{
			ins >> input;
			data[j + (numCols * i)] = input;
		}

}

void Matrix::display(std::ostream& outs) const
{
	for(int i = 0; i < numRows; i++)
	{
		outs << '|';
		for(int j = 0; j < numCols; j++)
			outs << std::right << std::setw(3) << data[j + (numCols * i)] << ' ';

		outs << '|' << std::endl;
	}

}

Matrix Matrix::operator+ (const Matrix& rhs)
{
	//assert that both matrices have the same dimensions
	if(this->numRows != rhs.getNumRows() || this->numCols != rhs.getNumCols())
	{
		std::cerr << "ERROR: These two matrices cannot be added together" << std::endl;
		exit(-1);
	}

	Matrix result(numRows, numCols);

	for(int i = 0; i < numRows; i++)
		for(int j = 0; j < numCols; j++)
			result(i, j) = (*this)(i, j) + rhs(i, j);

	return result;

}

Matrix Matrix::operator- (const Matrix& rhs)
{
	//assert that both matrices have the same dimensions
	if(this->numRows != rhs.getNumRows() || this->numCols != rhs.getNumCols())
	{
		std::cerr << "ERROR: These two matrices cannot be subtracted" << std::endl;
		exit(-1);
	}

	Matrix result(numRows, numCols);

	for(int i = 0; i < numRows; i++)
		for(int j = 0; j < numCols; j++)
			result(i, j) = (*this)(i, j) - rhs(i, j);

	return result;

}

Matrix Matrix::operator* (const Matrix& rhs)
{
	//assert the two matrices can be multipled
	if(this->numCols != rhs.getNumRows())
	{
		std::cerr << "ERROR: These two matrices cannot be multiplied" << std::endl;
		exit(-1);
	}

	Matrix result(this->numRows, rhs.getNumCols());
	

	for(int i = 0; i < numRows; i++)
	{
		
		for(int j = 0; j < rhs.getNumCols(); j++)
		{
			double total = 0.0;
			
			//add up row i and column j elements into total
			for(int k = 0; k < numCols; k++)
			{
				total += (*this)(i, k) * rhs(k, j);
			}

			//place total into resulting matrix
			result(i, j) = total;
		}

	}

	return result;

}

double& Matrix::operator()(int row, int col)
{
	return this->data[col + (numCols * row)];
}


double Matrix::operator()(int row, int col) const
{
	return this->data[col + (numCols * row)];
}


Matrix Matrix::transpose()
{
	Matrix result(numCols, numRows);

	for(int i = 0; i < numRows; i++)
		for(int j = 0; j < numCols; j++)
			result(j, i) = (*this)(i, j);

	return result;

}





