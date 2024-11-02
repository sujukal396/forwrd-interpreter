#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "forwrd.h"
#include "vector.h"

int hash_wrd(char *wrd) {// TODO: Complete hash_wrd function
    return wrd[0] << 16 | wrd[1] << 8 | wrd[2];
}

Token* to_token(Deque *deque) {
    Token *token = (Token *)malloc(sizeof(Token));
    token->type = PHR;
    token->val.phr_builder = deque;
    return token;
}

WrdOp init_wrd(WrdEnum wrd) {
    // I might need a disgusting switch-case now
    switch(wrd) {
        case ADD:
        case MUL:
        case MOD:
        case DIV:
        case EQU:
        case LSS:
        case GTR:
        case LTE:
        case GTE:
        case AND:
        case IOR:
        case NOT:
        case BND:
        case BOR:
        case BNT:
        case BXR:
        case LSH:
        case RSH:
        case SWP:
        case DEF:
        case SEL:
        case GET:
        case FCH:
        case PRT:
        case SLD:
        case EVA:
        case _LST:
        case LEN:
        case POP:
        case DUP:
        case CLR:
        default:
            puts("grah");// placeholder for error
    }
}

Token* tokenize(Deque *phr_stack, char *word) {// stack allocate phr_stack
    Token *token = malloc(sizeof(Token));

    if(*word == '-' || isdigit(*word)) {
        char *endptr;
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
        token->val.vptr = malloc(strlen(word));
        memcpy(token->val.vptr, word, strlen(word)+1); // TODO: Double check this code
    } else if(*word == '}') {
        token = to_token(pop(phr_stack));
    } else {
        token->type = WRD;
        token->val.wrd = init_wrd(WrdEnum(hash_wrd(token)));
    }
    return token;
}

int main() {
    char filepath[] = "wrd_files/factorial.fwrd";
    FILE *fptr = fopen(filepath, "r");
    if(fptr == NULL) {
        perror("Error: Invalid File");
       return 1;
    }
    char line[100];
    Deque phr_stack = { .vec = init_vec(1, sizeof(Token*)), .front = 0, .end = 0, .length = 0 };
    Deque exec_queue = { .vec = init_vec(1, sizeof(Token*)), .front = 0, .end = 0, .length = 0 };
    //Deque main_stack = { .vec = init_vec(1, sizeof(Token*)), .front = 0, .end = 0, .length = 0 };
    
    while((fgets(line, sizeof(line), fptr)) != NULL) {
        for(char *word = strtok(line, " \n\t"); word && *word; word = strtok(NULL, " \n\t")) {
            if (*word == '{') {
                push(&phr_stack, init_deque(sizeof(Token))); // each Deque is a PhraseBuilder
                continue;
            }
            
            push(&exec_queue, tokenize(&phr_stack, word));
        }
    }
}
