#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h> 

char RESPONSE[40];

void PromptCharacter(); // user prompt character that should always be represented.
void Commands(); // all commands the user may enter.
void INThandler(int); // exits.

int main(void)
{
    PromptCharacter();
    signal(SIGINT, INThandler);
    while (1)
        pause();
    INThandler(1);
    return 0;
}

// Driver
void PromptCharacter() {
    // This loop should always be running, waiting for user input. (We may push this into a function later).
    while (true) {
        printf(">: ");
        
        Commands();
        
        char c;
        int count;
        
        c = getchar();
        count = 0;
        while(c != EOF){
            RESPONSE[count] = c;
            ++count;
        }
    }
}

// Needs fixing
void Commands() {
    // ls command: shows all files in the directory.
    /* if (RESPONSE = "ls") {
        DIR *d;
        struct dirent *dir;
        d = opendir(".");
            
        if (d) {
            while ((dir = readdir(d)) != NULL) {
                printf("%s\n", dir->d_name);
            }
        closedir(d);
        }
    } */
}

void  INThandler(int sig) {
    char response;
    
    signal(sig, SIG_IGN);
    printf("Do you really want to quit? [y/n] ");
    response = getchar();
        
    if (response == 'Y' || RESPONSE == 'y')
        exit(0);
    else
        signal(SIGINT, INThandler);
        
        
    getchar(); // Get new line character
}
