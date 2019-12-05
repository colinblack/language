#include <stdio.h>
#include <string.h>

char* strrpos(char* dst, char *src)
{
    if(src == NULL)
    {
        return NULL;
    }
    
    char* pos = strrchr(dst, *src);
    if(pos == NULL)
    {
        return NULL;
    }
   return strstr(pos,src);

}

int main()
{
    char* p1 = "ab/*defgabci/*f";
    char* p2 = "/*f";
    char* pos = strrpos(p1, p2);
    printf("%s", pos);
    return 0;
}
