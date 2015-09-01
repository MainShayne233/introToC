/*
Shayne Tremblay
Program 1: Determines amount of sheep a dragon of a particular weight needs for 1 month.
8-31-2015
*/

//pre-processor directives
#include <stdio.h>

/*
the amount of protein per sheep is a constant of 200g
the amount of days in a month is a constant of 30 days
the conversion factor for protein needed for given weight is a constant of 1.5/2.2
*/
#define SHEEP_PROTEIN 200
#define DAYS_IN_MONTH 30
#define PROTEIN_NEEDED 1.5/2.2
#define REMAINDER_CHECK 0.99


//main function
int main(){
    
    //declaring needed variables
    int dragonWeight;
    int sheepNeeded;
    
    //prompt user for the weight of their dragon
    printf("How much does your dragon weigh?\n");
    
    //scan in user's input and store in in iny variable 'dragonWeight'
    scanf("%d", &dragonWeight);
    
    /*
    multiples weight by conversion factor to find protein needed for 1 day,
    multiplies that by the amount of days in 1 month,
    divides that by the amount of protein in 1 sheep,
    adds 0.99 constant to account for a possible remainder,
    value is stored as an int, which drops ending remainder
    */
    sheepNeeded = (dragonWeight*PROTEIN_NEEDED*DAYS_IN_MONTH/SHEEP_PROTEIN+REMAINDER_CHECK);
    
    //output telling the user the amount of sheep they need for their dragon
    printf("You will need %d sheep for your new dragon!", sheepNeeded);
    
    //end main function
    return 0;
    
}