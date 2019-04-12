#ifndef POLYAPPROX_H_INCLUDED
#define POLYAPPROX_H_INCLUDED

#include <fstream>
#include <iomanip>
#include <vector>

#include "GaussElim.h"
#include "Matrix.h"


/** \file
 */

/**
 * \relates PolyApprox
 * For readability, "point" will be an alias for a standard pair of doubles
 */
using point = std::pair<double, double>;

/**
 * Polynomial Approximation class. Generates an n degree polynomial from a given set of points.
 */
class PolyApprox
{

	private:

		int degree;		///< degree of the desired polynomial approximation
		std::vector<double> coefficients;	///< a list of all coefficients derived from Gaussian elimination
		Matrix x;		///< Matrix of x values
		Matrix y;		///< Matrix of y values
		std::vector<point> points;	///< container of points that will be used for approximation
	
	public:

		/**
		 * Defuault PolyApprox Constructor
		 */
		PolyApprox();

		/**
		 * PolyApprox Constructor when the degree and points are known
		 *
		 * @param deg degree of the desired polynomial approximation
		 * @param coords container of points used for the approximation
		 */
		PolyApprox(int deg, std::vector<point> coords);

		/**
		 * PolyApprox Destructor
		 */
		~PolyApprox();

		/**
		 * Access degree of a PolyApprox object
		 *
		 * @return degree of the polynomial approximation
		 */
		int getDegree() const;

		/**
		 * Access the list of points used for the approximation
		 *
		 * @return list of points for the approximation
		 */
		std::vector<point> getPoints() const;

		/**
		 * Access coefficients of a PolyApprox object
		 *
		 * @return container of the coefficients for the polynomial approximation
		 */
		std::vector<double> getCoefficients() const;

		/**
		 * Access matrix x
		 *
		 * @return matrix of the x values
		 */
		Matrix getXMatrix() const;

		/**
		 * Access matrix y
		 *
		 * @return matrix of the y values
		 */
		Matrix getYMatrix() const;

		/**
		 * Set the degree of the approximation
		 *
		 * @param deg the degree of the polynomial approximation
		 */
		void setDegree(int deg);

		/**
		 * Set the points used for the approximation
		 *
		 * @param coords coordinate points used for the approximation
		 */
		void setPoints(std::vector<point> coords);

		/**
		 * Build the X Matrix
		 */
		void buildXMatrix();

		/**
		 * Build the Y Matrix
		 */
		void buildYMatrix();

		/**
		 * Build the left and right matrices to be used in Gaussian Elimination
		 *
		 * @return a pair containing the two matrices
		 */
		std::pair<Matrix, Matrix> buildGaussMatrices();

		/**
		 * Driver for the polynomial approximation process
		 */
		void polyDriver();

		/**
		 * Display function that prints the coefficents to the screen in the format of a function
		 */
		void display(std::ostream& outs);

		/**
		 * Load points for approximation from an input file
		 *
		 * @param inf input containing the points for approximation
		 */
		void loadPoints(std::ifstream& inf);

};

inline
int PolyApprox::getDegree() const
{
	return degree;
}

inline 
std::vector<point> PolyApprox::getPoints() const
{
	return points;
}

inline
std::vector<double> PolyApprox::getCoefficients() const
{
	return coefficients;
}

inline
Matrix PolyApprox::getXMatrix() const
{
	return x;
}

inline
Matrix PolyApprox::getYMatrix() const
{
	return y;
}

inline
void PolyApprox::setDegree(int deg)
{
	degree = deg;
}

inline
void PolyApprox::setPoints(std::vector<point> coords)
{
	points = coords;
}

/**	\relates PolyApprox
 * Overloaded Stream Insertion Operator
 *
 * @param outs output stream
 * @param prt PolyApprox object to print to the screen
 *
 * @return output stream
 */
inline
std::ostream& operator<< (std::ostream& outs, PolyApprox prt)
{
	prt.display(outs);

	return outs;
}

#endif
