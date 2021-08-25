#include <bits/stdc++.h>
#include <stdio.h> 
#include <unistd.h> 
using namespace std;

int main(int argc, char *argv[]) 
{
    int opt;
    int b,c,w;
    for(;;)
    {
        switch(getopt(argc, argv, "b:c:w:h"))
        {
            case 'b':
            //printf("parameter 'b' specified with the value %s\n", optarg);
            b=stoi(optarg);
            continue;

            case 'c':
            //printf("parameter 'c' specified with the value %s\n", optarg);
            c=stoi(optarg);
            continue;

            case 'w':
            //printf("parameter 'w' specified with the value %s\n", optarg);
            w=stoi(optarg);
            continue;

            case '?':
            case 'h':
            default :
            printf("use like: ./driver -b 3 -c 4 -w 20\n");
            break;
            case -1:
            break;
        }
    break;
    }
      
    return 0;
}