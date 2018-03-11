#include<stdio.h>
#include<stdlib.h>

typedef struct nodejs {
	int value;
	struct nodejs* next;
} node;

node* BuildList(){
	node* head = NULL;
	
	for (int i = 5; i >= 0; i--) {
		node* newNode = (node*)malloc(sizeof(node));
		newNode->value = i;
		newNode->next = head;
		head = newNode;
	}
	return head;
}

void push(node** head_ref, int new_data) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->value = new_data;
	newNode->next = (*head_ref);
	(*head_ref) = newNode;
}

void insert(node* prev_node) {

}

void printlist(node* node) {
	while(node != NULL) {
		printf("\t%d\t(%#x)\n", node->value, node);
		node = node->next;
	}
}

int main() {
	node *head = BuildList();
	push(&head, 10);
	printlist(head);
}
