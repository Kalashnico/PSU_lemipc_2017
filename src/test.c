#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int **test = malloc(sizeof(int *) * 2);
    
    test[0] = malloc(sizeof(int));
    test[1] = malloc(sizeof(int));

    test[0][0] = 1;
    test[1][0] = 2;

    void *map;
    map = test;

    printf(": %d\n", (int**)map[1][0]);
}