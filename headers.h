//
// Created by ensea on 13/01/23.
//

#ifndef UNTITLED_HEADER_H
#define UNTITLED_HEADER_H

#endif //UNTITLED_HEADER_H



#include <unistd.h> //Pour Write et Read
#include <string.h> //Pour les chaine de caractÃƒÂ¨re
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>
#include <stdio.h>

#define WELCOME_MESSAGE "Bienvenu dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n"
#define BYE "Bye bye...\n"
#define SHELL "enseash %\n"
#define MAX_COMMAND_SIZE 512
#define COMMAND_DONT_EXIST "Commande %s non trouvée, veuillez ressayer\n"
#define MAX_OUTPUT_SIZE 512
#define SHELL_EXIT "enseash [exit:"
#define SHELL_SIGN "enseash [sign:"
#define SHELL_CLOSE "] %"