#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char s1[10];
	char *s2;

	strcpy(s1, "Good");
	s2 = "World";
	s2 = "WoRld";
	printf("%s %s\n", s1, s2);

	s1[0] = 'A';
	printf("%c %c\n", s1[0], s2[0]);

	printf("%d %d\n", strlen(s1), strlen(s2));

	return 0;
}

