#include <stdio.h>
// #include <string.h>
#include <stdlib.h>

int main()
{
    char *str1 = "123";
    int x1 = atoi(str1);
    printf("%d\n", x1);
    char str2[] = "3.14";
    double x2 = atof(str2);
    printf("%f\n", x2);

    return 0;
}