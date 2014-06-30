/*
** main.c for Perso in /Users/leroy_v/Perso
**
** Made by vincent leroy
** Login  <leroy_v@epitech.eu>
**
** Started on  Mar jui 24 20:50:18 2014 vincent leroy
** Last update Jeu jui 26 22:24:52 2014 vincent leroy
*/

#include <stdio.h>
#include <stdlib.h>

#include "bind.h"

struct s_node
{
    void *data;
    struct s_node *next;
};

typedef struct s_list
{
    void *data;
    struct s_node *first;

    void (*push_front)(void*);
} t_list;

void list_push_front(t_list *list, void *data)
{
    printf("list = %p, data = %p\n", list, data);
}

t_list* list_create(void *data)
{
    t_list *l = calloc(1, sizeof(t_list));

    l->data = data;
    l->push_front = bind1(void, list_push_front, void*, l);

    return l;
}

int add(int a, int b)
{
    return a + b;
}

int main()
{
    t_list *list = list_create(NULL);

    list->push_front(NULL);

    int (*incr)(int) = bind1(int, &add, int, 1);
    //int (*test2)(int, int) = bind(int, &add2, 2);

    printf("incr(3)  = %d\n", (*incr)(3));
    //printf("test2(4, 6) = %d\n", (*test2)(4, 6));

    return 0;
}
