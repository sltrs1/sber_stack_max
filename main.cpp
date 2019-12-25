/*
 * Стек с константным временем доступа к максимальному элементу
 * реализован при помощи двух обычных стеков.
 * Первый стек используется для хранения добавляемых значений.
 * Второй стек используется для хранения максимального значения.
 * Таким образом в любой момент максимальны элемент доступен за константное время,
 * поскольку максимальный элемент всегда хранится в вершине второго стека,
 * а операци доступа к вершине стека выполняется за константное время.
 * Минус такого решения - удвоенный расход памяти (на второй стек)
 * и усложнение операций вставки и удаления (хотя они все еще выполняются за константное время)
 *
 * Из особенностей реализации стоит отметить, что 0 и 1 используются как служебные значения,
 * и поэтому не рекомендуется использовать их как значения, помещаемые в стек
 *
 * Решение написано на Си без использования возможностей С++, т.к. собеседование проводилось на позицию разработчика Си.
 *
 * */


#include "defs.h"
#include "functions.h"


int main() {

    CONST_TIME_STACK cts;

    init_ct_stack(&cts);

    printf("Pushing values to stack:\n");
    ct_push(&cts, 10);
    printf("Top = %i, Max = %i\n",ct_top(&cts), ct_max(&cts));

    ct_push(&cts, 20);
    printf("Top = %i, Max = %i\n",ct_top(&cts), ct_max(&cts));

    ct_push(&cts, 30);
    printf("Top = %i, Max = %i\n",ct_top(&cts), ct_max(&cts));

    ct_push(&cts, 5);
    printf("Top = %i, Max = %i\n",ct_top(&cts), ct_max(&cts));

    ct_push(&cts, 15);
    printf("Top = %i, Max = %i\n",ct_top(&cts), ct_max(&cts));

    ct_push(&cts, 50);
    printf("Top = %i, Max = %i\n",ct_top(&cts), ct_max(&cts));

    printf("---------------------\n");

    printf("Popping values from stack:\n");
    ct_pop(&cts);
    printf("Top = %i, Max = %i\n",ct_top(&cts), ct_max(&cts));

    ct_pop(&cts);
    printf("Top = %i, Max = %i\n",ct_top(&cts), ct_max(&cts));

    ct_pop(&cts);
    printf("Top = %i, Max = %i\n",ct_top(&cts), ct_max(&cts));

    ct_pop(&cts);
    printf("Top = %i, Max = %i\n",ct_top(&cts), ct_max(&cts));

    ct_pop(&cts);
    printf("Top = %i, Max = %i\n",ct_top(&cts), ct_max(&cts));

    ct_pop(&cts);
    printf("Top = %i, Max = %i\n",ct_top(&cts), ct_max(&cts));

    ct_pop(&cts);
    printf("Top = %i, Max = %i\n",ct_top(&cts), ct_max(&cts));

    return 0;
}