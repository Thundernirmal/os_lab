#include<stdio.h>
#include <iostream>
#include <random>
int number_at(){
        const int range_from  = 0;
        const int range_to    = 10;
        std::random_device                  rand_dev;
        std::mt19937                        generator(rand_dev());
        std::uniform_int_distribution<int>  distr(range_from, range_to);

        return distr(generator);
}
int number_bt(){
        const int range_from  = 0;
        const int range_to    = 20;
        std::random_device                  rand_dev;
        std::mt19937                        generator(rand_dev());
        std::uniform_int_distribution<int>  distr(range_from, range_to);

        return distr(generator);
}
int number_p(){
        const int range_from  = 0;
        const int range_to    = 10;
        std::random_device                  rand_dev;
        std::mt19937                        generator(rand_dev());
        std::uniform_int_distribution<int>  distr(range_from, range_to);

        return distr(generator);
}
int main(int argc, char const *argv[])
{
    if(argc !=2){
        printf("Input number by argument like ./A 20\n");
    }else{
        FILE *fptr;
        fptr = fopen(argv[1],"w");
        int n = atoi(argv[1]);
        fprintf(fptr,"%d,%d,%d,%d\n",1,0,number_bt(),1);
        for(int i=1;i<n;i++){
            fprintf(fptr,"%d,%d,%d,%d\n",i+1,number_at(),number_bt(),number_p());
        }
    }
    return 0;
}
