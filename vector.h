#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct {
    int cap;
    size_t elem_size;
    void** arr;
} Vector;

typedef struct {
    Vector* vec;
    int front;
    int end;
    int length;
} Deque;

// Vector Functions:
Vector* init_vec(int cap, size_t elem_size);
int resize(Vector *vec, int new_size);
void free_vec(Vector *vec);

// Deque Functions:
Deque* init_deque(size_t elem_size);
int offer(Deque *deque, void *elem);
int push(Deque *deque, void *elem);
void* poll(Deque *deque);
void* pop(Deque *deque);
void* peek(Deque *deque, int index); // Pos -> Queue; Neg -> Stack
void free_deq(Deque *deque);

#endif // !VECTOR_H
