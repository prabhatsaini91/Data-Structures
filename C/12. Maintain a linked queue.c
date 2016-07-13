#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *next;
};

struct node *createNode(int val) {
	struct node *ptr = (struct node*)malloc(sizeof(struct node*));
	ptr->val = val;
	ptr->next = NULL;
	return ptr;
}

void pushToQueue(struct node **head, int val) {
	struct node *ptr = createNode(val);
	struct node *temp = *head;

	if(*head == NULL) {
		*head = ptr;
	}

	else {
		while(temp->next!=NULL) {
			temp = temp->next;
		}

		temp->next = ptr;
	}
}

int popFromQueue(struct node **head) {
	int returnVal;
	if(*head == NULL) {
		return -1;
	}

	else {
		struct node *ptr = *head;
		returnVal = ptr->val;
		ptr = ptr->next;
		free(*head);
		*head = ptr;
		return returnVal;
	}
}

void display(struct node *head) {
	struct node *ptr = head;

	while(ptr) {
		printf("%d -> ", ptr->val);
		ptr = ptr->next;
	}
}

bool isEmpty(struct node *head) {
	if(head == NULL) {
		return true;
	}
	eles {
		return false;
	}
}


int main () {
	struct node *head;
	head = NULL;

	printf("%d",isEmpty(head));

	pushToQueue(&head, 1);
	pushToQueue(&head, 2);
	pushToQueue(&head, 3);
	pushToQueue(&head, 4);
	pushToQueue(&head, 5);

	printf("%d \n", popFromQueue(&head));
	printf("%d \n", popFromQueue(&head));
	printf("%d \n", popFromQueue(&head));

	pushToQueue(&head, 43);
	pushToQueue(&head, 12);




	display(head);

	return 0;
}
