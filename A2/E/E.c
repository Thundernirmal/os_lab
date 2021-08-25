#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h> 
#include<unistd.h>
#include<sys/wait.h>
#include <time.h>
#include<math.h>
#define LINE printf("----------------------------------------------------------------\n");
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
int main(int argc, char const *argv[])
{
    printf("It takes some time to generate random number\n");
    LINE
    unsigned int randval;
    FILE *f;

    f = fopen("/dev/random", "r");
    fread(&randval, sizeof(randval), 1, f);
    fclose(f);
 
    
    time_t x =1;
    char *color[7];
    color[0]="Violet";
    color[1]="Indigo";
    color[2]="Blue";
    color[3]="Green";
    color[4]="Yellow";
    color[5]="Orange";
    color[6]="Red";
    int p1[2],p2[2], pid1,pid2,nbytes;
    int a,b,A,B;
    int q=10;
    int D1 =0 ,D2 = 0;
    unsigned int z,y,w;
    srand(1512654831);
    z=564 + rand();
    y=799;
    srand(624654831);
    w=randval;
    int p;
    
    for(int i=0;1;i++){
        printf("Round %d\n",i + 1);
        srand(w);
        p=rand()%7;
        w=w+152;
        printf("P chooses %s\n",color[p]);
    if (pipe(p1) < 0)
        exit(1);
    
    if ((pid1 = fork()) > 0) {
        //sleep(0.1);
        srand(z);
        A = rand()%7;
        //delay(50);
        write(p1[1], &A, sizeof(int));
        close(p1[1]);
        wait(NULL);
        //sleep(0.1);
        exit(0);
    }
    else {
        close(p1[1]);
        wait(&pid1);
        z=z+121;
        //kill(pid1, SIGKILL);
        while ((nbytes = read(p1[0], &a, sizeof(int))) > 0)
            printf("C1 chooses %s\n", color[a]);
        if (nbytes != 0)
            exit(2);
        //printf("Finished reading from 1\n");
    }
    //debug(1);
    
    if (pipe(p2) < 0)
        exit(1);
  
    if ((pid2 = fork()) > 0) {
        //sleep(0.1);
        srand(y+154);
        B=rand()%7;
        //delay(50);
        write(p2[1], &B, sizeof(int));
        close(p2[1]);
        wait(NULL);
        
        exit(0);
    }
    else {
        close(p2[1]);
        wait(&pid2);
        y=y+146;
        //kill(pid2, SIGKILL);
        while ((nbytes = read(p2[0], &b, sizeof(int))) > 0)
            printf("C2 chooses %s\n", color[b]);
        if (nbytes != 0)
            exit(2);
        //printf("Finished reading from 2\n");
    }
    LINE
    //p=4;
    //a=4;
    //b=4;
    if(p == a){
        if(p == b){
            printf("This round is ignored\n");
            LINE
            continue;
        }
        printf("C1 wins\n");
        return 0;
    }else if(p == b){
        printf("C2 wins\n");
        return 0;
    }else{
        D1 = D1 + abs(p-a);
        D2 = D2 + abs(p-b);
        printf("C1 accumulates coin is %d & C2 accumulates coin is %d \n",D1,D2);
        LINE
        if(D1>50){
            if(D2>50){
                printf("C1 & C2 both wins\n");
                return 0;
            }else{
                printf("C1 wins\n");
                return 0;
            }
        }else if(D2 > 50)
        {
            printf("C2 wins\n");
            return 0;
        }
        
    }
    }
    return 0;
}