//
// Created by htk332 on 2022-07-20.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main(){
    char *token = NULL;
    char *endptr = NULL;
    char* input = malloc(sizeof(char) * 3000000);
    fgets(input, 3000000, stdin);
    token = strtok(input, " ,-");
    int N = strtol(token, &endptr, 0);
    token = strtok (NULL," ,.-");
    int t = strtol(token, &endptr, 0);
    //printf("%d %d\n", N, t);
    int A[N];
    int freq[N];
    _Bool case2 = 0;
    int case3 = -1;
    fgets(input, 3000000, stdin);
    token = strtok (input," ,.-");
    A[0] = strtol(token, &endptr, 0);
    // Case 2 & 3
    for (int i = 1; i < N; i++) {
        token = strtok (NULL," ,.-");
        A[i] = strtol(token, &endptr, 0);
    }
    if (t == 2 || t == 3 || t == 4 || t == 5){
        mergeSort(A, 0, N - 1);
    }
    int i, count;
    int rem[7777];
    switch (t) {
        case 1:
            for (i = 0; i < 7777; i++)
                rem[i] = 0;
            for (i = 0; i < N; i++) {
                if (A[i] < 7777)
                    rem[A[i] % 7777] = A[i];
            }
            for (i = 1; i < 7777 / 2; i++) {
                if (rem[i] > 0 && rem[7777 - i] > 0) {
                    printf("Yes");
                    return 0;
                }
            }
            printf("No");
            return 0;
        case 2:
            for (i = 0; i < N-1; ++i) {
                if(A[i] == A[i+1]){
                    printf("Contains duplicate");
                    return 0;
                }
            }
            printf("Unique");
            return 0;
        case 3:
            for (i = 0; i < N-1; ++i) {
                count = 1;
                if (A[i] == A[i + 1]) {
                    while (A[i] == A[i + 1]) {
                        count++;
                        i++;
                        if (count > N / 2) {
                            printf("%d", A[i]);
                            return 0;
                        }
                    }
                }
            }
            printf("-1");
            return 0;
        case 4:
            if(N%2 == 0){
                N -= 1;
                printf("%d %d", A[(N/2)], A[(N/2)+1]);
                return 0;
            } else {
                N -= 1;
                printf("%d", A[((N+1)/2)]);
                return 0;
            }
        case  5:
            for (int i = 0; i < N; ++i) {
                if(A[i] >= 100 && A[i] < 1000){
                    printf("%d ", A[i]);
                } else if(A[i] >= 1000){
                    return 0;
                }
            }
            return 0;
        default:
            return 0;
    }
}