#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

// Function to insert a node at a specific position in the circular linked list
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    struct Node* newNode = createNode(data);

    if (position == 1) {
        insertAtBeginning(head, data);
    } else {
        struct Node* temp = *head;
        for (int i = 1; i < position - 1; i++) {
            if (temp == NULL || temp->next == *head) {
                printf("Invalid position\n");
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to delete a node from the end of the circular linked list
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        free(temp);
        *head = NULL;
    } else {
        prev->next = *head;
        free(temp);
    }
}

// Function to delete a node from the beginning of the circular linked list
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* last = *head;

    while (last->next != *head) {
        last = last->next;
    }

    if (temp->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        last->next = temp->next;
        *head = temp->next;
        free(temp);
    }
}

// Function to delete a node from a specific position in the circular linked list
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 1) {
        deleteAtBeginning(head);
    } else {
        struct Node* temp = *head;
        struct Node* prev = NULL;

        for (int i = 1; i < position; i++) {
            if (temp == NULL || temp->next == *head) {
                printf("Invalid position\n");
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        free(temp);
    }
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

// Function to free the memory allocated for the circular linked list
void freeList(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    struct Node* temp = *head;
    struct Node* nextNode;

    do {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != *head);

    *head = NULL;
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    display(head);  // Output: 1 2 3

    insertAtBeginning(&head, 0);
    display(head);  // Output: 0 1 2 3

    insertAtPosition(&head, 2.5, 3);
    display(head);  // Output: 0 1 2 2.5 3

    deleteAtEnd(&head);
    display(head);  // Output: 0 1 2 2.5

    deleteAtBeginning(&head);
    display(head);  // Output: 1 2 2.5

    deleteAtPosition(&head, 2);
    display(head);  // Output: 1 2.5

    // Free the memory allocated for the circular linked list
    freeList(&head);

    return 0;
}
