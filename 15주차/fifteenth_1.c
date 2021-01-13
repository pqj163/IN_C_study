#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *nick = "¸Í²ÇÀÌ", *mem = malloc(sizeof(char) * 20);

    printf("nick = %s\nmem = %s\n", nick, mem);
    strcpy(mem, nick);
    printf("\nstrcpy ÈÄ\n");
    printf("\n");
    printf("nick = %s\nmem = %s\n", nick, mem);
    free(mem);

    char a[10] = "¸Í²ÇÀÌ", b[10];

    printf("\n");
    printf("a = %s\nb = %s\n", a, b);
    strcpy(b, a);
    printf("\nstrcpy ÈÄ\n\n");
    printf("a = %s\nb = %s\n", a, b);

    return 0;
}