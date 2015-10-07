/*
 Shayne Tremblay
 Program 3: A program that, given an initial nest height, outputs a table showing the distance
 the dragon has fallen out of its nest every second
 9-15-15
 */

//pre-processor directives
#include <stdio.h>
#include <math.h>

//the 1/2(g) part of the distance formula is a constant of 16
#define HALF_GRAV_CONS 16

//main function
int main(){
    
    //declaring needed variables
    int nest_height, altitude, second;
    
    //ask the user for the height of the dragon's nest
    printf("\nWhat is the height of the dragon's nest?\n\n");
    
    //scan in the user's input and store it in an int variable called 'nest_height
    scanf("%d", &nest_height);
    
    //set the initial altitude of the dragon to the height of the nest
    altitude = nest_height;
    
    //print out the top of the chart using tabs
    printf("\nTime\tAltitude");
    
    /*
     the code within this loop will loop until the computed altitude is less than 1, which is when the
     dragon has reached the ground, and every time it loops, 1 is added to 'seconds'
     */
    for (second = 1; altitude > 1; second++){
        
        /*
        the altitude is computed by subtracting the distance the dragon has fallen given
        using the distance formula where t is the represented by the 'seconds' variables, and
        then subtracting this computed distance from the nest_height
        */
        altitude = nest_height - HALF_GRAV_CONS*pow(second,2);
        
        /*
        once the altiude has reached a value that is less than zero, this means the dragon has
        already reached the ground, so in this case, the altitude is set to 0 so it may be printed
        properly
        */
        if (altitude < 0){
            altitude = 0;
        }
        
        /*
        the program outputs to the user the next row in the table, giving the altitude of the dragon
        for every second,with the value being seperated by a tab to line up with the headings
        */
        printf("\n%d\t%d",second,altitude);
    }
    
    //print a new line just for styling the program's output
    printf("\n");
    
    //exit main function
    return 0;
}