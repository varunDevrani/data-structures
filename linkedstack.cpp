#include <iostream>
#include <cstring>

struct Node {
	char data;
	Node* next;
};

struct Stack {
	Node* head			= NULL;
	unsigned int size	= 0;
	int top				= -1;
};


void traverse(Stack* stack) {
	Node* iterator = stack->head;
	while(iterator != NULL) {
		std::cout << iterator->data << " ";
		iterator = iterator->next;
	}
	std::cout << std::endl;
}

void push(Stack* stack, char data) {
	Node* node = new Node{data, stack->head};
	stack->head = node;
	stack->top++;
	stack->size++;
}

char pop(Stack* stack) {
	if(stack->size == 0) {
		std::cout << "Error: Stack Underflow" << std::endl;
		return '\0';
	}

	char poped = stack->head->data;
	stack->head = stack->head->next;
	stack->top--;
	stack->size--;
	return poped;
}

// in case of linked lists where there is not
// limit since data being stored in the free store(heap)
// this function has no check meaning
bool isEmpty(Stack* stack) {
	return stack->size == 0;
}

char top(Stack* stack) {
	if(stack->size == 0) {
		return '\0';	
	}
	return stack->head->data;
}

int main() {

	Stack* stack = new Stack{};

	const char* str = "helloworld";
	unsigned int length = std::strlen(str);	
	std::cout << length << std::endl;
	
	for(unsigned int i = 0; i < length; i++) {
		push(stack, str[i]);
	}

	char reversedStr[length + 1];
	for(unsigned int i = 0; i < length; i++) {
		reversedStr[i] = pop(stack);
	}
	reversedStr[length] = 0;

	std::cout << str << std::endl;
	std::cout << reversedStr << std::endl;

	return 0;
}
