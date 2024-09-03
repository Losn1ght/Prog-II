#include <stdio.h>
#include <stdlib.h>

void bubsort(int arr[], int s);
void insertsort(int arr[], int s);
void selectsort(int arr[], int s);


int linearsearch(int arr[], int target, int s);
int binsearch(int arr[], int target, int s);

int main(){
	
	int arr[] = {3, 7, 4, 9, 5, 2, 6, 1};	
	int size = sizeof(arr)/sizeof(arr[0]);
	int i, find;
	
	// insert sort
	// start index 1
	// 8, 12, 4, 6, 10, 2
	// 4, 8, 12, 6, 10, 2
	// 4, 6, 8, 12, 10, 2
	// 4, 6, 8, 10, 12, 2
	// 2, 4, 6, 8, 10, 12s
	
	
	
	// select sort
	// iterate and find the minimum value
	// exchange places to its corresponding indexes
	// 2, 8, 4, 6, 10, 12
	// 2, 4, 8, 6, 10, 12
	// 2, 4, 6, 8, 10, 12
	// 2, 4, 6, 8, 10, 12
	// 2, 4, 6, 8, 10, 12

	
	
	// bub sort
	// compare adjacent elements
	// 8, 4, 6, 10, 2, 12
	// 4, 6, 8, 2, 10, 12
	// 4, 6, 2, 8, 10, 12
	// 4, 2, 6, 8, 10, 12
	// 2, 4, 6, 8, 10, 12
	

	
	
	
//	printf("Enter a number you want to find within the array: ");
//	scanf("%d", &find);

//	int num = linearsearch(arr, find, size);
//	(num != -1) ? printf("Number %d is found at index %d\n", find, num) : printf("Error! Number cannot be found!\n");
	
//	printf("Bubble sort: \n");
//	bubsort(arr, size);
	
	printf("Insertion sort: \n");
	insertsort(arr, size);
	
//	printf("Selection sort: \n");
//	selectsort(arr, size);
	
//	int num = binsearch(arr, find, size);
//	(num != -1) ? printf("Number %d is found at index %d\n", find, num) : printf("Error! Number cannot be found!\n");


	return 0;
}
void selectsort(int arr[], int s){
	int i, j, x;
	int temp;
	int count = 0;
	int min;
	
	for(i = 0; i < s - 1; i++){
		min = i;
		for(j = i + 1; j < s; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
	
	
}


void insertsort(int arr[], int s){
	int i, j, x, key;
	int count = 0;
	
	for(i = 1; i < s; i++){
		key = arr[i];
		j = i - 1;
		while(j >= 0  && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	
		
	}	
}
void bubsort(int arr[], int s){
	int i, j, x;
	int temp;
	int count = 0;
	
	for(i = 0; i < s - 1; i++){
		for(j = 0; j < s - i - 1;j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
			
		}
	}	
}


int binsearch(int arr[], int target, int s){
	int i, j;
	int mid;
	int low = 0;
	int high = s - 1;
	int val;
	
	for(i = 0; i < s; i++){
		mid = low + (high - low) / 2;
		val = arr[mid];
			if(val < target){
				low = mid + 1;
			}else if(val > target){
				high = mid - 1;
			}else{
				return mid;
			}
	}
	

	return -1;
}

int linearsearch(int arr[], int target, int s){
	int i;
	
	for(i = 0; i < s; i++){
		if(arr[i] == target){
			return i;
		}
	}
	return -1;
}

