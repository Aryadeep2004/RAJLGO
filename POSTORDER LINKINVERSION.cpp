#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

typedef struct node 
{
    int data;
    unsigned tag:1;
    struct node *left;
    struct node *right;
} node;

typedef struct 
{
    node *root;
} BST;

node* create_node(int item) 
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = item;
    new_node->tag = 0;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(node **ptr, int data) 
{
    if (*ptr == NULL) 
    {
        *ptr = create_node(data);
    } 
    else if (data < (*ptr)->data) 
    {
        insert_node(&(*ptr)->left, data);
    } 
    else if (data > (*ptr)->data) 
    {
        insert_node(&(*ptr)->right, data);
    }
}

void insert(BST *tree, int item) 
{
    insert_node(&tree->root, item);
}

void posttraversal(BST *tree) 
{
    node *pres = tree->root;
    node *prev = NULL;
    node *tmp;
    int flag = 0;
    
    while (prev != NULL || flag != 2) 
    {
        if (pres->left != NULL && flag == 0) 
        {
            pres->tag = 0;
            tmp = pres->left;
            pres->left = prev;
            prev = pres;
            pres = tmp;
            flag = 0;
        } 
        else 
        {
            if (pres->right != NULL && flag != 2)
            {
                pres->tag = 1;
                tmp = pres->right;
                pres->right = prev;
                prev = pres;
                pres = tmp;
                flag = 0;
            } 
            else if (prev != NULL && prev->tag == 0) 
            {
                tmp = prev->left;
                prev->left = pres;
                pres = prev;
                prev = tmp;
                flag = 1;
            } 
            else if (prev != NULL && prev->tag == 1) 
            {
                pres->tag = 0;
                tmp = prev->right;
                prev->right = pres;
                pres = prev;
                prev = tmp;
                flag = 2;
            }
        }
        if (flag == 2 || (pres->left == NULL && pres->right == NULL) || (pres->right == NULL && flag == 1)) 
        {
            printf("%d ", pres->data);
            flag = 2;
        }
    }
}

int main() 
{
    BST tree;
    tree.root = NULL;
    int ch, x = 0;
    
    while (1) 
    {
        printf("\nEnter 1 to insert // Enter 2 to print postorder traversal // Enter 3 to exit: ");
        scanf("%d", &ch);
        
        switch (ch) 
        {
            case 1: 
            {
                int item;
                printf("Enter item to insert: ");
                scanf("%d", &item);
                insert(&tree, item);
                break;
            }
            case 2: 
                posttraversal(&tree);
                printf("\n");
                break;
            case 3: 
                x = -1;
                break;
            default: 
                printf("Wrong Input\n");
        }
        if (x == -1) 
        {
            break;
        }
    }

    return 0;
}

