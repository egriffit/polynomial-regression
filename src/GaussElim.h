#ifndef GAUSSELIM_H_INCLUDED
#define GAUSSELIM_H_INCLUDED

#include "Matrix.h"
/**
 * \file
 * Gaussian Elimination Functions.
 * Functions used during Gaussian Elimination of a matrix.
 */

/**
 * Find largest row of a matrix based on the elements in a given column
 *
 * @param matrix Matrix to be searched
 * @param col Column to search through
 *
 * @return index of the row with the largest element
 */
int findLargestRowByCol(const Matrix& matrix, int col);

/**
 * Swap two rows in a matrix
 * 
 * @param matrix reference to the matrix where the rows will be swapped
 * @param a first row to be swapped
 * @param b second row to be swapped
 */
void swapRows(Matrix& matrix, int a, int b);

/**
 * Scale a row by a scaling factor
 *
 * @param matrix reference to the matrix whose row will be scaled
 * @param row row to be scaled
 * @param scale scaling factor
 */
void scaleRow(Matrix& matrix, int row, double scale);

/**
 * Add two rows of a matrix together
 *
 * @param matrix reference to the matrix
 * @param a row that will be mutated
 * @param b row that will be added to the other row
 * @param scale scaling factor for the row to be added
 */
void addRows(Matrix& matrix, int a, int b, double scale = 1);

/**
 * Eliminate all other elements in the column
 *
 * @param matrix reference to the matrix where elimination will occur
 * @param col column of elimination
 */
void eliminate(Matrix& matrix, int col);

/**
 * Find the coefficients after gaussian elimination is complete
 *
 * @param matrix matrix resulting from Gaussian elimination
 *
 * @return vector of coefficients gathered from final matrix
 */
std::vector<double> getCoefficients(Matrix matrix);

/**
 * Create the gaussian matrix from two matrices
 *
 * @param lhs matrix on the left hand side of the equation
 * @param rhs single column matrix on the right hand side of the equation
 *
 * @return matrix ready for gaussian elimination
 */
Matrix getGaussMatrix(Matrix lhs, Matrix rhs);

/**
 * Driver for gaussian elimination
 *
 * @param lhs Left matrix to be merged for elimination
 * @param rhs Right matrix to be merged for elimination
 * 
 * @return vector of coefficients gathered from final matrix
 */
std::vector<double> gaussDriver(Matrix lhs, Matrix rhs);

#endif
