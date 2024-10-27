#ifndef FORWRD_H
#define FORWRD_H

typedef enum { // c1 << 16 | c2 << 8 | c3
    ADD = 6382692,
    MUL = 7173484,
    MOD = 7171940,
    DIV = 6580598,
    EQU = 6648181,
    LSS = 7107443,
    GTR = 6780018,
    LTE = 7107685,
    GTE = 6780005,
    AND = 6385252,
    IOR = 6909810,
    NOT = 7237492,
    BND = 6450788,
    BOR = 6450788,
    BNT = 6450804,
    BXR = 6453362,
    LSH = 7107432,
    RSH = 7500648,
    SWP = 7567216,
    DEF = 6579558,
    SEL = 7562604,
    FCH = 6710120,
    PRT = 7369332,
    SLD = 7564388,
    EVA = 6649441,
    _LST = 7107444,
    LEN = 7103854,
    POP = 7368560,
    DUP = 6583664,
    CLR = 6515826
} WrdEnum;

typedef enum {
    INT,
    FLT,
    CHR,
    STR,// to simplify the printing of strings
    LST,
    WRD,
    PHR,
} TokenType;

typedef struct {
    TokenType type;
    union {
        long int num;
        char chr;
        double flt;
        WrdEnum *wrd;// 
        PhrBuilder phr;
        void *vptr; // strings, lists, and phrases
    } val;
} Token;

// Token Methods:
void free_token(Token *token);
void exec_wrd(Token *token);

typedef struct {
    int cap;
    int length;
    Token* arr;
} Vector;

Vector* init_vec();
void push(int index);
Token* get(int index);
void remove(int index);

typedef struct {
    Vector* vec;
    int front;
    int end;
} Deque;

// Deque Functions:
Deque* init_deque();
void offer(Token *token);
void push(Token *token);
Token* poll();
Token* pop();
Token* peek(int index); // Pos -> Queue; Neg -> Stack

#endif // !FORWRD_H
