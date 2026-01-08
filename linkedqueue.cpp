#include <iostream>

struct Node {
	int data;
	Node* head;
};

struct Queue {
	Node* head			= 0;
	unsigned int size	= 0;
	int front			= -1;
};


void push(Queue* queue, int value);
int pop(Queue* queue);

int front(Queue* queue);
int back(Queue* queue);

void traverse(Queue* queue);

int main() {



	return 0;
}
