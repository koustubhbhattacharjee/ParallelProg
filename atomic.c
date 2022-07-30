/* for quick calculations using hardware native infra */
void main(){

    #pragma omp parallel 
    {
        double tmp,B;
        B=DOIT();
        tmp=big_ugly_calc(B);
    #pragma omp atomic
        X+= tmp;
    }
}