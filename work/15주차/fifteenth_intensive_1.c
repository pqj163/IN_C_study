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
            strcpy(animal[i], "����");
            strcpy(cry[i], "�в�");
            break;
        case 1:
            strcpy(animal[i], "����");
            strcpy(cry[i], "����");
            break;
        case 2:
            strcpy(animal[i], "����");
            strcpy(cry[i], "�ܲ�");
            break;
        case 3:
            strcpy(animal[i], "��");
            strcpy(cry[i], "����");
            break;
        }
        strcat(animal[i], "�� ");
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