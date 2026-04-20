#include <stdio.h>

//prototyping the functions used in the program
int getValue(void);
void countCoins(int *quater, int *dime, int *nickel, int *penny, int change);

int main(void) {
    //Declaring the variables to store the number of each type of coin and the amount of change owed
    int change, quater, dime, nickel, penny;

    //Prompting the user for the amount of change owed and validating the input
    do {
        change = getValue();
    } while (change < 0);
    
    //Calling the function to count the coins
    countCoins( &quater,  &dime,  &nickel,  &penny,  change);

    printf("======== Change ========\n");
    printf("Quaters: %d\nDimes: %d\nNickels: %d\nPennies: %d\n", quater, dime, nickel, penny);
    return 0;
}


//This function prompts the user for the amount of change owed and returns it as an integer
int getValue(void){
    int integer;
    printf("Change owed: ");
    scanf("%d", &integer);

    return integer;
}

//This function counts the number of each type of coin needed to make change
void countCoins(int *quater, int *dime, int *nickel, int *penny, int change) {

    //Initializing the coin counts to 0 preventing garbage values
    *quater = 0; *dime = 0; *nickel = 0; *penny = 0;
    while(change > 0) {  
        
        if (change >= 25) {
            change -= 25;
            (*quater) ++;
        } else if(change >= 10) {
            change-= 10;
            (*dime) ++;
        } else if(change >= 5) {
            change -= 5;
            (*nickel) ++;
        } else {
            change --;
            (*penny) ++;
        }
    }
}