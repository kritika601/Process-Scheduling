#include <stdio.h>
#include <stdlib.h>
#include <time.h>
unsigned long long power(unsigned long long a,unsigned long long b){
    unsigned long long ans=1;
    for (unsigned long long i=1;i<=b;i++){
        ans*=a;
    }
    return ans;
}

int main() {
    struct timespec s,e;
    clock_gettime(CLOCK_MONOTONIC_RAW, &s);
    unsigned long long val=power(2,32);
    unsigned long long count=0;
    for (unsigned long long j=1;j<=val;j++){
        count+=1;
    }
    FILE *file = fopen("output.txt", "a");
    if (file == NULL) {
        printf("FILE WRITING ERROR!");
    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &e);
    double duration = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / 1e9;
    printf("Execution Time is %lf seconds\n", duration);
    char S[20];
    sprintf(S, "%.6lf", duration);
    fprintf(file,S);
    fprintf(file,"\n");
    fclose(file);
    return 0;
}
