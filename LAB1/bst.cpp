#include<iostream>
#include<stdlib.h>
using namespace std;
struct bst
{
    int data;
    struct bst *prev;
    struct bst *next;
};

struct bst* new_node (int data)
{
    struct bst* temp = (struct bst*)malloc(sizeof(struct bst*));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

struct bst* BST_insert (struct bst* node, int data)
{
    if (node == NULL)
        return new_node(data);
    else if (data < node->data)
        node->prev = BST_insert(node->prev,data);
    else
        node->next = BST_insert(node->next,data);

    return node;
}
void inorder(struct bst *node)
{
    if(node == NULL)
        return;
    else
    {
        inorder(node->prev);
        cout<<" "<<node->data<<" ";
        inorder(node->next);   
    }
    
}
void preorder(struct bst *node)
{
    if(node == NULL)
        return;
    else
    {
        cout<<" "<<node->data<<" ";
        inorder(node->prev);
        inorder(node->next);   
    }
}
void postorder(struct bst *node)
{
    if(node == NULL)
        return;
    else
    {
        
        inorder(node->prev);
        inorder(node->next); 
        cout<<" "<<node->data<<" ";  
    }
}
int main()
{
    struct bst *root = NULL;
    int ans = 0;
    cout<<"Enter Data to be inserted in the Tree"<<endl;
    do
    {
        cout<<"Enter -1 to stop entering data"<<endl;
        cout<<"Enter your answer: ";
        cin>>ans;
        if(ans == -1)
            break;
        else
        {
            root = BST_insert (root,ans);
        }
        
    }while (ans!=-1);
    cout<<"Inorder Tree : ";
    inorder(root);
    cout<<endl<<"Preorder Tree : ";
    preorder(root);
    cout<<endl<<"Postorder Tree : ";
    postorder(root);
    return 0;
}