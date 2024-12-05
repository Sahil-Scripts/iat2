#include<stdio.h>
# include<stdlib.h>
struct BST
{
    int info;
    struct BST *left,*right;
};
typedef struct BST node;
node *root=NULL,*p,*prev,*temp;
void insert(int num)
{
    p=(node*)malloc(sizeof(node));
    p->info=num;
    p->left=p->right=NULL;
    if(root==NULL)
    {
        root=p;
        return;
    }
    temp=root;
    while(temp!=NULL)
    {    
        if(num>temp->info)
        {
            prev=temp;
            temp=temp->right;
        }
        else
        if(num<temp->info)
        {
            prev=temp;
            temp=temp->left;
        }
        else
        {
            printf("Duplicate Values are not allowed");
            return;
        }
    }
    if(num>prev->info)
    prev->right=p;
    if(num<prev->info)
    prev->left=p;
}
void preorder(node *temp)
{
    if(temp!=NULL)
    {
        printf("\t%d",temp->info);
        preorder(temp->left);
        preorder(temp->right);
    }
}
void postorder(node *temp)
{
if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("\t%d",temp->info);
    }
}
void inorder(node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("\t%d",temp->info);
        inorder(temp->right);
    }
}
void search(node *temp,int data)
{
    if(temp==NULL)
    printf("\nElement not found.........");
    else if(data<temp->info)
    search(temp->left,data);
    else if(data>temp->info)
    search(temp->right,data);
    else
    printf("\nElement found......");
}
void traversal()
{
    printf("\n INORDER:");
    inorder(root);
    printf("\n PREORDER:");
    preorder(root);
    printf("\n POSTORDER:");
    postorder(root);
}
int main()
{
    int choice,n,i,ser;
    while(choice)
    {
        printf("\n-----------------BINARY SERACH TREE---------------------------------");
        printf("\n1.CREATE TREE 2.TRAVERSAL 3.SEARCH ELEMENT 4.Exit");
        printf("\n--------------------------------------------------------------------------------");
        printf("Enter your choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            for(i=1;i<=12;i++)
            {
                printf("\n Enter the data to be inserted into the tree:");
                scanf("%d",&n);
                insert(n);
            }
            break;
            case 2:
            traversal();
            break;
            case 3:
            printf("\n Enter the search element:");
            scanf("%d",&ser);
            search(root,ser);
            break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice. Try again.");
                break;
        }
    }
    return 0;
}
