/*
 * my_memcpy.c
 *
 *  Created on: 2019年4月3日
 *      Author: colin
 */

#include <cstdio>

#define OPSIZE 8


#define COPY_BY_BYTE(dst_p, src_p, len)\
do{	\
	size_t _len = len;\
	while(len > 0)\
	{		\
		unsigned char byte = ((unsigned char*)src_p)[0];\
		src_p++;\
		((unsigned char*)dst_p)[0] = byte;\
		dst_p++;\
		_len--;\
	}\
}while(0)\

#define COPY_BY_LONG(dst_p, src_p, len)\
do{	\
	size_t _len = len;\
	while(len > 0)\
	{		\
		unsigned long date = ((unsigned long*)src_p)[0];\
		src_p++;\
		((unsigned long *)dst_p)[0] = date;\
		dst_p++;\
		_len--;\
	}\
}while(0)\

void* my_memcpy(void* dst, void* src, size_t len)
{
	unsigned long p_src = (long)&src;
	unsigned long p_dst = (long)&dst;

	//先将字节不对齐的部分按byte拷贝
	len -= (-p_dst) % OPSIZE;
	COPY_BY_BYTE(p_dst, p_src, (-p_dst % OPSIZE));

	size_t long_len = len / sizeof(long);

	COPY_BY_LONG(p_dst, p_src, long_len);

	len %= sizeof(long);
	COPY_BY_BYTE(p_dst, p_src, len);

	return dst;
}


int main()
{

	return 0;
}
