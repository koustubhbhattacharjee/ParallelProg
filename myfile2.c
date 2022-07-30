#include<omp.h>

int main()
{
    int A[1000];
    omp_set_num_threads(4);
    #pragma omp parallel
    {
        int value;
        int ID = omp_get_thread_num();
        value=pooh(ID,A);
        printf("%d\n",value);
    }
    printf("alldone\n");
}

void pooh(int a, int A[])
{
    
    A[a] = a*a;
    return A[a];
}