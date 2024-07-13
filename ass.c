#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sched.h>
#include <errno.h>

void callcount(){
    char *count= "./count"; 
    execl(count, count, NULL);
    printf("ERROR IN EXECL");
    exit(EXIT_FAILURE);
}

int main() {
    int s;
    FILE *file = fopen("output.txt", "w");
    for (int i = 0; i <= 2; i++) {
        //creating child proccess.
        pid_t child_pid = fork();
        if (child_pid < 0) {
            printf("ERROR IN FORK");
            exit(EXIT_FAILURE);
        }
        else if (child_pid == 0) {
            int n = 0;
            if (i == 0) {
                n= 0; 
            } else if (i == 1) {
                n= 10; 
            } else if (i == 2) {
                n= -10; 
            }
            if (nice(n) == -1) {
                printf("ERROR IN NICE VALUE");
                exit(EXIT_FAILURE);
            }
            //callcount();
            char *count= "./count"; 
            execl(count, count, NULL);
            printf("ERROR IN EXECL");
            exit(EXIT_FAILURE);
            
        }
    }
    //child process must finish.
    int j=0;
    while(j<=2){
        pid_t tp = waitpid(-1, &s, 0);
        if (tp == -1) {
            printf("ERROR IN FINISHING PROCESS");
            exit(EXIT_FAILURE);
        }
        j++;
    }
    fclose(file);
    return 0;
}
