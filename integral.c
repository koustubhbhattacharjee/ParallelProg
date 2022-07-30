#include<omp.h>
static long num_steps = 100000;
double step;


/* APPLYING A SYNC TO THIS WOULD BE HORRIBLE TODO: ALWAYS TRY AN APPLY SYNC TO OUTER LOOPS, NOT INNER LOOPS, i SUPPOSE */


#define NUM_THREADS 4
int main()
{
    int i,nthreads; double pi,sum,start,end;
    sum=0.0;
    nthreads=NUM_THREADS;
    omp_set_num_threads(nthreads);
    step = 1.0/(double) num_steps;
    start=omp_get_wtime();
    for(i=0;i<num_steps;i=i+nthreads)
    {
        #pragma omp parallel
        {    
            int id; double val;
            id=omp_get_thread_num();
            val=(i+id+0.5)*step;
            
/* #pragma omp critical
        {    */
            sum+=(4.0/(1.0+val*val));
       /* } */

        }
    }
    pi=sum*step;
    end=omp_get_wtime();
    printf("%lf\n",pi);
    printf("%lf\n",end-start);

}