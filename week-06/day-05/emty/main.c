#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node_t;

int is_empty(node_t *node);

int main()
{
    node_t *head = (node_t *) malloc(sizeof(node_t));
    node_t *second = (node_t *) malloc(sizeof(node_t));

    head->value = 0;
    head->next = second;
    second->value = 1;
    second->next = NULL;

    int result = is_empty(head);
    if (result == 1) {
        printf("The list is empty");
    } else {
        printf("The list isn't empty");
    }

    return 0;
}

int is_empty(node_t *node)
{
    if (node->next == NULL)
        return 1;
    else
        return 0;
}