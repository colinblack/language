#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef   unsigned char  VOS_UINT8;
typedef   char   VOS_CHAR;
typedef   unsigned int   VOS_UINT32;

VOS_UINT8  g_u8Value[20] = {0x11,  0x01, 0x0, 0x2, 0x32, 0x0, 0x0, 0x0, 0x0, 0x5, 0x22, 0x43, 0x22, 0x55, 0x0, 0x01, 0x02, 0x08, 0x0, 0x01};


int main()
{
	VOS_UINT8  a = 0x7E;
    VOS_CHAR*  Info = (VOS_CHAR*)malloc(sizeof(VOS_CHAR)*512); 
	VOS_CHAR*  pAlarmInfo = Info;
    VOS_UINT32 u32Offest = ::snprintf(pAlarmInfo, 512, "%02x %02x %02x %02x %02x ", 0x7E, 0x01, 0x21, 0x42, 0x20);
    pAlarmInfo += u32Offest;   
	for (int i = 0; i < 20; ++i)
	{
       u32Offest = ::snprintf(pAlarmInfo, 512, "%02x ", g_u8Value[i]);
       if(u32Offest == -1)
       {
            printf("copy errc");
            return 0;
       }
       pAlarmInfo += u32Offest;
	}
    *pAlarmInfo = '\n';
        


   ::printf("%s", Info);    
    ::printf("haha"); 


	free(Info);
	return 0;
}
