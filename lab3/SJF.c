#include<stdio.h>
#include<limits.h>
#include <string.h>
#include "fun.h"
void debug1(int i){
    fprintf(stderr,"DEBUG %d\n",i);
}

void SJF (Process p[],int n){
    int process_done = 0;
    int prev = 0;
    int c_time = 0;
    //swap(&P[1],&P[3]);
    //debug1(P[1].id);
    //debug1(P[3].id);
    /*
    int wt[n];
    int tat[n];
    int rt[n];
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(P[i].atime > P[j].atime)
            {
                swap(&P[i],&P[j]);
                debug1(i);
                debug1(j);
            }
        }
    }
    */
   //debug1(10000);
   int process_s[n];
   memset(process_s,0,sizeof(process_s));
    
   while ( process_done != n){
       int index = -1;
       int minmum = INT_MAX;
       for(int i = 0; i < n; i++) {
            if(p[i].atime <= c_time && process_s[i] == 0) {
                if(p[i].cpub < minmum) {
                    minmum = p[i].cpub;
                    index = i;
                   // debug1(50000);
                }
                if(p[i].cpub == minmum) {
                    if(p[i].atime < p[index].atime) {
                        minmum = p[i].cpub;
                        index = i;
                        //debug1(50000);
                    }
                }
            }
        }
        //debug1(50000);
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
            //debug1(process_done);
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

    printf("Non-preemptive Shortest Job First,%f,%f,%f\n", avgwt,avgtat,avgrt);
}