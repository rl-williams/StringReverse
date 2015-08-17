#include <stdio.h>
#include <string.h>

void string_reverse1(char*);
char *string_reverse2(const char*);

int main(void)
{
    char str[100];
    printf("\nEnter the string:");
    gets(str);

    char *s1 = str;
    string_reverse1(s1);
    char* s2 = string_reverse2(str);
    printf("Reverse1 of string: %s\n", s1);
    printf("Reverse2 of string: %s\n", s2);

    return(0);
}


void string_reverse1(char *string) {

    // find length of string
    int length = 0;
    char *pointer = string;
    while (*(pointer + length) != '\0') length++;
    if (length < 2) return;

    char temp;
    int i = 0;
    int j = length - 1;

    // swap characters
    while (i <= j) {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
        i++;
        j--;
    }
}


char *string_reverse2(const char *string) {

    // find length of string
    int length = 0;
    const char *pointer = string;
    while (*(pointer + length) != '\0') length++;
    if (length < 2) return string;

    // allocate memory to store reversed string
    char *reversed = calloc(length + 1, sizeof(char));

    int i = 0;
    int j = length - 1;

    // swap characters
    while (i <= j) {
        reversed[i] = string[j];
        reversed[j] = string[i];
        i++;
        j--;
    }

    return reversed;
}
