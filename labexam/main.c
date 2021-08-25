#include <stdio.h>
#include <unistd.h>  
#include <sys/time.h>  
#include <stdlib.h>  
#include <fcntl.h>  
#include <signal.h>  
#include <sys/types.h>  
#include<threads.h>
void sig_handler(int signum){
  printf("Wait! I am confused\n");
}

int main(){
  pid_t pid;
  signal(SIGUSR1,sig_handler); 
  printf("I like Red\n");
  pid=getpid();     
  kill(pid,SIGUSR1);  
  printf("No, I like Blue\n");     
  return 0;
}