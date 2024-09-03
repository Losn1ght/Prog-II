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
	int accountNumber;
	int balance;
}bankInfo;
 
typedef struct node{
	bankInfo data;
	struct node* next;
}Node;




void display(Node*); // done
void insertLast(Node**, char [], char [], int, int, int, int); //done
void transferBalance(Node**, int, int, int); //done
void withdraw(Node**, int, int); //done
void removeExpired(Node**); // done
void searchAcc(Node**, int);  // done
int countNodes(Node**); // done
int checkBalance(Node**, int); // done
void sortAccN(Node**); //  | sort by name alpabetical
void sortAccA(Node**); //  | sort by account number 





int main(){
    Node* head = NULL;
    int choice;

    insertLast(&head, "Jedd Christian", "Juab", 6, 28, 22102538, 150000);
    insertLast(&head, "Christian Gabriel", "Dela Cruz", 2, 30, 22104571, 50000);
    insertLast(&head, "Hiroshi", "Curimatmat", 1, 24, 22107943, 500000);
    insertLast(&head, "Lovely Kaye", "Garcia", 2, 22, 22100549, 150000);

    
    
    do{
    	
    	int fromAcc = 0;
 		int toAcc = 0;
  		int amount = 0;
  		int accountTowithdraw = 0;
  		int withdrawAmount = 0;
  		int accountTosearch = 0;
  		int accountTocheckbal = 0;
  		
        printf("---------------------\n");
        printf("WELCOME TO K&B BANK\n");
        printf("---------------------\n");
        printf("1. Check balance\n");
        printf("2. Withdraw\n");
        printf("3. Transfer balance\n");
        printf("4. Remove exipred accounts\n");
        printf("5. Search Account\n");
        printf("6. Sort Accounts\n");
        printf("7. Count Nodes\n");
        printf("8. Display Database\n");
        printf("9. Exit...\n");
        printf("Please select an option: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            	printf("Enter account number: ");
            	scanf("%d", &accountTocheckbal);
				printf("Balance: $%d\n\n", checkBalance(&head, accountTocheckbal)); 
                break;
            case 2:
            	printf("Enter your account: ");
            	scanf("%d", &accountTowithdraw);
            	printf("Enter amount to withdraw: ");
            	scanf("%d", &withdrawAmount);
            	withdraw(&head, accountTowithdraw, withdrawAmount);
                break;
            case 3:
                printf("Enter your account number: ");
                scanf("%d", &fromAcc);
                printf("Enter an account to transfer: ");
                scanf("%d", &toAcc);
                printf("Enter amount to transfer: ");
                scanf("%d", &amount);
                transferBalance(&head, fromAcc, toAcc, amount);
                break;
            case 4:
            	removeExpired(&head);
                break;
            case 5:
            	printf("Enter account to search: ");
            	scanf("%d", &accountTosearch);
            	searchAcc(&head, accountTosearch);
                break;
            case 6:
				sortAccN(&head);
                break;
            case 7:
				printf("Node count: %d\n\n", countNodes(&head));
                break;
            case 8:
                printf("\n\nDatabase\n");
                display(head);
                break;
            case 9:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice\n");
                break;


                
        }
    }while(choice != 9);


    return 0;
}

void sortAccN(Node** head) {
    Node *temp;
    Node *current;
    int swapped;

    // Checking for empty list or single node list
    if (*head == NULL || (*head)->next == NULL){
    	return;	
	}
    
    do {
        swapped = 0;
        current = *head;

        while (current->next != NULL) {
            if (strcmp(current->data.personName.lname, current->next->data.personName.lname) > 0) {
                // Swap data of two nodes
                temp = current->next;
                current->next = temp->next;
                temp->next = current;
                
                if (current == *head)
                    *head = temp;
                else {
                    Node *prev = *head;
                    while (prev->next != current)
                        prev = prev->next;
                    prev->next = temp;
                }
                swapped = 1;
            } else {
                current = current->next;
            }
        }
    } while (swapped);
}



int checkBalance(Node** head, int accNum){
	Node* current = *head;
	Node* foundAcc = NULL;
	int balance = 0;
	while(current != NULL){
		if(current->data.accountNumber == accNum){
			foundAcc = current;
			break;
		}
		current = current->next;
	}
	
	if(foundAcc == NULL){
		printf("\nAccount does not exist!\n\n");
		return;
	}
	
	balance = foundAcc->data.balance;
	
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

void searchAcc(Node** head, int accNum){
	Node* current = *head;
	int found = 0;
	
	while(current != NULL){
		if(current->data.accountNumber == accNum){
			found++;
			break;
		}
		current = current->next;
	}
	
	if(found == 0){
		printf("\nAccount not found!\n\n");
	}else{
		printf("\nAccount found in the database!\n\n");
	}

}

void removeExpired(Node** head){
	Node* expiredList = NULL;
	Node* current = *head;
	Node* prev = NULL;
	Node* temp = NULL;
	
	if(*head == NULL){
		printf("\nEMPTY LIST!\n\n");
		return;
	}
	
	while(current != NULL){
		if(current->data.expiryDate.year < 24){
			
			if(*head == current){
				temp = *head;
				*head = (*head)->next;
				temp->next = NULL;
				insertLast(&expiredList, temp->data.personName.fname, temp->data.personName.lname, temp->data.expiryDate.month, temp->data.expiryDate.year, temp->data.accountNumber, temp->data.balance);
				free(temp);
				current = *head; 
			}else{
				temp = current;
				prev->next = current->next;
				current = current->next;
				temp->next = NULL;
				insertLast(&expiredList, temp->data.personName.fname, temp->data.personName.lname, temp->data.expiryDate.month, temp->data.expiryDate.year, temp->data.accountNumber, temp->data.balance);
				free(temp);
			}
			
			
		}else{
			prev = current;
			current = current->next;
		}
	}
	if(expiredList == NULL){
		printf("\nNo expired account/s\n\n");
		return;
	}else{
		printf("\nRemoved expired accounts before 2024\n");
		printf("Expired Account/s List\n");
		display(expiredList);	
	}
	
					
}

void withdraw(Node** head, int accNum, int amount){
	Node* current = *head;
	Node* foundAcc =  NULL;
	
	// check if account exist
	while(current != NULL){
		if(current->data.accountNumber == accNum){
			foundAcc = current;
			break;
		}
		current = current->next;
	}
	
	if(foundAcc == NULL){
		printf("\nERROR! Account does not exist!\n\n");
		return;
	}
	
	
	// check if  account have enough balance
	if(foundAcc->data.balance < amount){
		printf("\nERROR! Not enough balance!\n\n");
		return;
	}

	// perform withdrawal
	foundAcc->data.balance -= amount;
	printf("\nWithdraw successful!\n\n");
}

void transferBalance(Node** head, int fromAcc, int toAcc, int amount){
    Node* current = *head;
    Node* checkFA = NULL;
    Node* checkTA = NULL;
    
    // check if accounts exist
    while (current != NULL) {
        if (current->data.accountNumber == fromAcc) {
            checkFA = current;
        } else if (current->data.accountNumber == toAcc) {
            checkTA = current;
        }
        current = current->next;
    }

    if(checkFA == NULL || checkTA == NULL){
        printf("\nERROR! Account/s does not exist!\n\n");
        return;
    }
    

    // Check if account have enough balance to transfer
    if(checkFA ->data.balance < amount){
        printf("\nERROR! Not enough balance to transfer!\n\n");
        return;
    }

    checkFA ->data.balance -= amount;
    checkTA->data.balance += amount;
    printf("\nTransfer Successful!\n\n");
    
}

void display(Node* head){
    Node* current = head;

    printf("%-20s %-20s %-20s %-20s\n", "First Name", "Last Name", "Account Number", "Balance");
    printf("-----------------------------------------------------------------------------\n");
    while(current != NULL){
        printf("%-20s %-20s %-20d $%-20d\n", current->data.personName.fname, current->data.personName.lname, current->data.accountNumber, current->data.balance);
        current = current->next;
    }
    printf("-----------------------------------------------------------------------------\n");
    printf("\n\n");
}

void insertLast(Node** head, char fname[], char lname[], int mnth, int yr, int accNum, int balance){
    Node* newNode = malloc(sizeof(Node));

    strcpy(newNode->data.personName.fname, fname);
    strcpy(newNode->data.personName.lname, lname);
    newNode->data.expiryDate.month = mnth;
    newNode->data.expiryDate.year = yr;
    newNode->data.accountNumber = accNum;
    newNode->data.balance = balance;
    
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
