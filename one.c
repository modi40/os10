#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct {
int id;
int at;
int bt1;
int bt2;
int total_bt;
int rem_bt;
int ct;
int tat;
int wt;
} Process;
int main() {
int n, tq, i;
srand(time(NULL));
printf("Enter number of processes: ");
if(scanf("%d", &n) != 1) return 0;
Process p[20];
for(i = 0; i < n; i++) {
p[i].id = i + 1;
printf("Process P%d - Arrival Time: ", i + 1);
scanf("%d", &p[i].at);
printf("Process P%d - First CPU Burst: ", i + 1);
scanf("%d", &p[i].bt1);
p[i].bt2 = (rand() % 10) + 1;
p[i].total_bt = p[i].bt1 + p[i].bt2;
p[i].rem_bt = p[i].total_bt;
printf("Process P%d - Next CPU Burst (random): %d (Total Burst: %d)\n", i + 1, p[i].bt2, p[i].total_bt);
}
printf("Enter Time Quantum: ");
scanf("%d", &tq);
int current_time = 0, completed = 0;
int gantt_p[200], gantt_t[200], g_cnt = 0;
gantt_t[0] = 0;
while(completed < n) {
int done_something = 0;
for(i = 0; i < n; i++) {
if(p[i].at <= current_time && p[i].rem_bt > 0) {
done_something = 1;
int exec_time = (p[i].rem_bt > tq) ? tq : p[i].rem_bt;
p[i].rem_bt -= exec_time;
current_time += exec_time;
gantt_p[g_cnt] = p[i].id;
gantt_t[g_cnt + 1] = current_time;
g_cnt++;
if(p[i].rem_bt == 0) {
p[i].ct = current_time;
p[i].tat = p[i].ct - p[i].at;
p[i].wt = p[i].tat - p[i].total_bt;
completed++;
}
}
}
if(!done_something) {
current_time++;
}
}
printf("\nGantt Chart:\n|");
for(i = 0; i < g_cnt; i++) printf(" P%d |", gantt_p[i]);
printf("\n%d", gantt_t[0]);
for(i = 0; i < g_cnt; i++) printf("    %d", gantt_t[i + 1]);
printf("\n\nProcess\tAT\tTotal BT\tCT\tTAT\tWT\n");
float total_tat = 0, total_wt = 0;
for(i = 0; i < n; i++) {
total_tat += p[i].tat;
total_wt += p[i].wt;
printf("P%d\t%d\t%d\t\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].total_bt, p[i].ct, p[i].tat, p[i].wt);
}
printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
printf("Average Waiting Time = %.2f\n", total_wt / n);
return 0;
}
