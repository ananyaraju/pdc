#include <stdio.h>
#include <stdlib.h>

int main() {
    int total;
    printf("Enter number of sites: ");
    scanf("%d", &total);
    int t[20];
    int r[20][20];
    for (int i=0; i<total; i++) {
        t[i] = 0;
        for (int j=0; j<total; j++) {
            r[i][j] = 0;
        }
    }
    int hasToken;
    printf("Enter the site that initially has token: ");
    scanf("%d", &hasToken);
    hasToken--;
    int requested;
    int cont = 1;
    do {
        printf("Site %d currently has token\n", hasToken+1);
        printf("Enter the site that wants to enter CS: ");
        scanf("%d", &requested);
        requested--;
        for (int i=0; i<total; i++) {
            r[i][requested]++;
        }
        for (int i=0; i<total; i++) {
            if (i!=requested) {
                if (r[i][requested] > t[requested]+1) {
                    printf("Requested is outdated");
                    exit(0);
                }
                if (r[i][requested] != t[requested]+1) {
                    printf("There is an outstanding request");
                    exit(0);
                }
            }
        }
        printf("Token is given to process %d\n", requested+1);
        hasToken = requested;
        printf("Process %d executes CS\n", hasToken+1);
        t[hasToken]++;
        printf("Process %d completed executing its CS\n", hasToken+1);
        for (int i=0; i<total; i++) {
            printf("Process %d R array: ", i+1);
            for (int j=0; j<total; j++) {
                printf("%d ",r[i][j]);
            }
            printf("\n");
        }
        printf("Token array: ");
        for (int i=0; i<total; i++) {
            printf("%d ", t[i]);
        }
        printf("\n\nContinue? 1-yes 0-no: ");
        scanf("%d", &cont);
    } while (cont == 1);
}