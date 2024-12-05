#include<stdio.h>
#include<stdlib.h>  // For malloc

typedef struct dll node;
typedef struct dll {
    char ssn[15], name[15], dept[15], desg[15], phone[15];
    int sal;
    struct dll *rlink, *llink;
} node;

node *head = NULL, *last = NULL, *temp = NULL;
int count = 0;
void create_node() {
    temp = (node*)malloc(sizeof(node));
    printf("\n Enter [ssn name department desg. salary phone]: ");
    scanf("%s %s %s %s %d %s", temp->ssn, temp->name, temp->dept, temp->desg, &temp->sal, temp->phone);
    temp->rlink = NULL;
    temp->llink = NULL;
    count++;
}
void insert_last() {
    create_node();
    if (head == NULL) {
         head = temp;
        last = temp;
    } else {
        temp->llink = last;
        last->rlink = temp;
        last = temp;
    }
}
void create_list(int n) {
    for (int i = 0; i < n; i++) {
        insert_last();
    }
}
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("HEAD<=>");
    for (node *p = head; p != NULL; p = p->rlink) {
        printf("[%s %s %s %s %d %s]<=>", p->ssn, p->name, p->dept, p->desg, p->sal, p->phone);
    }
    printf("HEAD\n");
    printf("\t COUNT: %d\n", count);
}

void insert_front() {
    create_node();
    if (head == NULL) {
        head = temp;
        last = temp;
    } else {
        temp->rlink = head;
        head->llink = temp;
        head = temp;
    }
}

void delete_front() {
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    if (head == last) {  // Only one element
        head = last = NULL;
    }
    else {
        head = temp->rlink;
        head->llink = NULL;
    }
    free(temp);
    count--;
}
void delete_last() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = last;
    if (head == last) {  // Only one element
        head = last = NULL;
    } else {
        last = temp->llink;
        last->rlink = NULL;
    }
    free(temp);
    count--;
}

int main() {
    int choice;
    while (1) {
        printf("---------Menu----------------------------");
        printf("\n1. Create List\t 2. Insert Front\t 3. Delete Front\t 4. Insert Last \t 5. Delete Last\t 6. Display\t 7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_list(2);
                display();
                break;
            case 2:
                insert_front();
                display();
                break;
            case 3:
                delete_front();
                display();
                break;
            case 4:
                insert_last();
                display();
                break;
            case 5:
                delete_last();
                display();
                break;
            case 6:
                display();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
