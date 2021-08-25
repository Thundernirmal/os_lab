#include <stdio.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int MAX[1024];
void debug(int i){
    fprintf(stderr,"DEBUG %d\n",i);
}
void delay(int number_of_seconds)
{

    int milli_seconds = 1000 * number_of_seconds;
  
    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds)
        ;
}
int c=0;
int z=0;
void set(int i){
    MAX[z]=i;
    z++;
    //debug(MAX[z]);
    //debug(i);
}
int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    if(n<0){
        printf("Invaild input\n");
    }
    pid_t id;
    //debug(n);
    id = fork();
    int N[n];
    c=n;
    if( id < 0){
        fprintf(stderr,"child not created");
    } else if ( id == 0){
        int result = 0,a=0,b=1;
        for(int i=0;i<n;i++){
            result = a + b;
            a = b;
            b = result;
            N[i] = result;
            //debug(N[i]);
            set(result);
        }
        for(int i=0;i<n;i++){
            printf("%d ",N[i]);
        }
        //delay(2000);
    }else{
        wait(NULL);
        
        //debug(5555);
        
    }
    return 0;
}