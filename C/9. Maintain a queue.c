#include <stdio.h>
#include <stdlib.h>

const int size = 5;

void pushToQueue(int *queue, int val, int *front, int *rear) {
	if(*front == -1 && *rear ==-1) {
		*front=*rear=0;
	}
	
	if(*rear == size) {
		printf("Queue Overflow %d\n", val);
		return;
	}

	queue[(*rear)++] = val;

}

int popFromQueue(int *queue, int *front, int *rear) {
	int returnVal;

	if(*front == -1) {
		printf("Queue Underflow\n");
		return -1;
	}

	returnVal = queue[*front];
	queue[*front] = -1;
	
	if(*front == *rear) {
		*front = *rear = -1;
	}

	else {
		*front++;
	}

	return returnVal;

}

int main() {
	int queue[size];

	int front=-1, rear=-1;

	pushToQueue(queue, 1, &front, &rear);
	pushToQueue(queue, 2, &front, &rear);
	pushToQueue(queue, 3, &front, &rear);
	pushToQueue(queue, 4, &front, &rear);
	pushToQueue(queue, 5, &front, &rear);
	
	printf("%d\n", popFromQueue(queue, &front, &rear));

	pushToQueue(queue, 5, &front, &rear);
	pushToQueue(queue, 5, &front, &rear);

	int i;
	
	for(i=0;i<size;++i) {
		printf("%d -> ", queue[i]);
	}

	return 0;
}

