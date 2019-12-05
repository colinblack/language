#include <iostream>
#include <cstring>

class Solution {
public:
	static char *strStr(const char *haystack, const char *needle) {
		// if needle is empty return the full string
		if (!*needle) return (char*)haystack;
		const char *p1;
		const char *p2;
		const char *p1_advance = haystack;
		for (p2 = &needle[1]; *p2; ++p2) {
			p1_advance++; // advance p1_advance M-1 times
		}
		for (p1 = haystack; *p1_advance; p1_advance++) {
			char *p1_old = (char*)p1;
			p2 = needle;
			while (*p1 && *p2 && *p1 == *p2) {
				p1++;
				p2++;
			}
			if (!*p2) return p1_old;
			p1 = p1_old + 1;
		}
		return nullptr;
	}
};


int main()
{
	char* p1 = "abcdefghi";
	char* p2 = "cde";

	char* p3 = Solution::strStr(p1, p2);
	std::cout << p3 << std::endl;

	system("pause");
	return 0;
}