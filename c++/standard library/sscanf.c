//sscanf���Դ���
#include <stdio.h>



int main()
{
	char line[256];
	long arg1, arg2;
	fgets(line, sizeof(line), stdin);

	int ret = sscanf(line, "%ld%ld", &arg1, &arg2); //�Կո���������������
	printf("%d, %d, %d \n", ret, arg1, arg2);
}

