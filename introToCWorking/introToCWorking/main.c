#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    
    int riders_amt, rider, item, item_bool, lose_item, i, flag = 1;
    
    int inventory[6][6] = {0};
    
    char item_names[6][20] = {"BLANKET", "SADDLE", "JACKET", "HARNESS", "GOOGLES", "HELMET"};
    
    printf("How many dragonriders are raiding the equipment shed?\n");
    
    scanf("%d",&riders_amt);
    
    while (flag == 1){
        
        for (rider = 1; rider <= riders_amt; rider++){
            printf("Rider %d, it is your turn. Enter 0 to look for an item\n\n");
            scanf("%d");
            
            srand(time(0));
            
            item = rand() % 7;
            
            if (item != 6){
                printf("Rider %d, you have found %s.\n",rider,item_names[item]);
                if (item != 1 && item != 3){
                    if (inventory[rider-1][item] == 0){
                        inventory[rider-1][item] = 1;
                        printf("You now have %s\n",item_names[item]);
                    }
                    else{
                        printf("You already have that item.\n");
                    }
                }
                else{
                    if (inventory[rider-1][item] == 0){
                        if (inventory[rider-1][item-1] == 0){
                            printf("Sorry, you can't obtain %s\n",item_names[item]);
                        }
                        else{
                            inventory[rider-1][item] = 1;
                            printf("You now have %s\n",item_names[item]);
                        }
                    }
                    else{
                        printf("You already have that item.\n");
                    }
                }
            }
            else{
                printf("You've been caught!\n");
                item_bool = 0;
                for (i = 0; i < 6; i++){
                    if (inventory[rider][i] == 1)
                        item_bool = 1;
                }
                if (item_bool == 1){
                    printf("Which piece would you like to lose?\n");
                    for (i = 0; i < 6; i++){
                        if (inventory[rider][i] == 1)
                            printf("%d. %s",i,item_names[i]);
                    }
                    scanf("%d",lose_item);
                    
                    inventory[rider][lose_item] = 0;
                    
                    printf("You have selected the %s to discard.\n", item_names[lose_item]);
                }
                else{
                    printf("There is no equipment for you to lose. Lucky you, sort of.\n");
                }
                
            }
        }
        
        
    }
    
}