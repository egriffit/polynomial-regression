# Polynomial Approximation
# About
This project employs the polynomial approximation method to generate a polynomial given a set of 2-D coordinate points. The method used to generate the polynomial approximation is Least Squares Regression using two matrices. The first is generated based off the x values and desired degree of approximation. The second is generated from the y values. Then, gaussian elimination is used to solve for the coefficients of each term; outputting the approximate polynomial once complete. This project can create any degree polynomial approximation.
## Getting Started
Download MachineAssignment-3.zip to the desired directory. Extract the contents.
### Prerequisites
g++ (any version)
### Installing
Run make while in the directory to compile the executable.
Run make clean to remove all object and executable files.
## Running the program
The executable is named polyDriver and is located in the bin/ directory.
### Command Line Arguments
polyDriver accepts two command line arguments
1. the degree of the polynomial approximation
2. input file containing the points to be approximated
```
./polyDriver 3 samplePoints.txt
```
The following command will generate a cubic polynomial approximation based off of the points given inside the samplePoints.txt file.
### Input File Format
The points in the input file should be arranged as the x and y values separated by a space, with each coordinate on its own line of the input file.
For Example, the points (0, 0), (1, 3), and (-2, 4) would look like this in the input file:
```
0 0
1 3
-2 4
```
# Running the tests
Test drivers for the Matrix and GaussElim source files are included in the test/ directory along with some sample input files. To compile the tests, type:
```
make test
```
These executables will be located in the bin/ directory\n
Similarily,
```
make clean_test
```
removes all test objects and executables.
## Documentation
Documentation is provided by Doxygen and is located in the doc/ directory.
An html file is located on the path doc/html/index.html
## Authors
* **Edward Griffith**

