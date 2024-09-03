#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char fname[20];
	char lname[20];
}name;
 
typedef struct{
	int month;
	int year;
}date;
 
typedef struct{
	name personName;
	date expiryDate;
	int idNum;
	int balance;
}bankInfo;
 
typedef struct node{
	bankInfo data;
	struct node* next;
}Node;




void display(Node*);
void insertLast(Node**, char [], char [], int, int, int, int);
void transferBalance(Node**, int, int, int);
void withdraw(Node**, int, int);
void removeExpired(Node**);
void searchAcc(Node**, int);
int countNodes(Node**);
int checkBalance(Node**, int);
void sortAcc(Node**);


int main(){
	Node* head = NULL;
	
	insertLast(&head, "Jedd Christian", "Juab", 6, 2025, 22102600, 100000);
	insertLast(&head, "Hiroshi", "Curimatmat", 3, 2027, 22102140, 500000);
	insertLast(&head, "Christian", "Dela Cruz", 3, 2020, 22102341, 1000000);
	
	printf("Database:\n");
	display(head);
	printf("\n\n");
	
//	transferBalance(&head, 22102538, 22102541, 100000);
//	withdraw(&head, 22102540, 100000);
//	removeExpired(&head);
//	searchAcc(&head, 22102539);
//	printf("\nNode Count: %d\n\n", countNodes(&head)); 
//	
//	int accnum;
//	printf("Check balance\n");
//	printf("Enter account number: ");
//	scanf("%d", &accnum);
//	int cv = checkBalance(&head, accnum);
//	printf("Balance of account number %d: $%d\n\n",accnum, cv);
	
	sortAcc(&head);
	
	printf("Updated Database:\n");
	display(head);
	
	return 0;
}
void sortAcc(Node** head){
	int swapped;
	Node* ptr1;
	Node* lptr = NULL;
	bankInfo temp;
	
	if(*head == NULL){
		printf("Empty List!\n");
		return;
	}
	
	do{
		swapped = 0;
		ptr1 = *head;
		
		while(ptr1->next != lptr){
			if(ptr1->data.idNum > ptr1->next->data.idNum){
				temp = ptr1->data;
				ptr1->data = ptr1->next->data;
				ptr1->next->data = temp;
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
		
		
	}while(swapped);
}

int checkBalance(Node** head, int accNum){
	int balance = 0;
	int checkacc = 0;
	Node* current = *head;
	
	
	
	while(current != NULL){
		if(current->data.idNum == accNum){
			checkacc++;
			balance = current->data.balance;
			return balance;
		}
		current = current->next;
	}
	
	if(checkacc == 0){
		printf("Account does not exist!\n\n");
	}
	
	
	return balance;
	
}

int countNodes(Node** head){
	Node* current = *head;
	int count = 0;
	while(current != NULL){
		count++;
		current = current->next;
	}
	return count;
}

void searchAcc(Node** head, int account){
	Node* current = *head;
	
	while(current != NULL){
		if(current->data.idNum == account){
			printf("\nAccount found!\n");
			break;
		}
		current = current->next;
	}
	
	printf("Account does not exist!\n");
}

void display(Node* head){
	Node* current = head;
	
	printf("%-20s %-20s %-20s %-20s\n", "First Name", "Last Name", "Account Number", "Balance");
    printf("-----------------------------------------------------------------------------\n");
	while(current != NULL){
		printf("%-20s %-20s #%-20d $%-20d\n", current->data.personName.fname, current->data.personName.lname, current->data.idNum, current->data.balance);
		current = current->next;
	}
}
void removeExpired(Node** head){
	Node* expiredList = NULL;
	Node* temp = NULL;
	Node* current = *head;
	Node* prev = NULL;
	
	while(current != NULL){
		if(current->data.expiryDate.year < 2024){
			
			if(current == *head){
				temp = *head;
				*head = (*head)->next;
				temp->next = NULL;
				insertLast(&expiredList, temp->data.personName.fname, temp->data.personName.lname, temp->data.expiryDate.month, temp->data.expiryDate.year, temp->data.idNum, temp->data.balance);
				free(temp);
				current = *head;
			}else{
				temp = current;
				prev->next = current->next;
				current = current->next;
				temp->next = NULL;
				insertLast(&expiredList, temp->data.personName.fname, temp->data.personName.lname, temp->data.expiryDate.month, temp->data.expiryDate.year, temp->data.idNum, temp->data.balance);
				free(temp);
			}
		}else{
			prev = current;
			current = current->next;
		}
	}
	if(expiredList == NULL){
		printf("No expired accounts!\n\n");
		return;
	}else{
		printf("Expired List:\n");
		display(expiredList);	
		printf("\n\n");
	}
		
}

void withdraw(Node** head, int accNum, int balance){
	Node* current = *head;
	Node* foundAC = NULL;
	
	while(current != NULL){
		if(current->data.idNum == accNum){
			foundAC = current;
			break;
		}
		current =  current->next;
	}
	
	if(foundAC == NULL){
		printf("ERROR! Account does not exist in the database!\n\n");
		return;
	}
	
	if(foundAC->data.balance < balance){
		printf("ERROR! Not enough balance!\n\n");
		return;
	}
	
	foundAC->data.balance -= balance;
	printf("Withdraw successful!...\n\n");
	
}

void transferBalance(Node** head, int fromAcc, int toAcc, int balance){
	Node* current = *head;
	Node* foundFA = NULL;
	Node* foundTA = NULL;
	
	while(current != NULL){
		if(current->data.idNum == fromAcc){
			foundFA = current;
		}else if(current->data.idNum == toAcc){
			foundTA = current;
		}
		current = current->next;
	}

	if(foundTA == NULL || foundFA == NULL){
		printf("Account/s does not exist in the database!\n\n");
		return;
	}	
	
	if(balance > foundFA->data.balance){
		printf("ERROR! Not enough balance!\n\n");
		return;
	}
	
	foundFA->data.balance -= balance;
	foundTA->data.balance += balance;
	printf("Transfer successfull...\n\n");
}

void insertLast(Node** head, char fname[], char lname[], int mnth, int yr, int accNum, int balance){
	Node* newNode = malloc(sizeof(Node));
	Node* current = *head;
	
	strcpy(newNode->data.personName.fname, fname);
	strcpy(newNode->data.personName.lname, lname);
	newNode->data.expiryDate.month = mnth;
	newNode->data.expiryDate.year = yr;
	newNode->data.idNum = accNum;
	newNode->data.balance = balance;
	
	newNode->next = NULL;
	
	if(*head == NULL){
		*head = newNode;
		return;
	}
	
	while(current->next != NULL){
		current = current->next;
	}
	
	current->next = newNode;
}
