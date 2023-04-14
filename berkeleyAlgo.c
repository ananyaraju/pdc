#include <stdio.h>

int main() {
    int n;
    int shr, smin;
    printf("Enter server clock time: ");
    scanf("%d %d", &shr, &smin);
    int serverTime = shr*60 + smin;
    printf("Enter number of client clocks: ");
    scanf("%d", &n);
    int times[10];
    int hr, min;
    for (int i=0; i<n; i++) {
        printf("Enter time of client %d: ", i+1);
        scanf ("%d %d", &hr, &min);
        times[i] = hr*60+min;
    }
    int sum = serverTime;
    int count = 1;
    for (int i=0; i<n; i++) {
        if (serverTime-times[i]>=60 || serverTime-times[i]<=-60)
            continue;
        else {
            sum += times[i];
            count++;
        }
    }
    int avg = sum/count;
    int average = avg;
    int avgHr = 0, avgMin = 0;
    while (avg >= 60) {
        avgHr++;
        avg -= 60;
        avgMin = avg;
    }
    printf("\nAverage time: %d %d ", avgHr, avgMin);
    printf("\n\nUpdates in minutes: \n");
    printf("Server: %d mins\n", average-serverTime);
    for (int i=0; i<n; i++) {
        printf("Clock %d: %d mins\n", i, average-times[i]);
    }
}