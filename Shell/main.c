#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <dirent.h>

// Commands
void read();
void write();
void ls(char[]);
void help();
void quit();

int main(int argc, char **argv){

  char a[100];

  printf("Type \"help\" for the commands!\n\n");

  while (1) {

    printf(">: ");
    fflush(stdin);
    scanf("%s", a);

    if (strcmp(a, "read") == 0) {
      read();
    }
    else if (strcmp(a, "write") == 0) {
      write();
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
    else
      printf("Enter only stated things in help\n");  
    }

    return 0;
}

void read() {

  char a[100];

  printf("For reading, provide a file extension.\nEx: hello.txt\n\n");

  FILE *p;

  printf("Enter file name: ");
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

void write(){

  char a[100];

  printf("For reading, provide a file extension.\nEx: hello.txt\n\n");

  FILE *p;

  printf("Enter File Name To Write: ");
  scanf("%s", a);

  p = fopen(a, "w");

  fflush(stdin);

  printf("Enter ~ to exit from writing\n");
  printf("Start writing: \n");

  int ch = NULL;

  while (ch != '~') {
    ch = getchar();

    if (ch != '~') {

      fputc(ch, p);
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
  printf("write  : To write to a file\n");
  printf("read   : To read from a file\n");
  printf("ls     : Displays all directories in the user's current directory.");
  printf("quit   : To quit\n");
  printf("\n");
}

void quit(){
  exit(1);
}
