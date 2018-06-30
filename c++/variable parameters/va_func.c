#include<stdio.h>
#include<stdarg.h>

double add(double sum, ...)  
{
	va_list argptr;
va_start(argptr, sum);
	double end = 0.0;
	while(1)
	{
		end = va_arg(argptr, int);
		if (0.0000001 > end) break;
		sum += end;
	}
	va_end(argptr);
	return sum;
}

#define MACRO_(...) add(__VA_ARGS__, 0)

int main(int argc, char* argv[])
{
	double d2 = MACRO_(1, 6);
	printf("%0.2f", d2);
	return 0;
}
