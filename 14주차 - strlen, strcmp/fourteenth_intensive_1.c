#include <stdio.h>
#include <string.h>

int main()
{
    char rr[13];
    int rn[13], temp, er, ch, i;
    const int x[] = {2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5};
    do
    {
        if (er == 1)
            printf("올바른 주민번호가 아닙니다.\n");
        er = 0;
        printf("\n주민등록번호 입력('-'없이 13자리)\n");
        scanf("%s", rr);
        if (strlen(rr) != 13)
        {
            printf("13자리가 아닙니다.\n");
            continue;
        }
        for (i = 0; i < 13; i++)
        {
            temp = rr[i] - 48;
            if (temp >= 0 & temp < 10)
                rn[i] = temp;
            else
            {
                printf("13자리의 숫자여야 합니다.\n");
                er = 2;
                break;
            }
        }
        if (er == 2)
            continue;

        int year, fd, ly;
        year = (rn[0] * 10) + rn[1];
        fd = rn[6];
        switch (fd)
        {
        case 1:
        case 2:
            year += 1900;
            break;
        case 3:
        case 4:
            if (year > 21)
            {
                er = 1;
                continue;
            }
            year += 2000;
            break;
        default:
            er = 1;
            continue;
        }
        ly = ((year % 4 + year % 400) == 0) & (year % 100 != 0) ? 1 : 0;

        int month = (rn[2] * 10) + rn[3];
        if (1 > month | month > 12)
        {
            er = 1;
            continue;
        }

        int day = (rn[4] * 10) + rn[5], limit;
        if (month == 2)
        {
            limit = (ly == 1) ? 29 : 28;
        }
        else if (month > 7)
            limit = (month % 2 == 0) ? 31 : 30;
        else
            limit = (month % 2 == 0) ? 30 : 31;
        if (day<1 | day> limit)
        {
            er = 1;
            continue;
        }

        temp = 0;
        for (i = 0; i < 12; i++)
        {
            temp += x[i] * rn[i];
        }
        temp = 11 - (temp % 11);
        if (temp != rn[12])
        {
            er == 1;
            continue;
        }
        ch = 1;
    } while (ch != 1);
    printf("유효한 주민번호입니다.\n");

    return 0;
}