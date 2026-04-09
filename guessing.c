#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

    //visual presentation :P beautiful 
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Welcome to the     \n");
    printf("     |_|_|nnnn nnnn|_|_|         Guessing Game! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

    int maxnumber;
    srand(time(0)); // Seed random number generator (different number each run)

    int difficulty;
    int totalattempts;
    char playagain;
    playagain = 'y';

    // Main game loop (runs while player wants to keep playing)
    while (playagain == 'y' || playagain == 'Y')
    {
        double points = 1000;
        int attemptsused = 0;

        printf ("\nSelect Difficulty\n");
        printf ("(1) Easy #7 attempts (1-50)\n");
        printf ("(2) Medium #10 attempts (1-100)\n");
        printf ("(3) Hard #8 attempts (1-200)\n");
        printf ("(4) Extreme #5 attempts (1-200)\n");
        printf ("Choose: ");
        scanf("%d", &difficulty);

         // Set rules based on difficulty
        switch(difficulty)
        {
            case 1:
                totalattempts = 7;
                maxnumber = 50;
                break;

            case 2:
                totalattempts = 10;
                maxnumber = 100;
                break;

            case 3:
                totalattempts = 8;
                maxnumber = 200;
                break;
        
            case 4:
                totalattempts = 5;
                maxnumber = 200;
                break;

             // Fallback to medium if invalid input
            default:
                totalattempts = 10;
                maxnumber = 100;
                printf("\nInvalid choice. Setting difficulty to Medium.\n");
                break;
        }
        
        
        int secretnumber = rand() % maxnumber + 1; // Random number between 1 and maxnumber
        int guess;
        int won = 0; // Flag to check if player won

        // Thresholds for proximity feedback (based on range size)
        double veryclose = maxnumber * 0.03;  
        double close = maxnumber * 0.07;

        printf("Guess a number between 1 and %d\n", maxnumber);

        // Attempts loop
        for (int i = 1; i <= totalattempts; i++) //attempts counter
        {
            attemptsused = i;

            
            printf("\nAttempt #%d of #%d\n", i, totalattempts);
            printf("What's your guess? ");

            // Input validation (checks if input is a valid integer)
            if (scanf("%d", &guess) != 1)
            {
                printf("\nInvalid input! Guess a number between 1 and %d!\n", maxnumber);
                while (getchar() != '\n');
                i--;
                continue;
            }
            
            //range validation
            if (guess < 1 || guess > maxnumber)
            {
                printf("\nPlease enter a number between 1 and %d!\n", maxnumber);
                i--; //doesn't count as a valid attempt
                continue;
            }   
            
            int right = guess == secretnumber; //check if guess is correct
            int greater = guess > secretnumber; //check if guess is higher than secret number
            int diff = abs(guess - secretnumber); //check the distance between guess and secret number

            if (right)
            {
                won = 1;
                break; //exit loop if correct
            }
            else
            {
                //feedback to guide the player
                if (greater)
                {
                    printf("\nThe secret number is less than your guess!\n");
                }
                else
                {
                    printf("\nThe secret number is greater than your guess!\n");
                }
                //extra feedback on how close the guess is
                if (diff <= veryclose)
                {
                    printf("VERY CLOSE! You're almost there!\n");
                }
                else if (diff <= close)
                {
                    printf("Close! Keep trying!\n");
                }

            }
            
            // Scoring system:
            // - Lose points based on distance from the correct number
            // - Lose fixed points per attempt (discourages too many tries)
            double pointslost = abs(guess - secretnumber) / 2.0;
            points -= pointslost;
            points -= 10;

            //prevent negative score
            if(points < 0)
            {
                points = 0;
            }

        }
    
        //win condition
        if(won == 1)
        {
            printf("\n");
            printf("  __   __            _    _ _       \n");
            printf("  \\ \\ / /           | |  | (_)      \n");
            printf("   \\ V /___  _   _  | |  | |_ _ __  \n");
            printf("    \\ // _ \\| | | | | |/\\| | | '_ \\ \n");
            printf("    | | (_) | |_| | \\  /\\  / | | | |\n");
            printf("    \\_/\\___/ \\__,_|  \\/  \\/|_|_| |_|\n");
            printf("\n\n");


            printf("\n\nNice! You got it! You guessed the number!\n");
            printf("You scored %.2f points\n", points);
            printf("Attempts used: %d\n", attemptsused);       
        }
        else
        {
            //lose condition
            printf("\n\n");
            printf("       \\|/ ____ \\|/    \n");   
            printf("        @~/ ,. \\~@         YOU LOSE!   \n");   
            printf("       /_( \\__/ )_\\         \n");   
            printf("          \\__U_/        \n");

            printf("\nOh no! You've used all your attempts!\n");
            printf("Be careful - running out of attempts means game over.\n");
            printf("Give it another shot... you can do better next time!\n");
            printf("\n\nThe number was %d\n", secretnumber);

        }
        //ask player if they want to play again
        printf("\nPlay again and see if you can do even better! (y/n): ");
        scanf(" %c", &playagain);
    }
    printf("\nGAME OVER\n");
}