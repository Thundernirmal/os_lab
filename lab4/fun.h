#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
extern pthread_t* thread_id;
extern sigset_t signalset;
extern int stat[100],i;
extern queue<int> Q;
extern int N;
extern int thread_running;
extern int thread_array[100];
extern int bit;

void debug(string s);
void* worker(void* ptr );
void* RR(void* x);
void sig_h(int p);
void* print(void* x);
