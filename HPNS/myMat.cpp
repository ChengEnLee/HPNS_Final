#include "myMatrix.h"

dnMatrix::dnMatrix() { }

dnMatrix::~dnMatrix() { }

dnMatrix::dnMatrix(size_t n, double x)
{
   _mat.resize(n, Vector(n, x)); 
}
   
dnMatrix::dnMatrix(const string& name) 
{
   ifstream fin;   fin.open(name);
   if(fin.is_open()) {
      size_t m, n;
      string str;
      stringstream ss;
      ss >> m >> n; 
   }
}
   
Vector&
dnMatrix::operator[] (size_t i)
{
   return _mat[i];
}

const Vector&
dnMatrix::operator[] (size_t i) const
{
   return _mat[i];
}

Vector
dnMatrix::operator* (const Vector& v) const
{
   size_t n = _mat.size(); 
   Vector x(n);
   for(size_t i = 0; i < n; ++i)
      x[i] = _mat[i]*v;
   return x;
}
// Matrix + -
/*dnMatrix
dnMatrix::operator+ (const dnMatrix& m) const
{
   size_t n = _mat.size();
   dnMatrix B(n);
   for(size_t i=0; i<n; ++i){
      for(size_t j=0; j<n; j++){
         B[i][j] =
*/
size_t
dnMatrix::size() const
{
   return _mat.size();
}


