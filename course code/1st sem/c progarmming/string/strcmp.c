#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char s1[100] = "ABD";
	char s2[100] = "ABEDS";

	if (strcmp(s1, s2) < 0) {
		printf("%s < %s\n", s1, s2);
	} else if ( strcmp(s1, s2) > 0 ) {
		printf("%s > %s\n", s1, s2);
	} else {
		printf("%s == %s\n", s1, s2);
	}

	return 0;
}

