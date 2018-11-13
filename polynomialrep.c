#include<stdio.h>
#include<stdlib.h>
struct node{
		int coeff,exp;
		struct node *link;
		}*head;
void display()
		{
			struct node *ptr;
			ptr=head->link;
			while(ptr!=NULL)
			{
				printf("%dX^%d+",ptr->coeff,ptr->exp);
				ptr=ptr->link;
			}
			printf("\n");
		}
void main()
	{
		struct node *temp,*ptr;
		int e,c,choice;
		head=(struct node*)malloc(sizeof(struct node));
		head->exp=0;
		head->coeff=0;
		head->link=NULL;
		ptr=head;
		do{
			printf("enter the coeff");
			scanf("%d",&c);
			printf("enter the exp:");
			scanf("%d",&e);
			temp=(struct node*)malloc(sizeof(struct node));
			temp->coeff=c;
			temp->exp=e;
			temp->link=NULL;
			ptr->link=temp;
			ptr=ptr->link;
			printf("\n1.add more element\n2.exit\n");
			printf("enter the choice");
			scanf("%d",&choice);
		}while(choice==1);
		display();
}
