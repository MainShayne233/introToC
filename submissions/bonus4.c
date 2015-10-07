/*
Shayne Tremblay
Bonus Program 4: A program that has the user guess how much money they owe with
                feedback telling them if they owe more or less than their guess.
9-14-15
*/

//pre-processor directives
#include<stdio.h>
#include <time.h>
#include <stdlib.h>

//the mins and max values for the randomly generated amount owed are constants
#define MIN_OWED 500
#define MAX_OWED_DIF 4501

//main function
int main(){
    
    //declaring needed variables
    int owed, guess;
    
    //seeding the random number generator
    srand(time(0));
    
    /*
    generate a random amount owed, first by starting with a min of 500, and then
     adding a number between 0 and 4500 using a randomely generated number and finding its mod 4501
    */
    owed = MIN_OWED + (rand() % MAX_OWED_DIF);
    
    //loop that runs as long as the user's guess doesn't equal the amount they owe
    while (guess != owed){
        
        //prompt user for input
        printf("\nHow much do you think you owe?\n\n");
        
        //scan user's input and save it in an int variables called 'guess'
        scanf("%d",&guess);
        
        //if the user's guess was lower than the amount they owe, they are told this
        if (guess < owed){
            printf("\nYes, you owe more than %d dollars.\n",guess);
        }
        
        //if the user's guess was not lower than they amount they owe, the are told this
        else{
            printf("\nNo, you do not owe more than %d dollars.\n",guess);
        }
    }
    //once the user's guess is equal to the amount they owe, the loop ends
    
    //the user's guess was correct, so they are congratulated
    printf("\nCongratulations for figuring out you owe %d dollars.\n",owed);
    
    //exit main function
    return 0;
}


