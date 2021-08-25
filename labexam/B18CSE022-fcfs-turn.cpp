#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int cpu_bt[] = {6, 27, 18, 5, 17, 12, 13, 28, 13, 10, 5, 13, 14, 18, 10, 23, 28, 2, 30, 5, 9, 6, 30, 8, 16, 1, 29, 20, 1, 18, 13, 27, 26, 23, 17, 11, 1, 9, 5, 19, 23, 17, 2, 30, 14, 24, 10, 14, 17, 4, 2, 1, 23, 1, 30, 10, 8, 18, 28, 29, 3, 9, 15, 14, 15, 17, 16, 25, 1, 4, 15, 7, 18, 23, 2, 18, 23, 12, 10, 3, 14, 12, 20, 15, 26, 15, 25, 1, 23, 10, 9, 26, 16, 2, 9, 7, 3, 17, 30, 2, 22, 12, 11, 6, 17, 18, 14, 17, 24, 3, 26, 27, 24, 15, 6, 8, 17, 4, 12, 1, 30, 12, 1, 12, 9, 6, 14, 16, 21, 20, 30, 17, 8, 9, 9, 28, 15, 17, 30, 9, 28, 3, 27, 22, 10, 4, 3, 28, 8, 9, 28, 29, 9, 15, 12, 4, 1, 15, 10, 15, 25, 30, 10, 5, 29, 30, 9, 6, 12, 14, 1, 27, 1, 15, 20, 19, 7, 23, 10, 17, 19, 16, 22, 9, 11, 3, 20, 30, 10, 1, 23, 1, 5, 22, 4, 14, 28, 9, 4, 19, 7, 16, 23, 11, 18, 26, 28, 23, 25, 29, 17, 20, 20, 26, 1, 18, 30, 10, 3, 5, 4, 26, 19, 15, 18, 25, 25, 24, 24, 20, 24, 1, 1, 29, 24, 24, 29, 7, 29, 9, 23, 9, 6, 4, 9, 4, 4, 30, 10, 13};
    int rtime[] = {6, 27, 18, 5, 17, 12, 13, 28, 13, 10, 5, 13, 14, 18, 10, 23, 28, 2, 30, 5, 9, 6, 30, 8, 16, 1, 29, 20, 1, 18, 13, 27, 26, 23, 17, 11, 1, 9, 5, 19, 23, 17, 2, 30, 14, 24, 10, 14, 17, 4, 2, 1, 23, 1, 30, 10, 8, 18, 28, 29, 3, 9, 15, 14, 15, 17, 16, 25, 1, 4, 15, 7, 18, 23, 2, 18, 23, 12, 10, 3, 14, 12, 20, 15, 26, 15, 25, 1, 23, 10, 9, 26, 16, 2, 9, 7, 3, 17, 30, 2, 22, 12, 11, 6, 17, 18, 14, 17, 24, 3, 26, 27, 24, 15, 6, 8, 17, 4, 12, 1, 30, 12, 1, 12, 9, 6, 14, 16, 21, 20, 30, 17, 8, 9, 9, 28, 15, 17, 30, 9, 28, 3, 27, 22, 10, 4, 3, 28, 8, 9, 28, 29, 9, 15, 12, 4, 1, 15, 10, 15, 25, 30, 10, 5, 29, 30, 9, 6, 12, 14, 1, 27, 1, 15, 20, 19, 7, 23, 10, 17, 19, 16, 22, 9, 11, 3, 20, 30, 10, 1, 23, 1, 5, 22, 4, 14, 28, 9, 4, 19, 7, 16, 23, 11, 18, 26, 28, 23, 25, 29, 17, 20, 20, 26, 1, 18, 30, 10, 3, 5, 4, 26, 19, 15, 18, 25, 25, 24, 24, 20, 24, 1, 1, 29, 24, 24, 29, 7, 29, 9, 23, 9, 6, 4, 9, 4, 4, 30, 10, 13};
    int n = 250;
    int at[250];
    int wtime[250];
    int A=0;
    int C=0;
    int ct[250];
    for(int i=0;i<250;i++){
        at[i]=i;
        A=A+i;
        C = C + cpu_bt[i];
        ct[i]=C;
    }
    
    cout << (float) (C - A ) / 250 << endl;
    return 0;
}