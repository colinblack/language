#include <iostream>
#include <dlfcn.h>
#include "main.h"



int main()
{
	void* handle = dlopen("/usr/lib/liblusterstuff1.so.1.0.1", RTLD_LAZY);
	so_install_func p1 = dlsym(handle, "soLibInstall");
	p1(nullptr, 1);

	void* handle1 = dlopen("/usr/lib/liblusterstuff.so.1.0.1", RTLD_LAZY);
	so_install_func p2 = dlsym(handle1, "soLibInstall");
	p2(nullptr, 2);
	dlclose(handle);
	dlclose(handle1);

	return 0;
}