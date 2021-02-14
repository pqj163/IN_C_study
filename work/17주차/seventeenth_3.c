#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char Date[] = "2020-07-03(금요일)";
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
    strcpy(res, "오늘은 ");
    strcat(res, year);
    strcat(res, "년 ");
    strcat(res, month);
    strcat(res, "월 ");
    strcat(res, day);
    strcat(res, "일 ");
    strcat(res, dow);
    strcat(res, "이고, 현재시간은 ");
    strcat(res, hour);
    strcat(res, "시 ");
    strcat(res, min);
    strcat(res, "분 ");
    strcat(res, sec);
    strcat(res, "초 입니다");
    printf("%s\n", res);
    free(res);
    return 0;
}