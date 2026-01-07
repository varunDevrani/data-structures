#include <iostream>
#include <cstring>

// static capacity allocated for stack data structure
const unsigned int CAPACITY = 10;

struct Stack {
	int data[CAPACITY];
	int top  = -1;
	int size = 0;
};

void push(Stack* stack, int value) {
	if(stack->size >= CAPACITY) {
		std::cerr << "Error: Stack Overflow" << std::endl;
		return;
	}	

	stack->size++;
	stack->data[++stack->top] = value;
}

int pop(Stack* stack) {
	if(stack->size <= 0) {
		std::cerr << "Error: Stack Underflow" << std::endl;
		return -1;
	}
	
	stack->size--;
	return stack->data[stack->top--];
}

int top(Stack* stack) {
	return stack->data[stack->top];
}	

bool isEmpty(Stack* stack) {
	return stack->size < CAPACITY;
}

// shouldnt be possible but can be
void traverse(const Stack* const stack) {
	for(unsigned int i = 0; i < stack->size; i++) {
		std::cout << stack->data[i] << " ";
	}
	std::cout << std::endl;
}

int main() {

	Stack stack;

	for(unsigned int i = 0; i < 20; i++) {
		std::cout << stack.size << " " << stack.top << std::endl;
		push(&stack, i);
		traverse(&stack);
		std::cout << std::endl;
	}	

	return 0;
}





