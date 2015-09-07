/*
Shayne Tremblay
Bonus 2: This is a program that calculutes the amount of calories the user has consumed
9-1-2015
*/

//pre-processor directives
#include <stdio.h>

//setting the constants given by the assignment
#define CALS_PER_GR_PROTEIN 4
#define CALS_PER_GR_CARB 4
#define CALS_PER_GR_FAT 9

//main function
int main(){
    
    //declaring needed variables, setting total_calories to be 0.
    int protein;
    int carbohydrates;
    int fat;
    int total_calories = 0;
    
    //prompt the user to input what they ate that day
    printf("How many grams of protein did you eat?\n");
    scanf("%d",&protein);
    printf("How many grams of carbohydrates did you eat?\n");
    scanf("%d",&carbohydrates);
    printf("How many grams of fat did you eat?\n");
    scanf("%d",&fat);
    
    //add the amount of calories per amount of each nutrition type eaten
    total_calories += protein*CALS_PER_GR_PROTEIN;
    total_calories += carbohydrates*CALS_PER_GR_CARB;
    total_calories += fat*CALS_PER_GR_FAT;
    
    //output to the user how many calories they consumed
    printf("You ate %d calories of food.",total_calories);
    
    //end main function
    return 0;
    
}
