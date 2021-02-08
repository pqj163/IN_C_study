#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "dhfl rhrl siasia";
    char *ptr = strtok(str, " ");
    char *result[3];
    int i;
    result[0] = ptr;

    for (i = 1; i < 3; i++)
    {
        ptr = strtok(NULL, " ");
        result[i] = ptr;
    }
    for (i = 0; i < 3; i++)
        printf("%s\n", result[i]);

    return 0;
}