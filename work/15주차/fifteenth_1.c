#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *nick = "�Ͳ���", *mem = malloc(sizeof(char) * 20);

    printf("nick = %s\nmem = %s\n", nick, mem);
    strcpy(mem, nick);
    printf("\nstrcpy ��\n");
    printf("\n");
    printf("nick = %s\nmem = %s\n", nick, mem);
    free(mem);

    char a[10] = "�Ͳ���", b[10];

    printf("\n");
    printf("a = %s\nb = %s\n", a, b);
    strcpy(b, a);
    printf("\nstrcpy ��\n\n");
    printf("a = %s\nb = %s\n", a, b);

    return 0;
}