#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node *left;
    struct node *right;
};

void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d->", root->key);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d->", root->key);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d->", root->key);
}
struct node *newnode(int key)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newnode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

struct node *minvalue(struct node *node)
{
    struct node *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
struct node *deletenode(struct node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deletenode(root->left, key);
    else if (key > root->key)
        root->right = deletenode(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = minvalue(root->right);
        root->key = temp->key;
        root->right = deletenode(root->right, temp->key);
    }
    return root;
}
int main()
{
    struct node *root = NULL;
    int ch, ele;
    do
    {
        printf("\n1. Insert \n2. Inorder Traversal \n3. Preorder Traversal");
        printf("\n4. Postorder Traversal \n5. Delete a node \n6. Exit");
        printf("\nEnter your choice ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("Enter the Element to insert ");
            scanf("%d", &ele);
            root = insert(root, ele);
            break;
        }
        case 2:
            printf("Inorder Traversal \n");
            inorder(root);
            break;
        case 3:
            printf("Preorder Traversal \n");
            preorder(root);
            break;
        case 4:
            printf("Postorder Traversal \n");
            postorder(root);
            break;
        case 5:
            printf("Enter the element to delete ");
            scanf("%d", &ele);
            root = deletenode(root, ele);
            printf("Element is deleted");
            break;
        case 6:
            exit(0);
        default:
            printf("Wrong choice");
            break;
        }
    } while (ch != 6);
}
