#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *tree;
void create_tree(struct node *);
struct node *insertElement(struct node *, int);
void preordertraversal(struct node *);
void inordertraversal(struct node *);
void postordertraversal(struct node *);
struct node *deleteelement(struct node *, int);
int main()
{
    int op, val;
    struct node *ptr;
    create_tree(tree);
    for (;;)
    {
        printf("\n*******MAIN MENU*********\n");
        printf("\n1. Insert Element");
        printf("\n2.PreOrder Traversal");
        printf("\n3.Inorder Traversal");
        printf("\n4.PostOrder Traversal");
        printf("\n5.Delete Element");
        printf("\n6.Exit");
        printf("\nEnter an Option : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
        {
            printf("\n Enter Data : ");
            scanf("%d", &val);
            tree = insertElement(tree, val);
            break;
        }
        case 2:
        {
            printf("\n Preoder Traversal : ");
            preordertraversal(tree);
            break;
        }
        case 3:
        {
            printf("\n Inorder Traversal : ");
            inordertraversal(tree);
            break;
        }
        case 4:
        {
            printf("\n PostOrder Traversal : ");
            postordertraversal(tree);
            break;
        }
        case 5:
        {
            printf("Enter the Element to be deleted : ");
            scanf("%d", &val);
            tree = deleteelement(tree, val);
            printf("\n Deleted Succesfully...");
            break;
        }
        case 6:
        {
            exit(-1);
            break;
        }
        default:
            printf("Invalid Option!!!");
        }
    }
}
void create_tree(struct node *tree)
{
    tree = NULL;
}

struct node *insertElement(struct node *tree, int val)
{
    struct node *ptr, *nodeptr, *parentptr;
    ptr = malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if (tree == NULL)
    {
        tree = ptr;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
    {
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (val < nodeptr->data)
            {
                nodeptr = nodeptr->left;
            }
            else
            {
                nodeptr = nodeptr->right;
            }
        }
        if (val < parentptr->data)
            parentptr->left = ptr;
        else
            parentptr->right = ptr;
    }
    return tree;
}
void preordertraversal(struct node *tree)
{
    if (tree != NULL)
    {

        printf("\n%d\n", tree->data);
        preordertraversal(tree->left);
        preordertraversal(tree->right);
    }
}
void inordertraversal(struct node *tree)
{
    if (tree != NULL)
    {
        inordertraversal(tree->left);
        printf("\n%d\n", tree->data);
        inordertraversal(tree->right);
    }
}
void postordertraversal(struct node *tree)
{
    if (tree != NULL)
    {
        postordertraversal(tree->left);
        postordertraversal(tree->right);
        printf("\n%d \n", tree->data);
    }
}
struct node *deleteelement(struct node *tree, int val)
{
    struct node *cur, *suc, *psuc, *parent, *ptr;
    if (tree->left == NULL)
    {
        printf("\n tree is Empty ");
        return (tree);
    }
    parent = tree;
    cur = tree->left;
    while (cur != NULL && val != cur->data)
    {
        parent = cur;
        cur = (val < cur->data) ? cur->left : cur->right;
    }
    if (cur == NULL)
    {
        printf("\n The given value is not present !!!");
        return (tree);
    }
    if (cur->left == NULL)
        ptr = cur->right;
    else if (cur->right == NULL)
        ptr = cur->left;
    else
    {
        psuc = cur;
        cur = cur->left;
        while (suc->left != NULL)
        {
            psuc = suc;
            suc = suc->left;
        }
        if (cur == psuc)
        {
            suc->left = cur->right;
        }
        else
        {
            suc->left = cur->right;
            psuc->left = suc->right;
            suc->right = cur->right;
        }
        ptr = suc;
    }
    if (parent->left == cur)
        parent->left = ptr;
    else
        parent->right = ptr;
    free(cur);
    return tree;
}
