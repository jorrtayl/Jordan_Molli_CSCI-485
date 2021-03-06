#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>

// Commands
void cat();
void emacs();
void ls(char[]);
void help();
void quit();
void cp();
char **store_commands(char **, char *);
void history(char **);

int main(int argc, char **argv){

  char *a =  (char *)malloc(50 * sizeof(char));
  char **record = (char **)malloc(50 * sizeof(char *));
  
  printf("Type \"help\" for the commands!\n\n");
/*
  while (TRUE) {
    type prompt( );
    read command(command, parameters);
    if (for k( ) != 0) {
      
      waitpid(−1, &status, 0);
    } else {
      
      execve(command, parameters, 0);
    }
  }
*/
  
  while (1) {
    printf(">: ");
    fflush(stdin);
    scanf("%s", a);

    //printf("%s\n", "Value of commands: ", commands);

    record = store_commands(record, a);

    printf("s\n", record);
    
    for (int i = 0; i < strlen(record); i++) {
      printf("%s\n", record[i]);
    }
    
    if (strcmp(a, "cat") == 0) {
      cat();
    }
    else if (strcmp(a, "emacs") == 0) {
      emacs();
    }
    else if (strcmp(a, "ls") == 0) {
      if (argc == 1) {
	ls(".");
      }
      else {
	while (--argc) {
	  printf("%s:\n", *++argv);
	  ls(*argv);
	}
      }
    }
    else if (strcmp(a, "help") == 0) {
      help();
    }
    else if (strcmp(a, "quit") == 0) {
      quit();
    }
    else if (strcmp(a, "cp") == 0) {
      cp();
    }
    else if (strcmp(a, "history") == 0) {
      //printf("%s\n", "Test");
      //history(commands);
    }
    else
      printf("Enter only stated things in help\n");  
    }

    return 0;
}

void cat() {

  char a[100];

  FILE *p;
  
  scanf("%s", a);

  char c;

  p = fopen(a, "r");

  if (p == NULL) {
    printf("\nError\n");
  }

  printf("\n");

  c = fgetc(p);

  while (c != EOF){
    printf("%c", c);
    c = fgetc(p);
  }

  fclose(p);

  printf("\n\n Successfully Read\n");

}

void emacs() {

  char a[100];

  FILE *p;
  
  scanf("%s", a);

  p = fopen(a, "w");

  fflush(stdin);

  printf("Enter ~ to exit\n");
  
  int c = NULL;

  while (c != '~') {
    c = getchar();

    if (c != '~') {

      fputc(c, p);
    }
  }

  fclose(p);

  printf("\n\nSuccessfully Written\n");
}

void ls(char dirname[]) {
  DIR* dir_ptr;
  struct dirent *direntp;

  if ((dir_ptr = opendir(dirname)) == NULL) {
      fprintf(stderr, "ls1: cannot open %s\n", dirname);
  }
  else {
    while((direntp = readdir(dir_ptr)) != NULL) {
      if (strcmp(direntp -> d_name, ".") != 0 && strcmp(direntp -> d_name, "..") != 0) {
	printf("%s", direntp -> d_name);
	printf("%s", " ");
      }
    }

    printf("%s", "\n");
    
    close(dir_ptr);
  }
}

void help(){
  printf("\n");
  printf("Here are all of the possible commands\n\n");
  printf("help     : Displays this menu of commands.\n");
  printf("ls       : Displays all directories in the user's current directory.\n");
  printf("cat      : To read from a file\n");
  printf("cp       : Copies one file to another. Example use: original.txt new.txt\n");
  printf("emacs    : Allows the user to create and modify a file.\n");
  printf("history  : Displays all previous commands up to 50.\n");
  printf("quit     : To quit\n");
  printf("\n");
}

void quit(){
  exit(1);
}

 void cp() {
  char a[100];
  char b[100];
  
  FILE *original, *new;
  
  scanf("%s", a);
  scanf("%s", b);

  char c;
  
  original = fopen(a, "r");
  
  if (original == NULL) {
    printf("\nError\n");
    printf("Press any key to exit.\n");
    exit(1);
  }

  new = fopen(b, "w");

  if (new == NULL) {
    printf("\nError\n");
    printf("Press any key to exit.\n");
  }
  
  printf("\n");

  while ((c = fgetc(original)) != EOF) {
    fputc(c, new);
  }
  printf("Successfully Copied\n");
  
  fclose(original);
  fclose(new);
}

char **store_commands(char **userHistory, char *userCommands) {
  for (int i = 0; i < 50; i++) {
    if (userHistory[i] == ' ') {
      userHistory[i] = userCommands;
      
      return userHistory;
    }
  }

  for (int i = 0; i < 50 - 1; i++) {
    userHistory[i + 1] = userHistory[i];
    userHistory[50] = userCommands;

    return userHistory;
  }
}

void history(char **commands) {
  for (int i = 0; i < sizeof(commands); i++) {
    //printf("%s\n", commands[i]);
    //fflush(stdout);
  }
}
