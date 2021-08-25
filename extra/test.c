#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <unistd.h>
#include <fcntl.h>

#define MSGSIZE sizeof(int)

int main()
{
    int a,b;
    int p[2], pid,pid1, nbytes,p1[2];
  
    if (pipe(p) < 0)
        exit(1);
  
    /* continued */
    if ((pid = fork()) > 0) 
    {
        int color=1;
        write(p[1], &color, MSGSIZE);
        //write(p[1], &color, MSGSIZE);
        close(p[1]);
        wait(NULL);
        exit(0);
    }
  
    else {
        close(p[1]);
        while (nbytes=(read(p[0], &a, MSGSIZE))>0)
            printf("A= %d\n", a);
        //close(p[1]);
        close(p[0]);
        printf("Finished, reading\n");
    }

    if(pipe(p1)<0)
        exit(1);

    if ((pid1 = fork()) > 0) 
    {
        int color=4;
        write(p1[1], &color, MSGSIZE);
        close(p1[1]);
        wait(NULL);
        exit(0);
    }
  
    else {
        close(p1[1]);
        while (nbytes=(read(p1[0], &a, MSGSIZE))>0)
            printf("B= %d\n", a);
        close(p1[1]);
        close(p1[0]);
        printf("Finished reading\n");
    }


}