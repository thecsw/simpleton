#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

node* insert(node* prev_node, int new_data) {
	if (prev_node == NULL) {
		printf("Can't do it in front of a null");
		return NULL;
	}
	node* new_node = (node*)malloc(sizeof(node));
	new_node->value = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
	return new_node;
}

void delete(node* head, node* entry) {
	node** indirect = &head;
	while((*indirect) != entry)
		indirect = &((*indirect)->next);	
	*indirect = entry->next;
}

void delete_one (node* head, node* entry) {
	node* indirect = head;
	while(indirect->next != entry)
		indirect = indirect->next;
	indirect = entry->next;
}

void append(node** head, int new_data) {
	node* new_node = (node*)malloc(sizeof(node));
	new_node->value = new_data;
	new_node->next = NULL;
	node* last = *head;

	if (*head == NULL) {
		*head = new_node;
		return;
	}

	while (last->next != NULL)
		 last = last->next;

	last->next = new_node;
}

void printlist(node* node) {
	while(node != NULL) {
		printf("\t%d\t(%#x)\n", node->value, node);
		node = node->next;
	}
}

int main(int argc, char** argv) {
	node *head = BuildList();
	push(&head, 10);
	push(&head, 100);
	printf("\n%d\n", head->value);
	delete(head, head->next);
	printlist(head);
	printf("\n\thead (%#x)\n\t&head (%#x)\n\t*(&head) (%#x)\n", head, &head, *(&head));
}
