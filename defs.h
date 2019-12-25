//
// Created by sergey on 12/25/19.
//

#ifndef SBER_STACK_MAX_DEFS_H
#define SBER_STACK_MAX_DEFS_H

#define TRUE 1
#define FALSE 0

#define STACK_MAX_SIZE 100

// Обычный стек
typedef struct {

    int st[STACK_MAX_SIZE];
    unsigned st_size;

} STACK;

// Стек с константным временем доступа к максимальному элементу
typedef struct {

    STACK data_stack;
    STACK aux_stack;

} CONST_TIME_STACK;


#endif //SBER_STACK_MAX_DEFS_H
