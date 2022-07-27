//
// Created by htk332 on 2022-07-20.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
int main() {
    uint64_t sum = 0;
    uint64_t evensum = 0;
    char *token = NULL;
    char *endptr = NULL;
    char* input = malloc(sizeof(char) * 3000000);
    fgets(input, 3000000, stdin);
    token = strtok(input, " ,-");
    int N = strtol(token, &endptr, 0);
    token = strtok (NULL," ,.-");
    int t = strtol(token, &endptr, 0);
    //printf("%d %d\n", N, t);
    char string[N+1];
    int32_t A[N];
    fgets(input, 3000000, stdin);
    token = strtok (input," ,.-");
    A[0] = strtol(token, &endptr, 0);
    sum += A[0];
    if((A[0] % 2) == 0)
        evensum += A[0];
    //printf("%d ", A[0]);
    for (int i = 1; i < N; i++) {
        token = strtok (NULL," ,.-");
        A[i] = strtol(token, &endptr, 0);
        sum += A[i];
        if((A[i] % 2) == 0)
            evensum += A[i];
        //printf("%d ", A[i]);
    }
    //printf("\n");
    int iter = 0;
    _Bool visited[N];
    memset(visited, 0, sizeof(_Bool)*N);
    switch (t) {
        case 1:
            printf("%d", 7);
            return 0;
        case 2:
            if(A[0] > A[1]){
                printf("Bigger");
                return 0;
            } else if(A[0] == A[1]){
                printf("Equal");
                return 0;
            } else{
                printf("Smaller");
                return 0;
            }
        case 3:
            if ((A[0] < A[1] && A[1] < A[2]) || (A[2] < A[1] && A[1] < A[0]))
                printf("%d", A[1]);

            else if ((A[1] < A[0] && A[0] < A[2]) || (A[2] < A[0] && A[0] < A[1]))
                printf("%d", A[0]);
            else
                printf("%d", A[2]);
            return 0;
        case 4:
            printf("%llu", sum);
            return 0;
        case 5:
            printf("%llu", evensum);
            return 0;
        case 6:
            for (int i = 0; i < N; ++i) {
                if(A[i] % 26 == 0){
                    string[i] = 'a';
                }
                if(A[i] % 26 == 1){
                    string[i] = 'b';
                }
                if(A[i] % 26 == 2){
                    string[i] = 'c';
                }
                if(A[i] % 26 == 3){
                    string[i] = 'd';
                }
                if(A[i] % 26 == 4){
                    string[i] = 'e';
                }
                if(A[i] % 26 == 5){
                    string[i] = 'f';
                }
                if(A[i] % 26 == 6){
                    string[i] = 'g';
                }
                if(A[i] % 26 == 7){
                    string[i] = 'h';
                }
                if(A[i] % 26 == 8){
                    string[i] = 'i';
                }
                if(A[i] % 26 == 9){
                    string[i] = 'j';
                }
                if(A[i] % 26 == 10){
                    string[i] = 'k';
                }
                if(A[i] % 26 == 11){
                    string[i] = 'l';
                }
                if(A[i] % 26 == 12){
                    string[i] = 'm';
                }
                if(A[i] % 26 == 13){
                    string[i] = 'n';
                }
                if(A[i] % 26 == 14){
                    string[i] = 'o';
                }
                if(A[i] % 26 == 15){
                    string[i] = 'p';
                }
                if(A[i] % 26 == 16){
                    string[i] = 'q';
                }
                if(A[i] % 26 == 17){
                    string[i] = 'r';
                }
                if(A[i] % 26 == 18){
                    string[i] = 's';
                }
                if(A[i] % 26 == 19){
                    string[i] = 't';
                }
                if(A[i] % 26 == 20){
                    string[i] = 'u';
                }
                if(A[i] % 26 == 21){
                    string[i] = 'v';
                }
                if(A[i] % 26 == 22){
                    string[i] = 'w';
                }
                if(A[i] % 26 == 23){
                    string[i] = 'x';
                }
                if(A[i] % 26 == 24){
                    string[i] = 'y';
                }
                if(A[i] % 26 == 25){
                    string[i] = 'z';
                }
            }
            string[N] = '\0';
            printf("%s", string);
            return 0;
        case 7:
            do{
                if(A[iter] == N-1){
                    printf("Done");
                    return 0;
                } else if(visited[iter]){
                    printf("Cyclic");
                    return 0;
                } else{
                    visited[iter] = 1;
                    iter = A[iter];
                }
            } while(0 <= iter && iter < N);
            printf("Out");
            return 0;
        default:
            return 0;
    }
}