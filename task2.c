#include "task2.h"

void printArr(int* arr, int size){
    for (int i=0; i<size; i++){
        printf("%d,",arr[i]);
    }
    printf("\n");
}

void testSorter(char name[10], void sortrer(int *items, int count, ...)){
    int sizes[4]={5000, 10000, 50000, 100000};
    int* testArray= (int *) malloc(sizes[3] * sizeof(int));

    //результыт сортировки каждого массива размера sizes[1..4]
    // в четырех исходных состояниях каждый из четырех
    double results[4][4];

    //исходных состояния:
    char states[][17]={"Random","Vosrost","Umensh","Vosrost i Umensh"};
    void (*generator[4])(int*, int)={randomArr,increasingArr,decreasingArr,incrDecrArr};

    clock_t start_time, finish_time;

    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++) {
            generator[j](testArray,sizes[i]);
            start_time = clock();
            sortrer(testArray, sizes[i], 0);
            finish_time = clock();

            results[i][j] = (double) (finish_time - start_time) / CLOCKS_PER_SEC;
        }
    }
    //free(testArray);

    printf("%s:\n|%-16s|%-10s|%-8s|"
           "\n--------------------------------------\n",
                    name,"State","Size","Result");

    for (int i=0; i<4; i++){
        printf("|%-16s|",states[i]);
        for (int j=0; j<3; j++) {
            printf("%10d|%8f|\n|%16s|",sizes[j],results[i][j]," ");
        }
        printf("%10d|%8f|\n--------------------------------------\n",sizes[3],results[i][3]);
    }
    printf("\n");
}

void task2(){
    char shell[]="Shall";
    char qs[]="Quick sort";
    char std_qs[]="Std quick sort";

    testSorter(shell,Shell);
    testSorter(qs,Qs);
    testSorter(std_qs,StdQsort);
}
