# include <stdio.h>
# include <string.h>

void setRandoms(int arr[],int lower, int upper, int count)
{
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() %
           (upper - lower + 1)) + lower;
        arr[i]=num;
    }
}

int main()
{
    int n;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    int arr[n];
    int burst[n];
    int prior[n];
    srand(time(0));
    setRandoms(arr,0,10,n);
    setRandoms(burst, 1, 20, n);
    setRandoms(prior, 1, 10, n);
    // for(int i=0;i<n;i++)
    // printf("%d ",arr[i]);
    //     printf("\n");
    // for(int i=0;i<n;i++)
    // printf("%d ",burst[i]);
    //     printf("\n");
    // for(int i=0;i<n;i++)
    // printf("%d ",prior[i]);
    //     printf("\n");

    printf("Process  Arrival  CPUBurst  Priority\n");
    for(int i=0;i<n;i++)
    printf("  P%d      %d        %d         %d\n",i,arr[i],burst[i],prior[i]);

    FILE *fp;
    fp=fopen("file1.txt", "w");
    if(fp==NULL)
    {
        printf("Error in opening file");
    }
    fwrite(arr,sizeof(arr),1,fp);
    fwrite(burst,sizeof(burst),1,fp);
    fwrite(prior,sizeof(prior),1,fp);


    

}