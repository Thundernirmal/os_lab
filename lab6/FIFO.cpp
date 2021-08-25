#include <bits/stdc++.h>
#include "A-fun.h"
using namespace std;

int FIFO(int pages[], int n, int frames){
    unordered_set<int> set;
    queue<int> idx;
    int pf = 0;
    for (int i=0; i<n; i++)
    {
        if (set.size() < frames)
        {
            if (set.find(pages[i])==set.end())
            {
                set.insert(pages[i]);
                pf++;
                idx.push(pages[i]);
            }
        }
        else
        {
            if (set.find(pages[i]) == set.end())
            {
                int val = idx.front();
                idx.pop();
                set.erase(val);
                set.insert(pages[i]);
                idx.push(pages[i]);
                pf++;
            }
        }
    }
    return pf;
}