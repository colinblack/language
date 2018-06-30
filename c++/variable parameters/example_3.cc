#include<stdio.h>


void
UTIL_WriteLog(
int             Priority,
const char     *Fmt,
...
)
{
	va_list       vaa;
	time_t        lTime;
	struct tm    *curTime;
	char          szDateBuf[260];

	time(&lTime);

	curTime = localtime(&lTime);
	strftime(szDateBuf, 128, "%Y-%m-%d   %H:%M:%S", curTime);
	szDateBuf[strlen(szDateBuf) - 1] = '\0'; //remove the

	va_start(vaa, Fmt);

	fprintf(pLogFile, "[%s]", szDateBuf);
	vfprintf(pLogFile, Fmt, vaa);
	fprintf(pLogFile, "\n");
	fflush(pLogFile);

	va_end(vaa);
}


int main(int argc, char* argv[])
{

	return 0;
}