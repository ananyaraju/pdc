#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int seconds) {
       int ms = 1000*seconds;    
       clock_t start_time = clock();
       while (clock() < start_time+ms);
}

int main() {
    //client sends request
    time_t rawtime0 = time(NULL);
    struct tm *ptm0 = localtime(&rawtime0);
    printf("Current time: %02d:%02d:%02d\n", ptm0->tm_hour, ptm0->tm_min, ptm0->tm_sec);
    printf("Sending request to get server clock time..\n");
    delay(10); //delay when sending message
    //get server clock time
    time_t serverraw = time(NULL);
    struct tm *ptms = localtime(&serverraw);
    printf("Server time: %02d:%02d:%02d\n", ptms->tm_hour,
           ptms->tm_min, ptms->tm_sec);
    delay(10); //delay when recieving message
    time_t rawtime1 = time(NULL);
    struct tm *ptm1 = localtime(&rawtime1);
    printf("Current time: %02d:%02d:%02d\n", ptm1->tm_hour, ptm1->tm_min, ptm1->tm_sec);
    int t0 = ptm0->tm_hour*3600 + ptm0->tm_min*60 + ptm0->tm_sec;
    int t1 = ptm1->tm_hour*3600 + ptm1->tm_min*60 + ptm1->tm_sec;
    int rtt = (t1-t0)/2; //round trip time
    int ts = ptms->tm_hour*3600 + ptms->tm_min*60 + ptms->tm_sec;
    //calculating client clock time to be set
    int tclient = ts+rtt;
    int hr, min, sec;
    while (tclient>3600) {
       hr++;
       tclient-=3600;
    }
    while (tclient>60) {
       min++;
       tclient-=60;
    }
    sec = tclient;
    printf("Client clock time is set to: %02d:%02d:%02d\n", hr, min, sec);
}