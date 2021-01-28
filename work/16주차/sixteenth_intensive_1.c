#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AUTHOR 1
#define KEYWORD 2
#define YEAR 3

void set_Data(char *Data[]);
int ask();
void out(int (*fp)(), char *Data[]);
void print(char *Data[]);
void sort(char *Data[]);

int main()
{
    char *Data[21], *pt;

    set_Data(Data);

    out(ask, Data);

    return 0;
}

void set_Data(char *Data[])
{
    for (int i = 1; i <= 20; i++)
        Data[i] = malloc(sizeof(char) * 20);
    Data[1] = "오리요리책(김오리),1998";
    Data[2] = "토끼사냥책(이토끼),2008";
    Data[3] = "애완새기르기(박참새),2010";
    Data[4] = "부어요리책(최부어),2015";
    Data[5] = "애완아메바기르기(정아메바),1998";
    Data[6] = "애완강아지기르기(김오리),2008";
    Data[7] = "거북이요리책(이토끼),2015";
    Data[8] = "곰사냥책(박참새),1998";
    Data[9] = "나무늘보요리책(최부어),2008";
    Data[10] = "날다람쥐사냥책(정아메바),1998";
    Data[11] = "애완너구리기르기(최부어),2015";
    Data[12] = "돌고래요리책(이토끼), 2008";
    Data[13] = "두꺼비사냥책(이토끼),1998";
    Data[14] = "애완바다사자기르기(김오리),2015";
    Data[15] = "호랑이사냥책(최부어),2008";
    Data[16] = "비둘기요리책(김오리),2010";
    Data[17] = "애완개구리기르기(박참새),2015";
    Data[18] = "족제비요리책(김오리),1998";
    Data[19] = "애완백곰기르기(정아메바),2010";
    Data[20] = "사슴사냥책(최부어),1998";
}

int ask()
{
    int ans;
    printf("어느 것으로 찾으시겠습니까?\n");
    do
    {
        printf("1. 저자 2. 키워드 3. 출판연도 4. 찾는 건 됐고 정렬?\n");
        scanf("%d", &ans);
    } while (4 < ans || ans < 1);
    return ans;
}

void out(int (*fp)(), char *Data[])
{
    int y = 0, by = fp(), n, ll = 4,
        lr = (by == YEAR) ? 4 : 20;
    char find[10], *temp, *pt,
        *c = (by == YEAR) ? "," : "(",
        *co = (by != YEAR) ? "이상 " : "";

    if (by == 4)
    {
        print(Data);
        sort(Data);
    }
    else
    {
        do
        {
            printf("%d글자 %s입력 : ", (by == YEAR) ? 4 : 2, co);
            scanf("%s", &find);
            n = strlen(find);
            y = (ll <= n && n <= lr) ? 1 : 0;
            if (by == YEAR)
            {
                n = atoi(find);
                y = (999 < n && n <= 9999) ? 1 : 0;
            }
        } while (y != 1);

        y = 0;

        for (int i = 1; i <= 20; i++)
        {
            if (by == KEYWORD)
                strncpy(temp, Data[i], strchr(Data[i], *c) - Data[i]);
            else
                temp = strchr(Data[i], *c);
            pt = strstr(temp, find);
            if (pt != NULL)
            {
                y = 1;
                printf("%s\n", Data[i]);
            }
        }
        if (y == 0)
            printf("보유 서적이 아닙니다\n");
    }
}

void print(char *Data[])
{
    printf("\n");
    for (int i = 1; i <= 20; i++)
        printf("%d. %s\n", i, Data[i]);
    printf("\n");
}
void sort(char *Data[])
{
    printf("정렬중");
    char *temp;
    for (int i = 1; i <= 20; i++)
    {
        for (int j = i + 1; j <= 20; j++)
        {
            if (strcmp(Data[i], Data[j]) > 0)
            {
                temp = Data[i];
                Data[i] = Data[j];
                Data[j] = temp;
                printf(" . ");
            }
        }
    }
    printf("\n");
    print(Data);
}