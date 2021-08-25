#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h>
#include<signal.h>
#include<errno.h>
#define clear() printf("\033[H\033[J") 
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_RESET   "\x1b[0m"
#define ANSI_BOLD "\x1b[1m"
#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64



void printinfo(){
    char* uname = getenv("USER");
    char hostname[1024];
    gethostname(hostname, sizeof(hostname));
    char dir[1024]; 
	getcwd(dir, sizeof(dir));
    printf(ANSI_COLOR_MAGENTA ANSI_BOLD"%s@%s:" ANSI_COLOR_BLUE "%s" ANSI_RESET "$ " ,uname,hostname,dir);
}

char **tokenize(char *line)
{
  char **tokens = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
  char *token = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
  int i, tokenIndex = 0, tokenNo = 0;

  for(i =0; i < strlen(line); i++){

    char readChar = line[i];

    if (readChar == ' ' || readChar == '\n' || readChar == '\t'){
      token[tokenIndex] = '\0';
      if (tokenIndex != 0){
	tokens[tokenNo] = (char*)malloc(MAX_TOKEN_SIZE*sizeof(char));
	strcpy(tokens[tokenNo++], token);
	tokenIndex = 0; 
      }
    } else {
      token[tokenIndex++] = readChar;
    }
  }
 
  free(token);
  tokens[tokenNo] = NULL ;
  return tokens;
}

void exec_cmd(char** parsed) 
{ 
	pid_t pid = fork(); 

	if (pid == -1) { 
		printf("\nFailed forking child.."); 
		return; 
	} else if (pid == 0) { 
		if (execvp(parsed[0], parsed) < 0) { 
			printf(ANSI_COLOR_RED "Command not found\n" ANSI_RESET);
            return; 
		} 
		exit(0);
	} else {  
		wait(NULL); 
		return; 
	} 
} 

void cmd_cd(char *s)
{
    int flag;
    if(s==NULL)
    {
        s = getenv("HOME");
    }
    flag=chdir(s);
    if(flag==-1)
    {
        char buf[MAX_INPUT_SIZE];
        buf[0]='\0';
        strcat(buf,"cd: ");
        strcat(buf,s);
        perror(buf);
    }
    else
    {
        char *oldpwd = getenv("PWD");
        char buff[MAX_INPUT_SIZE];
        char *pwd = getcwd(buff,MAX_INPUT_SIZE);
        if(pwd == NULL)
        {
            perror("cd");
        }
        else
        {
            setenv("PWD",pwd,1);
            setenv("OLDPWD",oldpwd,1);
        }
    }
}

void cmd_exit(){
    exit(0);
}

int check_for_EOF() {
    if (feof(stdin)) return 1;
    int c = getc(stdin);
    if (c == EOF) return 1;
    ungetc(c, stdin);
    exit(0);
}

int main(int argc, char* argv[]){

    char instr[1000];
    char **parse;
    int flag=0;
    //char* uname = getenv("USER");
    //clear();
    //printf(ANSI_COLOR_YELLOW ANSI_BOLD"Hello, ");
    //printf("Welcome to Shell\n");
    printf(ANSI_RESET);
    //char hostname[20];
    //gethostname(hostname, 20);
    
    char  line[MAX_INPUT_SIZE];            
	char  **tokens;              
	int i;
    int count=0;
	FILE* fp;
	if(argc == 2) {
		fp = fopen(argv[1],"r");
		if(fp < 0) {
			printf("File doesn't exists.");
			return -1;
		}
	}

	while(1) {			
		/* BEGIN: TAKING INPUT */
		bzero(line, sizeof(line));
		if(argc == 2) { // batch mode
			if(fgets(line, sizeof(line), fp) == NULL) { // file reading finished
				break;	
			}
			line[strlen(line)] = '\0';
		} else { // interactive mode
			//printf("$ ");
            printinfo();
			scanf("%[^\n]", line);
            //if(line == EOF){
                //exit(0);
            //}
            //printf("Shell Closed %d\n ", errno);
            //printf("Degug %s",line);
			getchar();
            //printf("Shell Closed %d\n ", errno);
		}
		//printf("Command entered: %s (remove this debug output later)\n", line);
		/* END: TAKING INPUT */

		line[strlen(line)] = '\n'; //terminate with new line
		tokens = tokenize(line);
   
       //do whatever you want with the commands, here we just print them

		for(i=0;tokens[i]!=NULL;i++){
			//printf("found token %s (remove this debug output later)\n", tokens[i]);
            //(parse[i],tokens[i]);
            count++;
		}
        if(strcmp(tokens[0],"clear") == 0)
        {
            clear();
        }
        if(strcmp(tokens[0],"exit") == 0)
        {
            cmd_exit();
        }
        else if(strcmp(tokens[0],"cd")==0)
        {
            if(count < 2)
                cmd_cd(NULL);
            else
                cmd_cd(tokens[1]);
        }else
        {
        printf(ANSI_RESET); 
        exec_cmd(tokens);
        }
        
		// Freeing the allocated memory	
		for(i=0;tokens[i]!=NULL;i++){
			free(tokens[i]);
		}
		free(tokens);
	}
	return 0;
}