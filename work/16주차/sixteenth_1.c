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
    printf("h���� : %d\n", h);

    printf("ù��° s��ġ : %d\n", strchr(var, 's') - var);

    printf("%s\n", strrchr(var, 'r'));

    printf("������ i��ġ : %d\n", strrchr(var, 'i') - var);

    return 0;
}