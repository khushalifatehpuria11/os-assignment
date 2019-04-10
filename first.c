/*
CPU schedules N processes which arrive at different time intervals and each process is allocated the CPU for a specific user 
input time unit, processes are scheduled using a preemptive round robin scheduling algorithm. Each process must be assigned a 
numerical priority, with a higher number indicating a higher relative priority. In addition to the processes one task has priority 0. 
The length of a time quantum is T units, where T is the custom time considered as time quantum for processing. If a process is 
preempted by a higher priority process, the preempted process is placed at the end of the queue. Design a scheduler so that the task 
with priority 0 does not starve for resources and gets the CPU at some time unit to execute. Also compute waiting time, turn around.
*/
#include<stdio.h> 
int main() { 
  int c,j,n;
  int time,rem;
  int flag=0,tq=10; 
  int w_t=0,t_a_t=0,a_t[10],b_t[10],rt[10]; 
  printf("\n\nEnter the Total number of Process:\t "); 
  scanf("%d",&n); 
  rem=n; 
  for(c=0;c<n;c++) { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",c+1); 
    scanf("%d",&a_t[c]); 
    scanf("%d",&b_t[c]); 
    rt[c]=b_t[c]; 
  } 
  printf("Enter Time Quantum:%d\t",tq); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,c=0;rem!=0;) { 
    if(rt[c]<=tq && rt[c]>0) {
      time+=rt[c]; 
      rt[c]=0; 
      flag=1; 
    } 
    else if(rt[c]>0) 
    { 
      rt[c]-=tq; 
      time+=tq; 
    } 
    if(rt[c]==0 && flag==1) 
    { 
      rem--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",c+1,time-a_t[c],time-a_t[c]-b_t[c]); 
      w_t+=time-a_t[c]-b_t[c]; 
      t_a_t+=time-a_t[c]; 
      flag=0; 
    } 
    if(c==n-1) 
      c=0; 
    else if(a_t[c+1]<=time) 
      c++; 
    else 
      c=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",w_t*1.0/n); 
  printf("Avg Turnaround Time = %f",t_a_t*1.0/n); 

  return 0; 
}
