#include "task1.h"

#define SIZE 1000
#define sqrMatrix(s) (int**) malloc(s*sizeof(int*) + s*s*sizeof(int))

void arrOutput(int* arr,int r,int c){
    printf("-------------------------------------------------------------\n");
    arr+=r;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            printf("%3d|",*arr);
            arr++;
        }
        printf("\n-------------------------------------------------------------\n");
    }
    printf("\n\n");
}

void defMatrxPoiners(int** m, int size){
    m[0] = (int*)(m + size);
    for (int i = 1; i < size; i++) {
        m[i] = m[0] + i * size;
    }
}

int task1(void){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    clock_t start_time, finish_time; // объявляем переменные для определения времени выполнения

    int i, j, r, elem_c;

    int** a=NULL;
    int** b=NULL;
    int** c=NULL;

    a=sqrMatrix(SIZE);
    b=sqrMatrix(SIZE);
    c=sqrMatrix(SIZE);

    defMatrxPoiners(a,SIZE);
    defMatrxPoiners(b,SIZE);
    defMatrxPoiners(c,SIZE);

    printf("Matrix size: %d\n",SIZE);

    srand(time(NULL)); // инициализируем параметры генератора случайных чисел
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            a[i][j]=rand()% (SIZE/2) + 1; // заполняем массив случайными числами rand()% (SIZE/2) + 1
        }
    }


    srand(time(NULL)); // инициализируем параметры генератора случайных чисел
    i=0; j=0;

    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            b[i][j]=rand()% (SIZE/2) + 1; // заполняем массив случайными числами
        }
    }


    start_time=clock();
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            elem_c=0;
            for(r=0;r<SIZE;r++)
            {
                elem_c=elem_c+a[i][r]*b[r][j];
                c[i][j]=elem_c;
            }
        }
    }
    finish_time=clock();

    double wait_time = (double)(finish_time - start_time) / CLOCKS_PER_SEC;
    

    printf("%f",wait_time);

    free(a);
    free(b);
    free(c);

    return(0);
}