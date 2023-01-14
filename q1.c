#include "headers.h"

void displayWelcome(){
    write(STDOUT_FILENO,WELCOME_MESSAGE,sizeof(WELCOME_MESSAGE)-1);
}

void displayPrompt(){
    write(STDOUT_FILENO,SHELL,sizeof(SHELL)-1);
}