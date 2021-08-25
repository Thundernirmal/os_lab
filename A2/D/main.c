#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h> 
#include<unistd.h>
#include<sys/wait.h>

void debug(int i){
    fprintf(stderr,"DEBUG %d\n",i);
}

int main(int argc, char const *argv[])
{
    //printf("%d",argc);
    if(argc != 3){
        fprintf(stderr,"Argument is missing\n");
        exit(1);
    }
    //debug(1);
    int fd[2];
    fd[0] = open(argv[1], O_RDONLY);
    if(fd[0] == -1){
        printf("The file does not exist or you do not have read permission.\n");
    }
    //debug(2);
    fd[1] = creat(argv[2], 0644);
    if(fd[1] == -1){
        printf("The file could not be created.\n");
    }
    //debug(3);
    //close(0);
    //dup(fd[0]);
    //close(fd[0]);
    dup2(fd[0],0);
    
    //debug(4);
    dup2(fd[1],1);
    //close(0);
    //dup(fd[0]);
    //close(fd[0]);
    //debug(5);
    pid_t pid_in,pid_out;
    int p[2];
    if (pipe(p) < 0) 
        exit(1);
    //debug(6);
    /*
    if ((pid_in = fork()) != 0){
        if ((pid_out = fork()) != 0){
            //close(fd[1]);
            close(p[1]);
            debug(7);
            wait(&pid_out);
            wait(&pid_in);
        }else{
            //wait(&pid_in);
            close(1);
            dup(p[1]);
            close(p[1]);
            debug(8);
            //close(0);
            //dup(fd[0]);
            //close(fd[0]);
            execl("convert", "convert", (char *) 0);
        }
    }else{
        debug(9);
        //close(0);
        //dup(fd[0]);
        //close(fd[0]);
        //close(0);
        //dup(fd[0]);
        //close(fd[0]);
        execl("count", "count", (char *) 0);
        //execl("convert", "convert", (char *) 0);
        debug(10);
    }
    */

   /*

    if((pid_in = fork()) < 0){
        fprintf(stderr,"Not forked\n");
    }
    //if((pid_out = fork()) < 0){
        //fprintf(stderr,"Not forked\n");
    //}
    if(pid_in == 0){
        debug(9);
        close(0);
        dup(fd[0]);
        close(fd[0]);
        close(1);
        dup(p[1]);
        close(p[1]);
        execl("count", "count", (char *) 0);
        debug(10);
        //wait(&pid_in);
        //close(0);
    }else 
    {
        pid_out = fork();
        if(pid_out < 0){
            fprintf(stderr,"Not forked\n");
        }
        if(pid_out == 0){
            close(0);
            dup(p[0]);
            close(p[0]);
            debug(8);
            close(1);
            dup(fd[1]);
            close(fd[1]);
            execl("convert", "convert", (char *) 0);
            close(0);
        }else{
            debug(7);
            wait(&pid_in);
            wait(&pid_out);
            debug(11);
        }        
    }

    */

    pid_in = fork();
    //if((pid_in = fork()) < 0){
    //    fprintf(stderr,"Not forked child 1\n");
    //}
    if(pid_in != (pid_t)0)
    {
        pid_out = fork();
        //if((pid_out = fork()) < 0){
        //fprintf(stderr,"Not forked child 2\n");
        //}
        if(pid_out == 0)
        {
            close(p[1]);
            dup2(p[0],0);
            execl("convert","convert",(char *)0);
            close(p[0]);
            //exit(0);
        }
        else
        {
            close(p[0]);
            close(p[1]);
            wait(NULL);
            wait(NULL);
        }
    }
    else
    {
        close(p[0]);
        dup2(p[1],1);
        execl("count","count",(char *)0);   
        close(p[1]);
        //exit(0);
    }
    return 0;
}