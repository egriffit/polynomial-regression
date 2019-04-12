# Directories
SRCDIR:=src
BUILDDIR:=build
TESTDIR:=test
BINDIR:=bin

# Create directories
$(shell mkdir -p $(BUILDDIR) $(BINDIR))

# Main program lists
MAINPROG:=$(BINDIR)/poly-approx
SOURCES:=$(wildcard $(SRCDIR)/*.cpp)
OBJECTS:=$(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.cpp=.o))

# Test items
TEST_SOURCES:=$(wildcard $(TESTDIR)/*.cpp)
TEST_OBJECTS:=$(patsubst $(TESTDIR)/%,$(BUILDDIR)/%,$(TEST_SOURCES:.cpp=.o))

# Compiler
CC:=g++
# Compilation flags
CPPFLAGS:=-g -std=c++11 -Wall



all: $(MAINPROG)

$(MAINPROG): $(OBJECTS)
	$(CC) $(CPPFLAGS) $^ -o $@

$(OBJECTS): $(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@


#target
#bin/polyDriver: build/polyDriver.o build/PolyApprox.o build/Matrix.o build/GaussElim.o
#	$(CC) -o $@ $^




test: $(BINDIR)/testMatrix $(BINDIR)/testGauss

bin/testMatrix: build/testMatrix.o build/Matrix.o
	$(CC) -o $@ $^

bin/testGauss: build/testGauss.o build/GaussElim.o build/Matrix.o
	$(CC) -o $@ $^

$(TEST_OBJECTS): $(BUILDDIR)/%.o: $(TESTDIR)/%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@




#object files
#build/GaussElim.o: src/GaussElim.cpp
#	$(CC) $(CPPFLAGS) -c $< -o $@

#build/Matrix.o: src/Matrix.cpp
#	$(CC) $(CPPFLAGS) -c $< -o $@

#build/PolyApprox.o: src/PolyApprox.cpp
#	$(CC) $(CPPFLAGS) -c $< -o $@

#build/polyDriver.o: src/polyDriver.cpp
#	$(CC) $(CPPFLAGS) -c $< -o $@


#tester objects
#build/testMatrix.o: test/testMatrix.cpp
#	$(CC) $(CPPFLAGS) -c $< -o $@

#build/testGauss.o: test/testGauss.cpp
#	$(CC) $(CPPFLAGS) -c $< -o $@


clean:
	rm -r bin/ build/

