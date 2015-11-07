#include <stdio.h>

int main()
{
  long int n1, n2, result;
  char ch;

  do
  {
    fscanf(stdin, "%ld %ld", &n1, &n2);
    ch = fgetc(stdin);
    if (ch == EOF) return(0);
    else
    {
      if (n1 > n2) result = n1 - n2;
      else result = n2 - n1;
      printf("%ld\n", result);
    }
  } while(ch != EOF);

  return (0);
}
