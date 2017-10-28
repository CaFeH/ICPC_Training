#include <stdio.h>
#include <string.h>

int count_repetitions(char* str);

unsigned long int permutation_with_repetition(char* str);

unsigned long int factorial(int n);

int main()
{
    char str[21];
    int i, tests=0;
    unsigned long int perm=0;
    fscanf(stdin, "%d", &tests);
    for(i=0; i<tests; i++) 
    {
        fscanf(stdin, "%s", str);
        perm = permutation_with_repetition(str);
        fprintf(stdin, "Data set %d: %lu\n", i, perm);
    }

    return 0;
}

int count_repetitions(char* str)
{
    int i;
    for (i=0; str[i]; str[i]=='.' ? i++ : *str++);
    return i;
}

unsigned long int permutation_with_repetition(char* str)
{
    char s[21]="";
    int repet[21]; 
    unsigned long int fact_repet=1;
    int len, i;
    len = strlen(str);
    for(i=0; i<len; i++)
    {
        if(!strchr(s, str[i]))
        {
            strcat(s, (const char *)str[i]);
            repet[i] = count_repetitions(str);
            fact_repet *= factorial(repet[i]);
        }
    }
    return factorial(len) / fact_repet;
}

unsigned long int factorial(int n)
{
    if(n == 1)
        return 1;
    return factorial(n-1) * n;
}
