#include <stdio.h>
#include <stdbool.h>

int main() {
    int n = 5;                                              // Number of processes
    int m = 3;                                              // Number of resource types
    int alloc[n][m], maxNeed[n][m], avail[m];
    int need[n][m];
    bool finish[n];
    int safeSeq[n];
    int count = 0;

    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open input.txt\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {                            // Read Allocation and Max for each process
        for (int j = 0; j < m; j++) {            
            fscanf(fp, "%d", &alloc[i][j]);
        }
        for (int j = 0; j < m; j++) {
            fscanf(fp, "%d", &maxNeed[i][j]);
        }
    }

    for (int j = 0; j < m; j++) {                              // Read Available resources
        fscanf(fp, "%d", &avail[j]);
    }                            
    fclose(fp);

    for (int i = 0; i < n; i++)                                // Calculate Need matrix
        for (int j = 0; j < m; j++) {
            need[i][j] = maxNeed[i][j] - alloc[i][j];
        }

    for (int i = 0; i < n; i++)                                // Initialize finish array
        finish[i] = false;

    printf("Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++)
            printf("%d ", alloc[i][j]);
        printf("\n");
    }

    printf("\nMax Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++)
            printf("%d ", maxNeed[i][j]);
        printf("\n");
    }

    printf("\nNeed Matrix (Max - Allocation):\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    printf("\nInitial Available Resources: ");
    for (int j = 0; j < m; j++)
        printf("%d ", avail[j]);
    printf("\n\n");

    while (count < n) {                                     // Banker's Algorithm Main Loop
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < m; j++)
                    if (need[i][j] > avail[j])
                        break;

                if (j == m) {                               // If all needs are satisfied 
                    for (int k = 0; k < m; k++)
                        avail[k] += alloc[i][k];            // Resource Allocation

                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("The system is NOT in a safe state.\n");
            return 0;
        }
    }

    printf("The system is in a SAFE state.\nSafe Sequence: < ");
    for (int i = 0; i < n; i++) {
        printf("P%d", safeSeq[i]);
        if (i != n - 1) printf(", ");
    }
    printf(" >\n");

    return 0;
}
