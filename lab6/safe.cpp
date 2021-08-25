#include <bits/stdc++.h>
#include "B-fun.h"
using namespace std;

void safe(bool mark[], int allocated[100][10], int max[100][10], int need[100][10], int available[], vector<int> safe_v,int r,int n,int &result){
    for (int i = 0; i < n; i++) {
        if (!mark[i] && check(i, allocated, max, need, available,r)) {
            mark[i] = true;
            for (int j = 0; j < r; j++)
                available[j] += allocated[i][j];
            safe_v.push_back(i);
            safe(mark, allocated, max, need, available, safe_v,r,n,result);
            safe_v.pop_back();
            mark[i] = false;
            for (int j = 0; j < r; j++)
                available[j] -= allocated[i][j];
        }
    }
    if (safe_v.size() == n) {
        result++;
    }
}