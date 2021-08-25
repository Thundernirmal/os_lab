#include <bits/stdc++.h>
using namespace std;

bool check(int pid, int allocated[100][10], int max[100][10], int need[100][10], int available[],int r);

void safe(bool mark[], int allocated[100][10], int max[100][10], int need[100][10], int available[], vector<int> safe,int r,int n,int &result);