#include <stdio.h>  
#include <unistd.h>  
 
int main(int argc, char *argv[])  
{  
        int ch;  
        opterr = 0;  
        while ((ch = getopt(argc,argv,"a::b:cde"))!=-1)  
        {  
                switch(ch)  
                {  
                        case 'a':  
                                printf("option a:'%s'\n",optarg);  
                                break;  
                        case 'b':  
                                printf("option b :'%s'\n",optarg);  
                                break;  
                        default:  
                                printf("other option :%c\n",ch);  
                }  
        }  
        printf("optopt +%c\n",optopt);  
}  
