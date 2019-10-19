#include<stdio.h>
#include<stdlib.h>

 void insert_begin();
 void insert_end();
 void insert_intermediate();
 void deletion();
 void reverse_printing();
 void merge_two_LL();
 void search_data();
 void sort_data();
 void reverse_LL();
struct node
{
	int data;
	struct node *next;
};
struct node * create(int );
void display(struct node *);
 
struct node *head1,*head2;
void main()
{
	int size1,size2;
	int choice;
	
	
	
	
	printf("1.Creating and display\n");
	printf("2.Insert at begin\n");
	printf("3:Insert at end\n");
	printf("4:Insert at intermediate\n");
	printf("5:Deletion\n");
	printf("6:Merging two lnked list\n");
	printf("7:Reverse printing\n");
	printf("8:Search\n");
	printf("9:Sort\n");
	printf("10:Reverse the linked list\n");
	printf("11:End the program.\n");
	
	printf("Enter the choice\n");
	scanf("%d",&choice);
	
	 while(choice != 11){
	printf("Enter the size1\n");
	scanf("%d",&size1);
    switch(choice)
    {
     
      case 1: 
      head1=create(size1);
      display(head1);
      break;
      case 2:
      head1=create(size1);
       insert_begin();
        display(head1);
      break;
      case 3:
      head1=create(size1);
       insert_end();
        display(head1);
      break;
      case 4:  
      head1=create(size1);
       insert_intermediate();
        display(head1);
      break;
      case 5:
      head1=create(size1);   
       deletion();
       display(head1);
      break;
      case 6:
      printf("enter the size1\n");
	scanf("%d",&size1);
	printf("enter the size2\n");
	scanf("%d",&size2); 
        head1=create(size1);
        display(head1);
         head2=create(size2);
        display(head2);
        merge_two_LL();
         display(head1);
       case 7:
       head1=create(size1);
        reverse_printing();
        
        case 8:
        head1=create(size1);
        search_data();
        
        case 9:
        head1=create(size1);
        sort_data();
         display(head1);
        
         case 10:
         head1=create(size1);
         reverse_LL();
         display(head1);
        }
        
         }
}

struct node * create(int size)
{
	struct node *new,*temp,*head=NULL;
	int i;
	printf("Enter the input:\n");
	for(i=0;i<size;i++)
	{
		new=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&new->data);
		new->next=NULL;
		if(head==NULL)
		{
			head=new;
			temp=head;
		}
		else
		{
			temp->next=new;
			temp=new;
		}
        }
        return head;
 }
 
 void display(struct node *new1)
 
{
   struct node *new;
    new=new1;
    printf("linked list are:\n");
    while(new!=NULL)
    {
    	printf("%d\n",new->data);
    	new=new->next;
    }

}/*
 void display2()
 
{
   struct node *new;
    new=head2;
    printf("linked list are:\n");
    while(new!=NULL)
    {
    	printf("%d\n",new->data);
    	new=new->next;
    }

}
*/
void insert_begin()
{
 printf("Enter a value to store at the begining of node");
 struct node *new;
 new=(struct node*)malloc(sizeof(struct node));
 scanf("%d",&new->data);
 new->next=head1;
 head1=new;
 } 
 
 void insert_end()
 {
 printf("Enter a value to store at the end of node");
 struct node *new;
 struct node *temp;
 temp=head1;
 new=(struct node*)malloc(sizeof(struct node));
 scanf("%d",&new->data);
 new->next=NULL;
 while(temp->next != NULL)
 {
   temp=temp->next;
 }
  temp->next =new;
 }
void insert_intermediate()
{
 int pos,c=0;
 printf("enter a value to be inserted\n");
 struct node *new;
 struct node *temp;
 temp=head1;
 new=(struct node*)malloc(sizeof(struct node));
 scanf("%d",&new->data);
 printf("enter the position to be inserted");
 scanf("%d",&pos);
 while(c<pos-2)
 {
  temp=temp->next;
  c+=1;
  }
  new->next=temp->next;
  temp->next=new;
 }
 
 void deletion()
 {
   int pos,i;
   printf("enter the positon to be deleted\n");
   scanf("%d",&pos);
   struct node *temp;
   struct node *new;
   temp=head1;
   //new=head;
   /*while(c<pos-1)
   {
    temp=temp->next;
    c+=1;
   }
   while(d<pos-2)
   {
     new=new->next;
     d+=1;
    }*/
    if (pos==1)
    {
    head1=temp->next;
    }
    for(i=1;i<pos-1;i++)
    {
    temp=temp->next;
    }
    new=temp->next->next;
    temp->next=new;
    
    }
void reverse_printing()
{
  struct node *temp,*last=NULL;
  printf("reverse printing are:\n");
  while(last!=head1)
  {
   temp=head1;
  while(temp->next!=last)
  {
    temp=temp->next; 
   }
   printf("%d\n",temp->data);
   last=temp;
   } 
 }
void merge_two_LL()
{
  struct node *temp;
  temp=head1;
  while(temp->next!=NULL)
  {
   temp=temp->next;
  }
    temp->next=head2;
 }  

void search_data()
{
 int search;
 struct node *temp;
 printf("Enter the vale to search in LL:\n");
 scanf("%d",&search);
 temp=head1;
 while(temp->next!=NULL)
 {
   if(temp->data == search)
   printf("value is present:%d \n",search);
   temp=temp->next;
  }
}
void sort_data()
{
  struct node *temp,*new;
  int tmp;
  temp=head1;
  while(temp->next!=NULL)
  {
    new=temp->next;
    if(new->data < temp->data)
    {
      tmp = temp->data;
      temp->data = new->data;
      new->data = tmp;
     }
    temp = temp->next;
   }
}
void reverse_LL()
{
 struct node *prev=NULL,*curr,*rest;
 curr=head1;
 rest=head1->next;
 while(curr!=NULL)
 {
 curr->next=prev;
 prev=curr;
 curr=rest;
 if(rest!=NULL)
 {
 rest=rest->next;
 }
 }
 head1=prev;
 }
 
 
 
