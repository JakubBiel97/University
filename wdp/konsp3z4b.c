#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    //random number
    time_t t;
    srand((unsigned)time(&t));
    int randomNumber = rand() % 11;                                                                                 //mozna zmienic na dowolna


    printf("This is a guessing game.\nI have chosen a number between 0 and 10 which you must guess.\n\n");          //w zadaniu na 10

    printf("%d\n", randomNumber);
    int guess;
    int tries = 5;


    for(tries = 5; tries > 0; tries--)
    {
        printf("You have %d tr%s left.\nEnter a guess: ", tries, tries == 1 ? "y" : "ies");
        scanf("%d", &guess);

        if(guess == randomNumber)
        {
            printf("Your guess was correct!\n\n");
            break;                          //break i petla na dole lub "return"
        }
        else if(guess > 20 || guess < 0)
            printf("Ups, wrong number.\n\n");
        else if(guess > randomNumber )
            printf("My number is less than %d.\n\n", guess);
        else if(guess < randomNumber)
            printf("My number is more than %d. \n\n", guess);

    }
    if(guess != randomNumber)               //albo to albo return
        printf("You have had 5 tries and failed. The number was %d.\n", randomNumber);


    return 0;
}
