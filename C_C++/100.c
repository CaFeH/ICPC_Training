#include <stdio.h>

int cycle_length(long int n, int counter);

int main ()
{
  int current, maximum=0;
  long int i, j, test_val;
  char ch;

  do
  {
    fscanf(stdin, "%ld %ld", &i, &j);
    ch = fgetc(stdin);
    if (ch == EOF) return (0);
    else
    {
      current = 0;
      maximum = 0;
      if (i <= j)
      {
        for (test_val=i;test_val<=j; test_val++)
        {
          current = cycle_length(test_val, 0);
          if (current > maximum) maximum = current;
        }
      } else
      {
        for (test_val=j;test_val<=i; test_val++)
        {
          current = cycle_length(test_val, 0);
          if (current > maximum) maximum = current;
        }
      }
      printf("%ld %ld %d\n", i, j, maximum);
    }
  } while (ch != EOF);

  return(0);
}

int cycle_length(long int n, int counter)
{
  counter++;
  if (n == 1) return counter;
  else
  {
    if (n%2 != 0) return cycle_length(3*n + 1, counter);
    else return cycle_length(n/2, counter);
  }
}
