#include <bits/stdc++.h>
#include <unistd.h>  
#include <sys/time.h>  
#include <stdlib.h>  
#include <fcntl.h>  
#include <signal.h>  
#include <sys/types.h>  
#include <thread>
using namespace std;


void * thread_print(void* N){
    int*  data = reinterpret_cast<int*>(N);
    int   x    = *data;
    cout << "I am thread " << x << endl;
    
    sleep(1);
}
int main(){
    pthread_t p[5];
    for(int i=0;i<5;i++)
    pthread_create(&p[i],NULL, thread_print,new int(i));
    for(int i=0;i<5;i++)
    pthread_join(p[i],NULL);
    cout << "All threads finished" << endl;
    return 0; 
}