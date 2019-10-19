#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;

    struct Node* next;

    struct Node* prev;

}node;



node* alloc(int val){//Allocate node for Doubly Linked List

    node* newnode = (node*)malloc(sizeof(node));

    newnode->next = NULL;

    newnode->prev = NULL;

    newnode->data = val;

    return newnode;

}



node* push(node* head,int val){//Push in to the front of list

    if(head == NULL){//Handle case for first insertion

        node* newnode = alloc(val);

        head = newnode;

    }

    else{//Push into the front and readjust head after pointing previous of head to newnode

        node* newnode = alloc(val);

        newnode->next = head;

        head->prev = newnode;

        head = newnode;

    }

    return head;

}



void traverse(node* head){//Traverse the list until NULL

    node* current = head;

    if(head==NULL){//If no node present

        printf("Underflow - no nodes present\n");

        return;

    }

    printf("The current stack is \n");

    while(current!=NULL){//While not NULL traverse the list

        printf("%d ",current->data);

        current = current->next;

    }

    printf("\n");

}



node* pop(node* head){

    if(head==NULL){//Handle when no nodes present

        printf("Underflow -  no nodes present\n");

    }

    else if(head->next==NULL){//Handle when only one node present

        node* temp = head;

        head = NULL;

        free(temp);

    }

    else{//Else move the head by one node

        node* temp = head;

        head = head->next;

        head->prev = NULL;

        free(temp);

    }

    return head;

}

void peek(node* head){//Show the topmost element

    if(head==NULL){//When no node present

        printf("Underflow -  no nodes present\n");

    }

    else {//Show the data of head

        printf("The topmost element of the stack is : %d\n",head->data);

    }

}



int main(){

    node* head=NULL;

    long int i,n,k;

    printf("-------- Choose any number from the below sequence -------------\n");

    printf(" 1. Insert into stack \n");

    printf(" 2. Delete from stack \n");

    printf(" 3. Peek \n");

    printf(" 0. exit\n");

    printf("----------------------------------------------------------------\n");

    while(1){

        printf("Enter next choice : ");

        scanf("%ld",&i);

        switch(i){

            case 0:

                break;

            case 1:

                printf("Enter a value to push into stack : ");

                scanf("%ld",&n);

                head = push(head,n);

                traverse(head);

                break;

            case 2:

                head = pop(head);

                traverse(head);

                break;

            case 3:

                peek(head);

                break;

            default:

                printf("Enter a valid choice");

        }

        if(i==0)

            break;

    }

    return 0;

}
