#include <stdio.h>
#include <string.h>

int main()
{
    char *NickName = "�Ͳ���";
    int len = strlen(NickName);
    printf("%d����\n", len / 2);
    for (int i = 0; i < len; i += 2)
    {
        printf("%c%c", NickName[i], NickName[i + 1]);
    }
    printf("\n");
    for (int i = 0; i < len; i += 2)
    {
        printf("%c%c", NickName[len - (i + 2)], NickName[len - (i + 1)]);
    }
    printf("\n");
    return 0;
}