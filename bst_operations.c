#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *right, *left;
};

void insert(struct node **root, struct node *cur)
{
    if(!(*root))
    {
        *root = cur;
        return;
    }
    if(cur->val<=(*root)->val)
        insert(&(*root)->left,cur);
    else if(cur->val>(*root)->val)
        insert(&(*root)->right, cur);
}

void Preorder(struct node *root)
{
    printf("%d ",root->val);
    if(root->left)
        Preorder(root->left);
    if(root->right)
        Preorder(root->right);
}
void Inorder(struct node *root)
{
    if(root->left)
        Inorder(root->left);
    printf("%d ",root->val);
    if(root->right)
        Inorder(root->right);
}

void Postorder(struct node *root)
{
    if(root->left)
        Postorder(root->left);
    if(root->right)
        Postorder(root->right);
    printf("%d ",root->val);
}


int main()
{
    int ch;
    struct node *curr, *root;
    // clrscr();
    root = NULL;
    do
    {
        printf("\n\n\t1. Insert");
        printf("\n\t2. Postorder");
        printf("\n\t3. Inorder");
        printf("\n\t4. Preorder");
        printf("\n\t5. Exit");
        printf("\n\tEnter a Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    curr = (struct node *)malloc(sizeof(struct node));
                    curr->left = curr->right = NULL;
                    printf("\n\tEnter a No ");
                    scanf("%d",&curr->val);
                    insert(&root,curr);
                    break;
            case 2:
                    printf("\n\tPreorder Traversal : ");
                    Preorder(root);
                    break;
            case 3:
                    printf("\n\tInorder Traversal : ");
                    Inorder(root);
                    break;
            case 4:
                    printf("\n\tPostrder Traversal : ");
                    Postorder(root);
                    break;
            case 5: exit(0);
            default:
                    printf("\n\tInvalid Option!");
        }
    }while(ch!=5);

    // getch();
    return 0;
}
