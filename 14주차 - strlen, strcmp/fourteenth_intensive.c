
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char pw[20], *re[4] = {"����", "�빮��", "�ҹ���", "Ư������"};
    int i, pl, ch[5], rn, cn, count;
    do
    {
        ch[4] = 1;
        for (i = 0; i < 4; i++)
        {
            ch[i] = 0;
        }
        printf("\n8�ڸ� �̻� ��ȣ�� �Է����ּ���\n");
        scanf("%s", pw);
        pl = strlen(pw);
        if (pl < 8)
        {
            ch[4] = 0;
            printf("8�� �̻��̾�� �մϴ�.\n");
            continue;
        }

        for (i = 0; i < pl; i++)
        {
            if (48 <= pw[i] && pw[i] <= 57)
            {
                ch[0] = 1;
            }
            else if (65 <= pw[i] && pw[i] <= 90)
            {
                ch[1] = 1;
            }
            else if (97 <= pw[i] && pw[i] <= 122)
            {
                ch[2] = 1;
            }
            else if (33 <= pw[i] && pw[i] <= 47 || 58 <= pw[i] && pw[i] <= 64)
            {
                ch[3] = 1;
            }
        }
        for (i = 0; i < 4; i++)
            if (ch[i] == 0)
                ch[4] = 0;
        if (ch[4] == 0)
        {
            printf("��ȣ��");
            for (i = 0; i < 4; i++)
            {
                if (ch[i] == 0)
                    printf(" %s", re[i]);
            }
            printf("�� �����ؾ� �մϴ�.\n");
            continue;
        }
        srand(time(NULL));
        count = 5;
        do
        {
            do
            {
                rn = 30 * rand();
            } while (rn <= 100000);
            printf("�κ��� �ƴ϶�� ������ ������ �Է�:%d\n", rn);
            scanf("%d", &cn);
            if (cn != rn)
            {
                count -= 1;
                if (count > 0)
                    printf("���� ��ȸ:%d��\n", count);
            }
        } while (cn != rn && count > 0);
        if (count < 1)
        {
            ch[4] = 0;
            continue;
        }
    } while (ch[4] == 0);
    printf("������ �н����尡 ����������ϴ�.\n");

    return 0;
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char rr[13];
//     int rn[13], temp, er, ch, i;
//     const int x[] = {2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5};
//     do
//     {
//         if (er == 1)
//             printf("�ùٸ� �ֹι�ȣ�� �ƴմϴ�.\n");
//         er = 0;
//         printf("\n�ֹε�Ϲ�ȣ �Է�('-'���� 13�ڸ�)\n");
//         scanf("%s", rr);
//         if (strlen(rr) != 13)
//         {
//             printf("13�ڸ��� �ƴմϴ�.\n");
//             continue;
//         }
//         for (i = 0; i < 13; i++)
//         {
//             temp = rr[i] - 48;
//             if (temp >= 0 & temp < 10)
//                 rn[i] = temp;
//             else
//             {
//                 printf("13�ڸ��� ���ڿ��� �մϴ�.\n");
//                 er = 2;
//                 break;
//             }
//         }
//         if (er == 2)
//             continue;

//         int year, fd, ly;
//         year = (rn[0] * 10) + rn[1];
//         fd = rn[6];
//         switch (fd)
//         {
//         case 1:
//         case 2:
//             year += 1900;
//             break;
//         case 3:
//         case 4:
//             if (year > 21)
//             {
//                 er = 1;
//                 continue;
//             }
//             year += 2000;
//             break;
//         default:
//             er = 1;
//             continue;
//         }
//         ly = ((year % 4 + year % 400) == 0) & (year % 100 != 0) ? 1 : 0;

//         int month = (rn[2] * 10) + rn[3];
//         if (1 > month | month > 12)
//         {
//             er = 1;
//             continue;
//         }

//         int day = (rn[4] * 10) + rn[5], limit;
//         if (month == 2)
//         {
//             limit = (ly == 1) ? 29 : 28;
//         }
//         else if (month > 7)
//             limit = (month % 2 == 0) ? 31 : 30;
//         else
//             limit = (month % 2 == 0) ? 30 : 31;
//         if (day<1 | day> limit)
//         {
//             er = 1;
//             continue;
//         }

//         temp = 0;
//         for (i = 0; i < 12; i++)
//         {
//             temp += x[i] * rn[i];
//         }
//         temp = 11 - (temp % 11);
//         if (temp != rn[12])
//         {
//             er == 1;
//             continue;
//         }
//         ch = 1;
//     } while (ch != 1);
//     printf("��ȿ�� �ֹι�ȣ�Դϴ�.\n");

//     return 0;
// }
