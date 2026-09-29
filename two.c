#include <stdio.h>
#include <stdlib.h>
int main() {
int disk_size, n, head, i, j, total = 0;
printf("Enter total number of disk blocks: ");
if(scanf("%d", &disk_size) != 1) return 0;
printf("Enter number of requests: ");
if(scanf("%d", &n) != 1) return 0;
int req[100];
printf("Enter requests: ");
for(i = 0; i < n; i++) scanf("%d", &req[i]);
printf("Enter starting head position: ");
scanf("%d", &head);
for(i = 0; i < n - 1; i++) {
for(j = 0; j < n - i - 1; j++) {
if(req[j] > req[j + 1]) {
int t = req[j];
req[j] = req[j + 1];
req[j + 1] = t;
}
}
}
int left[100], right[100], l_cnt = 0, r_cnt = 0;
for(i = 0; i < n; i++) {
if(req[i] <= head) left[l_cnt++] = req[i];
else right[r_cnt++] = req[i];
}
printf("\nLOOK Order of Service (Direction: Left):\n%d", head);
int cur = head;
for(i = l_cnt - 1; i >= 0; i--) {
total += abs(cur - left[i]);
cur = left[i];
printf(" -> %d", cur);
}
for(i = 0; i < r_cnt; i++) {
total += abs(cur - right[i]);
cur = right[i];
printf(" -> %d", cur);
}
printf("\nTotal number of head movements: %d\n", total);
return 0;
}
