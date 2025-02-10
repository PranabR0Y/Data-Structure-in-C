#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *right,*left;
};
struct node *create_node(int item)
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=item;
    n->right=NULL;
    n->left=NULL;
    return n;
}
void add_right(struct node *parent,struct node *child)
{
    parent->right=child;
}
void add_left(struct node *parent,struct node *child)
{
    parent->left=child;
}
struct node *create_tree()
{
    struct node *two=create_node(2);
    struct node *seven=create_node(7);
    struct node *nine=create_node(9);
    add_right(two,nine);
    add_left(two,seven);

    struct node *one=create_node(1);
    struct node *six=create_node(6);
    add_left(seven,one);
    add_right(seven,six);

    struct node *five=create_node(5);
    struct node *ten=create_node(10);
    add_left(six,five);
    add_right(six,ten);

    struct node *eight=create_node(8);
    add_right(nine,eight);

    struct node *three=create_node(3);
    struct node *four=create_node(4);
    add_right(eight,four);
    add_left(eight,three);

    return two;
}

void pre_order(struct node *Node)//editorial video of geeksforgeeks
{
   if(Node==NULL)return;//root->left->right
   printf("%d ",Node->data);
   
   pre_order(Node->left);
   pre_order(Node->right);
}
void post_order(struct node *Node)
{
    if(Node==NULL)return;//left->right->root
    post_order(Node->left);
    post_order(Node->right);
    printf("%d ",Node->data);
}
void in_order(struct node *Node)
{
    if(Node==NULL)return;//left->root->right
    in_order(Node->left);
    printf("%d ",Node->data);
    in_order(Node->right);
}
int count(struct node *root)
{
    if(root==NULL)return 0;
    else{
        return 1+count(root->left)+count(root->right);
    }
}
int main()
{
    struct node *root=create_tree();
    printf("Pre_order:\n");
    pre_order(root);
    printf("%d",count(root));
    printf("\nPost_order:\n");
    post_order(root);
    printf("\nIn_order\n");
    in_order(root);

    return 0;
}
