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