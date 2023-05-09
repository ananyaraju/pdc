#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int seconds, struct tm *ptm) {
    if (seconds>=60) {
        while (seconds>=60) {
            ptm->tm_min++;
            seconds-=60;
            ptm->tm_sec += seconds;
        }
        if (ptm->tm_sec >=60 && seconds>0) {
            while (ptm->tm_sec>=60) {
                ptm->tm_sec-=60;
            }
        }
    }
    else {
        ptm->tm_sec += seconds;
        if (ptm->tm_sec >=60 && seconds>0) {
            while (ptm->tm_sec>=60) {
                ptm->tm_min++;
                ptm->tm_sec-=60;
            }
        }
    }
}

int main() {
    //client sends request
    time_t rawtime0 = time(NULL);
    struct tm *ptm0 = localtime(&rawtime0);
    printf("Request from client at (T0): %02d:%02d:%02d\n", ptm0->tm_hour, ptm0->tm_min, ptm0->tm_sec);
    int t0 = ptm0->tm_hour*3600+ptm0->tm_min*60+ptm0->tm_sec;
    printf("Sending request to get server clock time..\n");
    //get server clock time
    time_t serverraw = time(NULL);
    struct tm *ptms = localtime(&serverraw);
    int delay1 = 30; int delay2 = 10;
    delay(delay1, ptms); //delay when sending message
    printf("Server time (Ts): %02d:%02d:%02d\n", ptms->tm_hour,
           ptms->tm_min, ptms->tm_sec);
    time_t rawtime1 = time(NULL);
    struct tm *ptm1 = localtime(&rawtime1);
    delay(delay1+delay2, ptm1); //delay when recieving message
    printf("Current time (T1): %02d:%02d:%02d\n", ptm1->tm_hour, ptm1->tm_min, ptm1->tm_sec);
    int t1 = ptm1->tm_hour*3600 + ptm1->tm_min*60 + ptm1->tm_sec;
    int rtt = (t1-t0)/2; //round trip time
    int ts = ptms->tm_hour*3600 + ptms->tm_min*60 + ptms->tm_sec;
    //calculating client clock time to be set
    int tclient = ts+rtt;
    printf("%d CLIENT TIME \n", tclient);
    int hr = 0, min = 0, sec = 0;
    while (tclient>=3600) {
      hr++;
      tclient-=3600;
      printf("Client: %d\n", tclient);
    }
    while (tclient>=60) {
      min++;
      tclient-=60;
      printf("Client: %d\n", tclient);
    }
    sec = tclient;
    printf("Client clock time is set to: %02d:%02d:%02d\n", hr, min, sec);
}