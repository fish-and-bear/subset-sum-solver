#include <stdio.h>
#include <stdlib.h>

void findSubsets(int *set, int setSize, int targetSum);

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open input file.\n");
        return 1;
    }

    int numSets;
    if (fscanf(file, "%d", &numSets) != 1) {
        fprintf(stderr, "Error: Invalid input format.\n");
        fclose(file);
        return 1;
    }
    printf("Number of sets: %d\n", numSets);

    for (int i = 0; i < numSets; i++) {
        int targetSum;
        if (fscanf(file, "%d", &targetSum) != 1) {
            fprintf(stderr, "Error: Invalid target sum format.\n");
            fclose(file);
            return 1;
        }
        printf("Target Sum for set %d: %d\n", i + 1, targetSum);

        int *set = NULL;
        int setSize = 0;
        int capacity = 10;
        set = (int *)malloc(capacity * sizeof(int));
        if (set == NULL) {
            fprintf(stderr, "Error: Memory allocation failed.\n");
            fclose(file);
            return 1;
        }

        int value;
        while (fscanf(file, "%d", &value) == 1) {
            if (setSize == capacity) {
                capacity *= 2;
                set = (int *)realloc(set, capacity * sizeof(int));
                if (set == NULL) {
                    fprintf(stderr, "Error: Memory allocation failed.\n");
                    fclose(file);
                    return 1;
                }
            }
            set[setSize++] = value;
            if (fgetc(file) == '\n') break;
        }
        printf("Set %d size: %d\n", i + 1, setSize);
        printf("Set %d elements: ", i + 1);
        for (int j = 0; j < setSize; j++) {
            printf("%d ", set[j]);
        }
        printf("\n");

        findSubsets(set, setSize, targetSum);
        free(set);
    }

    fclose(file);
    return 0;
}

void findSubsets(int *set, int setSize, int targetSum) {
    int *stack = (int *)malloc(setSize * sizeof(int));
    if (stack == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return;
    }
    int stackSize = 0;
    int currentSum = 0;
    int foundSolution = 0;

    int i = 0;
    while (i < setSize || stackSize > 0) {
        if (currentSum == targetSum) {
            printf("{");
            for (int j = 0; j < stackSize; j++) {
                printf("%d", set[stack[j]]);
                if (j < stackSize - 1) {
                    printf(", ");
                }
            }
            printf("}\n");
            foundSolution = 1;
        }

        if (currentSum >= targetSum || i == setSize) {
            if (stackSize == 0) break;
            i = stack[--stackSize];
            currentSum -= set[i];
            i++;
        } else {
            if (currentSum + set[i] <= targetSum) {  // Branch and Bound
                stack[stackSize++] = i;
                currentSum += set[i];
            }
            i++;
        }
    }

    if (!foundSolution) {
        printf("No valid subsets found.\n");
    }

    free(stack);
}