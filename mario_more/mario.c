#include <stdio.h>

int main()
{
    int size; // Declare an integer variable to store the size of the pyramid
    do // Use a do-while loop to ensure the user inputs a valid size
    {
        // Prompt the user for the height of the pyramid
        printf("Height:");
        scanf("%d", &size);
        
    }
    while (size < 1 || size > 8); // Continue prompting until the user enters a size between 1 and 8

    for (int i = 1; i <= size; i++) // Use a for loop to iterate through each level of the pyramid
    {
        for (int j = 0; j < size; j++)// Use a nested for loop to print spaces and hashes for each level
        {
            if (j < size - i) // Print spaces for the left side of the pyramid
            {
                printf(" "); // Print a space character
            }
            else
            {
                printf("#"); //
            }
        }
        printf("  "); // Print two spaces for the gap between the two halves of the pyramid
        for(int k = 1; k <= size; k++) // Use another for loop to print the gap between the two halves of the pyramid
        {

            if (k <= i) // Print hashes for the right side of the pyramid
            {
                printf("#");
            }
            else
            {
                printf(" "); // Print a space character for the right side of the pyramid
            }
        }
        printf("\n"); // Move to the next line after printing each level of the pyramid
    }
}