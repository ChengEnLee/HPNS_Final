#include<iostream>
#include<stdio.h>
#include<omp.h>

using namespace std;

int main(){

    omp_set_num_threads(8);

#pragma omp parallel
{
    #pragma omp for
    for (int i=0; i<4 ; ++i){
        printf("%d,from %d\n",i,omp_get_thread_num());
    }
}
}
