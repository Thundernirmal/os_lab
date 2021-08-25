#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "fun.h"
#include <time.h>
#include <bits/stdc++.h>
#include <unistd.h>
pthread_t* thread_id;
sigset_t signalset;
int stat[100],i;
queue<int> Q;
int N;
int thread_running;
int thread_array[100];
int sig_lock[100];
int bit;
pthread_mutex_t myMutex;
vector<int> buff;
int SIZE = INT_MAX;
int N_set = 0;
using namespace std;
void debug(string s){
    cout << s << endl;
}
void sig_h(int p){
    if(p == SIGUSR1)
    system("pause");
}
void* RR(void* x){
    for(int t=0;t<N;t++){
        pthread_mutex_lock(&myMutex);
        sig_lock[t] = 1;
        cout << "Context Switch and buff size is "<< buff.size() << endl ;
        sleep(1); // time - q
        sig_lock[t] = 0;
        pthread_mutex_unlock(&myMutex);
    }
}
void* print(void* x)
{
    cout << Q.size() << endl;
    debug("IN PRINT");
	while(!Q.empty())
	{
        debug("IN PRINT XXX");
		if(stat[thread_running]==1)
			cout<<thread_running<<" = "<<"Terminated"<<endl;
		else 
			cout<<thread_running<<" = switched"<<endl;
		pthread_kill(thread_id[N],SIGUSR2);
		pause();
		if(Q.size()==0)
			cout<<thread_running<<" = "<<"Terminated "<<endl;	
	}
	cout<<"every thread executed"<<endl;
	pthread_kill(thread_id[N],SIGUSR2);
	pthread_exit(NULL);	
}


void* worker(void* ptr ){
    sigset_t set;
	int * thread_number = (int *)ptr;
    int w = *thread_number;
    //cout << w << endl;
	signal(SIGUSR1,sig_h);
	signal(SIGUSR2,sig_h);
    //cout << sig_lock[w] << endl;
    while (sig_lock[w] == 0)
    {
        //cout << sig_lock[w] << endl;
        sleep(0.1);
    }
    if( bit == 0){
        //debug("P");
        while (buff.size() == SIZE)
        {
            sleep(0.1);
        }
        pthread_mutex_lock(&myMutex);
        for(int x=0;x<1000;x++)
        buff.push_back(rand());
        pthread_mutex_unlock(&myMutex);
        N_set = N_set + 1000;
        bit = 1;
    }else{
        //debug("C");
        while (buff.empty())
        {
            sleep(0.1);
        }
            pthread_mutex_lock(&myMutex);
            buff.pop_back();
            pthread_mutex_unlock(&myMutex);
        bit = 0;
    }
    //cout << buff.size() << endl;
    return NULL;
}
int main(int argc, char const *argv[])
{
    if( argc != 2){
        cout << "use as: ./driver 5" << endl;
    }else{
        memset(stat, 0, sizeof(stat));
        memset(sig_lock, 0, sizeof(sig_lock));
        N = stoi(argv[1]);
        bit = 0;
        sigset_t s;
		sigfillset(&s);
		sigdelset(&s,SIGINT);
		sigemptyset(&signalset);
		sigaddset(&signalset, SIGUSR2);
        pthread_mutex_init(&myMutex,0);
        thread_id=(pthread_t*)calloc(N+2,sizeof(pthread_t));
        for(int l=0;l<N;l++)
			thread_array[l]=l;
        for(int j=0;j<N;j++){
            pthread_create(&thread_id[j], NULL, &worker, (void *)&thread_array[j]);
            sleep(0.2);
            Q.push(j);
        }
        //cout << Q.size() << endl;
        //sleep(0.1);
        //cout << Q.size() << endl;
        pthread_create(&thread_id[N], NULL, &RR, (void *)N);
        for(int l=0;l<N;l++)
            pthread_join(thread_id[l],NULL);

        pthread_mutex_destroy(&myMutex);
    }
    return 0;
}