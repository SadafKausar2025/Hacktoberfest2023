#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *creatNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void InorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        InorderTraversal(root->left);
        printf("%d\t", root->data);
        InorderTraversal(root->right);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
int main()
{
    struct node *p = creatNode(5);
    struct node *p1 = creatNode(3);
    struct node *p2 = creatNode(6);
    struct node *p3 = creatNode(1);
    struct node *p4 = creatNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    InorderTraversal(p);
    printf("\n");
    if (isBST(p))
    {
        printf("this is BST");
    }
    else
    {
        printf("this is not BST");
    }
    return 0;
}
