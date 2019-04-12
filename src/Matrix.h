#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED


#include <iostream>
#include <vector>

/**	\file
 */

/**
 * The matrix class. This class will handle all matrix operations.
 */
class Matrix
{
	private:
		int numRows;	///< Number of Rows
		int numCols;	///< Number of Columns
		std::vector<double> data;	///< 1-D container of all matrix data

	public:
		/**
		 * Default Matrix Constructor
		 */
		Matrix();

		/**
		 * Matrix Constructor
		 *
		 * @param row the number of rows
		 * @param col the number of columns
		 */
		Matrix(int row, int col);

		/**
		 * Matrix Copy Constructor
		 *
		 * @param src the matrix to be copied
		 */
		Matrix(const Matrix& src);

		/**
		 * Matrix Destructor
		 */
		~Matrix();

		/**
		 * Return the number of rows
		 */
		int getNumRows() const;

		/**
		 * Return the number of columns
		 */
		int getNumCols() const;

		/**
		 * Modify the number of rows
		 *
		 * @param row new number of rows
		 * @return number of rows
		 */
		void setNumRows(int row);

		/**
		 * Modify the number of columns
		 *
		 * @param col new number of columns
		 * @return number of columns
		 */
		void setNumCols(int col);

		/**
		 * Read in the matrix data
		 *
		 * @param ins the input stream
		 */
		void read(std::istream& ins);

		/**
		 * Print the matrix
		 *
		 * @param outs the output stream
		 */
		void display(std::ostream& outs) const;

		/**
		 * Overloaded + operator
		 *
		 * @param rhs matrix on the right hand side of the addition
		 * @return matrix resulting from the addition
		 */
		Matrix operator+(const Matrix& rhs);

		/**
		 * Overloaded - operator
		 *
		 * @param rhs matrix on the right hand side of the subtraction
		 * @return matrix resulting from the subtraction
		 */
		Matrix operator-(const Matrix& rhs);

		/**
		 * Overloaded * operator
		 *
		 * @param rhs matrix on the right hand side of the multiplication
		 * @return matrix resulting from the multiplication
		 */
		Matrix operator*(const Matrix& rhs);

		/**
		 * Overloaded () operator
		 *
		 * @param row row of desired element
		 * @param col column of desired element
		 * @return value at the specified row and column
		 */
		double& operator()(int row, int col);

		/**
		 * Overloaded () operator with constant object
		 *
		 * @param row row of desired element
		 * @param col column of desired element
		 * @return value at the specified row and column
		 */
		double operator()(int row, int col) const;


		
		/**
		 * Transpose a matrix (i.e. switch the data in the rows and columns)
		 *
		 * @return matrix resulting from the multiplication
		 */
		Matrix transpose();

		/**
		 * Invert a matrix
		 *
		 * @return result matrix resulting from the inversion
		 */
		Matrix inverse();

};

inline
int Matrix::getNumRows() const
{
	return this->numRows;
}

inline
int Matrix::getNumCols() const
{
	return this->numCols;
}

inline
void Matrix::setNumRows(int row)
{
	this->numRows = row;
}

inline
void Matrix::setNumCols(int col)
{
	this->numCols = col;
}

/**	\relates Matrix
 * Overloaded Stream Insertion Operator
 *
 * @param outs the output stream
 * @param prt the Matrix to be printed
 *
 * @return the modified output stream
 */
inline
std::ostream& operator<< (std::ostream& outs, const Matrix& prt)
{
	prt.display(outs);

	return outs;
}

#endif


