#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "fun.h"

float avg(int arr[],int n){
    int t=0;
    for(int i=0;i<n;i++){
        t=t+arr[i];
    }
    return (float)t / (float)n;
}

float avg_tat(Process P[],int n){
    int arr[n];
    for(int i=0;i<n;i++)
    arr[i]=P[i].tat;
    return avg(arr,n);
}

float avg_wt(Process P[],int n){
    int arr[n];
    for(int i=0;i<n;i++)
    arr[i]=P[i].wt;
    return avg(arr,n);
}

float avg_rt(Process P[],int n){
    int arr[n];
    for(int i=0;i<n;i++)
    arr[i]=P[i].rt;
    return avg(arr,n);
}