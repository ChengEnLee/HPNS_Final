#ifndef MY_MATRIX_H
#define MY_MATRIX_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// in myVec.cpp
class Vector{
public:
   Vector();
   ~Vector();
   // initialize a length n constant vector with value x (x is 0 by default) 
   Vector(size_t n, double x = 0);

   // return the ith component
   double& operator[] (size_t i);
   double  operator[] (size_t i) const;

   // return the inner product of two vectors
   double operator*  (const Vector& v) const;
   // return the summation(subtraction) of two vectors
   Vector operator+  (const Vector& v) const;
   Vector operator-  (const Vector& v) const;

   // return the length
   size_t size() const;

private:
   vector<double> _vec;
};

// in myMat.cpp
class dnMatrix{
public:
   dnMatrix();
   ~dnMatrix();
   // initialize an n by n constant matrix with value x (x is 0 by default)
   dnMatrix(size_t n, double x = 0);
   dnMatrix(const string& name);

   // return the ith row
   Vector&       operator[] (size_t i);
   const Vector& operator[] (size_t i) const;

   // return matrix vector multiplication
   Vector operator* (const Vector& v) const;

   // return matrix summation(subtraction) of two matrices
//   dnMatrix operator+ (const dnMatrix& m) const;
//   dnMatrix operator- (const dnMatrix& m) const;

   // return the number of rows
   size_t size() const;

private:
   vector<Vector> _mat;
};
/*
class spMatrix {
public:
   spMatrix() { }
   spMatrix(const string& name) {
      ifstream fin;   fin.open(name);
      if(fin.is_open()) {
         double v;
         size_t c, r;
         string str;
         stringstream ss;
         while(getline(fin, str)) {
            ss.str(""); ss.clear();
            ss << str;
         }
      }
      fin.close();
   }
   ~spMatrix() { }

   void print() const {
      cout << "values:" << endl << ' ';
      for(vector<double>::const_iterator it = _val.begin(); it != _val.end(); ++it)
         cout << (*it) << ' ';
      cout << "columns:" << endl << ' ';
      for(vector<size_t>::const_iterator it = _col.begin(); it != _col.end(); ++it)
         cout << (*it) << ' ';
      cout << "rows: " << endl << ' ';
      for(vector<size_t>::const_iterator it = _row.begin(); it != _row.end(); ++it)
         cout << (*it) << ' ';
   }
private:
   vector<double> _val; 
   vector<size_t> _col, _row;
};
*/
#endif
