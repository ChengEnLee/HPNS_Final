#include "myMatrix.h"
#include <vector>

Vector::Vector() { }
   
Vector::Vector(size_t n, double x)
{
   _vec.resize(n, x);
}

Vector::~Vector() { }


double&
Vector::operator[](size_t i)
{
   return _vec[i];
}

double
Vector::operator[](size_t i) const
{
   return _vec[i];
}

double 
Vector::operator* (const Vector& v) const
{
   double x;   x = 0;
   for(size_t i = 0, n = _vec.size(); i < n; ++i)
      x = x + _vec[i]*v[i];
   return x; 
}

Vector 
Vector::operator+ (const Vector& v) const 
{
   size_t n;   n = _vec.size();
   Vector x(n);    
   for(size_t i = 0; i < n; ++i)
      x[i] = _vec[i] + v[i];
   return x;
}

Vector 
Vector::operator- (const Vector& v) const
{
   size_t n;   n = _vec.size();
   Vector x(n);    
   for(size_t i = 0; i < n; ++i)
      x[i] = _vec[i] - v[i];
   return x;
}

size_t
Vector::size() const
{
   return _vec.size();
}

