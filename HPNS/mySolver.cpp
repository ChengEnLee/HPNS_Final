#include <vector>
#include <math.h>
#include "myMatrix.h"
#include "mySolver.h"
#include "myUtil.h"
#include <omp.h>

double nrm(const Vector& v){
    int n = v.size();
    int nrm = 0;
    for(int i=0;i<n;++i)
        nrm = nrm + v[i]*v[i];
    nrm = sqrt(nrm);

    return nrm;
}

bool
jacobi(const dnMatrix& A, const Vector& b)
{

   omp_set_num_threads(5);
   /* need to be worked on */
   // Init:
   // init = guess solution
   // R = A - D, D is A's diagonal entries
   size_t n = b.size();
   Vector u(n);
   dnMatrix D(n), R(n);
   int i,j;
   for(i=0;i<n;i++){
      for(j=0;j<n;j++){
         D[i][j]=0;
         R[i][j]=0;
      }
      u[i]=0;
   }
   // find D
   for(size_t i = 0;i < n; ++i)
      D[i][i]=A[i][i];

   // find R
   R = A;
   for(size_t i=0;i<n;++i){
      R[i][i] = R[i][i] - D[i][i];
   }

   // D = D inverse
   for(size_t i=0;i<n;i++)
      D[i][i] = 1/D[i][i];

   int iter = 0;
   // loop
   // Do u_{k+1} = D^{-1}Ru_{k} + D^{-1}b : update


//while(norm(A*u - b) > pow(10, -8)) {
//#pragma omp parallel
//   for(int j=0;j<100;j++){
//      u = D*b - D*(R*u);

// entries form
/*      #pragma omp for
      for(i=0;i<n;++i){
         u[i] = ((D*b) - D*(R*u))[i];
      }
      #pragma omp barrier */
      const clock_t begin = clock();
      #pragma omp parallel for
      for(i=0;i<n;++i){
         while(float(clock()-begin)/CLOCKS_PER_SEC < 10){
            u[i] = ((D*b) - D*(R*u))[i];
         }
      }
      #pragma omp barrier
      float time = (clock() - begin)/CLOCKS_PER_SEC;
//      #pragma omp master
//      {
//      iter = iter + 1;
      printf("time: %f, residual: %f \n", time,  norm((A*u)-b));

//      if( norm((A*u)-b) < pow(10,-8)){
//         break;
//      }
//   }
//}


//      iter = iter + 1;
 //     printf("%d iter residual: %f \n",iter, norm((A*u)-b));
   cout << "Exact Solution:" << endl;
   print(u);
  // end loop
   return true;
}


