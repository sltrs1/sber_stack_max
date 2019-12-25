//
// Created by sergey on 12/25/19.
//
#include "functions.h"


void init_stack(STACK * s) {

    if (s == NULL ) {
        return;
    }

    s->st_size = 0;
    memset(s->st, 0, sizeof(int)*STACK_MAX_SIZE);
}

int is_stack_empty (STACK * s) {

    if (s == NULL) {
        return FALSE;
    }

    if (s->st_size == 0 ) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

int push(STACK * s, int x) {

    if (s == NULL ) {
        return FALSE;
    }

    if (s->st_size == STACK_MAX_SIZE) {
        return FALSE;
    }

    s->st[s->st_size] = x;
    s->st_size++;
    return TRUE;

}

int pop(STACK * s) {

    if (s == NULL ) {
        return FALSE;
    }

    if (is_stack_empty( s )) {
        return FALSE;
    }
    else {
        s->st_size--;
        return TRUE;
    }
}

int top(STACK * s) {

    if (s == NULL ) {
        return FALSE;
    }

    if (is_stack_empty( s )) {
        return 0;
    }
    else {
        return s->st[s->st_size-1];
    }
}


void init_ct_stack(CONST_TIME_STACK * cts){

    if (cts == NULL) {
        return;
    }

    init_stack(&cts->data_stack);
    init_stack(&cts->aux_stack);

}

int ct_push(CONST_TIME_STACK * cts, int x) {

    if (cts == NULL) {
        return FALSE;
    }

    int res = 0;

    res = push( &cts->data_stack, x );
    if (res == FALSE) return FALSE;

    if ( is_stack_empty(&cts->aux_stack) ) {
        res = push(&cts->aux_stack, x);
        if (res == FALSE) return FALSE;
    }
    else {
        if ( top(&cts->aux_stack) < x ) {
            res = push(&cts->aux_stack, x);
            if (res == FALSE) return FALSE;
        }
    }

    return TRUE;
}

int ct_pop(CONST_TIME_STACK * cts) {

    if (cts == NULL) {
        return FALSE;
    }

    if ( is_stack_empty(&cts->data_stack) ) {
        printf("Stack is empty: nothing to pop!\n");
        return FALSE;
    }

    int head = top(&cts->data_stack);
    pop(&cts->data_stack);

    if (head == top(&cts->aux_stack) ) {
        pop(&cts->aux_stack);
    }

    return TRUE;


}

int ct_top(CONST_TIME_STACK * cts) {

    if (cts == NULL) {
        return FALSE;
    }

    if ( is_stack_empty(&cts->data_stack) ) {
        return FALSE;
    }
    else {
        return top(&cts->data_stack);
    }


}

int ct_max(CONST_TIME_STACK * cts) {

    if (cts == NULL) {
        return FALSE;
    }

    if ( is_stack_empty(&cts->data_stack) || is_stack_empty(&cts->aux_stack) ) {
        printf("No max value because stack is empty\n");
        return FALSE;
    }
    else {
        return top(&cts->aux_stack);
    }

}