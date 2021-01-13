# 과제
> **15주차**   
[[ 목차 ](https://github.com/pqj163/IN_C_study/blob/master/README.md)]

- [기본 1번](#기본-1번)(strcpy)
- [기본 2번](#기본-2번)(strcat)
- [심화 1번](#심화-1번)()
- [심화 2번](#심화-2번)()

### [⬆](#과제)기본 1번
1. 문자열 편집을 위해 string.h 를 인클루드 하고 다음 문항에 답하시오. (1시간 소요)
    ```
    가. char* 변수를 2개 선언하고, 첫번째 변수에는 자신의 아이디를 넣고 두번째 변수는 malloc(sizeof(char)*20) 으로 메모리를 확보하시오. 또한, 이를 암기하시오.​

    나. strcpy의 사용법은 아래와 같다.

        strcpy(복사값을넣을변수, 복사할값)

    이를 암기하시오. 또한, 아까 선언한 두 변수중 첫번째 변수를 두번째 변수에 복사하여 넣고 이를 출력해 보시오.

    다. '가'에서 확보하였던 메모리를 free를 이용하여 해제하시오.

    라. char 형의 배열 a[10], b[10]을 선언하시오.

    마. a에는 자신의 아이디를 넣고, b는 비워 두시오.

    바. b에 a를 복사하여 넣으시오. 또한, 이를 출력하시오.
    ```

    ```C
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    int main()
    {
        char *nick = "맹꽁이", *mem = malloc(sizeof(char) * 20);

        printf("nick = %s\nmem = %s\n", nick, mem);
        strcpy(mem, nick);
        printf("\nstrcpy 후\n");
        printf("\n");
        printf("nick = %s\nmem = %s\n", nick, mem);
        free(mem);

        char a[10] = "맹꽁이", b[10];

        printf("\n");
        printf("a = %s\nb = %s\n", a, b);
        strcpy(b, a);
        printf("\nstrcpy 후\n\n");
        printf("a = %s\nb = %s\n", a, b);

        return 0;
    }
    ```
    ![기본 1번 결과](https://user-images.githubusercontent.com/58128948/104403666-5be62280-559c-11eb-8b62-86f6f1c8acbd.PNG)
    ```
    사. 문자열 복사를 하려면 char배열 또는 char형으로 선언된 동적 메모리 변수를 이용하면 된다. 이 둘의 장단점을 비교해 보시오.
    ```
> char *str은 주소를 담고, char str[]은 값을 담는다. 구조체 멤버를 char *str로 선언하면 struct->str = "abc" 같은 방식으로 값을 줄 수 있는데, 이는 실제로는 "abc"의 주소값을 넘겨주는 식이다. 근데 이 경우 특정 글자만 찝어서, 혹은 중간의 어느 부분부터만 수정을 할 수 없으며, 만약 다른 배열에서 값을 가져온 것일 경우 해당 배열의 값이 수정되면 이쪽도 수정이 된다. 대신 *str은 메모리를 체크해보면 주소값이기 때문에 메모리가 적게 나오는데, 결국엔 다른 메모리에서 값을 가져오는 것이기 때문에 실질적으로 메모리가 적은 것은 아니지만, 코드 진행 과정에서 메모리 해제 등의 방법을 통해 메모리를 보다 절약하는 방향으로 쓸 수도 있다. 문자열 복사의 경우, []로 선언한 문자열에 복사를 하려거든 값이 넘지 않도록 주의해야 한다.

 
### [⬆](#과제)기본 2번
2. strcat 의 용법은 아래와 같다.

        strcat(원래문자열, 추가할문자열)

    이를 암기하시오. 또한, 아래 문항을 해결하시오. (2시간 소요)

    ```
    가. char 형의 배열 a[10], b[10] 을 선언하시오. a에는 dhfl를 넣고 b에는 ehowl를 넣으시오.

    나. a에 b를 합치면 dhflehowl 가 된다. 이를 strcat로 구현하고, 출력해보시오.

    다. char 형의 배열 c[10], d[10] 을 선언하시오. c에는 dhflrhrl를 넣고, d에는 ehowlrhrl를 넣으시오

    라. strcat를 이용하여 c에 d를 합치면 오류가 남을 확인하시오. 오류의 원인을 설명하고, 오류가 나지 않게 배열의 크기를 조절해 보시오.

    마. char형의 배열과, char*형 변수를 선언하고, 배열에는 dhfl를 넣고 포인터변수에는 ehowl를 넣으시오. '라'와 같은 오류가 생기지 않도록 배열의 크기를 고려하시오.

    바. 합치면 dhflehowl 가 된다. 이를 strcat로 구현하고, 출력해보시오.
    ```

    ```C
    #include <stdio.h>
    #include <string.h>

    int main()
    {
        char a[10] = "dhfl", b[10] = "ehowl";
        printf("a = %s\nb = %s\n", a, b);
        strcat(a, b);
        printf("\nstrcat 후\n");
        printf("\n");
        printf("a = %s\nb = %s\n", a, b);

        char c[17] = "dhflrhrl", d[10] = "ehowlrhrl";
        strcat(c, d);
        printf("\n%s\n", c);

        char e[10] = "dhfl", *f = "ehowl";
        strcat(e, f);
        printf("\n%s\n", e);

        return 0;
    }
    ```
    ![기본 2번 결과](https://user-images.githubusercontent.com/58128948/104405991-97372000-55a1-11eb-8c59-e09beffcf279.PNG)

    ```
    사. 문자열 붙이기를 하려면 char배열 또는 char형으로 선언된 동적 메모리 변수를 이용하면 된다. 이 둘의 장단점을 비교해 보시오.
        마찬가지로, []로 문자열에 붙이기를 하려거든 용량을 넘지 않도록 주의해야 한다. []로 선언한 문자열에는 중간의 어느 부분부터 붙이기를 하면 덮어쓰기를 통한 수정이 가능하지만(그래도 여전히 원래 길이를 넘으면 글자가 깨진다.), *로 선언했을 경우에는 불가능하다.
        
    ```

### [⬆](#과제)심화 1번
1. strcat를 이용하여 아래 내용을 구현하시오.
    ```
    가. animal 배열을 만들고 오리,염소,돼지,소를 넣으시오.

    나. cry 배열을 만들고 꽥꽥,음메,꿀꿀,음무를 넣으시오.

    다. for과 strcat를 이용하여 동물이름과 울음소리를 합쳐보시오. 예를들어, '오리는 꽥꽥'과 같이 출력하시오.
    ```

    ```C
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int main()
    {
        char *animal[4], *cry[4];
        int i = 0, l = 4;

        for (i; i < l; i++)
        {
            if (i == 3)
                animal[i] = malloc(sizeof(char) * 9);
            else
                animal[i] = malloc(sizeof(char) * 11);
            cry[i] = malloc(sizeof(char) * 4);
            switch (i)
            {
            case 0:
                strcpy(animal[i], "오리");
                strcpy(cry[i], "꽥꽥");
                break;
            case 1:
                strcpy(animal[i], "염소");
                strcpy(cry[i], "음메");
                break;
            case 2:
                strcpy(animal[i], "돼지");
                strcpy(cry[i], "꿀꿀");
                break;
            case 3:
                strcpy(animal[i], "소");
                strcpy(cry[i], "음무");
                break;
            }
            strcat(animal[i], "는 ");
            strcat(animal[i], cry[i]);
            printf("%s\n", animal[i]);
        }
        for (i = 0; i < l; i++)
        {
            free(animal[i]);
            free(cry[i]);
        }

        return 0;
    }
    ```
    ![심화 1번 결과](https://user-images.githubusercontent.com/58128948/104408647-d23c5200-55a7-11eb-992b-c946d36af015.PNG)

 
### [⬆](#과제)심화 2번
2. 어떤 해커가 사람들의 네이버 ID를 수집하는 프로그램을 만들었다. 해커가 수집한 자료는 다음과 같다.

    |아이디|블로그|메일|
    |:-:|:-:|:-:|
    dhflrhrl|사용함|사용함|
    duathrhrl|사용함|사용안함|
    ehowlrhrl|사용안함|사용함|
    thrhrl|사용함|사용안함|
    torhrl|사용함|사용함|
    xhrlrhrl|사용안함|사용함|   
    
    이를 통해 광고를 전송하고자 한다.

 
    ```
    가. 위 자료를 입력하기 위한 자료구조를 설계하고 데이터를 넣으시오.

    나. 블로그를 사용하는 사람에게 스팸을 보내기 위해 targetBlog이라는 이름의 배열을 만들고 http://blog.naver.com/ID 를 넣으시오.

    다. 메일을 사용하는 사람에게 스팸을 보내기 위해 targetMail이라는 이름의 배열을 만들고 ID@naver.com 를 넣으시오.

    라. 블로그를 사용하지 않는 사람의 블로그 주소 데이터는 지우시오.

    마. 메일을 사용하지 않는 사람의 메일 주소 데이터는 지우시오.

    바. 수집한 모든 회원의 아이디, 블로그주소, 메일 중 '라~마' 과정을 거친 데이터를 출력하시오.

    사. 블로그를 하는 모든 회원의 블로그 주소를 ,로 연결하여 한 변수에 담아보시오. 또한, 이를 출력하시오.
    
    예를들어 http://blog.naver.com/dhflrhrl,http://blog.naver.com/duathrhrl.... 처럼 되어야 함

    아. 메일을 사용하는 모든 회원의 메일 주소를 ,로 연결하여 한 변수에 담아보시오. 또한, 이를 출력하시오.

        예를들어, dhflrhrl@naver.com,ehowlrhrl@naver.com... 처럼 되어야 함. 
    ```
    ```C
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define YES 1
    #define NO 0

    typedef struct _Data
    {
        char *id;
        int blog, mail;
    } Data;

    int main()
    {
        int blogs[6] = {YES, YES, NO, YES, YES, NO}, mails[6] = {YES, NO, YES, NO, YES, YES};
        char *targetBlog[6], *targetMail[6], blog_linked[200], mail_linked[200];
        Data *datas[6];
        for (int i = 0; i < 6; i++)
        {
            targetBlog[i] = malloc(sizeof(char) * 31);
            strcpy(targetBlog[i], "http://blog.naver.com/");
            targetMail[i] = malloc(sizeof(char) * 19);
            datas[i] = malloc(sizeof(Data));
            datas[i]->blog = blogs[i];
            datas[i]->mail = mails[i];
            switch (i)
            {
            case 0:
                datas[i]->id = "dhflrhrl";
                break;
            case 1:
                datas[i]->id = "duathrhrl";
                break;
            case 2:
                datas[i]->id = "ehowlrhrl";
                break;
            case 3:
                datas[i]->id = "thrhrl";
                break;
            case 4:
                datas[i]->id = "torhrl";
                break;
            case 5:
                datas[i]->id = "xhrlrhrl";
                break;
            }
            strcat(targetBlog[i], datas[i]->id);
            strcpy(targetMail[i], datas[i]->id);
            strcat(targetMail[i], "@naver.com");

            if (datas[i]->blog == NO)
                targetBlog[i] = NULL;
            if (datas[i]->mail == NO)
                targetMail[i] = NULL;
        }
        for (int i = 0; i < 6; i++)
        {
            printf("%s\n", datas[i]->id);
            if (datas[i]->blog == YES)
            {
                printf("%s", targetBlog[i]);
                strcat(blog_linked, targetBlog[i]);
                strcat(blog_linked, ", ");
            }
            else
                printf("사용안함");
            printf("\n");
            if (datas[i]->mail == YES)
            {
                printf("%s", targetMail[i]);
                strcat(mail_linked, targetMail[i]);
                strcat(mail_linked, ", ");
            }
            else
                printf("사용안함");
            printf("\n\n");
        }
        printf("%s\n", blog_linked);
        printf("%s\n", mail_linked);
        for (int i = 0; i < 6; i++)
        {
            free(targetBlog[i]);
            free(targetMail[i]);
            free(datas[i]);
        }
        return 0;
    }
    ```
![심화 2번 결과](https://user-images.githubusercontent.com/58128948/104462733-48ff3c80-55f4-11eb-9749-d14b9b327ec7.PNG)

> 원래는 target 배열들에 대해 delete를 구현하고, 그대로 배열을 이어 붙이는 방식으로 만들 생각이었다. 그 외에 글자수 자체를 재서 target 배열이든 최종적으로 합져지는 변수건 간에 메모리를 할당한다던가 그런 것도 생각했었는데... 나중에 한번 도전해봐야겠다.
