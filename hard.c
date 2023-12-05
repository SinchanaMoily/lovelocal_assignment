#include <stdio.h>
#include <string.h>

// Function to find the shortest palindrome by adding characters in front of the string
char* shortestPalindrome(char* s) {
    // Check if the string is empty or has only one character
    int len = strlen(s);
    if (len <= 1) {
        return s;
    }

    // Create a new string to store the result
    char* result = (char*)malloc(2 * len * sizeof(char));

    // Copy the reverse of the string (excluding the first character) to the result
    for (int i = len - 1; i > 0; --i) {
        result[len - 1 - i] = s[i];
    }

    // Concatenate the original string to the result
    strcat(result, s);

    return result;
}

// Main function
int main() {
    char s[50001];  // Assuming the maximum length of the string is 50000

    // Input from the user
    printf("Enter the string: ");
    scanf("%s", s);

    // Calculate and display the result
    char* result = shortestPalindrome(s);
    printf("Input: s = \"%s\"\nOutput: \"%s\"\n", s, result);

    // Free the dynamically allocated memory
    free(result);

    return 0;
}