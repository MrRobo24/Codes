// Compile with: gcc sjf_linux.c -lncurses -o lol
// if you doesn't have ncurses lib type in terminal: sudo apt-get install libncurses5-dev
// http://www.ssau.ru/files/education/metod_1/%D0%9A%D1%83%D0%BF%D1%80%D0%B8%D1%8F%D0%BD%D0%BE%D0%B2%20%D0%90.%D0%92.%20%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC%D1%8B%20%D0%BF%D0%BB%D0%B0%D0%BD%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F.pdf


#include<stdio.h>

int main()
{
	
	float wtavg, tatavg;
    int n;
	printf("\nEnter the number of processes: ");
	scanf("%d", &n);
    int process[n], burst[n], wait[n], turnaround[n], i, k, temp;
    printf("Enter the burst time for each process one by one:\n");
	for(i=0;i<n;i++)
	{
		process[i]=i;
		scanf("%d", &burst[i]);
	}
	for(i=0;i<n;i++)
		for(k=i+1;k<n;k++)
			if(burst[i]>burst[k])
			{
				temp=burst[i];
				burst[i]=burst[k];
				burst[k]=temp;
				temp=process[i];
				process[i]=process[k];
				process[k]=temp;
			}
	wait[0] = wtavg = 0;
	
    turnaround[0] = tatavg = burst[0];
	for(i=1;i<n;i++)
	{
		wait[i] = wait[i-1] +burst[i-1];
		turnaround[i] = turnaround[i-1] +burst[i];
		wtavg = wtavg + wait[i];
		tatavg = tatavg + turnaround[i];
	}

	printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
	for(i=0;i<n;i++) {
        printf("\n\t %d \t\t %d \t\t %d \t\t %d", process[i], burst[i], wait[i], turnaround[i]);
    }
	
	printf("\nAverage Waiting Time = %.2f", wtavg);
	printf("\nAverage Turnaround Time = %.2f", tatavg);
	getch();
}