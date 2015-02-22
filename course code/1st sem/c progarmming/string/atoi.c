#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *s1;
	char s2[10];
	int i;

	s1 = "100";
	i = atoi(s1) + 2;	/* requires stdlib.h */
	printf("s1 = %s; i+2 = %d\n", s1, i);

	s1 = "150";		/* strcpy(s1, "150"); is wrong */
	i = atoi(s1) + 2;	/* requires stdlib.h */
	printf("s1 = %s; i+2 = %d\n", s1, i);

	strcpy(s2, "202");	/* s2 = "202"; is wrong */
	i = atoi(s2) + 2;
	printf("s2 = %s; i+2 = %d\n", s1, i);

	return 0;
}

