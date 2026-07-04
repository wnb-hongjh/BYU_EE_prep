#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

int main()
{
    struct node *a = malloc(sizeof(struct node));
    struct node *b = malloc(sizeof(struct node));
    struct node *c = malloc(sizeof(struct node));
    struct node *d = malloc(sizeof(struct node));

    a->value = 10;
    b->value = 20;
    c->value = 30;
    d->value = 40;

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;

    struct node *current = a;
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }

    free(a);
    a = NULL;
    free(b);
    b = NULL;
    free(c);
    c = NULL;
    free(d);
    d = NULL;

    return 0;
}