#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *next;
};

struct node* createNode(int val) {
	struct node *ptr = (struct node*)malloc(sizeof(struct node*));
	ptr->val = val;
	ptr->next = NULL;
	return ptr;
}


void addToTail(struct node **ptr, int val) {

	if(*ptr == NULL) {
		*ptr = createNode(val);
	}

	else {
		struct node *temp;
		temp = *ptr;
		while(temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = createNode(val);

	}
}

void addToHead(struct node **ptr, int val) {
	if(*ptr == NULL) {
		*ptr = createNode(val);
	}

	else {
		struct node *temp;
		temp = createNode(val);
		temp->next = *ptr;
		*ptr = temp;

	}
}

void display(struct node *ptr) {
	struct node *temp;
	temp = ptr;

	while(temp) {
		printf("%d -> ",temp->val);
		temp = temp->next;
	}

}

void addAfter(struct node **ptr, int index, int val) {
	struct node *temp = *ptr;
	while(index--) {
		temp = temp->next;
	}

	struct node *foo = createNode(val);
	foo->next = temp->next;
	temp->next = foo;

}

void deleteAtHead(struct node **ptr) {
	struct node *temp = *ptr;
	temp = temp->next;
	free(*ptr);
	*ptr = temp;
}

void deleteAtTail(struct node **ptr) {
	struct node *temp = *ptr;
	while(temp->next->next != NULL) {
		temp=temp->next;
	}
	free(temp->next);
	temp->next = NULL;
}

int main() {
	struct node *head;

	head = NULL;

	addToTail(&head, 5);
	addToTail(&head, 6);
	addToTail(&head, 7);
	addToTail(&head, 8);
	addToTail(&head, 9);

	addToHead(&head, 4);
	addToHead(&head, 3);
	addToHead(&head, 2);
	addToHead(&head, 1);



	addAfter(&head, 2, 23);

	deleteAtTail(&head);
	deleteAtHead(&head);

	display(head);

	return 0;
}
