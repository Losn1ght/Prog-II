#include <stdio.h>
#include <stdlib.h>

// Self-Referential Structure
typedef struct node{
	int data;
	struct node *next;
}Node;

void insertFront(Node **, int); // This function will insert front in the Linked list
void insertLast(Node**, int); // This function will insert last in the Linked List
void insertAt(Node**, int, int);
void deleteFront(Node**);  // This function will delete whatevers in Front in the Linked List
void deleteLast(Node**); //  This function will delete whatevers in Last in the Linked List
void deleteAt(Node**, int);
void display(Node*); // Displays the data in the link list
int length(Node*); 	//Given a linked list head pointer, compute and return the number of nodes in the list.
Node* findEven(Node*); // Create a function that will accept a linked list and return a new list that will contain all of the even numbers found in the initial list
int search(Node**, int searchFor); // This function searches for data inside the linked list and returns the position

int main(){
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;
	
	head = malloc(sizeof(Node));
	second = malloc(sizeof(Node));
	third = malloc(sizeof(Node));
	
	head->data = 20;
	head->next = second;
	
	second->data = 30;
	second->next = third;
	
	third->data = 40;
	third->next = NULL;
	
	insertFront(&head, 10);
	insertLast(&head, 51);
//	deleteFront(&head);
//	deleteLast(&head);
	
	printf("Original List: ");
	display(head);
	printf("\n");
	
	int l = length(head);
	printf(l == 0 ? "\n0 nodes in the list" : "\n%d nodes in the list", l);
	
	printf("\n");
	printf("Even numbers list: ");
	Node* displayEven = findEven(head);
	display(displayEven);
	
	return 0;
}

void deleteAt(Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (pos == 1) {
        // Deleting the first node
        Node* temp = *head;
        *head = (*head)->next;
        temp->next = NULL;
        free(temp);
        return;
    }

    Node* current = *head;
    Node* prev;
    int currentPos = 1;

    while (current != NULL && currentPos < pos) {
        prev = current;
        current = current->next;
        currentPos++;
    }

    if (currentPos != pos) {
        printf("Position out of bounds!\n");
        return;
    }

    // Unlink the node from the list
    prev->next = current->next;
    free(current);
}


void insertAt(Node** head, int num, int pos){
	Node* newNode = malloc(sizeof(Node));
	
	newNode->data = num;
	
	if(*head == NULL || pos == 1){
		*head = newNode;
		newNode->next = NULL;
	}else{
		Node* current = *head;
		int currentPos = 1;
		
		// Traverse the list to find the position
		while(currentPos < pos - 1 && current->next != NULL){
			current = current->next;
			currentPos++;
		}
		
		if(currentPos < pos - 1){
			printf("Position out of bounds!");
			free(newNode);
			return;
		}
		
		// Insert the new node at the specified position
		newNode->next = current->next; 
		current->next = newNode;
		
	}
	
	
}


int search(Node** head, int searchFor){
	int pos = 1;
	
	Node* current = *head;
	
	while(current != NULL){
		if(current->data == searchFor){
			return pos;
		}
		current = current->next;
		pos++;
	}
	
	return 0;
}

Node* findEven(Node* head){
	Node* evenList = NULL;
	
	Node* current = head;
	
	while(current != NULL){
		if(current->data % 2 == 0){
			insertFront(&evenList, current->data);
		}
		current = current->next;
	}
	
	return evenList;
}

int length(Node* head){
	int count = 0;
	
	Node* current = head;
	
	while(current != NULL){
		count++;
		current = current->next;
	}
	
	return count;
	
}

void deleteLast(Node** head){
	Node* prev = NULL;
	Node* current = *head;
	
	while(current->next != NULL){
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	free(current);
	
}

void deleteFront(Node** head){
	
	if(*head == NULL){
		printf("List is empty!");
		return 0;
	}
	
	*head = (*head)->next;

	
	
}

void insertLast(Node** head, int num){
	Node* newNode = malloc(sizeof(Node));
	
	newNode->data = num;
	newNode->next = NULL;
	
	if(*head == NULL){
		*head = newNode;
		return;
	}
	
	Node* current = *head;
	
	while(current->next != NULL){
		current = current->next;	
	}
	
	current->next = newNode;
	
}


void insertFront(Node **head, int num){
	Node* newNode = malloc(sizeof(Node));
	
	newNode->data = num;
	newNode->next = *head;
	
	*head = newNode;
	
	
}

void display(Node* head){
	Node* current = head;
	

	while(current != NULL){
		printf("%d ", current->data);
		current = current->next;
	}
	
}
