#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 48
#define MAX_TOKEN 8
int main(int argc, char **argv) 
{
    char command[BUFFER_SIZE];
    char *tokens[MAX_TOKEN];
    pid_t pid;
    char *args[MAX_TOKEN - 1];
    while(1) {
        printf("\norsh> ");
        fgets(command,BUFFER_SIZE,stdin);
        command[strcspn(command, "\n")] = '\0';
        char *token = strtok(command," ");
        int i = 0;
        for(; token != NULL && i < MAX_TOKEN - 1; i++) {
            tokens[i] = token;
            token = strtok(NULL, " ");
        }
        tokens[i] = NULL;
        pid = fork();
        if(pid == 0) {
            execvp(tokens[0], tokens);
        } else if(pid > 0) {
            wait(NULL);
        }
    }

    return 0;
}