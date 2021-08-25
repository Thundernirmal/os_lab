#include<stdio.h>
#include "fun.h"

void FCFS (Process P[],int n){
    int wt[n];
    int tat[n];
    int rt[n];

    rt[0]=P[0].atime;
    wt[0]=0;
    //debug1(rt[0]);
    for(int i=1;i<n;i++){
        rt[i] = rt[i-1] + P[i-1].cpub;
        //debug1(rt[i-1]);
        //debug1(P[i].cpub);
        //debug1(rt[i]);
        wt[i] = rt[i] - P[i].atime;
        if (wt[i] < 0)
            wt[i] = 0;
    }
    for (int i = 0; i < n ; i++)
        tat[i] = P[i].cpub + wt[i];
    
    int minwt = min(wt,n);
    int mintat = min(tat,n);
    int minrt = min(rt,n);

    int maxwt = max(wt,n);
    int maxtat = max(tat,n);
    int maxrt = max(rt,n);

    float avgwt = avg(wt,n);
    float avgtat = avg(tat,n);
    float avgrt = avg(rt,n);

    printf("First Come First Serve,%f,%f,%f\n", avgwt,avgtat,avgrt);
}