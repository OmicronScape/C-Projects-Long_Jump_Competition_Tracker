/* Long Jump Competition Tracker */

#include <stdio.h>

#define NUM_OF_ATHLETES 8  /* The competition has 8 athletes */
#define NUM_OF_JUMPS 6     /* Each athlete makes 6 jumps (3 initial and 3 for the top 4) */

/* Athlete numbers */
int ArithmAthl[NUM_OF_ATHLETES];                      /* Array: Athlete numbers */
float Epidoseis[NUM_OF_ATHLETES][NUM_OF_JUMPS] = {0}; /* Array: Athlete performances */
float maxEpid[NUM_OF_ATHLETES];                       /* Array: Maximum performances of athletes */

/* Function declarations */
void input_data_A(); /* Input data for jumps 1-2-3 (attempts) */
void input_data_B(); /* Input data for jumps 4-5-6 (attempts) */
void find_max();     /* Find the maximum performance for each athlete */
void sort_data();    /* Sort performances in descending order */
void print_data();   /* Print sorted performances */

/*                  |---------PROGRAM USAGE INSTRUCTIONS---------|
  The program records and processes the performances of 8 athletes in the long jump.
  - Step 1 --> Function "input_data_A": Ask the user to enter the numbers
               and performances of the athletes in the first 3 attempts.
  - Step 2 --> Function "find_max": Calculate the maximum performance of each athlete.
  - Step 3 --> Function "sort_data": Sort the athletes in descending order based on
               their maximum performance.
  - Step 4 --> Function "print_data": Display the sorted results of the athletes.
  - Step 5 --> Function "input_data_B": Ask the user to enter the performances
               of the top four athletes for attempts 4-5-6.
  - Step 6 --> Function "find_max": Update the maximum performances with the new attempts.
  - Step 7 --> Function "sort_data": Re-sort the athletes based on the final performances.
  - Step 8 --> Function "print_data": Display the final results of the athletes.
*/

int main()
{
    input_data_A(); /* Record athlete numbers and first 3 attempts */
    find_max();     /* Calculate maximum performance */
    sort_data();    /* Sort athletes based on best performance */
    print_data();   /* Print results after the first 3 attempts */
    input_data_B(); /* Record performances of the top 4 athletes */
    find_max();     /* Update maximum performances */
    sort_data();    /* Re-sort */
    print_data();   /* Print final results */
    return 0;       
}

/* Input athlete number (AA) */
void input_data_A()
{
    for (int i = 0; i < NUM_OF_ATHLETES; i++)
    {
        int valid = 0;
        while (!valid)
        {
            printf("Number of athlete %d (100-999): ", i + 1);
            scanf("%d", &ArithmAthl[i]);
            if (ArithmAthl[i] >= 100 && ArithmAthl[i] <= 999)
            {
                valid = 1;
            }
            else
            {
                printf("Invalid Value!\n");
            }
        }
    }

    /* First 3 attempts */
    /* Enter the first 3 performances with validity check 1-12 or -1 for invalid jump attempt. */
    for (int j = 0; j < 3; j++) 
    {
        printf("%d Attempt\n", j + 1);
        for (int i = 0; i < NUM_OF_ATHLETES; i++)
        {
            int valid = 0;
            while (!valid)
            {
                printf("Athlete %d (1-12 or -1 for invalid): ", ArithmAthl[i]);
                scanf("%f", &Epidoseis[i][j]);
                if ((Epidoseis[i][j] >= 1 && Epidoseis[i][j] <= 12) || Epidoseis[i][j] == -1)
                {
                    valid = 1;
                }
                else
                {
                    printf("Please enter a value between 1 and 12 or press -1 for invalid attempt.\n");
                }
            }
        }
    }
}
    
/* Input data for jumps 4-5-6 */
/* Only the top 4 athletes make the 3 additional attempts. */
void input_data_B()
{
    for (int j = 3; j < 6; j++) /* Additional 3 attempts */
    {
        printf("%d Attempt\n", j + 1);
        for (int i = 3; i >= 0; i--) /* Only the top 4 athletes */
        {
            int valid = 0;
            while (!valid)
            {
                printf("Athlete %d (1-12 or -1 for invalid): ", ArithmAthl[i]);
                if (scanf("%f", &Epidoseis[i][j]) != 1)
                {
                    while (getchar() != '\n'); // Clear the buffer
                    printf("Please enter a value between 1 and 12 or press -1 for invalid attempt.\n");
                    continue;
                }
                if ((Epidoseis[i][j] >= 1 && Epidoseis[i][j] <= 12) || Epidoseis[i][j] == -1)
                {
                    valid = 1;
                }
                else
                {
                    printf("Please enter a value between 1 and 12 or press -1 for invalid attempt.\n");
                }
            }
        }
    }
}

/* Find the maximum performance for each athlete */
/* Calculate the best performance from the first 3 attempts */
void find_max()
{
    for (int i=0; i< NUM_OF_ATHLETES; i++)
    {
        float max= Epidoseis[i][0];
        for (int j = 1; j < NUM_OF_JUMPS; j++)
        {
            if(Epidoseis[i][j] > max)
            {
                max = Epidoseis[i][j];
            }
        }
        maxEpid[i] = max;
    }
}

/* Sort performances in descending order */
/* Descending sort based on best performance */
/* Swap the positions of athletes and their corresponding performances. */
void sort_data()
{
    for (int i = 0; i < NUM_OF_ATHLETES -1; i++)
    {
        for (int j= i + 1; j < NUM_OF_ATHLETES; j++)
        {
            if(maxEpid[i] < maxEpid[j])
            {
                float tempEpid = maxEpid[i];
                maxEpid[i] = maxEpid[j];
                maxEpid[j] = tempEpid;

                int tempAthl = ArithmAthl[i];
                ArithmAthl[i] = ArithmAthl[j];
                ArithmAthl[j] = tempAthl;

                // Swap Epidoseis
                for (int k = 0; k < NUM_OF_JUMPS; k++)
                {
                    float tempJump = Epidoseis[i][k];
                    Epidoseis[i][k] = Epidoseis[j][k];
                    Epidoseis[j][k] = tempJump;
                }
            }
        }
    }
}

/* Print sorted performances */
/* Print the athlete numbers and their performances in a table. */
void print_data()
{   
    printf("--------------------------------------------------------------------------\n");
    printf("\n- INTERNATIONAL TRACK AND FIELD MEETING - LONG JUMP - FINAL RESULTS -\n");
    printf("--------------------------------------------------------------------------\n");
    printf("A_A |    1   |    2   |   3    |    4   |    5    |    6   |  max  |\n");
    printf("--------------------------------------------------------------------------\n");
    for (int i = 0; i < NUM_OF_ATHLETES; i++)
    {
        printf("%3d |", ArithmAthl[i]);
        for (int j = 0; j < NUM_OF_JUMPS; j++)
        {
            if (Epidoseis[i][j] == -1) /* Here is the invalid attempt */
            {
                printf("    X   |");
            }
            else if (Epidoseis[i][j] == 0 && j >= 3) /* Here are the empty attempts after the 3rd. */
            {
                printf("        |");
            }
            else
            {
                printf(" %6.2f |", Epidoseis[i][j]);
            }
        }
        printf(" %6.2f\n", maxEpid[i]); /* Here is the maximum performance */
    }
}

/*END OF PROGRAM */
