//Vishak PV
//S3 D
//56
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *llink,*rlink;
};

void main()
{
    int key,x,choice,flag;
    struct node *head,*temp,*ptr,*ptr1,*ptr2;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=0;
    head->llink=NULL;
    head->rlink=NULL;

    do
    {
        ptr=head;
        printf("\nMENU\n1.Insertion (end)\n2.Insertion (in b/w)\n3.Insertion (begining)\n4.Deletion\n5.Display\n6.Exit\nEnter choice:");
        scanf("%d",&choice);
        if(choice==1)
        {
            while(ptr->rlink!=NULL)
            {
                ptr=ptr->rlink;
            }
            temp=(struct node*)malloc(sizeof(struct node));
            ptr->rlink=temp;
            printf("Enter data: ");
            scanf("%d",&x);
            temp->data=x;
            temp->rlink=NULL;
            temp->llink=ptr;
        }
        else if(choice==2)
        {
            printf("Enter key: ");
            scanf("%d",&key);
            ptr=ptr->rlink;
            while(ptr!=NULL)
            {
                if(ptr->data==key)
                {
                    temp=(struct node*)malloc(sizeof(struct node));
                    ptr1=ptr->rlink;
                    ptr->rlink=temp;
                    temp->llink=ptr;
                    ptr1->llink=temp;
                    temp->rlink=ptr1;
                    printf("Enter data: ");
                    scanf("%d",&x);
                    temp->data=x;

                }
                ptr=ptr->rlink;
            }
        }

        else if(choice==3)
        {
            printf("Enter key: ");
            scanf("%d",&key);
            if(ptr->rlink==NULL)
            {
                temp=(struct node*)malloc(sizeof(struct node));
                ptr->rlink=temp;
                temp->llink=ptr;
                temp->rlink=NULL;
                temp->data=key;
            }
            else
            {
                temp=(struct node*)malloc(sizeof(struct node));
                ptr1=ptr->rlink;
                ptr->rlink=temp;
                temp->llink=ptr;
                temp->rlink=ptr1;
                ptr1->llink=temp;
                temp->data=key;
            }
        }
        else if(choice==4)
        {
            if(ptr->rlink==NULL)
            {
                printf("List is empty!!!");
            }
            else
            {
                printf("Enter key: ");
                scanf("%d",&key);
                flag=0;
                while(ptr->rlink!=NULL)
                {
                    ptr1=ptr;
                    ptr=ptr->rlink;
                    ptr2=ptr->rlink;
                    if(ptr->data==key)
                    {
                        if(ptr->rlink==NULL)
                        {
                            ptr1=ptr->llink;
                            ptr1->rlink=NULL;
                            free(ptr);
                            flag+=1;

                        }
                        else
                        {
                            ptr1=ptr->llink;
                            ptr2=ptr->rlink;
                            ptr1->rlink=ptr2;
                            ptr2->llink=ptr1;
                            free(ptr);
                            flag+=1;
                        }
                    }
                }
                if(flag==0)
                {
                    printf("Key not found!!!");
                }
            }
        }
        else if(choice==5)
        {
            ptr=ptr->rlink;
            while(ptr!=NULL)
            {
                printf("%d -> ",ptr->data);
                ptr=ptr->rlink;
            }
            printf("NULL");
        }
    }while(choice==1 || choice==2 || choice==3 || choice==4 || choice==5);
}
