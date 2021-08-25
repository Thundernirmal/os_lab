#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "fun.h"

int min(int arr[],int n){
    int minE = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] < minE) {
            minE = arr[i];
        }
    }
    return minE;
}

int min_tat(Process P[],int n){
    int arr[n];
    for(int i=0;i<n;i++)
    arr[i]=P[i].tat;
    return min(arr,n);
}

int min_rt(Process P[],int n){
    int arr[n];
    for(int i=0;i<n;i++)
    arr[i]=P[i].rt;
    return min(arr,n);
}

int min_wt(Process P[],int n){
    int arr[n];
    for(int i=0;i<n;i++)
    arr[i]=P[i].wt;
    return min(arr,n);
}