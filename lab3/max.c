#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "fun.h"

int max(int arr[],int n){
    int maxE = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxE) {
            maxE = arr[i];
        }
    }
    return maxE;
}

int max_tat(Process P[],int n){
    int arr[n];
    for(int i=0;i<n;i++)
    arr[i]=P[i].tat;
    return max(arr,n);
}

int max_rt(Process P[],int n){
    int arr[n];
    for(int i=0;i<n;i++)
    arr[i]=P[i].rt;
    return max(arr,n);
}

int max_wt(Process P[],int n){
    int arr[n];
    for(int i=0;i<n;i++)
    arr[i]=P[i].wt;
    return max(arr,n);
}