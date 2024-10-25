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

int hash_wrd(char *wrd) {// TODO: Complete hash_wrd function
    return 0;
}

int main() {
    char filepath[] = "wrd_files/factorial.fwrd";
    FILE *fptr = fopen(filepath, "r");
    if(fptr == NULL) {
        perror("Error: Invalid File");
       return 1;
    }

    // while stack > 0:
    // PhraseBuilder phr_builder = peek(stack, 0);
    // append(phr_builder->queue, token)
    
    char line[100];
    while((fgets(line, sizeof(line), fptr)) != NULL) {
        for(char* word = strtok(line, " \n\t"); word && *word; word = strtok(NULL, " \n\t")) {
            Token *token = malloc(sizeof(Token));

            if(*word == '-' || isdigit(*word)) { //TODO: Currently no safeguards against combinations of numbers and characters where numbers precede the characters
                int *endptr;
                if(strchr(word, '.')) {
                    token->type = FLT;
                    token->val.flt = strtod(word, &endptr);
                } else {
                    token->type = INT;
                    token->val.num = strtol(word, &endptr, 10);
                }
            } else if(*word == '\'') {
                token->type = CHR;
                token->val.chr = *word;
            } else if(*word == '\"') {
                word++;
                token->type = STR;
                token->val.voidptr = malloc(strlen(word) * sizeof(char));
                memcpy(token->val.voidptr, word, strlen(word)+1); // TODO: Double check this code
            } else if(*word == '{') {
                token->type = PHR;
                // PhraseBuilder stuff
            } else {
                token->type = WRD;
                token->val.WrdEnum = WrdEnum(hash_wrd(wrd));
            }
            // If it belongs in a Phrase, pack into PhraseBuilder
            // Either PUSH action or WRD action
            // If word[0] == '-' or isdigit
            //      If word contains '.'
            //          token->val.flt = strtof(word)
            //          token->type = FLT
            //      Else: 
            //          token->val.num = strtol(word)
            //          token->type = INT
            // If word[0] == '\''
            //      word++;
            //      token->val.chr = *word;
            //      token->type = CHR;
            // If word[0] == '\"'
            //      word++;
            //      token->type = STR;
            //      token->val.voidptr = malloc(strlen(word) * sizeof(char));
            //      memcpy(token->val.voidptr, word, strlen(word)+1);
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
