#include<stdio.h>
struct Process;

typedef struct 
{
    int id;
    int atime;
    int cpub;
    int pri;
    int st;
    int rt;
    int tat;
    int ct;
    int wt;
}Process;

void FCFS (Process P[],int n);
void SJF (Process P[],int n);
void SJF_P (Process P[],int n);
void RR (Process P[],int n);
void PB (Process P[],int n);
int min(int arr[],int n);
int max(int arr[],int n);
float avg(int arr[],int n);
int min_tat(Process P[],int n);
int max_tat(Process P[],int n);
float avg_tat(Process P[],int n);
int min_wt(Process P[],int n);
int max_wt(Process P[],int n);
float avg_wt(Process P[],int n);
int min_rt(Process P[],int n);
int max_rt(Process P[],int n);
float avg_rt(Process P[],int n);