#include <stdio.h>
#include <string.h>

int main()
{
    char *var = "dhflrhrlsiasia",
         *temp = strchr(var, 'r');
    printf("%s\n", temp);
    printf("%s\n", strchr(temp + 1, 'r'));

    temp = strchr(var, 'h');
    int h = 0;
    while (temp != NULL)
    {
        h++;
        temp = strchr(temp + 1, 'h');
    }
    printf("h개수 : %d\n", h);

    printf("첫번째 s위치 : %d\n", strchr(var, 's') - var);

    printf("%s\n", strrchr(var, 'r'));

    printf("마지막 i위치 : %d\n", strrchr(var, 'i') - var);

    return 0;
}