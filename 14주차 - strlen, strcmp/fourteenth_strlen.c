
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
        printf("비밀번호:");
        scanf("%s", &pw);
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

// #include <stdio.h>
// #include <string.h>
// #define REV -2

// void copy(char *list1[], char *list2[], int len);
// void print(char *list[], int len);
// void sort(char *list[], int len, int con);
// void strcmp_valid(char *temp_list[], char *list[], int len, int con);

// int main()
// {
//     char *temp_list[5], *list[5] = {"Apple", "Dog", "Cat", "Banana", "Elephant"};
//     int i, len = sizeof(list) / sizeof(list[0]);
//     copy(temp_list, list, len);

//     strcmp_valid(temp_list, list, len, 1);
//     strcmp_valid(temp_list, list, len, -1);
//     strcmp_valid(temp_list, list, len, REV);

//     return 0;
// }

// void copy(char *list1[], char *list2[], int len)
// {
//     for (int i = 0; i < len; i++)
//         list1[i] = list2[i];
// }

// void print(char *list[], int len)
// {
//     printf("[ ");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%s", list[i]);
//         if (i != (len - 1))
//             printf(", ");
//     }
//     printf(" ]\n");
// }

// void sort(char *list[], int len, int sort)
// {
//     char *basket, *order = (sort == REV) ? "역순" : "정순";
//     int a, b, temp, cmp = (sort == 1) ? 1 : -1;
//     printf("strcmp가 %d일 때를 검사하여, %s 정렬중", cmp, order);
//     for (int i = 0; i < (len - 1); i++)
//     {
//         for (int j = i + 1; j < len; j++)
//         {
//             a = (cmp == 1 | sort == REV) ? i : j;
//             b = (cmp == 1 | sort == REV) ? j : i;
//             temp = strcmp(list[a], list[b]);
//             if (temp == cmp)
//             {
//                 basket = list[a];
//                 list[a] = list[b];
//                 list[b] = basket;
//             }
//         }
//         printf(" . ");
//     }
//     printf("\n");
// }
// void strcmp_valid(char *temp_list[], char *list[], int len, int con)
// {
//     printf("\n");
//     print(list, len);
//     sort(list, len, con);
//     print(list, len);
//     copy(list, temp_list, len);
//     printf("리스트 복구\n");
//     print(list, len);
// }

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char *NickName = "맹꽁이";
//     int len = strlen(NickName);
//     printf("%d글자\n", len / 2);
//     for (int i = 0; i < len; i += 2)
//     {
//         printf("%c%c", NickName[i], NickName[i + 1]);
//     }
//     printf("\n");
//     for (int i = 0; i < len; i += 2)
//     {
//         printf("%c%c", NickName[len - (i + 2)], NickName[len - (i + 1)]);
//     }
//     printf("\n");
//     return 0;
// }
