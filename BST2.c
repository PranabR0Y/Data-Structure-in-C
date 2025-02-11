#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *right,*left,*parent;
};
struct node *create_node(int item)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)
        exit(1);
    new_node->data=item;
    new_node->left=new_node->right=new_node->parent=NULL;
    return new_node;
}
void add_right(struct node *ptr,struct node *child)
{
    ptr->right=child;
    if(child!=NULL)
    {
        child->parent=ptr;
    }

}
void add_left(struct node *ptr,struct node *child)
{
    ptr->left=child;
    if(child!=NULL)
        child->parent=ptr;
}
struct node* insert(struct node *root,struct node *Node)
{
    struct node *parent,*current_node;
    if(root==NULL)
    {
        root=Node;
        return root;
    }
    parent=NULL;
    current_node=root;
    while(current_node!=NULL)
    {
        parent=current_node;
        if(Node->data<current_node->data)
            current_node=current_node->left;
        else
            current_node=current_node->right;

    }
    if(Node->data<parent->data)
        add_left(parent,Node);
    else
        add_right(parent,Node);
    return root;
}
void traverse(struct node *root)
{
    if(root==NULL)return;
    printf("%d ",root->data);
    traverse(root->left);
    traverse(root->right);
}
void traverse2(struct node *root)
{
    if(root==NULL)return;
    traverse2(root->left);
    printf("%d ",root->data);
    traverse2(root->right);
  
}

int main()
{
    int a[]={5,17,3,7,4,1,19,12};
    struct node *root,*Node;
    root=create_node(10);
    for(int i= 0;i<8;i++)
    {
        Node=create_node(a[i]);
        root=insert(root,Node);
    }

    traverse(root);
    printf("\n");
    traverse2(root);






    return 0;
}
