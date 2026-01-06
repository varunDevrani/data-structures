#include <iostream>

struct Node {
	int data;
	Node* next;
};

Node* createNode(int data);

unsigned int length(Node* head);

void printList(Node* head);

void insertAtStart(Node** head, int data);
void insertAtEnd(Node** head, int data);
void insertAt(Node** head, unsigned int index, int data);

void deleteAtStart(Node** head);
void deleteAtEnd(Node** head);
void deleteAt(Node** head, unsigned int index);

void deleteList(Node* head);



int main() {

	Node* head = NULL;	
	
	insertAtEnd(&head, 25);
	insertAtEnd(&head, 90);
	insertAtEnd(&head, 40);	

	insertAtStart(&head, 11);
	insertAtStart(&head, 12);
	insertAtStart(&head, 13);
	
	printList(head);



	deleteAt(&head, 0);
	deleteAt(&head, length(head) - 1);
	printList(head);	
	deleteAtEnd(&head);
	printList(head);

	deleteList(head);

	return 0;
}



Node* createNode(int data) {
	return new Node{data, NULL};
}

void printList(Node* head) {
	while(head != NULL) {
		std::cout << head->data << " ";
		head = head->next;
	}
	std::cout << std::endl;
}

void insertAtStart(Node** head, int data) {
	Node* node = createNode(data);	
	node->next = *head;
	*head = node;
}

void insertAtEnd(Node** head, int data) {
	while(*head != NULL) {
		head = &((*head)->next);		
	}
	*head = createNode(data);
}

void insertAt(Node** head, unsigned int index, int data) {
	if(index >= length(*head)) {
		std::cerr << "Error: Index out of bounds" << std::endl;
		return;
	}

		unsigned int count = 0;	
	while(*head != NULL) {
		if(count == index) {
			break;
		}
		head = &((*head)->next);
		count++;
	}
	Node* node = createNode(data);
	node->next = *head;
	*head = node;
}
	
unsigned int length(Node* head) {
	unsigned int result = 0;
	while(head != NULL) {
		head = head->next;	
		result++;
	}
	return result;
}

void deleteList(Node* head) {
	while(head) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

void deleteAtStart(Node** head) {
	if(*head == NULL) {
		return;
	}
	
	Node* temp = *head;
	*head = temp->next;
	delete temp;
}

void deleteAtEnd(Node** head) {
	if(*head == NULL) {
		return;
	}

	if((*head)->next == NULL) {
		delete *head;
		*head = NULL;
		return;
	}

	for(unsigned int i = 0; i < length(*head) - 1; i++) {
		head = &((*head)->next);
	}
	Node* temp = (*head)->next;
	(*head)->next = NULL;
	delete temp;
}

void deleteAt(Node** head, unsigned int index) {
	if(*head == NULL) {
		return;
	}

	if(index >= length(*head)) {
		std::cerr << "Error: Index out of bounds" << std::endl;
		return;
	}

	if(index == 0) {
		deleteAtStart(head);
		return;
	}

	for(unsigned int i = 0; i < index - 1; i++) {
		head = &((*head)->next);
	}

	Node* temp = (*head)->next;
	(*head)->next = temp->next;
	delete temp;
}




