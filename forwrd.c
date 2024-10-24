#include <stdio.h>
#include <string.h>
#include "forwrd.h"

// Token Methods:
void free_token(Token *token) {}
void exec_wrd(Token *token) {}

// Stack Methods:
void push(Stack *stack, Token *token) {}
Token* pop(Stack *stack) {}
Token* peek(Stack *stack, int index) {}

int main() {
    char filepath[] = "wrd_files/factorial.wrd";
    FILE *fptr = fopen(filepath, "r");
    if(fptr == NULL) {
        perror("Error: Invalid File");
        return 1;
    }

    char line[100];
    while((fgets(line, sizeof(line), fptr)) != NULL) {
        for(char* word = strtok(line, " \n\t"); word && *word; word = strtok(NULL, " \n\t")) {
            puts(word);
        }
    }
}
