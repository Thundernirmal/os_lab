#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<stdlib.h>
#include "fun.h"
void debug_R(int i){
    fprintf(stderr,"DEBUG R %d\n",i);
}
void swap( Process *A,Process *B){
    Process process_s = *A;
    *A = *B;
    *B = process_s;
}
int MAX(int a,int b ){
    return a > b ? a : b;
}
void debug3(int i){
     fprintf(stderr,"DEBUG RR %d\n",i);
}
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(
        queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}
 
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

void RR (Process p[],int n){
    
    int quantum = 2;
    //debug3(1);
    //debug_R(1);
    int process_done = 0;
    int prev = 0;
    int c_time = 0;
    int br[n];
    int index;
    int total;
    int j,k,i,y;
    int process_s[n];
    memset(process_s,0,sizeof(process_s));
    p[0].rt=0;
    for(i=1;i<n;i++){
        p[i].rt = p[i - 1].rt + quantum;
    }
    for(i=0;i<n;i++){
        process_s[i] = p[i].cpub;
    }
    y=n;
    //debug_R(2);
    for(total=0, i = 0; y!=0; ) {  
        if(process_s[i] <= quantum && process_s[i] > 0){  
            total = total + process_s[i];  
            process_s[i] = 0;  
            process_done=1;  
        }     
        else if(process_s[i] > 0)  
        {  
            process_s[i] = process_s[i] - quantum;  
            total = total + quantum;    
        }  
        if(process_s[i]==0 && process_done==1)  
        {  
            y--;
            p[i].wt = total-p[i].atime-p[i].cpub;
            p[i].tat = total-p[i].atime;
            process_done =0;     
        }  
        if(i==n-1)  
        {  
            i=0;  
        }  
        else if(p[i+1].atime<=total)  
        {  
            i++;  
        }  
        else  
        {  
            i=0;  
        }
        //debug_R(y);  
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

    printf("Round Robin,%f,%f,%f\n", avgwt,avgtat,avgrt);
}