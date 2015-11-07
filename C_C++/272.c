#include <stdio.h>

int main()
{
  char ch;
  int flag = 0;

  do
  {
    ch = fgetc(stdin);
    if (ch==EOF) return(0);
    else if (ch != '\"') printf("%c", ch);
    else if (ch == '\"' && flag == 0)
    {
      printf("``");
      flag = 1;
    }
    else
    {
      printf("''");
      flag = 0;
    }
  } while (ch!=EOF);

  return(0);
}
