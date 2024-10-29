#include <stdlib.h>
#include "vector.h"

/* Vector */
Vector* init_vec(int cap, size_t elem_size) { // TODO: Error handling for malloc
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    if(!vec) return (Vector *)NULL; // failed malloc for Vector
    vec->cap = cap;
    vec->elem_size = elem_size;
    vec->arr = malloc(vec->cap * vec->elem_size);
    if(!vec->arr) return (Vector *)NULL; // failed malloc for array
    return vec;
}

int resize(Vector *vec, int new_size) {
    void *new_arr = realloc(vec->arr, new_size * vec->elem_size); // TODO: Error handling for realloc
    if(!new_arr) return 0;
    vec->cap = new_size;
    vec->arr = new_arr;
    return 1;
}

/* Deque */
Deque* init_deque(size_t elem_size) {
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    if(!deque) return (Deque *)NULL; // Failed malloc
    deque->vec = init_vec(1, elem_size);
    if(!deque->vec) {// Failed init_vec
        free(deque);
        return NULL;
    }
    deque->front = 0;
    deque->end = 0;
    deque->length = 0;
    return deque;
}

int push(Deque *deque, void *elem) {// push to end
    if(deque->length == 0) {
        deque->vec->arr[0] = elem;
    } else {
        if((deque->end + 1) % deque->vec->cap == deque->front) {
            if(!resize(deque->vec, deque->vec->cap * 2)) return 0; // failed resize
        }
        deque->end = (deque->end + 1) % deque->vec->cap;
        deque->vec->arr[deque->end] = elem;
    }
    deque->length++;
    return 1;
}

int offer(Deque *deque, void *elem) {// push to front
    int new_front = (deque->front > 0)? (deque->front - 1) : (deque->vec->cap - 1);
    if(new_front == deque->end) {
        if(!resize(deque->vec, deque->vec->cap * 2)) return 0; // failed resize
        new_front = (deque->front > 0)? (deque->front - 1) : (deque->vec->cap - 1); // I hope this works
    }
    deque->front = new_front;
    deque->vec->arr[deque->front] = elem;
    deque->length++;
    return 1;
}

void* poll(Deque *deque) {// pop off front
    void *first = deque->vec->arr[deque->front];
    deque->vec->arr[deque->front] = NULL;
    deque->front++;
    deque->length--;
    return first;
}

void* pop(Deque *deque) {// pop off end
    void *last = deque->vec->arr[deque->end];
    deque->vec->arr[deque->end] = NULL;
    deque->end--;
    deque->length--;
    return last;
}

void *peek(Deque *deque, int index) {// index into deque
    if(deque->length == 0 || index >= deque->length || abs(index) > deque->length) {
        return NULL; // invalid peek
    }
    if(deque->length == 1) {
        return deque->vec->arr[deque->front];
    }
    return (index >= 0)?
        deque->vec->arr[(deque->front + index) % deque->vec->cap] :
        deque->vec->arr[(deque->front + (deque->length + index)) % deque->vec->cap];
}
