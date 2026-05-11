#include <stdio.h>
#include <string.h>

int charToInt(char value);
void checkCreditCard(char arr[]);
void checkBrandCreditCompany(char arr[], char* stringBuffer);
//TODO: Create a function that acepts only numbers and max 16 caracters
//TODO: Refactor the functions to be opmizates

int main(void) {
    char cardNumber[17];

    printf("Number: ");
    scanf("%s", cardNumber);//fgets(cardNumber, 17, stdin);
    //char *cardNumber = "30569309025904";//"2223000048400011";//"6176292929";//"4003600000000014", "30569309025904";
    
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
    int checkSum = 0; 

    
    for(int i = 0; i < arrLenght; i++) {
        
        cardNumber[i] = charToInt(arr[i]);

        if(i % 2 ==0) {
            
            if ((cardNumber[i] * 2) > 9) {
                sumEvenPosition += ((cardNumber[i] * 2)/10) + ((cardNumber[i] * 2)%10);
            } else {
                sumEvenPosition += cardNumber[i] * 2;
            }
        } else {
            sumOddPosition += cardNumber[i];
        }
    }

    checkSum = (sumEvenPosition + sumOddPosition) % 10;
    
    char cardBrand[25];
    if(checkSum != 0) {
        printf("INVALID\n");
        return;
    }
    checkBrandCreditCompany(arr, cardBrand);
    printf("%s\n", cardBrand);
}   

void checkBrandCreditCompany(char arr[], char* stringBuffer) {
    char brandDigits[3];
    strncpy(brandDigits, arr, 2);
    brandDigits[2] = '\0';

    if(strcmp(brandDigits, "30") == 0) {
        strcpy(stringBuffer, "Diners Club");
    } else if(strcmp(brandDigits, "37") == 0) {
        strcpy(stringBuffer, "American Express");
    } else if(strcmp(brandDigits, "40") == 0 || strcmp(brandDigits, "41") == 0 || strcmp(brandDigits, "42") == 0 || strcmp(brandDigits, "49") == 0) {
        strcpy(stringBuffer, "VISA");
    } else if(strcmp(brandDigits, "22") == 0 || strcmp(brandDigits, "51") == 0 || strcmp(brandDigits, "55") == 0)  {
        strcpy(stringBuffer, "MasterCard");
    } else {
        strcpy(stringBuffer, "Unknown Card Company");
    }
}