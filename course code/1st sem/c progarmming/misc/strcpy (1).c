#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char s1[100];
	char s2[100] = "100";
	int i;

	strcpy(s1, s2);		/* requires string.h */
	printf("s1 = %s; s2 = %s\n", s1, s2);

	s1[0] = 'A';
	printf("s1 = %s; s2 = %s\n", s1, s2);

	i = atoi(s2) + 2;	/* requires stdlib.h */
	printf("i = %d\n", i);

	return 0;
}

