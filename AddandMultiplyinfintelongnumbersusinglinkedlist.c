#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Node{
  int data;
  struct Node *next;
};
void printList(struct Node *node){
  while (node != NULL){
     printf("%d ", node->data);
     node = node->next;
  }
}
void rev(struct Node** head_ref){
  struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL){
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
// Insertion at Begining
void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
//Insertion at End
void append(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL){
       *head_ref = new_node;
       return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
void add(struct Node *first,struct Node *second){
  struct Node* result=NULL;
  int num1=0,num2=0,carry=0,sum=0;
  while (first!=NULL || second!=NULL) {
    if(first!=NULL){
      num1=first->data;
      first=first->next;
    }
    else
     num1=0;
    if(second!=NULL){
      num2=second->data;
      second=second->next;
    }
    else
      num2=0;
    sum=num1+num2+carry;
    carry=0;
    if(sum>9){
      carry=sum/10;
      sum%=10;
    }
    push(&result,sum);
  }
  if(carry!=0)
    push(&result,carry);
  printf("After Addition : \t");
  printList(result);
}
int length(struct Node *temp){
  int len=0;
  while(temp!=NULL){
    temp=temp->next;
    len++;
  }
  return len;
}
void multiply(struct Node *first,struct Node *second){
    int m = length(first), n = length(second);
    struct Node *result =NULL;
    for(int i=0;i<(m + n + 1);i++)
      push(&result,0);
    struct Node *second_ptr = second,*result_ptr1 = result, *result_ptr2, *first_ptr;
    while (second_ptr){
        int carry = 0;
        result_ptr2 = result_ptr1;
        first_ptr = first;
        while (first_ptr){
            int mul = first_ptr->data * second_ptr->data+ carry;
            result_ptr2->data += mul % 10;
            carry = mul / 10 + result_ptr2->data / 10;
            result_ptr2->data = result_ptr2->data % 10;
            first_ptr = first_ptr->next;
            result_ptr2 = result_ptr2->next;
        }
        if (carry > 0)
            result_ptr2->data += carry;
        result_ptr1 = result_ptr1->next;
        second_ptr = second_ptr->next;
    }
    rev(&result);
    while (result->data == 0) {
        struct Node* temp = result;
        result = result->next;
        free(temp);
    }
    printf("After Multiplication :\t");
    printList(result);
}
int main(){
  struct Node* head = NULL;   //first number
  struct Node* head1 = NULL;  //Second number
  int num;
  char c;
  printf("Enter 1st number :\t");
  while((c=getche())!='\r'){
    num=(int) c-'0';
    append(&head,num);
  }
  printf("\nThe 1st Number is:\t");
  printList(head);
  rev(&head);
  printf("\nEnter 2nd number :\t");
  while((c=getche())!='\r'){
    num=(int)c-'0';
    push(&head1,num);
  }
  printf("\n");
  add(head,head1);
  printf("\n");
  multiply(head,head1);
}
