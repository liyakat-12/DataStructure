#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

int main() {
    Node* head = NULL;
 int elements ;
 printf("enter the elments you want to enter:");
    int value;
    printf("Enter the value to insert: ");
    scanf("%d", &value);

    insert(&head, value);

    printf("Linked list: ");
    Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
