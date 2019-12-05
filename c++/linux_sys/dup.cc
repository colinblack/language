/*
 * dup.cc
 *
 *  Created on: 2019年2月21日
 *      Author: colin
 */

#include <unistd.h>
#include <cstdio>


int main()
{
	int ret = dup(2);

	printf("%d", ret);
	perror("");
	return 0;
}


