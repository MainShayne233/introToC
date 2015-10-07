/*
Shayne Tremblay
 
Program 4: This program will calculate average flight distances that the 
            user's dragon flew per day
 
9-24-15
*/

//pre-processor directives
#include <stdio.h>

//main function
int main(){
    
    //declares needed int variables
    int t_days, day, flight;
    
    //declares needed double variables
    double avg_distance, distance, t_flights, t_distance;
    
    //prompts user to input how many days their dragon has been practicing
    printf("\nHow many days has your dragon been practicing?\n\n");
    
    //scans the user's input and store it in the t_days int variable
    scanf("%d", &t_days);
    
    //starts a for loop that will loop from 1 to the value for t_days, representing each day of practice
    for (day = 1; day<=t_days; day++){
        
        //prompts the user for the amount of flights that were completed on the particular day the loop is on
        printf("\nHow many flights were completed in day #%d?\n\n",day);
        
        //scans the user's input and store it in the t_flights double variable
        scanf("%lf",&t_flights);
        
        /*
        sets the t_distance to 0, as it will be the variables that
        counts up the total distance for each specific day
        */
        t_distance = 0;
        
        //starts a foor loop that loops from 1 to the value of t_flights, representing each flight for the day
        for (flight = 1; flight<=t_flights; flight++){
            
            //prompts user for the length of the specific flight the loop is on
            printf("\nHow long was flight #%d?\n\n", flight);
            
            //scans the user's input and stores it in the distance double variable
            scanf("%lf", &distance);
            
            //adds the distance value to the t_distance value
            t_distance += distance;
            
        }
        
        /*
        once the for loop has ended, the program should have the total distance, so it now
        computers the average distance by dividing the total distance by the amount of flights
        for that day
        */
        avg_distance = t_distance/t_flights;
        
        //ouputs to the user the average flight distance for that day rounded to 3 decimal points
        printf("\nDay #%d: The average distance is %.3f.\n", day, avg_distance);
    }
    
    //exit main function
    return 0;
}