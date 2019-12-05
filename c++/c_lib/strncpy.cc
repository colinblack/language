/*
 * strncpy.cc
 *
 *  Created on: 2019年4月3日
 *      Author: colin
 */

#include <cstdio>
#include <assert.h>
#include <string.h>

char* strcpy(char* dst, const char* src)
{
	assert(dst != NULL && src != NULL);
	char* ret = dst;
	while((*dst++ = *src++) != '\0')
		;

	return ret;
}


char* strncpy(char* dst, const char* src, size_t len)
{
	assert(dst != NULL && src != NULL);
	char* ret = dst;
	size_t src_len = strlen(src);

	size_t cnt = 0;
	if(src_len >= len)
	{
		while(cnt <= len)
		{
			*dst++ = *src++;
			cnt++;
		}
	}
	else
	{
		while(cnt <= src_len)
		{
			*dst++ = *src++;
			cnt++;
		}

		*dst = '\0';
	}

	return dst;
}
