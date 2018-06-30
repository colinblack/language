#include <iostream>
#include <dlfcn.h>
#include "main.h"

extern "C"
{
    int soLibInstall(char* var1, int var2);
}

int main()
{
	void* handle = dlopen("/usr/lib/libtest.so", RTLD_LAZY);
	if(handle == nullptr)
        std::cout << "err" << std::endl;
    so_install_func p  = (so_install_func)dlsym(handle, "soLibInstall");

    p(nullptr, 1);

	void* handle1 = dlopen("/usr/lib/libtest1.so", RTLD_LAZY);
	so_install_func p2 = (so_install_func)dlsym(handle1, "soLibInstall");
	p2(nullptr, 2);

    dlclose(handle);
    dlclose(handle1);
	return 0;
}
