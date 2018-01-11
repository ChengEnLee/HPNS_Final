#include "myMatrix.h"
#include <math.h>

using namespace std;

double
norm(const Vector& v)
{
   return sqrt(v*v);
}

void
print(const Vector& v) 
{
   size_t n = v.size(); 
   for(size_t i = 0; i < n; ++i)
      cout << v[i] << ' ';
   cout << endl;
}

void
print(const dnMatrix& m) 
{
   size_t n = m.size(); 
   for(size_t i = 0; i < n; ++i)
      print(m[i]); 
}
