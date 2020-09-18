#include "task1.h"
#include "task2.h"

int main(void){

    printf("Task ?: ");
    char task=_getch();
    printf("\n");

    if (task=='1'){
        printf("Task 1:\n");
        task1();
        _getch();
    }

    if (task=='2'){
        printf("\nTask 2:\n");
        task2();
        _getch();
    }

    return 0;
}

