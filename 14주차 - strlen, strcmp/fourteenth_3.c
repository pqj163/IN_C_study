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

    strcpy(DB[0]->Name, "����");
    strcpy(DB[0]->ID, "DUCK");
    strcpy(DB[0]->PW, "dhflrhrl");

    strcpy(DB[1]->Name, "����");
    strcpy(DB[1]->ID, "PIG");
    strcpy(DB[1]->PW, "ehowlrhrl");
    strcpy(DB[2]->Name, "�䳢");
    strcpy(DB[2]->ID, "RABBIT");
    strcpy(DB[2]->PW, "xhRlrhrl");

    strcpy(DB[3]->Name, "��");
    strcpy(DB[3]->ID, "BIRD");
    strcpy(DB[3]->PW, "torhrl");

    strcpy(DB[4]->Name, "��ѱ�");
    strcpy(DB[4]->ID, "PIGEON");
    strcpy(DB[4]->PW, "qlenfrlrhrl");

    strcpy(DB[5]->Name, "�β���");
    strcpy(DB[5]->ID, "FROG");
    strcpy(DB[5]->PW, "enRjqlrhrl");

    char id[20], pw[20], *er;
    int temp, ch_id, ch_pw, ch, num;
    do
    {
        printf("���̵�:");
        scanf("%s", &id);
        printf("%s\n", id);
        printf("��й�ȣ:");
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
                er = "���̵�";
            else
                er = "PW";
            printf("%s�� �߸��Ǿ����ϴ�.\n", er);
        }
    } while (ch != 2);
    printf("%s��, �α��εǾ����ϴ�.\n", DB[num]->Name);

    for (i = 0; i < len; i++)
    {
        free(DB[i]);
    }
    return 0;
}