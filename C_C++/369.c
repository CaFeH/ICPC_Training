#include <stdio.h>

unsigned long int triangle(int n, int m);

int main()
{
    int n=0, m=0;
    unsigned long int result=0;
    fscanf(stdin, "%d %d", &n, &m);
    while(n != 0)
    {
        result = triangle(n, m);
        fprintf(stdout, "%d things taken %d at a time is %lu exactly.\n", n, m, result);
        fscanf(stdin, "%d %d", &n, &m);
    }

    return 0;
}

unsigned long int triangle(int n, int m)
{
    unsigned long int t[n+1][n+1];
    int i, j;
    t[0][0] = 1;
    for(j=1; j<=n; j++)
        t[0][j] = 0;
    for(i=1; i<=n; i++)
    {
        t[i][0] = 1;
        for(j=1; j<=i; j++)
            t[i][j] = t[i-1][j] + t[i-1][j-1];
        for(j=i+1; j<=n; j++)
            t[i][j] = 0;
    }

    return t[n-1][m] + t[n-1][m-1];
}
