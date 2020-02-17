#include <stdio.h>
#include <stdbool.h>


bool czy_pierwsza(int n)
{
	if(n<2)
		return 0;                        //gdy liczba jest mniejsza ni¿ 2 to nie jest pierwsz¹

	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return 0;                    //gdy znajdziemy dzielnik, to dana liczba nie jest pierwsza

	return 1;
}

int main()
{
	int n;

	printf("Podaj liczbe: \n");
	scanf("%d", &n);

	if(czy_pierwsza(n)==1)
		printf("Liczba %d, jest liczba pierwsza.", n);
    else
		printf("Liczba %d, nie jest liczba pierwsza.", n);


	return 0;
}
