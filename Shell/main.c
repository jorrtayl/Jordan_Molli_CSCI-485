#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

void read();
void write();
void help();
void quit();

int main(){

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

    int ch=NULL;

    while(ch != '~'){
        ch = getchar();

        if(ch != '~'){

        fputc(ch, p);
        }
    }
    
    fclose(p);

    printf("\n\nSuccessfully Written\n");
}

void help(){
    printf("\n");
    printf("Here are all of the possible commands\n\n");
    printf("write  : To write to a file\n");
    printf("read   : To read from a file\n");
    printf("quit   : To quit\n");
    printf("\n");
}

void quit(){
    exit(1);
}
