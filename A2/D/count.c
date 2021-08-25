/*
    Took help from: https://stackoverflow.com/questions/2496668/how-to-read-the-standard-input-into-string-variable-until-eof-in-c
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUF_SIZE 1024
int main()
{
    int n;
    char buffer[BUF_SIZE];
    size_t contentSize = 1;
    char *content = malloc(sizeof(char) * BUF_SIZE);
    if(content == NULL)
    {
        perror("Failed to allocate content");
        exit(1);
    }
    content[0] = '\0';
    while(fgets(buffer, BUF_SIZE, stdin))
    {
        char *old = content;
        contentSize += strlen(buffer);
        content = realloc(content, contentSize);
        if(content == NULL)
        {
            perror("Failed to reallocate content");
            free(old);
            exit(2);
        }
        strcat(content, buffer);
    }

    if(ferror(stdin))
    {
        free(content);
        perror("Error reading from stdin.");
        exit(3);
    }
    n=strlen(content);
    int count=0;
    for (int i = 0; i < n; i++) {

        if((content[i] >= 'a' && content[i] <= 'z') || content[i] >= 'A' && content[i] <= 'Z'){
            continue;
        }else{
            count++;
        }
    }
    for (int i = 0; i < n; i++){
        printf("%c",content[i]);
    }
    fprintf(stderr,"final count = %d\n",count);
    
    return 0;
}