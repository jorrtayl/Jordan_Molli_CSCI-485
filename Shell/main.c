#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <string.h>


int SIZE = 40;

void PromptCharacter(); // user prompt character that should always be represented.
void Commands(char *response); // all commands the user may enter.
void INThandler(int); // exits.
void ToString(char *response); // converts the user's input into a string.
int responseLength(char *response); // gets the length of the response.

int main(void)
{
  PromptCharacter();
  return 0;
}

int responseLength(char *response) {
  char *temp; // This is so we do not change the original.
  int length = 0;
  
  for (temp = response; response != '\0'; temp++) {
    length++;
  }

  return length;
}

// Driver
void PromptCharacter() {
  // This loop should always be running, waiting for user input. (We may push this into a function later).
  char response[SIZE];
  int length = 0;
  
  while(1) {
    printf(">: ");

    int c;
    int count = 0;

    c = getchar();
    
    length = responseLength(response); // Important for converting the character array to a string, it needs to know the exact size to iterate through.
    printf(responseLength);
    
    while (c != EOF) {
      response[count] = c;
      ++count;
      c = getchar();
    }
    
    getchar(); // eats newline character, this prevents two ">: " from appearing every time.

    // ToString(response);
  }
  
  signal(SIGINT, INThandler);
  while (1)
    pause();

  INThandler(1);
}

/*void ToString(char *response) {
  char c = getchar(); // If this is removed, an infinite loop will occur.
  int count = 0;

  while (c != EOF) {
    response[count] = c;
    ++count;
  }
  }*/

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
