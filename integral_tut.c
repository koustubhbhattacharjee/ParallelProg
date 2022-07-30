#include<omp.h>
static long num_steps = 100000;
double step;
#define PAD 8
/* this doesn't work due to the inner for loop which takes forever, use the one mentioned by the videos */
#define NUM_THREADS 4
void main()
{
    /* Next step is the most TODO:IMPORTANT thing in parallel processing*/
    int i,nthreads; double pi,sum[NUM_THREADS][PAD];
    omp_set_num_threads(NUM_THREADS);
    step = 1.0/(double) num_steps;
    /*printf("%lf\n",omp_get_wtime()); */
    #pragma omp parallel
    {
        int i,id,nthrds;
        double x;
        id=omp_get_thread_num();
        nthrds=omp_get_num_threads();

        /* TODO:the next step is subtle threads = local number of threads*/

        if (id==0) nthreads = nthrds;
        for (i=id,sum[id]=0.0;i<num_steps;i=i+nthrds)
        {
            x=(i+0.5)*step;
            sum[id][0]+= 4.0/(1.0+x*x);
        
        }
    }
    for (i=0,pi=0.0;i<nthreads;i++)
    {
            pi+=sum[i][0]*step;
    }
    printf("what %lf",pi);
}

