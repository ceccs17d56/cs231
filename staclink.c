//Vishak PV
//S3 D
//56
#include<stdio.h>
#include<stdlib.h>
struct node{
		int data;
		struct node *next;
	}*top=NULL;
void push(int value)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));

	newnode->data=value;
	if(top==NULL)
		newnode->next==NULL;
	else
		newnode->next=top;
	top=newnode;
}
void pop()
{
	if(top==NULL)
		printf("stack is empty");
	else
	{
		struct node *temp=top;
		printf("deleted element %d",temp->data);
		top=temp->next;
		free(temp);

	}
}
void display()
{
	if(top==NULL)
		printf("stack is empty");
	else
	{
	struct node *temp=top;
	while(temp->next!=NULL)
	{
	printf("%d->",temp->data);
	temp=temp->next;
	}
	printf("%d->",temp->data);
	}
}
void main()
{
	int choice,value;
	do{
		printf("\n1.push\n2.pop\n3.display\n4.exit\n");
		printf("enter the choice");
		scanf("%d",&choice);
			switch(choice)
				{
				case 1:
					{
					printf("enter the value to be insert");
					scanf("%d",&value);
					push(value);
					break;
					}
				case 2:
					{
					pop();
					break;
					}
				case 3:
					{
					display();
					break;
					}
				case 4:
					{
					printf("exit");
					break;
					}
				}
		}
		while(choice!=4);
}


