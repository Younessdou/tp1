#include "headers.h"

void executeCommand(){
    int nbCharRead;
    int status;
    char buffer[MAX_OUTPUT_SIZE];
    char output_buffer[MAX_OUTPUT_SIZE];
    char stringSTATUS[1] ={0};

    nbCharRead=read(STDIN_FILENO,buffer,MAX_COMMAND_SIZE);
    buffer[nbCharRead-1]='\0';
    if (fork()==0){
        if(strcmp(buffer,"exit")==0){
            //Ici on veut que si la commande demandÃ©e par l'utilisateur est 'exit', alors on Ã©xÃ©cute exit.

            write(STDOUT_FILENO, BYE, strlen(BYE));
            kill(0,SIGINT); //utilise les appels systÃ¨me ; on peut aussi utiliser exit(0); mais on a besoin d'une librairie pour exit
        }
        execlp(buffer,buffer,NULL);
        sprintf(output_buffer,COMMAND_DONT_EXIST,buffer);
        write(STDOUT_FILENO,strlen(output_buffer),output_buffer);
        exit(EXIT_FAILURE);
    }

    wait(&status);
    if(WIFEXITED(status)){
        write(STDOUT_FILENO,SHELL_EXIT,strlen(SHELL_EXIT));

        stringSTATUS[0]=(WTERMSIG(status)&0xf) +'0';
        write(STDOUT_FILENO,stringSTATUS,1);

        write(STDOUT_FILENO,SHELL_CLOSE,strlen(SHELL_CLOSE));
    }

    if(WIFSIGNALED(status)) {
        write(STDOUT_FILENO, SHELL_SIGN, strlen(SHELL_SIGN));

        stringSTATUS[0] = (WTERMSIG(status) & 0xf) + '0';
        write(STDOUT_FILENO, stringSTATUS, 1);

        write(STDOUT_FILENO, SHELL_CLOSE, strlen(SHELL_CLOSE));
    }
    displayPrompt();

}