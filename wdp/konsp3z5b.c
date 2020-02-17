#include <stdio.h>
#include <math.h>


int main()
{
    for(int n = 1; n < 101; n++)
    {
        if(n % 2 == 0)
            printf("%d  -  %d\n", n, n*n);
        else
            printf("%d  -  %f\n", n, sqrt(n));

    }


    return 0;
}
