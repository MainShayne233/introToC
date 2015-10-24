/*
Shayne Tremblay
Program 5: This programs determines the best month for a dragon to hold its
           Celebration of first flight by comparing the dragon's preferred flying
           weather to a weather data file for Dragon Island
10-8-2015
*/

//pre-processor directives
#include <stdio.h>

//main function
int main(){
    
//initilaizing the file pointer
    FILE * ifp;

    
/*initializing needed variables
fname: weather data file name, maximum of 30 characters
good_days_cal: calendar array, with 12 elements, all starting at 0, that count up good flying days per month
total_days_cal: calendar array, with 12 elements, all starting at 0, that count up total days per month
ctemp: coldest temperture dragon can fly in
htemp: hottest temperature dragon can fly in
month: the month in question, regardless of year
best_month: best month for dragon to fly in
cur_val: the current value scanned from the weather data file
percent: percent of good flying days for a given month
highest_perc: the percent of good flying days for the best month
*/
    char fname[30];
    int good_days_cal[12] = { 0 };
    int total_days_cal[12] = { 0 };
    int ctemp, htemp, month, best_month = 0;
    float cur_val, percent, highest_perc = 0;
    
//prompt user for their dragon's weather preferences
    printf("Tell me about your dragon’s preferred temperature for flying:\n\n");
    
//ask the user for the lowest temperature their dragon can fly in
    printf("What is the coldest temperature they can fly in?\n");
    
//store value in an int variable called ctemp
    scanf("%d",&ctemp);
    
//ask the user for the highest temperature their dragon can fly in
    printf("\nWhat is the hottest temperature they can fly in?\n");

//store the value in an int variable called htemp
    scanf("%d",&htemp);
    
//ask the user for the name of the weather data file
    printf("\nPlease enter the name of the weather data file for Dragon Island.\n");

//store the string in an array called fname
    scanf("%s",fname);

//initialize the file pointer to the first location in the given file and set to read mode
    ifp = fopen(fname, "r");

//scan the first value into a float varuavle called cur_val
    fscanf(ifp, "%f", &cur_val);
    
//while loop that runs until the last value is scanned in, which is -1 in this case
    while (cur_val != -1){
        
/*
set the value of month, to the cur_val (which is the month scanned in from the
weather data file) minus 1, so that we can use it to be our index when accessing our calendar arrys
*/
        month = cur_val-1;
        
/*
for loop that simply runs fscanf 3 times since the DAY and YEAR values are irrelevant for
this program, and ends with the temperature for that day being stored in cur_val
*/
        for (int i = 0; i < 3; i++)
            fscanf(ifp, "%f", &cur_val);

/*
if the temperature for that day falls within the dragon's preferred range,
the good_days_cal array is updated at the current month's index to be +1 it's current value
*/
        if (cur_val >= ctemp && cur_val <= htemp)
            good_days_cal[month] += 1;

//the total_days_cal array is updated at the current month's index to be +1 it's current value
        total_days_cal[month] += 1;
        
//scan in the next value, which is next data entry's month value (exits loop if it's -1)
        fscanf(ifp, "%f", &cur_val);
    }
    
//close the weather data file, as it is no longer needed
    fclose(ifp);
    
//newline just for formatting
    printf("\n");

//for loop that itterates for each month
    for (month = 0; month < 12; month++){

/*
the percent of good flying days for each month is calculated by dividing the amount of
good flying days per month, by the amount of total days per month, and multiplying this value by 100
*/
        percent = (float) good_days_cal[month]/total_days_cal[month]*100;
        
/*
if the current calculated percent is higher than the last highest percent, then the 
best_month variable is set equal to the current month+1 (to compensate for the 0 index), and
the highest percent variable is set equal to the newely calculated percent
*/
        if (percent > highest_perc){
            best_month = month+1;
            highest_perc = percent;
        }

//prints the current month, followed by the percent of days within the dragon's preffered range
        printf("Month %d: %.2f%% of days in range.\n", month+1,percent);
    }

//tells the user which month will likely have the best flying weather for their dragon
    printf("\nI recommend month %d for the Celebration of the First Flight!\n\n", best_month);
    
//exit main function
    return 0;
    
}