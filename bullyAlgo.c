#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int id;
    bool isActive;
}nodes[20];

void printNodes(int total) {
    printf("\nNodes:\n");
    for (int i=0; i<total; i++)
        printf("Node %d: %s\n", nodes[i].id, nodes[i].isActive ? "active" : "inactive");
    printf("\n");
}

int main() {
    int total;
    printf("Enter number of processes: ");
    scanf("%d", &total);
    for (int i=0; i<total; i++) {
        nodes[i].id = i+1;
        nodes[i].isActive = true;
    }
    printNodes(total);
    int coordinator, proc;
    printf("Current Coordinator: ");
    scanf("%d", &coordinator);
    coordinator--;
    printf("Enter the node that sends message to coordinator: ");
    scanf("%d", &proc);
    proc--;
    int fail;
    printf("Coordinator fails? 1-yes 0-no: ");
    scanf("%d", &fail);
    while (fail == 1) {
        nodes[coordinator].isActive = false;
        for (int i=proc+1; i<total; i++) {
            if (nodes[i].isActive && i!=coordinator) {
                printf("Process %d sends msg to Process %d\n",proc+1, i+1);
                printf("Process %d doesnt reply to Process %d\n", i+1, proc+1);
            }
        }
        printf("Process %d becomes coordinator\n", proc+1);
        printf("Sends message to all about its election: \n");
        for (int i=0; i<total; i++) {
            if (nodes[i].isActive) {
                printf("Process %d sends election info to process %d\n", proc+1, i+1);
            }
        }
        int cont;
        printf("NEW COORDINATOR: %d\n\n", proc+1);
        coordinator = proc;
        printf("Continue? 1-yes 0-no: ");
        scanf("%d", &cont);
        if (cont == 1) {
            printf("Enter the node that sends message to new coordinator: ");
            scanf("%d", &proc);
            proc--;
            printf("New Coordinator fails? 1-yes 0-no: ");
            scanf("%d", &fail);
        }
        else {
            fail = 0;
        }
    }
    printNodes(total);
}