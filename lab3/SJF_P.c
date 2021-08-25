#include<stdio.h>
#include<limits.h>
#include<string.h>
#include "fun.h"
void debug_P(int i){
    fprintf(stderr,"DEBUG P%d\n",i);
}
void SJF_P(Process p[],int n){
    int process_done = 0;
    int prev = 0;
    int c_time = 0;
    int process_s[n];
    int br[n];
    memset(process_s,0,sizeof(process_s));
    for(int i=0;i<n;i++){
        br[i]=p[i].cpub;
    }
    //debug_P(1);
   while ( process_done != n){
       int index = -1;
       int minmum = 10000000;
       for(int i = 0; i < n; i++) {
            if(p[i].atime <= c_time && process_s[i] == 0) {
                if(br[i] < minmum) {
                    minmum = br[i];
                    index = i;
                   // debug1(50000);
                }
                if(br[i] == minmum) {
                    if(p[i].atime < p[index].atime) {
                        minmum = br[i];
                        index = i;
                        //debug1(50000);
                    }
                }
            }
        }
        //debug_P(process_done);
        //debug1(50000);
        if(index != -1) {
             if(br[index] == p[index].cpub) {
                p[index].st = c_time;
            }
            br[index] -= 1;
            c_time++;
            prev = c_time;
            
            if(br[index] == 0) {
                p[index].ct = c_time;
                p[index].tat = p[index].ct - p[index].atime;
                p[index].wt = p[index].tat - p[index].cpub;
                p[index].rt = p[index].st - p[index].atime;

                process_s[index] = 1;
                process_done++;
            }
            //debug1(process_done);
        }
        else {
            c_time++;
        }
        
    }
    //debug_P(4);
    int minwt = min_wt(p,n);
    int mintat = min_tat(p,n);
    int minrt = min_rt(p,n);

    int maxwt = max_wt(p,n);
    int maxtat = max_tat(p,n);
    int maxrt = max_rt(p,n);

    float avgwt = avg_wt(p,n);
    float avgtat = avg_tat(p,n);
    float avgrt = avg_rt(p,n);

    printf("Preemptive Shortest Job First,%f,%f,%f\n", avgwt,avgtat,avgrt);
}