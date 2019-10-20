//below is a C program for parenthesis checker using Stack
#include<stdio.h>
#include<string.h>
#define max 10
int top=-1;
int stk[max];
void push(char c)
{
	if(top==(max-1))
	{
		printf("Stack overflow\n");
	}
	else
		stk[++top]=c;
}

char pop()
{
	if(top==-1)
		{printf("Stack underflow\n");}
	else
		return (stk[top--]);
}

void main()
{
	char exp[20],temp;
	int i,flag=1;
	//ask the user to enter the expression
	printf("Enter expression\n");
	scanf("%s",&exp);
	//check whether parenthesis is closed or not
	for (int i = 0; i < strlen(exp); i++)
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
			push(exp[i]);
		if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
		{
			if(top==-1)
				flag=0;
			else
			{
				temp=pop();
				if(exp[i]==')'&&(temp=='{') || temp=='[')
					flag=0;
				if(exp[i]=='}'&&(temp=='(') || temp=='[')
					flag=0;
				if(exp[i]==']'&&(temp=='{') || temp=='(')
					flag=0;
		
			}
		}
	}
	if(top>=0)
		flag=0;
	if(flag==1)
		printf("Valid expression\n");
	else
		printf("Invalid Expression\n");
}