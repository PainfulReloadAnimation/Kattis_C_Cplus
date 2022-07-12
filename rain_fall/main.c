//
// Created by htk332 on 2022-06-27.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
    double outmax;
    char *token = NULL;
    char *endptr = NULL;
    char input[150];
    fgets(input, 150, stdin);
    token = strtok(input, " ,-");
    double position = strtod(token, &endptr);
    if (position < 0.01 || position > 1000.00){
        return 0;
    }
    token = strtok(NULL, " ,-");
    double rate = strtod(token, &endptr);
    if (rate < 0.01 || rate > 1000.00){
        return 0;
    }
    token = strtok(NULL, " ,-");
    double t0 = strtod(token, &endptr);
    if (t0 < 0.01 || t0 >  1000.00){
        return 0;
    }
    token = strtok(NULL, " ,-");
    double t1 = strtod(token, &endptr);
    if (t1 < 0.01 || t1 >  1000.00){
        return 0;
    }
    token = strtok(NULL, " ,-");
    double observe = strtod(token, &endptr);
    if (observe <  0.01 || observe >  1000.00){
        return 0;
    }
    if (observe < position) {
        printf("%f %f", observe, observe);
        return 0;
    }
    /*double test1 = observe+rate*t0+rate*t1;
    double test2 = sqrt(((rate*t0+rate*t1+observe)*(rate*t0+rate*t1+observe))-4*position*rate*t0);
    double test3 = test1 + test2;
    printf("Test 1: %f Test 2: %f Test3: %f\n", test1, test2, test3);*/
    outmax = ((observe+rate*t0+rate*t1+ sqrt(((rate*t0+rate*t1+observe)*(rate*t0+rate*t1+observe))-4*position*rate*t0))*t0)/(t0*2);
    if (observe > position) {
        printf("%f %f", outmax, outmax);
        return 0;
    }
    else {
        printf("%f %f", position, outmax);
        return 0;
    }
}