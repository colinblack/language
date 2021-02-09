#include<stdio.h>
#include<stdlib.h>


int main(){
    int* pValue = (int*)malloc(sizeof(int));
    *pValue = 1;
    printf("value=%d", *pValue);
    return 0;
}

