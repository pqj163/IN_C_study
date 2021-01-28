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
            printf("������");
        printf("\n");
        if (datas[i]->mail == YES)
        {
            printf("%s", targetMail[i]);
            strcat(mail_linked, targetMail[i]);
            strcat(mail_linked, ", ");
        }
        else
            printf("������");
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