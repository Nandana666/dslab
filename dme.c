#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void display() {
    if(head == NULL) {
        printf("\nList is empty");
    } else {
        struct node* temp = head;
        printf("\nElements are:");
        while(temp != NULL) {
            printf("\n%d", temp->data);
            temp = temp->next;
        }
    }
}

void insert_begin() {
    int data;
    printf("\nEnter element to be inserted: ");
    scanf("%d", &data);
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    newnode->prev = NULL;
    if (head != NULL) {
        head->prev = newnode;
    }
    head = newnode;
    display();
}

void insert_end() {
    int data;
    printf("\nEnter element to be inserted: ");
    scanf("%d", &data);
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    display();
}

void insert_anywhere() {
    int data, p;
    printf("\nEnter the position to be inserted: ");
    scanf("%d", &p);
    
    if(p == 1) {
        insert_begin();
    } else {
        struct node *temp = head;
        int c = 1;
        while (temp != NULL && c < p) {
            temp = temp->next;
            c++;
        }
        if (temp == NULL) {
            printf("\nPosition exceeds list size. Inserting at the end.\n");
            insert_end();
        } else {
            printf("\nEnter element to be inserted: ");
            scanf("%d", &data);
            struct node *newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = data;
            newnode->next = temp;
            newnode->prev = temp->prev;
            if (temp->prev != NULL) {
                temp->prev->next = newnode;
            }
            temp->prev = newnode;
            if (temp == head) {
                head = newnode;
            }
            display();
        }
    }
}

void delete_begin() {
    if (head == NULL) {
        printf("\nList is empty");
    } else {
        struct node *temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        printf("\nDeleted element from the beginning");
        display();
    }
}

void delete_end() {
    if (head == NULL) {
        printf("\nList is empty");
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        if (temp->prev != NULL) {
            temp->prev->next = NULL;
        } else {
            head = NULL;
        }
        free(temp);
        printf("\nDeleted element from the end");
        display();
    }
}

void delete_anywhere() {
    int p;
    printf("\nEnter the position to be deleted: ");
    scanf("%d", &p);

    if (p == 1) {
        delete_begin();
    } else {
        struct node *temp = head;
        int c = 1;
        while (temp != NULL && c < p) {
            temp = temp->next;
            c++;
        }
        if (temp == NULL) {
            printf("\nPosition exceeds list size");
        } else {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            if (temp == head) {
                head = temp->next;
            }
            free(temp);
            printf("\nDeleted element at position %d", p);
            display();
        }
    }
}

int main() {
    int ch;
    do {
        printf("\nMENU\n1. Insert at beginning\n2. Insert anywhere\n3. Insert at end\n4. Delete from beginning\n5. Delete from anywhere\n6. Delete from end\n7. Display\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: insert_begin(); break;
            case 2: insert_anywhere(); break;
            case 3: insert_end(); break;
            case 4: delete_begin(); break;
            case 5: delete_anywhere(); break;
            case 6: delete_end(); break;
            case 7: display(); break;
            case 8: printf("\nExit\n"); exit(0);
            default: printf("\nInvalid choice");
        }
    } while(ch != 8);
    return 0;
}
