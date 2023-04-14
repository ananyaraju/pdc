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
    int fail = 1;
    int n = total-1;
    do {
        printf("Coordinator fails!\n");
        nodes[coordinator].isActive = false;
        printf("Enter the node that detects failure starts election: ");
        scanf("%d", &proc);
        proc--;
        n--;
        int next;
        for (int i=0; i<total; i++) {
            next = (proc+i)%total;
            if (next!=proc && nodes[next].isActive) {
                printf("Process %d recieves msg from process %d\n",     next+1, proc+1);
            }
            else if (!nodes[next].isActive) {
                continue;
            }
        }
        for (int i=total-1; i>=0; i--) {
            if (nodes[i].isActive) {
                printf("Process %d becomes new coordinator\n", i+1);
                coordinator = i;
                break;
            }
        }
        int cont;
        printf("Continue?: 1-yes 0-no: ");
        scanf("%d", &cont);
        if (cont == 0) {
            printNodes(total);
            fail = 0;
        }
    } while (fail == 1);
}