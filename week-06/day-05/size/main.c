#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node_t;

void print_list(node_t *node);

int size(node_t *node);

int main()
{
    node_t *head = (node_t *) malloc(sizeof(node_t));
    node_t *second = (node_t *) malloc(sizeof(node_t));
    node_t *third = (node_t *) malloc(sizeof(node_t));
    node_t *fourth = (node_t *) malloc(sizeof(node_t));
    node_t *fifth = (node_t *) malloc(sizeof(node_t));

    head->value = 0;
    head->next = second;
    second->value = 1;
    second->next = third;
    third->value = 2;
    third->next = fourth;
    fourth->value = 3;
    fourth->next = fifth;
    fifth->value = 4;
    fifth->next = NULL;

    int result = size(head);
    printf("%d\n", result);

    return 0;
}

void print_list(node_t *node)
{
    while (node != NULL) {
        printf("%d\n", node->value);
        node = node->next;
    }
}

int size(node_t *node)
{
    int counter = 0;
    while (node != NULL) {
        counter++;
        node = node->next;
    }
    return counter;
}