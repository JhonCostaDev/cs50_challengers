#include <stdio.h>
#include <string.h>

int charToInt(char value);
void checkCreditCard(char arr[]);

int main(void) {
    //char cardNumber[17];

    //printf("Number:\n");
    //scanf("%s", cardNumber);//fgets(cardNumber, 17, stdin);
    char *cardNumber = "4003600000000014";
    printf("%s\n", cardNumber);
    checkCreditCard(cardNumber);

    

    

    return 0;
}

int charToInt(char value) {
    int number;
    number = value - '0';
    
    return number;
}
void checkCreditCard(char arr[]) {
    int arrLenght = strlen(arr);
    int cardNumber[arrLenght];
    int sumEvenPosition = 0;
    int sumOddPosition = 0;
    int checkSum;

    //printf("%d\n", arrLenght);
    for(int i = 0; i < arrLenght; i++) {
        
        cardNumber[i] = charToInt(arr[i]);

        if(i % 2 ==0) {
            printf("%d, ", cardNumber[i]);
            if ((cardNumber[i] * 2) > 9) {
                sumEvenPosition += ((cardNumber[i] * 2)/10) + ((cardNumber[i] * 2)%10);
            } else {
                sumEvenPosition += cardNumber[i] * 2;
            }
        } else {
            sumOddPosition += cardNumber[i];
        }
    }

    printf("\n%d\n", sumEvenPosition);
    printf("\n%d\n", sumOddPosition);
    printf("%d\n", checkSum);
    checkSum = (sumEvenPosition + sumOddPosition) % 10;
    printf("%d\n", checkSum);
    //TODO: implemente the cardbrand
}   