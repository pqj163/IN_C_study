#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char pw[20], *re[4] = {"숫자", "대문자", "소문자", "특수문자"};
    int i, pl, ch[5], rn, cn, count;
    do
    {
        ch[4] = 1;
        for (i = 0; i < 4; i++)
        {
            ch[i] = 0;
        }
        printf("\n8자리 이상 암호를 입력해주세요\n");
        scanf("%s", pw);
        pl = strlen(pw);
        if (pl < 8)
        {
            ch[4] = 0;
            printf("8자 이상이어야 합니다.\n");
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
            printf("암호는");
            for (i = 0; i < 4; i++)
            {
                if (ch[i] == 0)
                    printf(" %s", re[i]);
            }
            printf("를 포함해야 합니다.\n");
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
            printf("로봇이 아니라면 다음의 정수를 입력:%d\n", rn);
            scanf("%d", &cn);
            if (cn != rn)
            {
                count -= 1;
                if (count > 0)
                    printf("남은 기회:%d번\n", count);
            }
        } while (cn != rn && count > 0);
        if (count < 1)
        {
            ch[4] = 0;
            continue;
        }
    } while (ch[4] == 0);
    printf("안전한 패스워드가 만들어졌습니다.\n");

    return 0;
}