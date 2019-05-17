#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node_t;

void print_list(node_t *node);

node_t *delete_head(node_t *node);

int main()
{
    node_t *head = (node_t *) malloc(sizeof(node_t));
    node_t *second = (node_t *) malloc(sizeof(node_t));
    node_t *third = (node_t *) malloc(sizeof(node_t));

    head->value = 0;
    head->next = second;
    second->value = 1;
    second->next = third;
    third->value = 2;
    third->next = NULL;

    print_list(head);
    printf("------------------------------------\n");
    head = delete_head(head);
    print_list(head);

    return 0;
}

void print_list(node_t *node)
{
    while (node != NULL) {
        printf("%d\n", node->value);
        node = node->next;
    }
}

node_t *delete_head(node_t *node)
{
    node_t *temp = node;
    if (node->next != NULL) {
        node = temp->next;
        free(temp);
    } else {
        printf("The list is empty\n");
    }
    return node;
}