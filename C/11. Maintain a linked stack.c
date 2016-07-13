#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *next;
};

struct node *createNode(int val) {
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr->val = val;
	ptr->next = NULL;
	return ptr;
}

void pushToStack(struct node **tos, int val) {
	struct node *ptr = createNode(val);
	if(*tos == NULL) {
		*tos = ptr;
	}

	else {
		ptr->next = *tos;
		*tos = ptr;
	}
}

int popFromStack(struct node **tos) {
	int returnVal;
	if(*tos == NULL) {
		return -1;
	}

	else {
		struct node *ptr = *tos;
		returnVal = ptr->val;
		ptr = ptr->next;
		free(*tos);
		*tos = ptr;
		return returnVal;
	}
}

void display(struct node *tos) {
	struct node *ptr = tos;
	while(ptr) {
		printf("%d -> ",ptr->val);
		ptr = ptr->next;
	}
}

int main() {
	struct node *tos;

	tos = NULL;

	pushToStack(&tos, 1);
	pushToStack(&tos, 2);
	pushToStack(&tos, 3);
	pushToStack(&tos, 4);
	pushToStack(&tos, 5);
	pushToStack(&tos, 6);
	pushToStack(&tos, 7);

	printf("%d \n", popFromStack(&tos));
	printf("%d \n", popFromStack(&tos));
	printf("%d \n", popFromStack(&tos));


	display(tos);

	return 0;
}