#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char Date[] = "2020-07-03(�ݿ���)";
    char Time[] = "12:34:56";
    char *year;
    char *month;
    char *day;
    char *dow;
    char *hour;
    char *min;
    char *sec;
    year = strtok(Date, "-");
    month = strtok(NULL, "-");
    day = strtok(NULL, "(");
    dow = strtok(NULL, ")");
    hour = strtok(Time, ":");
    min = strtok(NULL, ":");
    sec = strtok(NULL, "\0");
    char *res = malloc(sizeof(char) * 100);
    strcpy(res, "������ ");
    strcat(res, year);
    strcat(res, "�� ");
    strcat(res, month);
    strcat(res, "�� ");
    strcat(res, day);
    strcat(res, "�� ");
    strcat(res, dow);
    strcat(res, "�̰�, ����ð��� ");
    strcat(res, hour);
    strcat(res, "�� ");
    strcat(res, min);
    strcat(res, "�� ");
    strcat(res, sec);
    strcat(res, "�� �Դϴ�");
    printf("%s\n", res);
    free(res);
    return 0;
}