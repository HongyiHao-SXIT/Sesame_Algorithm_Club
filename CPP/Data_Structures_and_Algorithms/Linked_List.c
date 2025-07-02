#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

Node* create_node(int data) 
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_tail(Node** head, int data) 
{
    Node* new_node = create_node(data);
    if (*head == NULL) 
    {
        *head = new_node;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void print_list(Node* head) 
{
    Node* temp = head;
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void delete_node(Node** head, int target) 
{
    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != target) 
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (prev == NULL) 
    {
        *head = temp->next;
    } 
    else 
    {
        prev->next = temp->next;
    }

    free(temp);
}

void free_list(Node* head) 
{
    Node* temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() 
{
    Node* head = NULL;

    insert_tail(&head, 10);
    insert_tail(&head, 20);
    insert_tail(&head, 30);
    insert_tail(&head, 40);

    printf("Linked list: ");
    print_list(head);

    delete_node(&head, 20);

    printf("After deleting 20: ");
    print_list(head);

    free_list(head);
    return 0;
}