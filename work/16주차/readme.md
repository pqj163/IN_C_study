# 과제
> **16주차**   
[[ 목차 ](https://github.com/pqj163/IN_C_study/blob/master/README.md)]

- [기본 1번](#기본-1번)(strchr)
- [기본 2번](#기본-2번)(strstr, strcat, strncpy)
- [심화 1번](#심화-1번)(atoi)
- [심화 2번](#심화-2번)(fopen, fgets, 공백 scanf)

### [⬆](#과제)기본 1번
1. 문자열 편집을 위해 string.h 를 인클루드 하고 다음 문항에 답하시오. (3시간 소요)
   
        가. strchr 의 사용법은 아래와 같다.

            찾은문자및 이후의 텍스트 데이터 = strchr(문자열,찾을 문자)  

            단, 문자가 찾아지지 않으면 NULL(0) 리턴.
        
        이를 암기하시오. 한편, 문자열 "dhflrhrlsiasia"를 변수로 선언하시오.

        나. "dhflrhrlsiasia"에서 r 이 처음으로 나타난 이후의 모든 문자열을 출력하고자 한다.

            문자열에 dhflrhrlsiasia을 주고, 찾을 문자는 'r'로 주고 strchr을 이용한 뒤 결과를 출력하시오.

        다. "dhflrhrlsiasia"에서 r 이 두번째로 나타난 이후의 모든 문자열을 출력하고자 한다. https://dojang.io/mod/page/view.php?id=369 를 참조하여, strchr을 이용한 뒤 결과를 출력하시오.

        라. "dhflrhrlsiasia" 에서, h가 몇개나 들어있는지 구하고자 한다.

        https://scvtwo.tistory.com/146 를 참조하여, h가 몇개 있는지 구하시오. 한편, while 문을 사용하시오. strchr를 이용하시오.

        마. "dhflrhrlsiasia" 에서, s가 처음으로 등장하는 것이 몇번째인지 구하고자 한다.

        https://wwwwwwwwwwwww.tistory.com/102 를 참조하여, s가 몇번째에 처음으로 등장하는지 구하시오. 한편, while 문을 사용하시오. strchr를 이용하시오.

        바. 나~마는 문자열의 앞에서부터 찾는다. 문자열의 뒤쪽부터 앞쪽으로 찾으려면 strrchr을 이용한다. 이를 암기하시오. 또한, 이를 이용하여 r이 마지막으로 나타난 이후의 모든 문자열을 출력하시오.

        사. i가 마지막으로 등장하는 위치는 앞에서부터 몇번째인지 구하고 이를 출력하시오.

    ```C
    #include <stdio.h>
    #include <string.h>

    int main()
    {
        char *var = "dhflrhrlsiasia",
            *temp = strchr(var, 'r');
        printf("%s\n", temp);
        printf("%s\n", strchr(temp + 1, 'r'));

        temp = strchr(var, 'h');
        int h = 0;
        while (temp != NULL)
        {
            h++;
            temp = strchr(temp + 1, 'h');
        }
        printf("h개수 : %d\n", h);

        printf("첫번째 s위치 : %d\n", strchr(var, 's') - var);

        printf("%s\n", strrchr(var, 'r'));

        printf("마지막 i위치 : %d\n", strrchr(var, 'i') - var);

        return 0;
    }
    ```
    > 처음에 컴파일이 안돼서 애먹었는데, 알고보니 ""로 문자를 입력하면 한글자만 적어도 널문자가 뒤에 붙어 문자열로 취급 된다고 한다. 그러니 변수를 ''로 넣어야 정상적으로 컴파일이 된다. 그래서 이와 같은 연유로, 문자임에도 %s를 쓰려면 ""로 문자를 넣어줘야 한다.   

    ![기본 1번 결과](https://user-images.githubusercontent.com/58128948/105947778-13a32600-60ad-11eb-8697-86c39b4738de.PNG)

### [⬆](#과제)기본 2번
2. strstr 의 사용법은 아래와 같다.

        찾은문자및 이후의 텍스트 데이터 = strstr(문자열,찾을 문자열)  

        단, 문자열이 찾아지지 않으면 NULL(0) 리턴. 

    이를 암기하시오. 한편, 문자열 "dhflrhrlsiasia"를 변수로 선언하시오. (2시간 소요)  

        가. 'rhrl'가 찾아지는지 확인하고 찾은 이후의 모든 문자열을 출력하시오.

        나. strstr로 siasia를 찾은 후, WjqWjq으로 바꾸어 보시오. http://blog.daum.net/sualchi/13720440  를 참조하시오. strncpy를 이용하시오.

        다. 'dhfl'를 삭제할 목적으로, 'rhrl'를 찾은 후 변수에 넣으시오. 이렇게 하면 삭제가 되는 원리를 말하시오. 이후, 'dhfl' 대신에 'ehowl'로 바꾸어 지도록 strcat를 이용해보시오.

        라. 찾을 문자와 바꿀 문자의 크기가 같으면 strncpy를 이용하고, 그렇지 않으면 '다'처럼 부분삭제 후 새 문자열을 합쳐야 함을 확인하시오. dhflrhrlsiasia 을, dhflqnfrhrlWjqWjq 으로 바꾸기 위해, dhfl를 삭제 한 후, dhflqnf 을 앞에 추가한 뒤, siasia은 WjqWjq으로 바꾸어 보시오.

    ```C
    #include <stdio.h>
    #include <string.h>

    int main()
    {
        char var[] = "dhflrhrlsiasia";

        printf("%s\n", strstr(var, "rhrl"));

        strncpy(&var[strstr(var, "siasia") - var], "WjqWjq", 6);
        printf("%s\n", var);

        char *temp1 = strstr(var, "rhrl");
        printf("%s\n", temp1);

        char temp2[] = "ehowl";
        printf("%s\n", strcat(temp2, temp1));

        char temp3[] = "dhflqnf";
        temp1 = "dhflrhrlsiasia";
        strcat(temp3, strstr(temp1, "rhrl"));
        strncpy(&temp3[strstr(temp3, "siasia") - temp3], "WjqWjq", 6);
        printf("%s\n", temp3);

        return 0;
    }
    ```

    ![기본 2번 결과](https://user-images.githubusercontent.com/58128948/105980072-c5574c80-60d7-11eb-89c0-b6bfdce00048.PNG)

 

 

 

### [⬆](#과제)심화 1번

1. 도서관에 다음과 같은 책 장부가 있다. 책 한권당 책이름, 저자이름과 출판연도가 하나의 문자열 변수로 되어 있다.

    

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

        

        위 소스를 그대로 소스편집창에 복사한 후 아래 문항을 해결하시오.

        

        가. 김오리가 쓴 모든 책을 구하시오. strstr과 반복문을 이용하시오.

        나. 저자 이름을 넣으면 그 사람이 쓴 책이 전부 나오도록 해보시오.

        

        다. 요리와 관련된 모든 책을 구하시오. strstr과 반복문을 이용하시오.

        라. 요리, 사냥, 애완 중 하나를 넣으면 그와 관련된 책이 전부 나오도록 해보시오.

        

        마. 2008년에 나온 모든 책을 구하시오. strstr과 반복문을 이용하시오.

        바. 출판연도를 넣으면 그와 관련된 책이 전부 나오도록 해보시오.

        

        사. 20권의 책을 책이름 가나다순으로 정렬해 보시오.  https://m.blog.naver.com/PostView.nhn?blogId=gtd9292&logNo=20128696656&proxyReferer=https:%2F%2Fwww.google.com%2F 를 참조하시오. https://itng.tistory.com/92 도 참조하시오.

        

        아. 책이름 검색, 책목적 검색, 출판연도 검색 중 하나를 고른 후 값을 넣으면 그와 관련된 책이 나오도록 해보시오. 가~바를 재사용 하시오. 또한, 값이 찾아지지 않으면 '보유 서적이 아닙니다'를 출력하시오.

    ```C
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
        int y = 0, by = fp(), n,
            ll = (by == YEAR) ? 4 : 2,
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
                printf("%d글자 %s입력 : ", ll, co);
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
    ```

    ![심화 1번 결과_1](https://user-images.githubusercontent.com/58128948/106002927-0447cb00-60f5-11eb-8328-989564ffb9e8.PNG)
    ![심화 1번 결과_2](https://user-images.githubusercontent.com/58128948/106351241-72bba180-631e-11eb-8cca-89394cc6e85e.PNG)
    ![심화 1번 결과_3](https://user-images.githubusercontent.com/58128948/106089739-eff2e500-616b-11eb-8101-13af9fb0cd17.PNG)
    ![심화 1번 결과_4](https://user-images.githubusercontent.com/58128948/106003170-483ad000-60f5-11eb-941c-f13d673f20ad.PNG)
 

 

 
### [⬆](#과제)심화 2번
2. 어떤 게임에서는 회원간의 욕설을 방지하기 위해 다음과 같은 필터를 만들었다.

    

        욕 목록 : https://jaweb.tistory.com/entry/%EC%9A%95-%ED%95%84%ED%84%B0%EB%A7%81-%EB%AA%A9%EB%A1%9D

        가. 위 욕 목록을 문자열 배열로 만들고 값을 넣으시오. ,로 이미 분리되어 있으니 그대로 복사하여 사용하시오.

        나. scanf로 문자열을 입력받으시오.

        다. 입력된 문자열 중에 욕 목록 문자열 배열에 있는 단어가 포함되어 있는지 검색하시오. 단, 욕설이 처음 감지되면 '라' 처럼 처리하고, 그 이후의 검색은 하지 않아도 됨을 구현하시오.

        라. 포함되어 있지 않다면 '욕이 없습니다'와 입력받은 문자열을 그대로 출력하고, 포함되어 있다면 '욕설을 하지 말아주세요'를 출력하고 입력받은 문자열은 출력하지 마시오.

        마. 욕설을 할 떄 마다 횟수를 세시오. 5번 이상 욕설을 하면 프로그램이 종료되도록 해보시오. Do while또는 while을 이용하시오.
    
    ```C
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
    ```
    > 처음에 욕 필터링이 안돼서 애 먹었다. 쉽표를 지우고 전부 개행으로 구별하기도, 쉼표를 냅두고 strchr로 걸러보기도 했는데, 분명 문자열 배열에 욕이 안담기고, 다 담겨도 필터링이 안되고 그러더라. 지금와서 추측해보건데, 안되던 사례 중 하나인 반복문 밖에서 버퍼를 선언한 케이스는 해당 버퍼에 문자열 배열의 모든 포인터들이 연결되어서 그런 것이 아닐까 싶은데, 이거 예시를 보고 따라적은건데 예시에서는 됐었던지라 정확히는 모르겠다. 어쨌든 마지막으로 안됐던 사례는 개행으로 구별한 탓에 각 욕들의 끝에 다 개행 문자가 포함되어 제일 끝 욕을 제외하고는 필터링이 안됬었던 것인데, 이는 모든 문자의 끝 문자를 제거함으로써 해결했다. 그 외에 문장에 공백이 들어가면 입력이 이상하게 되는 사례도 [^\n]을 이용해 엔터가 들어오는 시점까지의 모든 공백을 포함한 문자를 입력받되 %를 한칸 띔으로써 개행을 무시함으로써 해결했다. (정확히는, 엔터를 누를 경우 다음 입력 버퍼에 개행 문자가 남게 되어 자동으로 연달아 입력이 되는 것인데, 이를 %s를 한칸 띔으로써 입력 버퍼의 제일 첫칸에 남은 개행 문자를 무시하는? 그런 원리인 것 같다.)

    ![심화 2번 결과](https://user-images.githubusercontent.com/58128948/106088531-7ce86f00-6169-11eb-8202-187abab9ca74.PNG)