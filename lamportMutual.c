#include<stdio.h>

struct process {
    struct message {
      int tstamp;
      int pid;
    }m[20];
    int nreply;
}p[50];

int main() {
  int total,n,i,j,k,tempid,temptstamp;
  int a,b;
  printf("enter the total no of processes\n");
  scanf("%d",&total);
  printf("enter the no of processes competing to enter CS: ");
  scanf("%d",&n);
  j=0;
  for(i=0;i<n;i++) {
    printf("enter the process id: ");
    scanf("%d",&tempid);
    printf("enter the timestamp of that process: ");
    scanf("%d",&temptstamp);
    for(k=0;k<total;k++) {
      p[k].m[j].pid=tempid;
      p[k].m[j].tstamp=temptstamp;
      p[k].nreply=total;
    }
    j++;
  }
  for(k=0;k<total;k++) {
    for(i=0;i<n-1;i++) {
        for(j=i+1;j<n;j++) {
            if(p[k].m[i].tstamp>p[k].m[j].tstamp) {
	            tempid=p[k].m[i].pid;
	            temptstamp=p[k].m[i].tstamp;
	            p[k].m[i].pid=p[k].m[j].pid;
	            p[k].m[i].tstamp=p[k].m[j].tstamp;
	            p[k].m[j].pid=tempid;
	            p[k].m[j].tstamp=temptstamp;
            }
        }
    }
  }
  for(i=0;i<total;i++) {
    printf("process %d with %d REPLY messages  ",i,p[i].nreply);
    for(j=0;j<n;j++) {
      printf("(%d,%d)<--",p[i].m[j].pid,p[i].m[j].tstamp);
    }
    printf("\n");
  }
  while(n>0) {
    for(i=0;i<total;i++) {
        if(p[i].m[0].pid==i) {
            printf("Since process %d is at the top of the request queue ,it enters the critical section\n",i);
            printf("\nUpon exiting the critical section ");
            printf("process %d sends a RELEASE message to all the other processes\n",i);
            for(a=0;a<total;a++) {
                for(j=0;j<n-1;j++) {
	                p[a].m[j].pid=p[a].m[j+1].pid;
	                p[a].m[j].tstamp=p[a].m[j+1].tstamp;
                }
            }
            n--;
            if(n>0) {
                printf("Now the request queue status in each process is\n");
                for(a=0;a<total;a++) {
	                printf("process %d with %d REPLY messages",a,p[a].nreply);
	                for(b=0;b<n;b++) {
	                    printf("(%d,%d)<--",p[a].m[b].pid,p[a].m[b].tstamp);
	                }
	                printf("\n");
                }
            }
            else
                printf("Now the request queue is empty\n");

        }
    }
  }
  scanf("%d", &tempid);
}