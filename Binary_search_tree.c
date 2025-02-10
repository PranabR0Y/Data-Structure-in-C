#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *right,*left;

};
struct Node* create_node(int item)
{
    struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=item;
    new_node->left=new_node->right=NULL;
    return new_node;
}
struct Node* insert_node(struct Node* root,int data)
{
    if(root==NULL)
        root=create_node(data);
    else if(data<=root->data)
        root->left=insert_node(root->left,data);
    else
        root->right=insert_node(root->right,data);
    return root;

}
void traverse(struct Node *node)//pre_order
{
    if(node==NULL)return;
    printf("%d ",node->data);
    traverse(node->left);
    traverse(node->right);
}
void traverse2(struct Node *root)//post_order
{
    if(root==NULL)return;
    traverse2(root->left);
    traverse2(root->right);
    printf("%d ",root->data);
}
void in_order(struct Node *node)//left->root->right
{
    if(node==NULL)return;
    in_order(node->left);
    printf("%d ",node->data);
    in_order(node->right);
}
int find_min(struct Node *root)
{
    if(root==NULL)
    {
        printf("Tree is empty\n");
        return -1;
    }
    int temp;
    while(root!=NULL)
    {
        temp=root->data;
        root=root->left;
    }
    return temp;
}
int find_max(struct Node *root)
{
    if(root==NULL)
    {
        printf("Tree is empty\n");
        return -1;
    }
    int temp;
    while(root!=NULL)
    {
        temp=root->data;
        root=root->right;
    }
    return temp;
}

int main()
{
    struct Node *root=NULL;
    root=insert_node(root,30);
    root=insert_node(root,20);
    root=insert_node(root,10);
    root=insert_node(root,15);
    root=insert_node(root,25);
    root=insert_node(root,23);
    root=insert_node(root,39);
    root=insert_node(root,35);
    root=insert_node(root,42);
    root=insert_node(root,35);
    traverse2(root);
    printf("\n");
    traverse2(root);
    printf("\n");
    in_order(root);
    printf("\n");
    printf("Min element %d\n",find_min(root));
    printf("Maximum element %d\n",find_max(root));


    return 0;
}
