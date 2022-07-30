/* PARTS of a code can be mutually excluded, so it's not just concurrent code */

float res;

#pragma omp parallel
void main()
{
    float B; int i,id,nthrds;
    id=omp_get_thread_num();
    nthrds=omp_get_num_threads();
    for(i=id;i<niters;i+=nthrds)
    {
        B=big_job(i);
#pragma omp critical  /*waits here*/
        res+= consume(B);
    }
}

