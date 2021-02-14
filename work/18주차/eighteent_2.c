#include <stdio.h>
#include <stdlib.h>

int i_to_a(char *y, int x);
double f_to_a(char *y, double x);

int main()
{
    int num1 = 123;
    // 이유는 모르겠는데 여기서 num2를 선언했더니 실행하다가 종료됐다.
    // 도대체 왜...?
    char *alp;
    i_to_a(alp, num1);
    printf("%s\n", alp);
    double num2 = 54.321;
    f_to_a(alp, num2);
    printf("%s\n", alp);
    itoa(num1, alp, 10);
    printf("%s\n", alp);
    return 0;
}

int i_to_a(char *y, int x)
{
    sprintf(y, "%d", x);
}

double f_to_a(char *y, double x)
{
    sprintf(y, "%f", x);
}