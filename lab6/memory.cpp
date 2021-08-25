#include <bits/stdc++.h>
#include "A-fun.h"
using namespace std;
#define clear() printf("\033[H\033[J") 
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_RESET   "\x1b[0m"
#define ANSI_BOLD "\x1b[1m"
#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

int main(int argc, char const *argv[])
{
    if(argc < 3){
        cout << "Use this like : ./memory 3 1 2 3 4 5 6 7 1 (here 1st arugument is number of frames and followed by Reference string each sperated by space)\n" ;
    }else{
        int n = argc - 2;
        int pages[n];
        for(int i = 0;i<n;i++){
            pages[i] = atoi(argv[i+2]);
        }
        int fr = atoi(argv[1]);
        printf(ANSI_COLOR_GREEN ANSI_BOLD);
        cout<< "FIFO page faults are " << FIFO(pages,n,fr) << " ,";
        cout<< "LRU page faults are " << LRU(pages,n,fr) << " and ";
        cout<< "Optimal Page Replacement page faults are " << OPR(pages,n,fr) <<".\n";
        printf(ANSI_RESET);
    } 
    return 0;
}