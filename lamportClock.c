#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, k;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int p[20];
    int **e = calloc(n, sizeof(int*));
    for (i=0; i<n; i++) {
        printf("Enter number of events in process%d: ",i+1);
        scanf("%d",&p[i]);
        e[i] = calloc(p[i], sizeof(int));
        for (j=0; j<p[i]; j++) {
            e[i][j] = j+1;
        }
    }
    for (i=0; i<n; i++) {
        for (j=0; j<p[i]; j++) {
            printf("e%d%d (%d) -> ", i+1, j+1, e[i][j]);
        }
        printf("\n");
    }
    int choice = 0;
    int c, d, l, m;
    do {
        printf("Is there a sending event? 1-yes 2-no 3-exit\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1: {
                printf("Enter sending process num and event num: ");
                scanf("%d %d", &c, &d);
                c--; d--;
                printf("Enter recieving process num and event num: ");
                scanf("%d %d", &l, &m);
                l--; m--;
                if (e[l][m] < (e[c][d]+1)) {
                    e[l][m] = e[c][d]+1;
                    for (k=m+1; k<j; k++) {
                        e[l][k] = e[l][k-1]+1;
                    }
                }
                for (i=0; i<n; i++) {
                    for (j=0; j<p[i]; j++) {
                        printf("e%d%d (%d) -> ", i+1, j+1, e[i][j]);
                    }
                    printf("\n");
                }
                break;
            }
            case 2: {
                for (i=0; i<n; i++) {
                    for (j=0; j<p[i]; j++) {
                        printf("e%d%d (%d) -> ", i+1, j+1, e[i][j]);
                    }
                    printf("\n");
                }
                break;
            }
        }
    } while (choice<=2);
}