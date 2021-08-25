#include <bits/stdc++.h>
#include "B-fun.h"
using namespace std;

bool check(int pid, int allocated[100][10], int max[100][10], int need[100][10], int available[],int r){
    bool temp = true;
    for (int i = 0; i < r; i++) {
        if (need[pid][i] > available[i])
            temp = false;
    } 
    return temp;
}