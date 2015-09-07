/*
Shayne Tremblay
9-6-2015
Bonus Program 3: This is a program that determines the cost of OJ taking into account 
    the discounts the user gets from a BOGO deal
*/

//pre-processor directives
#include <stdio.h>

//main function
int main(){
    
    //declaring needed variables
    float unitPrice;
    int amount;
    float totalCost;
    
    //ask the user for the cost of one container of OJ
    printf("\nWhat is the cost of one container of OJ in dollars?\n\n$");
    
    //scan and save the user's input into a float variable called 'unitPrice'
    scanf("%f", &unitPrice);
    
    //ask the user for the amount of containers that they are buying
    printf("\nHow many containers are you buying?\n\n");
    
    //scan and save the user's input into an int variable called 'amount;
    scanf("%d", &amount);
    
    /*
    total cost gets calculated based on the unit price, the amount of containers being
    purchased, and the BOGO deal
    */
    
    /*
    if the user buys an even amount of containers, than the total cost is simply the cost per
    container, multiplied by the amount the user is buying, and all of that divides by 2 as the
    user gets every other container for free
    */
    
    if (amount%2==0){
        totalCost = amount/2*unitPrice;
    }
    
    /*
    if the user didn't buy an even amount of containers, than the amount that they purchased is
    odd, and the total cost is calcuated the same way, 1 is added to the 'purchasing amount' after th
    */
    
    else{
        totalCost = (amount/2+1)*unitPrice;
    }
    
    //ouput the total cost to the user
    printf("\nThe total cost is $%.2f.\n",totalCost);
    
    //end main function
    return 0;
}