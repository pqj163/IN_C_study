#include <stdio.h>
#include <string.h>

int main()
{
    char a[10] = "dhfl", b[10] = "ehowl";
    printf("a = %s\nb = %s\n", a, b);
    strcat(a, b);
    printf("\nstrcat 후\n");
    printf("\n");
    printf("a = %s\nb = %s\n", a, b);

    char c[10] = "dhflrhrl", d[10] = "ehowlrhrl";

    return 0;
}