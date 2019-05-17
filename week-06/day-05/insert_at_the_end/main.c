#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

void print_list(node_t *node);

void append(node_t *node, int number);

int main()
{
    node_t *head = NULL;
    node_t *second = NULL;
    node_t *third = NULL;

    head = (node_t *) malloc(sizeof(node_t));
    second = (node_t *) malloc(sizeof(node_t));
    third = (node_t *) malloc(sizeof(node_t));

    head->data = 0;
    head->next = second;

    second->data = 1;
    second->next = third;

    third->data = 2;
    third->next = NULL;

    append(head, 3);

    print_list(head);

    return 0;
}

void print_list(node_t *node)
{
    while (node != NULL) {
        printf("%d\n", node->data);
        node = node->next;
    }
}

void append(node_t *node, int number)
{
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->data = number;
    new_node->next = NULL;

    while (node->next != NULL) {
        node = node->next;
    }
    node->next = new_node;
}