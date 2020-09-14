#include "task2.h"

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

void printArr(int* arr, int size){
    for (int i=0; i<size; i++){
        printf("%d,",arr[i]);
    }
    printf("\n");
}

void testSorter(void func()){

}

void task2(){
    int size=1000;
    double result;


    //shell
    printf("Shell:\n");

    int* testArray=(int*)malloc(size*sizeof(int));

    

}
