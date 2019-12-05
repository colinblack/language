#include <iostream>

#define POWER_RECOVER_PER_SEC 4 
#define AddPower(now, last) ((now - last)/POWER_RECOVER_PER_SEC)

int main()
{
	int ret = AddPower(25, 5);
    std::cout << ret << std::endl;
	return 0;
}
