# include<stdio.h>
# include<stdlib.h>
typedef struct LinkedList node;
typedef struct LinkedList
{
    char name[20];
    char usn[12];
    char phone[12];
    char pgm[5];
    int sem;
    node *next;
}node;
node *first,*temp,*ptr;
void create_node()
{
    temp=(node*)malloc(sizeof(node));
    printf("\n Enter the [usn,name,pgm,sem,Phone number]");
    scanf("%s %s %s %d %s",temp->usn,temp->name,temp->pgm,&temp->sem,temp->phone);
    temp->next=NULL;
}
void create_list(int n)
{
    for(int i=0;i<n;i++)
    {
        create_node();
        if(first!=NULL)
            temp->next=first;
        first=temp;
    }
}
void print_list()
{
    for(ptr=first;ptr!=NULL;ptr=ptr->next)
        printf("\n %s %s %s %d %s->",ptr->usn,ptr->name,ptr->pgm,ptr->sem,ptr->phone);
    printf("NULL")
}
void insert_front()
{
    create_node();
    if(first!=NULL)
        temp->next=first;
    first=temp;
}
void insert_last()
{
create_node();
    ptr=first;
    while(ptr->next!=NULL)
        {
        ptr=ptr->next;
        }
    ptr->next=temp;
}
void delete_front()
{
    temp=first;
    printf("\n The Deleted Node: %s %s %s %d %s",temp->usn,temp->name,temp->pgm,temp->sem,temp->phone);
    first=first->next;
    free(temp);
}
void delete_last()
{
    node *prev;
    ptr=first;
    while(ptr->next!=NULL)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    temp=ptr;
    prev->next=NULL;
    free(temp);
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n---------Menu----------------------------");
        printf("\n1.Create List
        \t 2.Insert Front
        \t 3.Delete Front
        \t 4.Insert Last
        \t 5. Delete Last
        \t 6.  Stack Operation - Push
        \t 7. Stack Operation - Pop
        \t 8. Display 9.Exit");
        printf("\nEnter your choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                create_list(4);
                print_list();
                break;
            case 2:
           
                insert_front();
                print_list();
                break;
            case 3:
                delete_front();
                print_list();
                break;
            case 4:
                insert_last();
                print_list();
                break;
            case 5:
                delete_last();
                print_list();
                break;
            case 6:
            insert_front();
                print_list();
                break;
            case 7:
                delete_front();
                print_list();
                break;
            case 8:
                print_list();
                break;
            default:
                return 0;
        }
    }
    return 0;
}
