# 14주차

### 기본 1번
1. 문자열 편집을 위해 string.h 를 인클루드 하고 다음 문항에 답하시오. (1시간 소요)

   가. char*변수를 만들고 자신의 아이디를 저장해보시오.

   나. strlen의 사용방법은 아래와 같다.

       문자열의 길이 = strlen(char*변수)

     이를 암기하시오. 또한, '가'에서 만든 변수에 몇글자가 저장되어 있는지 구하고 printf로 출력해보시오.

   다. '가'에서 만든 변수에 대해, 변수명[0], 변수명[1], 변수명[2]... 를 이용하여 문자열을 한글자씩 분리하고 이를 출력해보시오. 수동으로 하지 말고 반복문을 이용하시오.

   라. '나'에서 만든 문자열의 길이와 '다'에서의 문자 한개씩 접근하는 방법을 이용하여 for문으로 아이디를 거꾸로 뒤집어 출력해보시오. 예를들어, 아이디가 apple2 였다면 2elppa 를 출력해야함.
   
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
  
  
### 기본 2번
2. strcmp의 사용방법은 아래와 같다.

       두 문자열의 비교값 = strcmp(문자열1 변수명,문자열2 변수명)

    두문자가 같으면 0, 다르면 -1또는 1. https://dojang.io/mod/page/view.php?id=346 참조하시오.

    이를 암기하시오. 또한 다음 문항을 해결하시오.

    단, 버전에 따라 -1또는 1이 먹히지 않을 경우가 있고 그때는 양수 또는 음수가 받아지므로 이를 활용하시오(2시간 소요)

    가. char* 배열에 다음의 값을 넣으시오. "Apple" "Dog" "Cat" "Banana" "Elephant"

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


### 기본 3번
3. 다음과 같은 원시자료가 있다.

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

