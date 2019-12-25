//
// Created by sergey on 12/25/19.
//

#include "defs.h"
#include <string.h>
#include "stdio.h"

#ifndef SBER_STACK_MAX_FUCTIONS_H
#define SBER_STACK_MAX_FUCTIONS_H

// Вспомгательные функции для работы с обычным стеком
// Не рекомендуются к прямому использованию, т.к. предназначены для использования
// внутри функций работы с константным стеком

void init_stack(STACK * s);

int is_stack_empty (STACK * s);

int push(STACK * s, int x);

int pop(STACK * s);

int top(STACK * s);

// -----------------------------------------

// Функции для работы с константным стеком

// Инициализация стека нулевыми значениями
void init_ct_stack(CONST_TIME_STACK * cts);

// Добавление значения в стек
// Возвращает TRUE в случае успешной вставки и FALSE в случае неудачи
int ct_push(CONST_TIME_STACK * cts, int x);

// Удаление вершины стека
// Возвращает TRUE в случае успешной вставки и FALSE в случае неудачи
int ct_pop(CONST_TIME_STACK * cts);

// Просимор вершины стека
// Возвращает значение вершины стека, если оно существует, и FALSE в случае неудачи
int ct_top(CONST_TIME_STACK * cts);

// Просимор максимального значения в стеке
// Возвращает максимальное значение в стеке, если оно существует, и FALSE в случае неудачи
int ct_max(CONST_TIME_STACK * cts);

#endif //SBER_STACK_MAX_FUCTIONS_H
