#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char ch;
	char str1[10];
	char *str2;
	int i;

	ch = getchar();
	getchar();

	/* read 9 chars add null */
	str2 = fgets(str1, 10, stdin);

	printf("ch = %c\n", ch);
	printf("str1 = %s\n", str1);
	printf("str2 = %s\n", str2);

	str2 = "Hello World";
	printf("str2 = %s\n", str2);

	return 0;
}

