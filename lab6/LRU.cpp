#include <bits/stdc++.h>
#include "A-fun.h"
using namespace std;

int LRU(int pages[], int n, int frames){
    unordered_set<int> set;
    unordered_map<int, int> idx;
    int pf = 0;
    for (int i=0; i<n; i++)
    {
        if (set.size() < frames)
        {
            if (set.find(pages[i])==set.end())
            {
                set.insert(pages[i]);
                pf++;
            }
            idx[pages[i]] = i;
        }
        else
        {
            if (set.find(pages[i]) == set.end())
            {
                int lru = INT_MAX, val;
                for (auto it=set.begin(); it!=set.end(); it++)
                {
                    if (idx[*it] < lru)
                    {
                        lru = idx[*it];
                        val = *it;
                    }
                }
                set.erase(val);
                set.insert(pages[i]);
                pf++;
            }
            idx[pages[i]] = i;
        }
    }
    return pf;
}