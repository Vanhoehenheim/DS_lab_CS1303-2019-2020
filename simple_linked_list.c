#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void create()                                        //Function to create a linked list, taking number of nodes as input.
{

    int n;
    printf("Enter how many nodes you want \n");
    scanf("%d", &n);
    struct node *temp;
    for (int i = 0; i < n; i++)
    {
        printf("Enter data %d :", (i + 1));
        temp = (struct node *)malloc(sizeof(struct node *));
        scanf("%d", &temp->data);
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            struct node *ptr;
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }
}
int length()                                        //Funtion that returns the lenght of the linked list.
{
    int count = 0;
    struct node *ptr;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}
void display()                                        //Funtion to display all the nodes in the linked list.
{
    struct node *ptr;
    ptr = head;
    printf("%d -> ", ptr->data);
    do
    {
        ptr = ptr->next;

        if (ptr->next == NULL)
        {
            printf("%d", ptr->data);
        }
        else
        {
            printf("%d -> ", ptr->data);
        }
    } while (ptr->next != NULL);
}
void append()                                        //Function to add a new node to the end of the linked list.
{
    printf("Enter data :");
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node *));
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *ptr;
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void insert()                                        //Function to insert a node at a specified location.
{
    int loc, i = 2;
    printf("\nEnter your location\n");
    scanf("%d", &loc);
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node *));
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (loc == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        struct node *ptr;
        ptr = head;
        while (i < loc && ptr->next != NULL)
        {
            ptr = ptr->next;
            i++;
        }
        if (ptr->next == NULL)
        {
            ptr->next = temp;
        }
        else
        {
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }
}
void delete ()                                        //Funtion to delete a node at a specified location.
{
    int loc, i = 1;
    struct node *ptr, *q;
    ptr = head;
    printf("\nEnter your location to be deleted\n");
    scanf("%d", &loc);
    if (head == NULL)
    {
        printf("The List is empty\n");
    }
    else
    {
        if (loc == 1)
        {
            head = ptr->next;
            ptr->next = NULL;
            free(ptr);
        }
        else
        {
            while (i < loc - 1 && ptr->next != NULL)
            {
                ptr = ptr->next;
                i++;
            }
            q = ptr->next;
            ptr->next = q->next;
            q->next = NULL;
            free(q);
        }
    }
}
void reverse_linked_list()                                        //Funtion to Reverse the linked list.
{
    struct node *p, *q;
    int len, temp, k;
    len = length();
    p = head;
    q = head;
    int i = 0;
    int j = len;
    while (i < j)
    {
        k = 0;
        while (k < j)
        {
            q = q->next;
            k++;
        }
        temp = p->data;
        p->data = q->data;
        q->data = temp;
        i++;
        j--;
        p = p->next;
        q = head;
    }
}
void main()
{
    int d;
    do
    {
        printf("\nEnter your option\n1. Create\n2. Display\n3. Insert\n4. Delete\n5. Reverse\n6. Append\n7. Exit\n");
        scanf("%d", &d);
        switch (d)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            delete ();
            break;
        case 5:
            reverse_linked_list();
            break;
        case 6:
            append();
            break;

        default:
            break;
        }
    } while (d != 7);
}