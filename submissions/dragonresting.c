/*
Shayne Tremblay
 
Program 2: Determines the amount of rest the user's dragon
needs depending on how active they were, and tells the user
if their dragon needs to be more active
 
9-7-2015
*/

//pre-processor directives
#include <stdio.h>

/*
defined constants
the multiplication factor to convert timeActive to totalRest is 2.5
there are 60 minutes per hour
*/
#define REST_CONSTANT 2.5
#define MIN_PER_HOUR 60

int main(){
    
    //declaring needed variables
    int timeActive;
    int totalRest;
    int hoursNeeded;
    int minutesNeeded;
    
    //ask the user for the amount of minutes their dragon was active for
    printf("\nHow long was your dragon active for (in minutes)?\n\n");
    
    //scan in the user's input and save it as an int variable called timeActive
    scanf("%d", &timeActive);
    
    //if the dragon was active for more than 0 minutes, the condition is evaluted to true
    if (timeActive){
        
        //calculates the total rest time by multiplying the time the dragon was active by the rest constant
        totalRest = timeActive*REST_CONSTANT;
        
        //calculates the amount of hours by dividing the total rest time by the amount of minutes in an hour
        hoursNeeded = totalRest/MIN_PER_HOUR;
    
        //calcuates the amount of remaining minutes by finding totalRest mod MIN_PER_HOUR
        minutesNeeded = totalRest%MIN_PER_HOUR;
        
        //outputs to the user the amount of rest their dragon needs in terms of hours and minutes
        printf("\nYour dragon should rest for %d hours and %d minutes.\n",hoursNeeded,minutesNeeded);
        
    }
    
    /*
    if the user's dragon was active for 0 minutes, than the initial condition will evaluate to
    false, which will skip over the calcuations, and run this else code block instead
    */
    else{
        
        //in the case that timeActive=0, the user is told that there dragon needs more training time
        printf("\nYour dragon should spend more time training.\n");
        
    }
    
    //end main function
    return 0;
    
}
