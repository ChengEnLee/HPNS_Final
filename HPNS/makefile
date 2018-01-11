main: main.o myVec.o myMat.o mySolver.o myUtil.o
	g++ -std=c++11 -g -Wall -fopenmp -o $@ $^

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

#myMatrix.o: myVec.o myMat.o myMatrix.h
#	g++ -std=c++11 -O3 -o myMatrix.o  myVec.o myMat.o

myVec.o: myVec.cpp 
	g++ -std=c++11 -c myVec.cpp

myMat.o: myMat.cpp 
	g++ -std=c++11 -g -c myMat.cpp

mySolver.o: mySolver.cpp
	g++ -std=c++11 -fopenmp -g -c mySolver.cpp

myUtil.o: myUtil.cpp myUtil.h
	g++ -std=c++11 -c myUtil.cpp

clean:
	rm *.o
