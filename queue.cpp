#include <iostream>

static const unsigned int CAPACITY = 10;

struct Queue {
	int data[CAPACITY]	= {};
	int front			= -1;
	int size			= 0;
};

void push(Queue* queue, int value);
int pop(Queue* queue);

int front(Queue* queue);
int back(Queue* queue);

bool isEmpty(const Queue* const queue);

int main() {

	Queue q;
	
	return 0;
}
