#include <stdio.h>
#include <stdlib.h>

int i_to_a(char *y, int x);
double f_to_a(char *y, double x);

int main()
{
    int num1 = 123;
    // ������ �𸣰ڴµ� ���⼭ num2�� �����ߴ��� �����ϴٰ� ����ƴ�.
    // ����ü ��...?
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