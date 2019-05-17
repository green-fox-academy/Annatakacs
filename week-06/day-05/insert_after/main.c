#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node_t;

void print_list(node_t *node);

void insert_after(node_t *node, int value, node_t *node1);

int main()
{
    node_t *head = (node_t *) malloc(sizeof(node_t));
    node_t *second = (node_t *) malloc(sizeof(node_t));
    node_t *third = (node_t *) malloc(sizeof(node_t));

    head->data = 0;
    head->next = second;
    second->data = 1;
    second->next = third;
    third->data = 2;
    third->next = NULL;

    insert_after(head, 5, second);
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

void insert_after(node_t *node, int value, node_t *node1)
{
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->data = value;
    while (node != node1) {
        node = node->next;
    }
    new_node->next = node->next;
    node->next = new_node;
}