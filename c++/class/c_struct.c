#include <stdio.h>
#include <stdlib.h>

typedef struct data{
    int a;
    float b;
}data_s, *data_p;

int main(void)
{
    data_p mem = (data_p)malloc(sizeof(data_s));    



    return 0;
}
