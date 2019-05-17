#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *new;
} node_t;

void insert_to_beginning(node_t *node, int number);

void print_struct(node_t *node);

int main()
{
    node_t *head = NULL;
    node_t *second = NULL;
    node_t *third = NULL;

    head = (node_t *) malloc(sizeof(node_t));
    second = (node_t *) malloc(sizeof(node_t));
    third = (node_t *) malloc(sizeof(node_t));

    head->data = 0;
    head->new = second;

    second->data = 1;
    second->new = third;

    third->data = 2;
    third->new = NULL;

    insert_to_beginning(head, 5);

    print_struct(head);

    return 0;
}

void print_struct(node_t *node)
{
    while (node != NULL) {
        printf("%d\n", node->data);
        node = node->new;
    }
}

void insert_to_beginning(node_t *node, int number)
{
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->data = number;
    new_node->new = node->new;
    node->new = new_node;
}