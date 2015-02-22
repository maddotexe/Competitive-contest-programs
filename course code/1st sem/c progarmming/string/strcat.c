#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char s1[100];
	char s2[100] = "100";

	strcpy(s1, s2);
	printf("s1 = %s; s2 = %s\n", s1, s2);

	strcat(s1, "1  1");	/* requires string.h */
	printf("s1 = %s; s2 = %s\n", s1, s2);

	strcat(s1, "\nyes\n");	/* requires string.h */
	printf("s1 = %s; s2 = %s\n", s1, s2);

	return 0;
}

/* See also strncat() */

