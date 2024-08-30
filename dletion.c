#include <stdio.h>
#include <malloc.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
int total = 0;
int inserted_values[100];
int deleted_values[100];
int inserted_count = 0;
int deleted_count = 0;

void insert(int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = head;
    head = new_node;
    total += value;
    inserted_values[inserted_count] = value;
    inserted_count++;
}
void delete(int value) {
    Node* current = head;
    Node* previous = NULL;
    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Element not found\n");
        return;
    }
    total -= current->data;
    deleted_values[deleted_count] = value;
    deleted_count++;
    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    printf("Total: %d\n", total);
}

void display() {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void print_inserted_values() {
    printf("Inserted values: ");
    for (int i = 0; i < inserted_count; i++) {
        printf("%d ", inserted_values[i]);
    }
    printf("\n");
}

void print_deleted_values() {
    printf("Deleted values: ");
    for (int i = 0; i < deleted_count; i++) {
        printf("%d ", deleted_values[i]);
    }
    printf("\n");
}
int main() {
    int choice, value;
    while (1) {
        printf("Enter 1 to insert, 2 to delete, 3 to display, 4 to exit: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(value);
        } else if (choice == 2) {
            printf("Enter value to delete: ");
            scanf("%d", &value);
            delete(value);
        } else if (choice == 3) {
            display();
        } else if (choice == 4) {
            print_inserted_values();
            print_deleted_values();
            return 0;
        } else {
            printf("Invalid choice\n");
        }
    }
}