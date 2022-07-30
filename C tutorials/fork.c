#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(int arg, char* argv[]) {
    int id1=fork();
    int id2=fork();
    int arr[2]={id1,id2};
    printf("hellowrold from id:%d      %d\n",arr[0],arr[1]);

    if (id1!=0 && id2!=0){
        printf("Hello from parent process\n");
    }
    else {
        printf("Hello from child processes\n");
    }
    return 0;
}