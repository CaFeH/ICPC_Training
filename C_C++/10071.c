#include <stdio.h>
#include <math.h>

int main()
{
  int v, t;
  float disp, teste;
  char ch;

  do
  {
    fscanf(stdin, "%d %d", &v, &t);
    ch = fgetc(stdin);
    if (ch == EOF) return(0);
    else
    {
      if (t == 0) printf("0\n");
      else
      {
        disp = (((1.0*v)/t) * pow(t*2.,2.))/2.;
        printf("%.0f\n", disp);
      }
    }
  } while (ch!=EOF);
  return(0);
}
