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