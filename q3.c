#include "headers.h"

void executeCommand(){
    int nbCharRead;
    int status;
    char buffer[MAX_OUTPUT_SIZE];
    char output_buffer[MAX_OUTPUT_SIZE];
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
    displayPrompt();

}

//En tapant la commande exit dans le micro shell, on vÃ©rifie que cela fonctionne bien.
//C'est une mission REUSSIE ! cela nous renvoie bien Bye bye... et provoque la sortie du shell.