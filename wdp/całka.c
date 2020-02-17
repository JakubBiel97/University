#include <stdio.h>
#include <math.h>

double calka(double x)
{
  return(sin(x)+cos(x)+cos(2*x)+(1.0/9));
}

int main()
{
  double a,b,s,h;
  int i,n;


  printf("Podaj poczatek przedzialu \n a = ");
  scanf("%lf",&a);
  printf("Podaj koniec przedzialu \n b = ");
  scanf("%lf",&b);
  printf("Podaj liczbe trapezow\n n = ");
  scanf("%d",&n);

  s  = 0;
  h = (b - a) / n;
  for(i = 1; i < n; i++)
  {
    s += calka(a + i * h);
  }
  s = (s + (calka(a) + calka(b)) / 2) * h;

  printf("Wartosc calki wynosi : %lf",  s);


  return 0;
}
