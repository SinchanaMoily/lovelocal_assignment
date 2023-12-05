#include <stdio.h>
#include <stdlib.h>

// Function to find elements that appear more than ⌊ n/3 ⌋ times
int* majorityElement(int nums[], int numsSize, int* returnSize) {
    int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;

    // Voting process to find potential candidates
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = nums[i];
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = nums[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Count occurrences of potential candidates
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        }
    }

    // Check if candidates appear more than ⌊ n/3 ⌋ times
    *returnSize = 0;
    int threshold = numsSize / 3;
    int* result = (int*)malloc(sizeof(int) * 2);

    if (count1 > threshold) {
        result[(*returnSize)++] = candidate1;
    }

    if (count2 > threshold && candidate1 != candidate2) {
        result[(*returnSize)++] = candidate2;
    }

    return result;
}

// Function to print an array
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int n;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int nums[n];

    // Get array elements from the user
    printf("Enter %d elements separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int returnSize;
    int* result = majorityElement(nums, n, &returnSize);

    // Output the result
    printf("Input: ");
    printArray(nums, n);
    printf("Output: ");
    printArray(result, returnSize);

    free(result);

    return 0;
}