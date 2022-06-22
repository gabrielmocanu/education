/*

Write a function countEven(int*, int) which receives an integer array and its size, and returns the number of even numbers in the array. 

*/

#include<stdio.h>
#include <stdlib.h>

int countEven(int* array, int arraySize){
    int even, i;
    even = 0;
    for(i = 0; i < arraySize; i++){
        if(array[i] % 2 == 0){
            even++;
        }
    }
    return even;
}

int main(){
    int *vector, vectorSize, i;
    i = 0;
    scanf("%d", &vectorSize);
    vector = malloc(sizeof(int) * vectorSize); 
    for(i = 0; i < vectorSize; i++){
        scanf("%d", &vector[i]);
    }
    printf("%d\n", countEven(vector, vectorSize));
    return 0;
}