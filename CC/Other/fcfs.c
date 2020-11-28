#include <stdio.h>
#define LLI long long
int main() {

    LLI n,i;
    printf("Enter the number of processes: ");
    scanf("%lld", &n);

    LLI burst[n], wait[n], turnaround[n];
    float avgwait = 0;
    printf("Enter the burst time for all processes one by one:\n");
    for (i=0;i<n;i++) {
        scanf("%lld", &burst[i]);
    }

    wait[0] = 0;
    for (i=1;i<n;i++) {
        wait[i] = wait[i-1] + burst[i-1];
        avgwait += wait[i];
    }

    for (i=0;i<n;i++) {
        turnaround[i] = wait[i] + burst[i];
    }

    avgwait = avgwait / n;

    printf("Process ID --- Burst Time ---  Wait Time --- Turn Around Time\n");
    for (i=0;i<n;i++) {
        printf("%lld --- %lld --- %lld --- %lld\n", i, burst[i], wait[i], turnaround[i]);
    }

    printf("Average waiting time = %.2f\n", avgwait);

    return 0;
}