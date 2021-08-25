#include <bits/stdc++.h>
#include "A-fun.h"
using namespace std;

bool search(int key, vector<int>& fr)
{
    for (int i = 0; i < fr.size(); i++)
        if (fr[i] == key)
            return true;
    return false;
}
int predict(int pg[], vector<int>& fr, int pn, int index)
{
    int res = -1, farthest = index;
    for (int i = 0; i < fr.size(); i++) {
        int j;
        for (j = index; j < pn; j++) {
            if (fr[i] == pg[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == pn)
            return i;
    }
    return (res == -1) ? 0 : res;
}
int OPR(int pages[], int n, int frames){
    vector<int> fr;
    int hit = 0;
    for (int i = 0; i < n; i++) {
        if (search(pages[i], fr)) {
            hit++;
            continue;
        }
        if (fr.size() < frames)
            fr.push_back(pages[i]);
        else {
            int j = predict(pages, fr, n, i + 1);
            fr[j] = pages[i];
        }
    }
    return n - hit;
}