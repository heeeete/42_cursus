#include <stdio.h>
#include <unistd.h>

int main()
{
	if (access("aa", W_OK) == 0)
		printf("ㅆㅡ기 권권한  있있음음\n");
	else
		printf("nope");
}