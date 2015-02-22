#include <stdio.h>
#include <string.h>

int main()
{
	char str1[]="hello world";
	char str2[]="lo";
	void *result;

	result = strstr(str1, str2);

	if ( result == NULL ) {
		printf("%s is not a substring of %s\n", str2, str1);
	} else {
		printf("%s is a substring of %s\n", str2, str1);
	}

	return 0;
}

