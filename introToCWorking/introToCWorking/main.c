#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    
    int riders_amt, item, item_bool, lose_item, i, total, seed, tossout, rider = 1, flag = 1;
    
    int inventory[6][6] = {0};
    
    char item_names[6][20] = {"BLANKET", "SADDLE", "JACKET", "HARNESS", "GOOGLES", "HELMET"};
    
    printf("How many dragonriders are raiding the equipment shed?\n");
    
    scanf("%d",&riders_amt);
    
    seed = time(NULL);
    
    srand(seed);
    
    while (flag == 1){
        
        for (rider = 1; rider <= riders_amt; rider++){
            printf("\nRider %d, it is your turn. Enter 0 to look for an item.\n", rider);
            scanf("%d",&tossout);
            
            item = ((rand()/157) % 7);
            
            if (item != 6){
                printf("\nRider %d, you have found %s.\n",rider,item_names[item]);
                if (item != 1 && item != 3){
                    if (inventory[rider-1][item] == 0){
                        inventory[rider-1][item] = 1;
                        printf("You now have %s!\n",item_names[item]);
                    }
                    else{
                        printf("\nYou already have that item.\n");
                    }
                }
                else{
                    if (inventory[rider-1][item] == 0){
                        if (inventory[rider-1][item-1] == 0){
                            printf("\nSorry, you can't obtain %s.\n",item_names[item]);
                        }
                        else{
                            inventory[rider-1][item] = 1;
                            printf("\nYou now have %s\n",item_names[item]);
                        }
                    }
                    else{
                        printf("\nYou already have that item.\n");
                    }
                }
            }
            else{
                printf("\nYou've been caught!\n");
                item_bool = 0;
                for (i = 0; i < 6; i++){
                    if (inventory[rider-1][i] == 1)
                        item_bool = 1;
                }
                if (item_bool == 1){
                    printf("\nWhich piece would you like to lose?\n");
                    for (i = 0; i < 6; i++){
                        if (inventory[rider-1][i] == 1)
                            if (!((i == 0 && inventory[rider-1][1] == 1) || (i == 2 && inventory[rider-1][3] == 1)))
                                printf("%d. %s\n",i,item_names[i]);
                    }
                    scanf("%d",&lose_item);
                    
                    inventory[rider-1][lose_item] = 0;
                    
                    printf("\nYou have selected the %s to discard.\n", item_names[lose_item]);
                }
                else{
                    printf("\nThere is no equipment for you to lose. Lucky you, sort of.\n");
                }
            }
            printf("\nRider %d, here is what you currently have:\n", rider);
            total = 0;
            for (i = 0; i < 6; i++){
                if (inventory[rider-1][i] == 1){
                    printf("%s\n",item_names[i]);
                    total += 1;
                }
            }
            if (total == 6){
                flag = 0;
                break;
            }
        }
    }
    printf("\nCongratulations Rider %d, you are the first dragon rider!\n\n",rider);
    
    return 0;
}