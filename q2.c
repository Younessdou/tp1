#include <sys/wait.h>
#include <string.h>
#include "headers.h"

void executeCommand(){
    int nbCharRead;
    int status;
    char buffer[MAX_OUTPUT_SIZE];
    char output_buffer[MAX_OUTPUT_SIZE];
    nbCharRead=read(STDIN_FILENO,buffer,MAX_COMMAND_SIZE);
    buffer[nbCharRead-1]='\0';
    if (fork()==0){
        execlp(buffer,buffer,NULL);
        sprintf(output_buffer,COMMAND_DONT_EXIST,buffer);
        write(STDOUT_FILENO,strlen(output_buffer),output_buffer);
        exit(EXIT_FAILURE);
    }
    wait(&status);
    displayPrompt();

}