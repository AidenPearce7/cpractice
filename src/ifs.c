#include <stdio.h>
#include <stdlib.h>
#define temperature 38.0
void Fine();
int main()
{
    float temp = 0;
    printf("What is your  temperature?\n");
    scanf("%f", &temp);
    if (temp <= temperature)
    {
        Fine();
    }
    else if (temp > temperature)
    {
        int indicator = 0;
        printf("Do you have trouble breathing?\n");
        scanf("%d", &indicator);
        if (!indicator)
        {
            Fine();
        }
        else
        {
            printf("You might have covid-19, call a doctor.\n");
        }
    }
    else
    {
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;


}
void Fine()
{
    printf("You probably do not have covid-19\n");
    exit(EXIT_SUCCESS);
}
