#include <stdio.h>
#include <stdlib.h>

int main() {
    int total, index;
    printf("Enter number of processes: ");
    scanf("%d", &total);
    int p[20];
    printf("Enter priorities: \n");
    for (int i=0; i<total; i++) {
        printf("Process %d: ", i+1);
        scanf("%d", &index);
        p[index-1] = i;
    }
    printf("\n\nProcesses according to priorities: \n");
    for (int i=0; i<total; i++) {
        printf("Process %d\n", p[i]+1);
    }
    printf("\n");
    for (int i=0; i<total; i++) {
        int curr = p[i];
        for (int j=0; j<total; j++) {
            if (curr != j)
                printf("Process %d sends request to Process %d\n", curr+1, j+1);
        }
        for (int j=0; j<total; j++) {
            if (curr != j)
                printf("Process %d sends ack to Process %d\n", j+1, curr+1);
        }
        printf("Process %d executes its CS\n", curr+1);
        for (int j=0; j<total; j++) {
            if (curr != j) {
                printf("Process %d sends msg to Process %d\n", curr+1, j+1);
            }
        }
        printf("\n");
    }
}