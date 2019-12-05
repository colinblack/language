#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "memleak.h"

int main()
{
  void *a,*b,*c;
  char *s;
  dbg_init(10);
  dbg_catch_sigsegv();
  a = malloc(1000);


  dbg_mem_stat();
  dbg_heap_dump("");
  return 0;
}
