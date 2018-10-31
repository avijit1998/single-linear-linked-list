#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* link;
}node;
node* head;
void main()
{
    head=NULL;//empty list
    insert(1,1);print();//1
    insert(2,2);print();//1 2
    insert(3,1);print();//3 1 2
    insert(4,2);print();//3 4 1 2
    insert_beg(5);print();//5 3 4 1 2
    insert_beg(6);print();//6 5 3 4 1 2
    insert_end(7);print();//6 5 3 4 1 2 7
    delete_node(2);print();//6 3 4 1 2 7
    delete_node(3);print();//6 3 1 2 7
    /*hey bro done something wrong here*/
    delete_beg();print();//3 1 2 7
    delete_end();print();//3 1 2
}
void insert(int data,int n)
{
    node* temp1=(node* )malloc(sizeof(node));
    temp1->data=data;
    temp1->link=NULL;
    if(n==1)
    {
        temp1->link=head;
        head=temp1;
        return;
    }
    node* temp2=(node* )malloc(sizeof(node));
    temp2=head;
    int i;
    for(i=0;i<n-2;i++)
    {
        temp2=temp2->link;
    }
    temp1->link=temp2->link;
    temp2->link=temp1;
}
void print()
{
    node* temp=(node*)malloc(sizeof(node));
    temp=head;
    printf("the list is:");
    while(1)
    {
        printf("%d ",temp->data);
        temp = temp->link;
        if(temp == NULL)
        break;
    }
    printf("
");
}

void delete_node(int pos)
{
    node* temp1 = (node*)malloc(sizeof(node));
    temp1 = head;
    if(pos==1)
    {
        head = temp1->link;
        free(temp1);
        return;
    }
    int i=0;
    for(i=0;i<pos-2;i++)
    {
        temp1=temp1->link;
    }
    node* temp2 = (node*)malloc(sizeof(node));
    temp2 = temp1->link;
    temp1->link = temp2->link;
    free(temp2);
}
void insert_beg(int x)
{
    node* temp1=(node* )malloc(sizeof(node));
    temp1->data=x;
    temp1->link=head;
    head = temp1;
}
void insert_end(int x)
{
    node* temp1=(node* )malloc(sizeof(node));
    temp1->data=x;
    temp1->link=NULL;
    node* temp=(node*)malloc(sizeof(node));
    temp=head;
    while(temp->link!= NULL)
    {
        temp = temp->link;
    }
    temp->link=temp1;
    return;
}
void delete_beg()
{
    node* temp=(node*)malloc(sizeof(node));
    temp=head;
    head=head->link;
    free(temp);
}
 void delete_end()
 {
     node* temp=(node*)malloc(sizeof(node));
     temp=head;
     node* temp1=(node*)malloc(sizeof(node));
     temp1=head;
     temp=temp->link;
     while(temp->link!= NULL)
     {
        temp1=temp1->link;
        temp = temp->link;
     }
     temp1->link=NULL;
     free(temp);
 }

