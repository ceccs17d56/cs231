#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
}*HEADER;

struct node *newNode() {
	struct node *newptr = malloc(sizeof(struct node));
	if (newptr == NULL) {
		printf("Memory overflow");
		
		exit(0);
	}
	
}
void enqueue() {
  int data;
  printf("Enter data to be entered : ");
  scanf("%d", &data);
	struct node *newptr = newNode(), *currentNode = HEADER;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}
	newptr->next = NULL;
	newptr->data = data;
	currentNode->next = newptr;
}
void dequeue() {
	struct node *currentNode = HEADER->next;
	if (currentNode == NULL) {
		printf("Empty linked list.\nDeletion failed.\n");
	} else {
		HEADER->next = currentNode->next;
		free(currentNode);
	}
}
void printQueue() {
	struct node *currentNode = HEADER->next;
	printf("\nLinked List\nHEADER->");
	while (currentNode != NULL) {
		printf("%d->", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("NULL\n");
}
int main() {
	char choice;
	HEADER = malloc(sizeof(struct node));
	HEADER->data = 0;
	HEADER->next = NULL;
	do {
		printf("\n\tQueue using linked list\n1.Enqueu\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice : ");
		scanf(" %c", &choice);
		switch(choice) {
			case '1':
				enqueue();
				break;
			case '2':
				dequeue();
				break;
			case '3':
				printQueue();
				break;
		}
	} while(choice != '4');
	  
}
		

