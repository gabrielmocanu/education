/*

Write a function that returns a pointer to the maximum value of an array of double's.  If the array is empty, return NULL.
double* maximum(double* a, int size);

*/
#include<stdio.h>
#include <stdlib.h>
double* maximum(double* a, int size){
    int i;
    double min;
    double* p;
    if (size == 0){
        return NULL;
    }
    min = a[0];
    p = &a[0]; // p = a;
    for(i = 1; i < size; i++){
        if(a[i] > min){
            min = a[i];
            p = &a[i]; // p = a + i;
        }
    }
    return p;
}

int main(){
    double *vector, *pointer;
    int vectorSize, i;
    scanf("%d", &vectorSize);
    vector = malloc(sizeof(double) * vectorSize); 
    for(i = 0; i < vectorSize; i++){
        scanf("%lf", &vector[i]);
    }
    pointer = maximum(vector, vectorSize);
    printf("%lf", *pointer);
}