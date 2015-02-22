#include <stdio.h>

int main()
{
    int k =0 ;
    char c;
    scanf("%c", &c);
    while(c != '\n')
    {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            {
                 k++;
            }
            scanf("%c", &c);
    }
    printf("%d\n", k);
    return 0;
}
