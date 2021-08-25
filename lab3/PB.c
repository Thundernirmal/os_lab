#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<stdlib.h>
#include "fun.h"

void PB (Process p[],int n){
    int process_done = 0;
    int prev = 0;
    int c_time = 0;
    int process_s[n];
    memset(process_s,0,sizeof(process_s));
    int br[n];
    int index;
    while(process_done != n) {
        int index = -1;
        int mx = -1;
        for(int i = 0; i < n; i++) {
            if(p[i].atime <= c_time && process_s[i] == 0) {
                if(p[i].pri > mx) {
                    mx = p[i].pri;
                    index = i;
                }
                if(p[i].pri == mx) {
                    if(p[i].atime < p[index].atime) {
                        mx = p[i].pri;
                        index = i;
                    }
                }
            }
        }
        if(index != -1) {
            p[index].st = c_time;
            p[index].ct = p[index].st + p[index].cpub;
            p[index].tat = p[index].ct - p[index].atime;
            p[index].wt = p[index].tat - p[index].cpub;
            p[index].rt = p[index].st - p[index].atime;
            
            process_s[index] = 1;
            process_done++;
            c_time = p[index].ct;
            prev = c_time;
        }
        else {
            c_time++;
        }
        
    }
    int minwt = min_wt(p,n);
    int mintat = min_tat(p,n);
    int minrt = min_rt(p,n);

    int maxwt = max_wt(p,n);
    int maxtat = max_tat(p,n);
    int maxrt = max_rt(p,n);

    float avgwt = avg_wt(p,n);
    float avgtat = avg_tat(p,n);
    float avgrt = avg_rt(p,n);

    printf("Priority based scheduling,%f,%f,%f\n",avgwt,avgtat,avgrt);
}