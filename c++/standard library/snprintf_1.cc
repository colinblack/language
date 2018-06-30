#include<cstdio>
#include<cstdlib>
#if 1
//snprintf是否是线程安全函数
int main()
{
	unsigned char *p = new unsigned char[10]{0x1a,0x2b,0x3c, 0x4d, 0x5e, 0x6f, 0x7a, 0x8b, 0x9c, 0x1d};

		
	char a[255] = { 0 }; int j = 0;

		for (int i = 0; i < 10; ++i)
		{
			//printf("%x ", p[i]);
			j += snprintf(a + j, 255 - j, "%x ", p[i]);
		//	printf("%d,", j);
		}
		printf("%s", a);
		delete[] p;

	return 0;
}

#endif
