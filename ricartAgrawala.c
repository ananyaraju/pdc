#include <stdio.h>

struct process {
    int nreply;
    int pid;
    int tstamp;
}p[50];

int main() {
    int total, n;
    printf("Enter total number of processes: ");
    scanf("%d", &total);
    int i;
    for (i=0; i<total; i++) {
        p[i].tstamp = 0;
        p[i].nreply = 0;
    }
    printf("Enter number of competing processes: ");
    scanf("%d", &n);
    int tempid, tempstamp;
    for (i=0; i<n; i++) {
        printf("enter the process id: ");
        scanf("%d",&tempid);
        printf("enter the timestamp of that process: ");
        scanf("%d",&tempstamp);
        p[tempid].pid = tempid;
        p[tempid].tstamp = tempstamp;
    }
    for (i=0; i<total; i++) {
        if (p[i].tstamp !=0) {
            printf("(%d %d %d) ", p[i].pid, p[i].tstamp, p[i].nreply);
        }
    }
    int j;
    for (i=0; i<total; i++) {
        if (p[i].tstamp == 0) {
            printf("Process %d isnt competing, sends replies\n", i);
            for (j=0; j<total; j++) {
                if (p[j].tstamp != 0) {
                    p[j].nreply++;
                }
            }
        }
        else {
            for (j=0; j<total; j++) {
                if (p[j].tstamp!=0 && p[i].tstamp>p[j].tstamp) {
                    printf("Process %d sends reply to process %d", i, j);
                    p[j].nreply++;
                }
            }
        }
    }
    for (i=0; i<total; i++) {
        if (p[i].tstamp != 0) {
            printf("(%d %d %d) ", p[i].pid, p[i].tstamp, p[i].nreply);
        }
    }
    int count = 0;
    int k;
    do {
        for (i=0; i<total; i++) {
            if (p[i].nreply == total-1) {
                printf("Process %d enters CS and exits\n", i);
                p[i].tstamp = 0; p[i].nreply = 0;
                count++;
                for (k=0; k<total; k++) {
                    if (p[k].tstamp != 0) {
                        p[k].nreply++;
                    }
                }
                for (i=0; i<total; i++) {
                    if (p[i].tstamp != 0) {
                        printf("(%d %d %d) ", p[i].pid, p[i].tstamp, p[i].nreply);
                    }
                }
            }
        }
    } while (count<n);
}