all: mainCalc

mainCalc: mainCalc.cpp
		g++ -o LinkedListCalculator mainCalc.cpp



clean:
		rm mainCalc
