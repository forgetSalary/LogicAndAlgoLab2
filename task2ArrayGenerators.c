#include "task2ArrayGenerators.h"

void randomArr(int *arr,int size){
    srand(time(NULL)+&(*arr));
    for (int i = 0; i < size; i++){
        arr[i]=(rand()%size*2)-size;
    }
}

void increasingArr(int *arr,int size){
    for (int i = 0; i < size; i++){
        arr[i]=i;
    }
}

void decreasingArr(int *arr,int size){
    for (int i = 0; i < size; i++){
        arr[i]=size-i-1;
    }
}

void incrDecrArr(int* arr,int size){
    //первая половина - массива возрастающая, вторая - убывающая

    int fstHalf=size/2;
    int scndHalf=size-fstHalf;

    int i=0;
    for (i = 0; i < fstHalf; i++){
        arr[i]=i;
    }
    for (i = scndHalf-1; i < size; i++){
        arr[i]=size-i-1;
    }
}