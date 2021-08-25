#include <bits/stdc++.h>
#include "B-fun.h"
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
    int n;
    int r;
    cout << "Enter number of processes:" ;
    cin >> n;
    cout << "Enter number of resource type:" ;
    cin >> r;
    cout << "Enter available resource:" << endl;
    int available[r];
    for(int i=0;i<r;i++){
        cout << "For resource "<< i+1 <<" : " ;
        cin >> available[i];
    }
    int max[100][10];
    int allocated[100][10];
    cout << "Enter Max resource for each process: " << endl;
    for(int i=0;i<n;i++){
        cout << "For " << i+1 << " Process: \n";
        for(int j=0;j<r;j++){
            cout << "For resource "<< j+1 <<" : " ;
            cin >> max[i][j];
        }
    }
    cout << "Enter Allocation resource for each process: " << endl;
    for(int i=0;i<n;i++){
        cout << "For " << i+1 << " Process: \n";
        for(int j=0;j<r;j++){
            cout << "For resource "<< j+1 <<" : " ;
            cin >> allocated[i][j];
        }
    }
    vector<int> safe_v;
    bool marked[n];
    memset(marked, false, sizeof(marked));
    int need[100][10];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            need[i][j] = max[i][j] - allocated[i][j];
    int result1=0;
    safe(marked, allocated, max, need, available, safe_v,r,n,result1);
    cout << endl;
    //cout << "Result is " << result1 << " \n";
    cout << "Process request id: " ;
    int N;
    cin >> N;
    int temp;
    cout << "Enter number of instances required for each resource type: \n";
    int need1[100][10];
    for(int i=0;i<r;i++){
        cout << "For resource "<< i+1 <<" : " ;
        //cin >> temp;
        //need[N-1][r] = temp;
        cin >> need1[N-1][r];
        //cout << need1[N-1][r];
    }
    for (int i = 0; i < n; i++){
        if(i!=N-1){
        for (int j = 0; j < r; j++)
            need1[i][j] = max[i][j] - allocated[i][j];
        }
    }
    //cout << "New reqest for " << N << "is " << need1[N-1][0] <<","<< need1[N-1][1] <<","<< need1[N-1][2] << endl; 
    memset(marked, false, sizeof(marked));
    int result2=0;
    vector<int> safe_v2;
    safe(marked, allocated, max, need1, available, safe_v2,r,n,result2);
    //cout << "Result is " << result2 << " \n";

    if(result1 > 0){
        printf(ANSI_BOLD ANSI_COLOR_GREEN"\nInput state is safe\n" ANSI_RESET);
    }else{
        printf(ANSI_BOLD ANSI_COLOR_RED"\nInput state is safe\n" ANSI_RESET);
    }
    if(result2 > 0){
        printf(ANSI_BOLD ANSI_COLOR_GREEN"\nAnd request can be fulfilled.\n" ANSI_RESET);
    }else{
        printf(ANSI_BOLD ANSI_COLOR_RED"\nAnd request cannot be fulfilled.\n" ANSI_RESET);
    }
    return 0;
}