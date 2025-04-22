#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Element {
    int value;
    struct Element* next;
} Element;


struct Element* insert(struct Element* head, int x) {
    struct Element* p = (struct Element*)malloc(sizeof(struct Element));
    p->value = x;
    p->next = NULL;
    if (head == NULL) {
        head = p;
    } else {
        struct Element* l = head;
        while (l->next != NULL) l = l->next;
        l->next = p;
    }
    return head;
}

void display(struct Element* head) {
    struct Element* c = head;
    if (head == NULL) printf("\nThe list is empty!\n");
    else {
        printf("\nThe content of the list is : ");
        while (c != NULL) {
            printf("%d ", c->value);
            c = c->next;
        }
        printf("\n");
    }
}

bool exist(struct Element* head, int x) {
    struct Element* p = head;
    while (p != NULL) {
        if (p->value == x) return true;
        p = p->next;
    }
    return false;
}

int size(struct Element* head) {
    int counter = 0;
    struct Element* p = head;
    while (p != NULL) {
        counter++;
        p = p->next;
    }
    return counter;
}

int numberOcc(struct Element* head, int x) {
    int counter = 0;
    struct Element* p = head;
    while (p != NULL) {
        if (p->value == x) counter++;
        p = p->next;
    }
    return counter;
}

struct Element* insertInTheHead(struct Element* head, int x) {
    struct Element* p = (struct Element*)malloc(sizeof(struct Element));
    p->value = x;
    p->next = head;
    head = p;
    return head;
}

struct Element* delete(struct Element* head, int x) {
    if (head == NULL) {
        printf("The list is empty!\n");
        return head;
    }
    struct Element* p = head;
    struct Element* prev = NULL;
    while (p != NULL && p->value != x) {
        prev = p;
        p = p->next;
    }
    if (p == NULL) {
        printf("X is not in the list!\n");
        return head;
    }
    if (p == head) {
        head = head->next;
    } else {
        prev->next = p->next;
    }
    free(p);
    return head;
}

struct Element* deleteAllOccurences(struct Element* head, int x) {
    struct Element* p = head;
    struct Element* prev = NULL;
    while (p != NULL) {
        if (p->value == x) {
            if (p == head) {
                head = head->next;
                free(p);
                p = head;
            } else {
                prev->next = p->next;
                free(p);
                p = prev->next;
            }
        } else {
            prev = p;
            p = p->next;
        }
    }
    return head;
}

int main() {
    struct Element* head = NULL;
    int choice, x;

    do {
        printf("\n\nMenu:");
        printf("\n1. Insert at the end");
        printf("\n2. Insert at the head");
        printf("\n3. Display the list");
        printf("\n4. Delete an element");
        printf("\n5. Delete all occurrences of an element");
        printf("\n6. Size of the list");
        printf("\n7. Number of occurrences of an element");
        printf("\n0. Exit");
        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter value to insert at the end: ");
                scanf("%d", &x);
                head = insert(head, x);
                break;
            case 2:
                printf("\nEnter value to insert at the head: ");
                scanf("%d", &x);
                head = insertInTheHead(head, x);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("\nEnter value to delete: ");
                scanf("%d", &x);
                head = delete(head, x);
                break;
            case 5:
                printf("\nEnter value to delete all its occurrences: ");
                scanf("%d", &x);
                head = deleteAllOccurences(head, x);
                break;
            case 6:
                printf("\nThe size of the list is: %d\n", size(head));
                break;
            case 7:
                printf("\nEnter value to count occurrences: ");
                scanf("%d", &x);
                printf("\nThe number of occurrences of %d is: %d\n", x, numberOcc(head, x));
                break;
            case 0:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice! Please try again.");
        }
    } while (choice != 0);
}
