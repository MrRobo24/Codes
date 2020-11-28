#include<stdio.h>
 
int main() {
      int i, limit, total = 0, x, counter = 0, time_quantum;      
      float average_wait_time, average_turnaround_time;
      
      printf("Enter Total Number of Processes:");
      scanf("%d", &limit);

      int wait_time = 0, turnaround_time = 0, arrival_time[limit], burst_time[limit], temp[limit];
      x = limit;
      printf("Enter arrival time and burst time one by one:\n"); 
      for (i = 0; i < limit; i++) {
            scanf("%d", &arrival_time[i]);
            scanf("%d", &burst_time[i]); 
            temp[i] = burst_time[i];
      }
 
      printf("Enter Time Quantum:");
      scanf("%d", &time_quantum);
      printf("Process ID\t\tBurst Time\t Turnaround Time\t Waiting Timen");

      for(total = 0, i = 0; x != 0;) {
            if(temp[i] <= time_quantum && temp[i] > 0) {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            } else if(temp[i] > 0) {
                  temp[i] = temp[i] - time_quantum;
                  total = total + time_quantum;
            }
            if(temp[i] == 0 && counter == 1) {
                  x--;
                  printf("\n\n%d\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i];
                  turnaround_time = turnaround_time + total - arrival_time[i];
                  counter = 0;
            }

            if(i == limit - 1) {
                  i = 0;
            } else if(arrival_time[i + 1] <= total) {
                  i++;
            } else {
                  i = 0;
            }
      }
 
      average_wait_time =  (float) wait_time / limit;
      average_turnaround_time = (float) turnaround_time / limit;

      printf("\n\n Average Waiting Time:\t%f", average_wait_time);
      printf("\n\n Avg Turnaround Time:\t%f", average_turnaround_time);
      return 0;
}