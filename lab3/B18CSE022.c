#include<stdio.h>
#include<stdlib.h>
#include "fun.h"
void debug(int i){
    fprintf(stderr,"DEBUG %d\n",i);
}
int main(int argc, char const *argv[])
{
    if(argc !=2){
        printf("Input number by argument like ./driver 4(process file name)\n");
    }else{
        int n = atoi(argv[1]);
        Process ptable[n];
        FILE *fp;
        //debug(n);
        fp = fopen(argv[1],"r");
        for(int i=0;i<n;i++){
            fscanf(fp,"%d,%d,%d,%d",&ptable[i].id,&ptable[i].atime,&ptable[i].cpub,&ptable[i].pri);
        }
        //for(int i=0;i<n;i++){
        //    printf("%d,%d,%d,%d\n",ptable[i].id,ptable[i].atime,ptable[i].cpub,ptable[i].pri);
        //}
        FCFS(ptable,n);
        SJF(ptable,n);
        SJF_P(ptable,n);
        RR(ptable,n);
        PB(ptable,n);
    }
    return 0;
}