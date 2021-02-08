# 과제
> **16주차**   
[[ 목차 ](https://github.com/pqj163/IN_C_study/blob/master/README.md)]

- [기본 1번](#기본-1번)(strtok)
- [기본 2번](#기본-2번)()
- [기본 3번](#기본-3번)()
- [심화 1번](#심화-1번)()
- [심화 2번](#심화-2번)()

### [⬆](#과제)기본 1번
1. 문자열 편집을 위해 string.h 를 인클루드 하고 다음 문항에 답하시오. (2시간 소요)

        가. 문자 배열 "dhfl rhrl siasia"을 선언하시오.

        나. strtok 함수의 사용법은 아래와 같다.

        

            자른결과물 = strtok(원래문자열, 자를기준이되는 구분자 문자);



            이를 암기하시오. 또한, '가'에서 만든 문자열을 공백 " "를 기준으로 잘라 출력해보시오.

            https://dojang.io/mod/page/view.php?id=376 를 참조하시오.

        다. '나'에서 자른 문자열을 result[3]을 만들고 잘린 문자를 각각 변수에 대입해보시오.

            https://dojang.io/mod/page/view.php?id=379를 참조하시오.

        라. '다'에서 만든 result[0], result[1], result[2] 를 printf로 출력하여 확인하시오. 

    ```C
    #include <stdio.h>
    #include <string.h>

    int main()
    {
        char str[] = "dhfl rhrl siasia";
        char *ptr = strtok(str, " ");
        char *result[3];
        int i;
        result[0] = ptr;

        for (i = 1; i < 3; i++)
        {
            ptr = strtok(NULL, " ");
            result[i] = ptr;
        }
        for (i = 0; i < 3; i++)
            printf("%s\n", result[i]);

        return 0;
    }
    ``` 

    ![기본 1번 결과](https://user-images.githubusercontent.com/58128948/107176281-3ec53800-6a12-11eb-8139-a335fa4971b1.PNG)

### [⬆](#과제)기본 2번
2. 다음 문항에 답하시오. (2시간 소요)

        가. 문자 포인터로 "dhfl rhrl siasia"을 선언하시오.

        나. strtok를 이용하여 공백문자 " "를 기준으로 잘라보시오. 이렇게 하면 오류가 나면서 실행이 안됨을 확인하시오. 또한 왜 실행이 되지 않는지 설명해보시오.
    사실 안그래도 1번 문제에서 포인터로 해봤었다. 그러고 왜 안되는 건지를 검색해봤었는데, 저번에 포인터와 배열의 차이를 조사하던 중 문자열을 포인터로 선언하면 문자열 자체를 담는 것이 아니라 문자열의 첫글자의 주소를 담는 것이기 때문에 중간만 수정하는 등의 방식이 불가능하다는 사실을 알아냈었는데 그게 여기서도 적용되는 거더라. 근데 나는 검색해보기 전까지 까맣게 잊고 있었다. 여튼 결론은 strtok는 기준이 되는 문자를 NULL로 바꿔 문자열을 끊어내는 방식인데, 포인터로 문자열을 선언하면 수정이 안돼서 그렇단다.

        다. '가'로 돌아가서, 문자 포인터를 만들고 malloc으로 문자 30개 분량의 메모리를 할당하시오. 

            strcpy로 문자포인터에 "dhfl rhrl siasia"을 넣으시오.

        라. strtok를 이용하여 공백문자 " "를 기준으로 잘라보시오. 이렇게 하면 오류가 없이 실행이 됨을 확인하시오. 또한 왜 실행이 되는지 설명해보시오.
    근데 위의 결론에 대해서 의문이 들었던 점이, 배열 문자열에서조차 각 칸에 문자를 하나씩 담는 방식으로 수정이 가능한데, 문자열의 첫글자의 주소를 담았다고 해서 왜 이 방법이 불가능해지는 것인가? 포인터에 담기는 문자열은 배열 문자열에 담기는 문자열과는 다른 문자열이란 말인가?

    근데 실제로 다른 문자열이었다. 아직 지식이 부족해 정확히는 모르겠지만, 컴파일러는 '문자열 리터럴'이라고 하는 고정 문자열을 컴파일 시에 따로 모아두고, 실행 파일을 로드 시 이러한 고정된 값들은 프로그램의 data 영역 중 읽기 전용으로만 쓰이는 static 메모리 공간에 올려지며, 포인터 문자열은 그 메모리 공간에 있는 문자열 리터럴의 주소값을 가지는 것이라고 한다.

    사실 왜 문자열 배열은 따로 배열의 칸을 지정해서 수정이 가능한 것인지는 여전히 내게는 미지수이다. 굳이 추측해보자면 문자열 배열은 각각의 칸에 '문자 리터럴'이 담긴 상태여서 가능한 것이 아닐까? 하나의 칸에 값을 넣는 방식으로 수정할 때는 문자 리터럴의 주소가 아닌 값을 가져와서 해당 칸의 메모리를 수정한다던지... 일단 이 방법 말고 다른 가능한 방법은 떠오르지가 않는다. 그래도 최소한 포인터에 동적 메모리를 할당할 경우 말그대로 '동적'이라 수정이 가능하다는 점은 오래 기억할 것 같다.

        마. 잘라낸 결과물을 result[3] 에 각각 저장하시오. 또한, result[0], result[1], result[2] 를 printf로 출력하여 확인하시오. 이후, 할당받은 메모리를 free하는 것을 잊지 말고 구현하시오.

        바. 문자열을 처리하기 위해, 1번문항의 문자배열을 이용한 방법과 2번문항의 문자포인터를 이용한 방법을 비교하고 장단점을 50자 이상 적어보시오.
    동적 할당의 장점으로 항상 빠지지 않는 것은 메모리 관리이다. 하지만 이는 동작을 늘림으로써 필연적으로 실행 속도의 저하를 가져온다. 둘 중 어느 방법을 쓸 지는 사용 가능한 메모리의 양과 실행이 어느 만큼 빨라야 하는가 등을 고려하여 나름의 타협점을 찾아 결정해야 할 것이다.

    ```C
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int main()
    {
        char *str = malloc(sizeof(char) * 30);
        strcpy(str, "dhfl rhrl siasia");
        char *result[3];
        char *ptr = strtok(str, " ");
        int i;
        result[0] = ptr;
        for (i = 1; i < 3; i++)
        {
            ptr = strtok(NULL, " ");
            result[i] = ptr;
        }
        for (i = 0; i < 3; i++)
            printf("%s\n", result[i]);

        free(str);
        return 0;
    }
    ```

    ![기본 2번 결과](https://user-images.githubusercontent.com/58128948/107179257-6d92dc80-6a19-11eb-81bd-5d4b5aa470ad.PNG)

### [⬆](#과제)기본 3번
3. 다음과 같은 문자 배열이 있다. (2시간 소요)

        Date[] = 2020-07-03(금요일);

        Time[] = 12:34:56;

        가. year,month,day,dow 를 저장할 적절한 데이터형으로 변수를 선언하시오. dow는 요일임.

        나. Date를 -또는 (또는 )으로 자르시오. 자른 결과물을 year,month,day,dow에 넣으시오.

            https://dojang.io/mod/page/view.php?id=378 를 참조하시오.

        다. hour,min,sec를 저장할 적절한 데이터형으로 변수를 선언하시오.

        라. Time를 :으로 자르시오. 자른 결과물을 hour,min,sec에 넣으시오.

        마. 가~라에서 만든 결과물을 이용하여, 다음과 같은 내용을 담은 문자열을 만드시오.

        "오늘은 2020년 07월 03일 금요일이고, 현재시간은 12시 34분 56초 입니다"

            힌트 : strcat를 이용하시오.

        바. '마'에서 만든 문자열을 printf해보시오.


    ```C
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
    ```

    ![기본 3번 결과](https://user-images.githubusercontent.com/58128948/107180557-4d185180-6a1c-11eb-8d07-1981b72f4f6f.PNG)
 

 

 

### [⬆](#과제)심화 1번
    
1. C에서는 문자열 치환 함수가 없다. 따라서, 치환을 위해서는 치환 함수를 직접 작성하여야 한다.

        가. http://mwultong.blogspot.com/2006/10/c-string-replace-all.html 를 참조하여 치환 함수를 구현해보시오. 자신이 구현할 수 없는 경우 소스를 그대로 복제하여 사용하여도 무방함.

        나. 문자열 "오리고기냠냠 돼지고기냠냠 소고기냠냠 닭고기냠냠"을 선언하시오.

        다. 공백을 기준으로 나누어, 변수에 저장하시오.

        라. "고기"를 "불고기"로 바꾸어 보고, 이를 출력해 보시오.

        마. "냠냠"을 "쩝쩝"으로 바꾸어보고, 이를 출력해 보시오.

        바. 치환은 구현방법을 몰라도 누군가 짜 놓은 위 함수를 이용하면 됨을 확인하고, 소스를 보관하도록 하시오.

    ```C
    ```

    ![심화 1번 결과_1]()
 

 

 
### [⬆](#과제)심화 2번
2. 다음 소스는 네이버 모 카페의 가입인사 게시판의 태그 중 일부이다.

        소스 : http://tujanote.cafe24.com/bbs/board.php?bo_table=club&wr_id=1428

    이를 이용하여 회원의 아이디를 수집하는 프로그램을 구현하고자 한다.

        가. 전체 소스를 char[] 또는 char* 변수를 이용하여 하나의 변수에 넣으시오. (소스에있는 "는 모두 삭제하여야 함. 한글 등을 이용하여 "를 공백또는 '로 일괄변환하시오)

        나. 아이디가 들어있는 부분은 다음과 같다.

            <a href="#" class="m-tcol-c" onclick="ui(event, 'angelpes78',3,'내버들','11786850','', 'false', 'true', 'goodhakwon', 'false', '146'); return false;">내버들</a><span class="mem-level">

            이를 이용하기 위해 ui(event, 를 기준으로 자르시오. (이렇게 하면 10+1개의 문자열로 분리된다.)

        다. 잘라온 부분을 ,를 기준으로 다시 자르시오. 그러면, 세번째 값에 ID가 들어가게 된다.

        라. '다'를 이용하여 ID를 10개 추출하시오.

        마. 추출한 ID에 영어,숫자 이외의 문자가 있는지 검사하고, 있다면 모두 지우시오. 예를들어, '는 지워야함.

        바. 추출한 ID에 @naver.com을 붙여 이메일 배열을 만드시오.

        사. '다'에서, 닉네임을 추출하고 닉네임 배열을 만드시오.

        아. 만든 ID와 닉네임 배열을 출력해보시오.

        자. '닉네임(이메일)'님, 경품에 당첨되셨습니다! 를 출력하는 스팸메시지를 만들어 보시오.
    
    ```C
    ```

    ![심화 2번 결과]()