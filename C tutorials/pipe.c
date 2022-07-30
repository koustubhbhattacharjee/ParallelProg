int main(int argc, char* argv[]){
    int fd[2];
    if (pipe(fd) == -1) {
        printf("An error occured with opening in pipe \n");
        return 1;
    }
    int id = fork();
    return 0;

}