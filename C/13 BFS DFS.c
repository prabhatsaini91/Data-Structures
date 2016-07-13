#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node {
	int val;
	struct node *next;
};
					
struct node *createNode(int val) {
	struct node *ptr = (struct node*)malloc(sizeof(struct node*));	//single line comment
	ptr->val = val;			//another comment
	ptr->next = NULL;
	return ptr;
}


//yet another single line comment

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

/* this is a multiline comment 
	another line of the comment
		another line */


int popFromQueue(struct node **head) {  /*another multiline comment
	after /n and indent*/
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

bool isEmpty(struct node *head) {
	if(head==NULL) {
		return true;
	}

	else 
		return false;
}

void displayQueue(struct node *head) {
	struct node *ptr = head;

	while(ptr) {
		printf("%d -> ", ptr->val);
		ptr = ptr->next;
	}
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

void displayStack(struct node *tos) {
	struct node *ptr = tos;
	while(ptr) {
		printf("%d -> ",ptr->val);
		ptr = ptr->next;
	}
}


struct AdjListNode {
	int vertex;
	struct AdjListNode *next;
};

struct AdjList {
	struct AdjListNode *head;
};

struct Graph {
	int numofVertices;
	struct AdjList *vertices;
};


struct AdjListNode *createGraphNode(int vertex) {
	struct AdjListNode *ptr = (struct AdjListNode*)malloc(sizeof(struct AdjListNode*));
	ptr->vertex = vertex;
	ptr->next = NULL;
	
	return ptr;
}

struct Graph *createGraph(int vertices) {
	struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph*));
	graph->numofVertices = vertices;
	graph->vertices = (struct AdjList*)malloc(vertices * sizeof(struct AdjList*));

	int i;
	for(i=0;i<vertices;++i) {
		graph->vertices[i].head = NULL;
	}

	return graph;
}

void addEdge(struct Graph *graph, int sourceVertex, int destinationVertex) {
	struct AdjListNode *node = createGraphNode(destinationVertex);
	node->next = graph->vertices[sourceVertex].head;
	graph->vertices[sourceVertex].head = node;

	node = createGraphNode(sourceVertex);
	node->next = graph->vertices[destinationVertex].head;
	graph->vertices[destinationVertex].head = node;
}

void displayGraph(struct Graph *graph) {
	int v;
	for(v=0;v<graph->numofVertices;++v) {
		struct AdjListNode *iterator = graph->vertices[v].head;
		while(iterator) {
			printf("--> %d", iterator->vertex);
			iterator = iterator->next;
		}

		printf("\n");
	}
}

void BreadthFirstSearch(struct Graph *graph, int startVertex) {
	bool *visited = malloc(graph->numofVertices * sizeof(bool));
	struct node* front;
	front=NULL;
	int i;

	for(i=0;i<graph->numofVertices;++i) {
		visited[i]=false;
	}
	
	pushToQueue(&front,startVertex);
	visited[startVertex] = true;

	while(!isEmpty(front)) {
		int newVertex = popFromQueue(&front);
		printf("\n Got vertex from queue : %d", newVertex);
		printf("\n  Queue Now: -> ");
		displayQueue(front);
		struct AdjListNode *iterator = graph->vertices[newVertex].head;
		while(iterator) {
			if(!visited[iterator->vertex]) {
				printf("\nPushing to queue :%d",iterator->vertex);
				pushToQueue(&front, iterator->vertex);
				printf("\n  Queue Now: -> ");
				displayQueue(front);
				visited[iterator->vertex] = true;
			}
			iterator = iterator->next;
		}
		printf("\nsetting true for visit %d\n", newVertex);
		printf("%d \n\n", newVertex);

	}

}

void DepthFirstSearch(struct Graph *graph, int startVertex) {
	bool *visited = malloc(graph->numofVertices * sizeof(bool));
	struct node* tos;
	tos=NULL;
	int i;

	for(i=0;i<graph->numofVertices;++i) {
		visited[i]=false;
	}
	
	pushToStack(&tos,startVertex);
	visited[startVertex] = true;

	while(!isEmpty(tos)) {
		int newVertex = popFromQueue(&tos);
		printf("\n Got vertex from Stack : %d", newVertex);
		printf("\n  Stack Now: -> ");
		displayStack(tos);
		struct AdjListNode *iterator = graph->vertices[newVertex].head;
		while(iterator) {
			if(!visited[iterator->vertex]) {
				printf("\nPushing to Stack :%d",iterator->vertex);
				pushToStack(&tos, iterator->vertex);
				printf("\n  Stack Now: -> ");
				displayStack(tos);
				visited[iterator->vertex] = true;
			}
			iterator = iterator->next;
		}
		printf("\nsetting true for visit %d\n", newVertex);
		printf("%d \n\n", newVertex);

	}
}

int main() {
	int vertices=5;
	struct Graph *graph = createGraph(vertices);

	addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    displayGraph(graph);

    // BreadthFirstSearch(graph,3);
    DepthFirstSearch(graph,3);

    return 0;
}
