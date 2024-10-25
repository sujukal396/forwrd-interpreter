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
    char filepath[] = "wrd_files/factorial.fwrd";
    FILE *fptr = fopen(filepath, "r");
    if(fptr == NULL) {
        perror("Error: Invalid File");
       return 1;
    }

    char line[100];
    while((fgets(line, sizeof(line), fptr)) != NULL) {
        for(char* word = strtok(line, " \n\t"); word && *word; word = strtok(NULL, " \n\t")) {
            // Either PUSH action or WRD action
            // If word[0] == '-' or isdigit
            //      If word contains '.'
            //          PUSH strtof(word) <- FLT
            //      Else: 
            //          PUSH strtol(word) <- INT
            // If word[0] == '\''
            //      word++;
            //      PUSH word; <- CHR
            // If word[0] == '\"'
            //      word++;
            //      word[strlen(word)-1] = 0;
            //      PUSH word; <- STR
            // If word[0] == '{'
            //      Use PhraseBuilder
            //      PUSH PHR; <- PHR
            // Else
            //      exec_wrd(WrdEnum(hash_wrd(wrd)));
        }
    }
}
