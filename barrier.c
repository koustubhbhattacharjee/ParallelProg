/* all threads arrive here before we go on*/

#include<omp.h>

void main(){
#pragma omp parallel
{
    int id=omp_get_thread_num();
    A[id]=big_cal1(id);
/* A has to be finished before B */    
#pragma omp barrier
    B[id]=big_calc2(id);

}
}