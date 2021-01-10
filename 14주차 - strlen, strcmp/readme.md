# 14주차 [(주차 목록)](https://github.com/pqj163/IN_C_study#c-%EC%8A%A4%ED%84%B0%EB%94%94)

- [기본 1번](https://github.com/pqj163/IN_C_study/blob/master/14%EC%A3%BC%EC%B0%A8%20-%20strlen%2C%20strcmp/readme.md#%EA%B8%B0%EB%B3%B8-1%EB%B2%88-%EB%AA%A9%EC%B0%A8)(strlen)
- [기본 2번](https://github.com/pqj163/IN_C_study/blob/master/14%EC%A3%BC%EC%B0%A8%20-%20strlen%2C%20strcmp/readme.md#%EA%B8%B0%EB%B3%B8-2%EB%B2%88-%EB%AA%A9%EC%B0%A8)(strcmp)
- [기본 3번](https://github.com/pqj163/IN_C_study/blob/master/14%EC%A3%BC%EC%B0%A8%20-%20strlen%2C%20strcmp/readme.md#%EA%B8%B0%EB%B3%B8-3%EB%B2%88-%EB%AA%A9%EC%B0%A8)(구조체 포인터 배열)
- [심화 1번](https://github.com/pqj163/IN_C_study/blob/master/14%EC%A3%BC%EC%B0%A8%20-%20strlen%2C%20strcmp/readme.md#%EC%8B%AC%ED%99%94-1%EB%B2%88-%EB%AA%A9%EC%B0%A8)()
- [심화 2번](https://github.com/pqj163/IN_C_study/blob/master/14%EC%A3%BC%EC%B0%A8%20-%20strlen%2C%20strcmp/readme.md#%EC%8B%AC%ED%99%94-2%EB%B2%88-%EB%AA%A9%EC%B0%A8)(난수)

### 기본 1번 [(목차)](https://github.com/pqj163/IN_C_study/blob/master/14%EC%A3%BC%EC%B0%A8%20-%20strlen%2C%20strcmp/readme.md#14%EC%A3%BC%EC%B0%A8-%EC%A3%BC%EC%B0%A8-%EB%AA%A9%EB%A1%9D)

1.  문자열 편집을 위해 string.h 를 인클루드 하고 다음 문항에 답하시오. (1시간 소요)

    ```
    가. char\*변수를 만들고 자신의 아이디를 저장해보시오.

    나. strlen의 사용방법은 아래와 같다.

            문자열의 길이 = strlen(char*변수)

    이를 암기하시오. 또한, '가'에서 만든 변수에 몇글자가 저장되어 있는지 구하고 printf로 출력해보시오.

    다. '가'에서 만든 변수에 대해, 변수명[0], 변수명[1], 변수명[2]... 를 이용하여 문자열을 한글자씩 분리하고 이를 출력해보시오. 수동으로 하지 말고 반복문을 이용하시오.

    라. '나'에서 만든 문자열의 길이와 '다'에서의 문자 한개씩 접근하는 방법을 이용하여 for문으로 아이디를 거꾸로 뒤집어 출력해보시오. 예를들어, 아이디가 apple2 였다면 2elppa 를 출력해야함.
    ```

    ```C
    #include <stdio.h>
    #include <string.h>

    int main()
    {
        char *NickName = "맹꽁이";
        int len = strlen(NickName);
        printf("%d글자\n", len / 2);
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
    ```

    ![](https://user-images.githubusercontent.com/58128948/104117836-bfd3d580-5367-11eb-9b7f-a5cf8260d8dd.png)

### 기본 2번 [(목차)](https://github.com/pqj163/IN_C_study/blob/master/14%EC%A3%BC%EC%B0%A8%20-%20strlen%2C%20strcmp/readme.md#14%EC%A3%BC%EC%B0%A8-%EC%A3%BC%EC%B0%A8-%EB%AA%A9%EB%A1%9D)

2.  strcmp의 사용방법은 아래와 같다.

        두 문자열의 비교값 = strcmp(문자열1 변수명,문자열2 변수명)

        두문자가 같으면 0, 다르면 -1또는 1. https://dojang.io/mod/page/view.php?id=346 참조하시오.

    이를 암기하시오. 또한 다음 문항을 해결하시오.

    단, 버전에 따라 -1또는 1이 먹히지 않을 경우가 있고 그때는 양수 또는 음수가 받아지므로 이를 활용하시오(2시간 소요)

        가. char\* 배열에 다음의 값을 넣으시오. "Apple" "Dog" "Cat" "Banana" "Elephant"

        나. '가'에서 만든 값을 strcmp값이 1임을 검사하여 사전식으로 재배열해 보시오. strcmp와 반복문을 이용하시오.
        결과값은 Apple, Banana, Cat, Dog, Elephant 처럼 되어야 함.

        다. '가'에서 만든 값을 strcmp값이 -1임을 검사하여 사전식으로 재배열해 보시오. strcmp와 반복문을 이용하시오.
        결과값은 Apple, Banana, Cat, Dog, Elephant 처럼 되어야 함.

        라. '가'에서 만든 값을 알파벳 역순으로 재배열해보시오. strcmp와 반복문을 이용하시오.
        결과값은 Elephant, Dog, Cat, Banana, Apple 처럼 되어야 함.

    ```C
    #include <stdio.h>
    #include <string.h>
    #define REV -2

    void copy(char *list1[], char *list2[], int len);
    void print(char *list[], int len);
    void sort(char *list[], int len, int con);
    void strcmp_valid(char *temp_list[], char *list[], int len, int con);

    int main()
    {
        char *temp_list[5], *list[5] = {"Apple", "Dog", "Cat", "Banana", "Elephant"};
        int i, len = sizeof(list) / sizeof(list[0]);
        copy(temp_list, list, len);

        strcmp_valid(temp_list, list, len, 1);
        strcmp_valid(temp_list, list, len, -1);
        strcmp_valid(temp_list, list, len, REV);

        return 0;
    }

    void copy(char *list1[], char *list2[], int len)
    {
        for (int i = 0; i < len; i++)
            list1[i] = list2[i];
    }

    void print(char *list[], int len)
    {
        printf("[ ");
        for (int i = 0; i < len; i++)
        {
            printf("%s", list[i]);
            if (i != (len - 1))
                printf(", ");
        }
        printf(" ]\n");
    }

    void sort(char *list[], int len, int sort)
    {
        char *basket, *order = (sort == REV) ? "역순" : "정순";
        int a, b, temp, cmp = (sort == 1) ? 1 : -1;
        printf("strcmp가 %d일 때를 검사하여, %s 정렬중", cmp, order);
        for (int i = 0; i < (len - 1); i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                a = (cmp == 1 | sort == REV) ? i : j;
                b = (cmp == 1 | sort == REV) ? j : i;
                temp = strcmp(list[a], list[b]);
                if (temp == cmp)
                {
                    basket = list[a];
                    list[a] = list[b];
                    list[b] = basket;
                }
            }
            printf(" . ");
        }
        printf("\n");
    }
    void strcmp_valid(char *temp_list[], char *list[], int len, int con)
    {
        printf("\n");
        print(list, len);
        sort(list, len, con);
        print(list, len);
        copy(list, temp_list, len);
        printf("리스트 복구\n");
        print(list, len);
    }
    ```

    ![](https://user-images.githubusercontent.com/58128948/104117853-ded26780-5367-11eb-8055-7220032fcff4.png)

### 기본 3번 [(목차)](https://github.com/pqj163/IN_C_study/blob/master/14%EC%A3%BC%EC%B0%A8%20-%20strlen%2C%20strcmp/readme.md#14%EC%A3%BC%EC%B0%A8-%EC%A3%BC%EC%B0%A8-%EB%AA%A9%EB%A1%9D)

3.  다음과 같은 원시자료가 있다.

        번호  닉네임     ID      PASSWORD

         1      오리     DUCK      dhflrhrl

         2      돼지       PIG      ehowlrhrl

         3      토끼   RABBIT    xhRlrhrl

         4      새         BIRD       torhrl

         5      비둘기  PIGEON  qlenfrlrhrl

         6      두꺼비   FROG    enRjqlrhrl

    이에 따라 아래 문항을 해결하시오. (2시간 소요)

        가. 위 자료를 처리하기 위해 배열이나 구조체 등을 이용하여 적절한 자료구조를 만들어 보시오.

        나. ID와 PASSWORD를 입력받아 위 자료에 있는대로 입력되면,
        "'닉네임'님, 로그인되었습니다."를 출력하시오. 누가 로그인하고 있는지를 판별하기 위해 입력받은 ID와 위 데이터베이스에 있는 ID를 반복문으로 일일이 검사하여야 함. 한편, strcmp를 이용하시오.

        다. 입력받은 ID와 일치하는 ID가 없는 경우, "ID가 잘못되었습니다"를 출력하시오. 그리고, ID와 PW를 다시 받을수 있도록 해보시오.

        라. 입력받은 ID는 있으나 PW가 일치하지 않는 경우, "PW가 잘못되었습니다"를 출력하시오. 그리고, ID와 PW를 다시 받을수 있도록 해보시오.

    ```C
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    struct Data
    {
        char Name[20];
        char ID[20];
        char PW[20];
    };

    int main()
    {
        struct Data *DB[6];
        int i, len = sizeof(DB) / sizeof(DB[0]);
        for (i = 0; i < len; i++)
        {
            DB[i] = malloc(sizeof(struct Data));
        }

        strcpy(DB[0]->Name, "오리");
        strcpy(DB[0]->ID, "DUCK");
        strcpy(DB[0]->PW, "dhflrhrl");

        strcpy(DB[1]->Name, "돼지");
        strcpy(DB[1]->ID, "PIG");
        strcpy(DB[1]->PW, "ehowlrhrl");
        strcpy(DB[2]->Name, "토끼");
        strcpy(DB[2]->ID, "RABBIT");
        strcpy(DB[2]->PW, "xhRlrhrl");

        strcpy(DB[3]->Name, "새");
        strcpy(DB[3]->ID, "BIRD");
        strcpy(DB[3]->PW, "torhrl");

        strcpy(DB[4]->Name, "비둘기");
        strcpy(DB[4]->ID, "PIGEON");
        strcpy(DB[4]->PW, "qlenfrlrhrl");

        strcpy(DB[5]->Name, "두꺼비");
        strcpy(DB[5]->ID, "FROG");
        strcpy(DB[5]->PW, "enRjqlrhrl");

        char id[20], pw[20], *er;
        int temp, ch_id, ch_pw, ch, num;
        do
        {
            printf("아이디:");
            scanf("%s", &id);
            printf("%s\n", id);
            printf("비밀번호:");
            scanf("%s", &pw);
            printf("%s\n", pw);
            for (i = 0; i < len; i++)
            {
                if (strcmp(id, DB[i]->ID) == 0)
                {
                    ch_id = 1;
                    temp += 1;
                }
                if (strcmp(pw, DB[i]->PW) == 0)
                {
                    ch_pw = 1;
                    temp += 1;
                }
                if (temp == 2)
                {
                    num = i;
                    break;
                }
                else
                {
                    temp = 0;
                    ch_pw = 0;
                }
            }
            ch = ch_id + ch_pw;
            if (ch != 2)
            {
                if (ch_id != 1)
                    er = "아이디";
                else
                    er = "PW";
                printf("%s가 잘못되었습니다.\n", er);
            }
        } while (ch != 2);
        printf("%s님, 로그인되었습니다.\n", DB[num]->Name);

        for (i = 0; i < len; i++)
        {
            free(DB[i]);
        }
        return 0;
    }
    ```

    ![](https://user-images.githubusercontent.com/58128948/104117862-ec87ed00-5367-11eb-9533-5870ba0176ae.png)

### 심화 1번 [(목차)](https://github.com/pqj163/IN_C_study/blob/master/14%EC%A3%BC%EC%B0%A8%20-%20strlen%2C%20strcmp/readme.md#14%EC%A3%BC%EC%B0%A8-%EC%A3%BC%EC%B0%A8-%EB%AA%A9%EB%A1%9D)

1.  주민등록번호 검증 알고리즘을 구현하시오.

        가. 주민등록번호 13자리를 입력받아 문자열 변수에 넣으시오.

        나. 앞자리는 생년, 월, 일 이므로, 월은 1~12 중 하나인지 확인하는 알고리즘을 만드시오. (주민번호의 세번째수와 네번째수를 배열로 접근하여 가져온 후 처리하시오)
            예를들어, '월'이 13월, 14월.... 등인 경우 유효하지 않음.

        다. 앞자리의 '일'은 1일~월말의 날짜 중 하나인지 확인하는 알고리즘을 만드시오. 말일의 일 수는 자동화 하는 방법이 없으므로 일일이 구현하여야 함. (주민번호의 다섯번째수와 여섯번째수를 배열로 접근하여 가져온 후 처리하시오)
            예를들어, '일'이 4월 31일, 6월 31일 .... 등인 경우 유효하지 않음.

        라. '다'를 보충하여, 2월 29일이 있는 해에 대한 알고리즘을 구현하시오.
            https://ko.wikipedia.org/wiki/2%EC%9B%94_29%EC%9D%BC  를 참조하시오.
            예를들어, 2020년 2월 29일은 유효하며, 2019년 2월 29일은 없음.

        마. 뒷자리 7자리 중 앞 6자리는 검사하지 않도록 하시오.

        바. 뒷자리 7자리 중 맨 뒷 자리의 수를 정해보시오.
            https://smok95.tistory.com/43 을 참조하시오.

        사. 위 검증 알고리즘을 통과하면 '유효한 주민번호입니다'를 출력하고, 통과하지 못하면 '올바른 주민번호가 아닙니다'를 출력 후 다시 입력 받도록 해보시오.

    ```C
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
    ```

    ![](https://user-images.githubusercontent.com/58128948/104117875-fc073600-5367-11eb-8600-449429f3ad86.png)

### 심화 2번 [(목차)](https://github.com/pqj163/IN_C_study/blob/master/14%EC%A3%BC%EC%B0%A8%20-%20strlen%2C%20strcmp/readme.md#14%EC%A3%BC%EC%B0%A8-%EC%A3%BC%EC%B0%A8-%EB%AA%A9%EB%A1%9D)

2.  다음과 같은 조건을 만족하는 암호 검증 알고리즘을 만드시오.

    모 싸이트에서는 회원들의 패스워드를 안전하게 보호하기 위해 다음과 같은 규칙을 만들었다.

    패스워드는 8자 이상, 문자와 숫자를 섞어 이용, 특수문자를 하나이상 포함, 로봇이 아님을 검증하기 위한 임의의 검증코드 입력. 여기까지 완료되면 안전한 패스워드로 판단하고, 프로그램 종료

        가. 패스워드를 입력 받으시오.

        나. 패스워드가 8자리 이상인지 글자수를 세어 보시오.

        다. 패스워드가 저장된 문자열 변수에 변수[0], 변수[1], 변수[2]... 등으로 접근하여

            패스워드가 끝나기 전까지 숫자가 있는지 확인하시오. 아스키코드를 이용하면 쉽게 구현됨. 없으면 오류를 출력하고 패스워드를 다시 입력받으시오.

        라. 패스워드가 끝나기 전까지 알파벳 문자가 있는지 확인하시오.없으면 오류를 출력하고 패스워드를 다시 입력받으시오.

        마. 패스워드가 끝나기 전까지 숫자,알파벳 이외의 특수문자가 있는지 확인하시오. 없으면 오류를 출력하고 패스워드를 다시 입력받으시오.

        바. srand를 이용하여 여섯자리 정수를 만들고, '마'단계까지 통과한 경우에 한해 로봇이 아님을 검증하기 위한 코드를 입력받으시오. 여섯자리가 아닌 정수가 뽑아지는 경우 여섯자리가 나올때까지 다시 뽑도록 하는 알고리즘을 구현하시오.

        사. '바'에서, 여섯자리 정수 생성값과 입력값이 같으면 '안전한 패스워드가 만들어졌습니다'를 출력하고 프로그램을 종료하시오. 같지 않으면 다시 여섯자리 정수를 만들어 로봇이 아님을 검증하도록 하시오. 단, 5번 연속 검증코드를 통과하지 못하는 경우 처음으로 돌아가 패스워드 입력을 다시 받도록 하시오.

    ```C
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
    ```

    ![](https://user-images.githubusercontent.com/58128948/104118445-8ea9d400-536c-11eb-9254-6c0e09690006.PNG)
