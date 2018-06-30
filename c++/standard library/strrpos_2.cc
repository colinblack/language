#include <stdio.h>
#include <string.h>

const char* strrpos(const char* dst,const  char *src)
{
    if(src == NULL)
    {
        return NULL;
    }
    
 const   char* pos = strrchr(dst, *src);
    if(pos == NULL)
    {
        return NULL;
    }
   return strstr(pos,src);

}


const char* findStrInRange(const char* begin, const char* end, const char* src)
{
const   char *pos = strrpos(begin, src);
   if(pos > end)
   {
      return NULL;
   }
   return pos;
}

int main()
{
    char* p1 = "abcdekfabdekghhhf";
    char *p2 = p1+2;    
    char *p3 = p1+14;
    char *p4 = "dek";
    const char* pos = findStrInRange(p2, p3, p4);
    printf("%s \n", pos);
    return 0;
}
