#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h> 

int SIZE = 40;

void PromptCharacter(); // user prompt character that should always be represented.
void Commands(char *response); // all commands the user may enter.
void INThandler(int); // exits.
void ToString(char *response); // converts the user's input into a string.
int responseLength(char *response); // gets the length of the response.

int main(void)
{
    PromptCharacter();
    signal(SIGINT, INThandler);
    while (1)
        pause();
    INThandler(1);
    return 0;
}

int responseLength(char *response) {
  int length = 0;
  
  for (int i = 0; i < response[i]; i++) {
    length = i;
  }

  return length;
}

// Driver
void PromptCharacter() {
    // This loop should always be running, waiting for user input. (We may push this into a function later).
  char response[SIZE];
  
    while (true) {
      printf(">: ");

      printf(response[0]);

      ToString(response); // Gets user input and converts it to a string.

      printf(response);

      Commands(response); // Passes previously store response into command for checking if a command was entered.
    }
}

void ToString(char *response) {
  char c = getchar();
  int count = 0;

  while (c != EOF) {
    response[count] = c;
    ++count;
  }
}

// Needs fixing
void Commands(char *response) {
  // ls command: shows all files in the directory.
  int length = 0;
  
  for (int i = 0; i < response[i]; i++) {
    length = i;
  }
  
  for (int i = 0; i < length; i++) {
    if (response[i] = "ls") {
      DIR *d;
      struct dirent *dir;
      d = opendir(".");

      if (d) {
	while ((dir = readdir(d)) != NULL) {
	  printf("%s\n", dir -> d_name);
	}
	closedir(d);
      }
    }
  }
}

void  INThandler(int sig) {
    char response;
    
    signal(sig, SIG_IGN);
    printf("Do you really want to quit? [y/n] ");
    response = getchar();
        
    if (response == 'Y' || response == 'y')
        exit(0);
    else
        signal(SIGINT, INThandler);
        
        
    getchar(); // Get new line character
}
