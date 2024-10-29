#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "forwrd.h"
#include "vector.h"

int hash_wrd(char *wrd) {// TODO: Complete hash_wrd function
    return wrd[0] << 16 | wrd[1] << 8 | wrd[2];
}

/*
Token* tokenize(char *word) {// stack allocate phr_stack
    Deque phr_stack = { .vec = init_vec(), .front = 0, .end = 0, .length = 0 };
    if(*word == '{') {
        push(&phr_stack, (Deque *)malloc(sizeof(Deque))); // each Deque is a PhraseBuilder
        continue;
    }

    Token *token = malloc(sizeof(Token));
    if(*word == '-' || isdigit(*word)) {
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
        token->val.voidptr = malloc(strlen(word));
        memcpy(token->val.voidptr, word, strlen(word)+1); // TODO: Double check this code
    } else if(*word == '}') {
        token = to_token(pop(phr_stack));
    } else {
        token->type = WRD;
        token->val.WrdEnum = WrdEnum(hash_wrd(wrd));
    }
    return token;
}
*/

int main() {
    char filepath[] = "wrd_files/factorial.fwrd";
    FILE *fptr = fopen(filepath, "r");
    if(fptr == NULL) {
        perror("Error: Invalid File");
       return 1;
    }
    char line[100];
    // stack allocate Stack
    
    while((fgets(line, sizeof(line), fptr)) != NULL) {
        for(char *word = strtok(line, " \n\t"); word && *word; word = strtok(NULL, " \n\t")) {
            puts(word);
        }
    }
}
