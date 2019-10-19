#include<stdio.h>
#include<process.h>
#include<stdlib.h>
void push();
void pop();
void display();
typedef struct node{  //structure creation
	int data;
	struct node *link;
}stacknode;
stacknode *top=NULL;
int main ()
{
	int ch;
	char a;
	do
	{
		printf("***STACK USING LINKED LIST***\n");
		printf("Press 1 to PUSH\n");
		printf("Press 2 to POP\n");
		printf("Press 3 to DISPLAY\n");
		printf("Press 4 to EXIT\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			case 4: exit(0);
			default: printf("Wrong Choice!\n");
		}
		printf("\nAre you want to continue?: ");
		scanf("%s",&a);
	}while(a=='y' || a=='Y'); //end of do-while //if user will press 'y' or 'Y' the loop will continue again
}  //end of main()
void push()
{
	stacknode *p;
	p=(stacknode*)malloc(sizeof(stacknode));//dynamic allocation of nodes
	printf("Enter the data to be pushed: ");
	scanf("%d",&p->data); 
	if(top==NULL)
	{
		p->link=NULL; //if there is no node then p will be the first node so we assign NULL to its link portion
		top=p; // so top will now point to p
	}
	else
	{
		p->link=top; // if there is a node in the stack then top has its address so we assign this addess to the link part of the new node p and now p will point that node
		top=p; //  update the top with the address of p so top will point to p now
	}
}     //end of push()
void pop()
{
	stacknode *p;
	if(top==NULL)
	{
		printf("The STACK is UNDERFLOW!\n"); //if there is no node to delete
	}
	else
	{
		p=top; //p will point to the node which is pointed by top
		top=top->link; // top will point to the second node
		free(p); // free the node from the stack
	}
}   //end of pop()
void display()
{
	stacknode *p;
	if(top==NULL)
	{
		printf("The STACK is UNDERFLOW!\n");
	}
	p=top;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->link;
	}
}  //end of display()
