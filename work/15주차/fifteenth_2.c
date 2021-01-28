#include <stdio.h>
#include <string.h>

int main()
{
    char a[10] = "dhfl", b[10] = "ehowl";
    printf("a = %s\nb = %s\n", a, b);
    strcat(a, b);
    printf("\nstrcat ÈÄ\n");
    printf("\n");
    printf("a = %s\nb = %s\n", a, b);

    char c[17] = "dhflrhrl", d[10] = "ehowlrhrl";
    strcat(c, d);
    printf("\n%s\n", c);

    char e[10] = "dhfl", *f = "ehowl";
    strcat(e, f);
    printf("\n%s\n", e);

    return 0;
}