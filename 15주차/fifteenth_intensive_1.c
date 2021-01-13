#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *animal[4], *cry[4];
    int i = 0, l = 4;

    for (i; i < l; i++)
    {
        if (i == 3)
            animal[i] = malloc(sizeof(char) * 9);
        else
            animal[i] = malloc(sizeof(char) * 11);
        cry[i] = malloc(sizeof(char) * 4);
        switch (i)
        {
        case 0:
            strcpy(animal[i], "¿À¸®");
            strcpy(cry[i], "²Ð²Ð");
            break;
        case 1:
            strcpy(animal[i], "¿°¼Ò");
            strcpy(cry[i], "À½¸Þ");
            break;
        case 2:
            strcpy(animal[i], "µÅÁö");
            strcpy(cry[i], "²Ü²Ü");
            break;
        case 3:
            strcpy(animal[i], "¼Ò");
            strcpy(cry[i], "À½¹«");
            break;
        }
        strcat(animal[i], "´Â ");
        strcat(animal[i], cry[i]);
        printf("%s\n", animal[i]);
    }
    for (i = 0; i < l; i++)
    {
        free(animal[i]);
        free(cry[i]);
    }

    return 0;
}