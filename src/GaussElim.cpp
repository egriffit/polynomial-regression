#include <vector>
#include "GaussElim.h"

int findLargestRowByCol(const Matrix& matrix, int col)
{
	int maxRow = 0;
	double maxElement = matrix(0, col);	//set maxElement to first column element

	for(int i = 0; i < matrix.getNumRows(); i++)
	{
		if(matrix(i, col) > maxElement)
			maxRow = i;
	}

	return maxRow;
}

void swapRows(Matrix& matrix, int a, int b)
{
	double temp = 0;

	for(int i = 0; i < matrix.getNumCols(); i++)
	{
		
		temp = matrix(a, i);
		matrix(a, i) = matrix(b, i);
		matrix(b, i) = temp;
	}

}

void scaleRow(Matrix& matrix, int row, double scale)
{
	for(int i = 0; i < matrix.getNumCols(); i++)
		matrix(row, i) *= scale;
}

void addRows(Matrix& matrix, int a, int b, double scale)
{
	for(int i = 0; i < matrix.getNumCols(); i++)
		matrix(a, i) += scale * matrix(b, i);
}

void eliminate(Matrix& matrix, int col)
{
	for(int i = 0; i < matrix.getNumRows(); i++)
	{
		if(i != col)
			//eliminate the other column entries by adding rows
			addRows(matrix, i, col, (-1 * matrix(i, col)));
	}
}

std::vector<double> getCoefficients(Matrix matrix)
{
	std::vector<double> coefficients;

	for(int i = 0; i < matrix.getNumRows(); i++)
		coefficients.push_back(matrix(i, (matrix.getNumCols() - 1)));

	return coefficients;
}

Matrix getGaussMatrix(Matrix lhs, Matrix rhs)
{
	//make a matrix with one extra column
	Matrix gaussMatrix(lhs.getNumRows(), lhs.getNumCols() + 1);

	for(int j = 0; j < lhs.getNumCols() + 1; j++)
	{
		for(int i = 0; i < lhs.getNumRows(); i++)
		{
			//final column will be the elements from the right hand matrix
			if(j == lhs.getNumCols())
				gaussMatrix(i, j) = rhs(i, 0);
			else
				gaussMatrix(i, j) = lhs(i, j);
		}
	}
	
	return gaussMatrix;
}

std::vector<double> gaussDriver(Matrix lhs, Matrix rhs)
{
	Matrix gaussMatrix = getGaussMatrix(lhs, rhs);

	for(int i = 0; i < gaussMatrix.getNumRows(); i++)
	{
		//std::cerr << "Working on column " << i << std::endl;

		//pivot the largest row
		int maxIndex = findLargestRowByCol(gaussMatrix, i);
		swapRows(gaussMatrix, i, maxIndex);

		//std::cerr << "Pivot step:\n" << gaussMatrix << std::endl;

		//scale target row to 1
		scaleRow(gaussMatrix, i, 1 / gaussMatrix(i, i));
		
		//std::cerr << "Scale step:\n" << gaussMatrix << std::endl;

		//eliminate all other elements in the column
		eliminate(gaussMatrix, i);

		//std::cerr << "Eliminate step:\n" << gaussMatrix << std::endl;
	}

	return getCoefficients(gaussMatrix);
}
