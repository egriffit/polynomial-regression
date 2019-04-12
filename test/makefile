MAINPROG=testMatrix

SOURCES:=$(wildcard *.cpp) ../src/Matrix.cpp
OBJECTS:=$(SOURCES:.cpp=.o)
FLAGS=-std=c++11 -Wall

all: $(SOURCES) $(MAINPROG)

$(MAINPROG): $(OBJECTS)
	g++ $(FLAGS) $(OBJECTS) -o $@

.cpp.o:
	g++ $(FLAGS) -c $< -o $@

clean:
	rm $(OBJECTS) $(MAINPROG)



#testMatrix: testMatrix.o ../src/Matrix.o
#	g++ -std=c++11 -Wall testMatrix.o ../src/Matrix.o -o testMatrix

#testMatrix.o: testMatrix.cpp
#	g++ -std=c++11 -Wall -c testMatrix.cpp -o testMatrix.o

#../src/Matrix.o: ../src/Matrix.cpp ../src/Matrix.h
#	g++ -std=c++11 -Wall -c Matrix.cpp -o Matrix.o
