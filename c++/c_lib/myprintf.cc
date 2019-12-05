/*
 * myprintf.cc
 *
 *  Created on: 2019年3月18日
 *      Author: colin
 */
#include <iostream>
#include <cstdio>
#include <cstdarg>

#define MAX_BUF 128


int myprintf(const char* format, ...)
{
	char buff[MAX_BUF] = {0};
	va_list var;
	va_start(var, format);

	int integer = 0;
	int number = 0;
	int count = 0;
	int tmp  = 0;
	char* tmpS = NULL;

	for(char* pBuff = buff; *format != '\0'; )
	{
		switch(*format)
		{
		case '%':
			++format;
			switch(*format)
			{
			case 'd':
				++format;
				integer = va_arg(var, int);
				tmp = integer;
				while(tmp)
				{
					++number;
					++count;
					tmp /= 10;
				}

				for(int i = number; i > 0; --i)
				{
					*(pBuff + i -1) = (integer % 10) + '0';
					 integer /= 10;
				}
				pBuff += number;

				break;

			case 'c':
				++format;
				*pBuff++ = va_arg(var, int);
				count += 1;
				break;

			case 's':
				++format;
				tmpS = va_arg(var, char*);
				while(*tmpS != '\0')
				{
					*pBuff++ = *tmpS++;
					count++;
				}

				break;
			}
			break;
		default:
			*pBuff++ = *format++;
			break;
		}
	}

	va_end(var);
	puts(buff);
	return count;
}


int main()
{
	int a = 111;
	myprintf("%d \n", a);
	return 0;
}
