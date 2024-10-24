#include <stdio.h>
#include "forwrd.h"

// Token Methods:
void free_token(Token *token) {}
void exec_wrd(Token *token) {}

// Stack Methods:
void push(Stack *stack, Token *token) {}
Token* pop(Stack *stack, Token *token) {}
Token* peek(Stack *stack, int index) {}

int main() {
  char filepath[] = "wrd_files/factorial.wrd";
  FILE *fptr = fopen(filepath, "r");
  char line[100];
  // handle strtok stuff
  while(word != NULL) {
    Token *token = parse_token(word);
    if(token->type == WRD) {
      execute_wrd(token);
    } else {
      push(stack, token);
    }
  }
}
