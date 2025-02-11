#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;//self referential structure which contains a pointer to structure of same type
};
struct node *create_node(int item,struct node *Node)
{
    Node=(struct node*)malloc(sizeof(struct node));
    if(Node==NULL)
        exit(1);
    Node->data=item;
    Node->link=NULL;
    return Node;

}
void append(struct node *Head,int item)
{
    struct node *new_node=create_node(item,Head);
    if(Head==NULL)
        exit(1);
     struct node *current=Head;
    while(current->link!=NULL)
    {
        current=current->link;
    }
    current->link=new_node;

}
struct node *add_begin(struct node *Head,int item)
{
    struct node *ptr=create_node(item,Head);
    ptr->data=item;
    ptr->link=Head;
    return ptr;
}
void add_position(struct node *Head,int item,int position)
{
    struct node *new_node=create_node(item,Head),*current;
    position--;
    while(position!=1){
        Head=Head->link;
        position--;

    }
    current=Head->link;
    Head->link=new_node;
    new_node->link=current;
}
struct node *delete_first(struct node *head)
{
    struct node* temp=head;
    head=head->link;
    free(temp);
    temp=NULL;
    return head;
}
void delete_last(struct node *head)
{
    struct node *temp;
    while(head->link!=NULL)
        {
            temp=head;
            head=head->link;

        }
       temp->link=NULL;

}
void print(struct node *head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        exit(1);
    }
    while(1)
    {
        printf("%d ",head->data);
        if(head->link==NULL)break;
        head=head->link;
    }
    printf("\n");
}
int main()
{
    struct node *head,*current;
    head=create_node(10,NULL);
    append(head,10);
    append(head,20);
    append(head,30);
    append(head,40);
    printf("Linked list is: \n");
    print(head);
    printf("Add new at begining\n");
    head=add_begin(head,1);
    print(head);
    add_position(head,100,2);
    print(head);
    head=delete_first(head);
    printf("Deleting first node\n");
    print(head);
    delete_last(head);
    print(head);


    return 0;
}
