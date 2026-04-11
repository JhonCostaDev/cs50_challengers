#include <stdio.h>

int main(void) {
    int size; // Declare an integer variable to store the size of the pyramid

    // Use a do-while loop to ensure the user inputs a valid size
    do {
        // Prompt the user for the height of the pyramid
        printf("Height: ");
        scanf("%d", &size);
    } while (size < 1 || size > 8); // Continue prompting until the user enters a size between 1 and 8

    // Use a for loop to iterate through each level of the pyramid
    for (int i = 1; i <= size; i++) {
        // Use a nested for loop to print spaces and hashes for each level
        for (int j = 0; j < size; j++) {
            if (j < size - i) // Print spaces for the left side of the pyramid
            {
                printf(" "); // Print a space character
            }
            else
            {
                printf("#"); //
            }
        }
        printf("\n"); // Move to the next line after printing each level of the pyramid
    }
}