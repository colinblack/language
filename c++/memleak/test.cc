#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char* mm = NULL;
	do{
		mm = (char *)malloc(100);  
		memset(mm,0x0,100);
		sleep(1);
//        free(mm);
	}while(1);

}

