#include <stdio.h>

int main()
{


    for(; ;)
    {
        char operator;
        int a = 0, b = 0;

        printf("Wprowadz pierwsza liczbe: \n");
        scanf("%d", &a);
        printf("Wprowadz druga liczbe: \n");
        scanf("%d", &b);
        printf("Wprowadz operator akcji( - , + , / , * ): \n");
        scanf("%s", &operator);

        switch(operator)
        {
        case '-':
            printf("%d - %d = %d \n\n\n", a, b, a - b);
            break;
        case '+':
            printf("%d + %d = %d \n\n\n", a, b, a + b);
            break;
        case '/':
            printf("%d / %d = %d \n\n\n", a, b, a / b);
            break;
        case '*':
            printf("%d * %d = %d \n\n\n", a, b, a * b);
            break;
        default:
            printf("Zly operator.\n\n\n");
            break;
        }
    }



    return 0;
}
