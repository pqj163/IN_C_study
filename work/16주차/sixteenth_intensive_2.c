#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RemoveEnd(char *buf);
int main()
{
    FILE *fp = fopen("work\\16주차\\욕목록.txt", "r");
    char *lan[480];
    for (int i = 0; i < 480; i++)
    {
        char *buf = (char *)malloc(40);
        fgets(buf, 10, fp);
        RemoveEnd(buf);
        lan[i] = buf;
    }
    fclose(fp);

    int count = 0, ch = 0;
    char sc[50], *temp;
    while (count < 5)
    {
        ch = 0;
        printf("입력(멈추고 싶으면 '그만') : ");
        scanf(" %[^\n]s", &sc);
        if (strcmp(sc, "그만") == 0)
            break;

        for (int i = 0; i < 480; i++)
        {
            temp = strstr(sc, lan[i]);
            while (temp != NULL)
            {
                printf("욕설을 하지 말아주세요. 남은 경고 횟수 = %d\n", 4 - count);
                count += 1;
                ch = 1;
                temp = strstr(temp + 1, lan[i]);
            }
        }

        if (ch == 0)
            printf("욕이 없습니다\n");
    }

    for (int i = 0; i < 480; i++)
        free(lan[i]);

    return 0;
}

void RemoveEnd(char *buf)
{
    int i = 0;
    while (buf[i])
    {
        i++;
    }

    buf[i - 1] = '\0';
}
