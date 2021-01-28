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
    Data[1] = "�����丮å(�����),1998";
    Data[2] = "�䳢���å(���䳢),2008";
    Data[3] = "�ֿϻ��⸣��(������),2010";
    Data[4] = "�ξ�丮å(�ֺξ�),2015";
    Data[5] = "�ֿϾƸ޹ٱ⸣��(���Ƹ޹�),1998";
    Data[6] = "�ֿϰ������⸣��(�����),2008";
    Data[7] = "�ź��̿丮å(���䳢),2015";
    Data[8] = "�����å(������),1998";
    Data[9] = "�����ú��丮å(�ֺξ�),2008";
    Data[10] = "���ٶ�����å(���Ƹ޹�),1998";
    Data[11] = "�ֿϳʱ����⸣��(�ֺξ�),2015";
    Data[12] = "�����丮å(���䳢), 2008";
    Data[13] = "�β�����å(���䳢),1998";
    Data[14] = "�ֿϹٴٻ��ڱ⸣��(�����),2015";
    Data[15] = "ȣ���̻��å(�ֺξ�),2008";
    Data[16] = "��ѱ�丮å(�����),2010";
    Data[17] = "�ֿϰ������⸣��(������),2015";
    Data[18] = "������丮å(�����),1998";
    Data[19] = "�ֿϹ���⸣��(���Ƹ޹�),2010";
    Data[20] = "�罿���å(�ֺξ�),1998";
}

int ask()
{
    int ans;
    printf("��� ������ ã���ðڽ��ϱ�?\n");
    do
    {
        printf("1. ���� 2. Ű���� 3. ���ǿ��� 4. ã�� �� �ư� ����?\n");
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
        *co = (by != YEAR) ? "�̻� " : "";

    if (by == 4)
    {
        print(Data);
        sort(Data);
    }
    else
    {
        do
        {
            printf("%d���� %s�Է� : ", (by == YEAR) ? 4 : 2, co);
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
            printf("���� ������ �ƴմϴ�\n");
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
    printf("������");
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