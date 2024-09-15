#include <stdio.h>
#include <string.h>

struct Student {
    	char name[50];
    	int id;
    	char emailId[50];
};

int choice() {
	int c;
	printf("enter the sorting algorithm you want \nBubble sort (enter 1) \t Selection sort (enter 2) \t Insertion sort (enter 3) \n");
	scanf("%d",&c);
	if (c==1 || c==2 || c==3) return c;
	printf("wrong input");
	choice();
}

void display(struct Student students[], int n){
    	printf("ID\tName\temail\n");
    	for (int i = 0; i < n; i++){
        	printf("%d\t%s\t%s\n", students[i].id, students[i].name, students[i].emailId);
    	}
    	printf("\n");
}

void bubbleSort(struct Student students[], int n){
    	for (int i = 0; i < n - 1; i++){
        	for (int j = 0; j < n - i - 1; j++){
            		if (students[j].id > students[j + 1].id){
                		struct Student temp = students[j];
                		students[j] = students[j + 1];
                		students[j + 1] = temp;
            		}
        	}
    	}
}

void insertionSort(struct Student students[], int n){
    	for (int i = 1; i < n; i++){
        	struct Student key = students[i];
        	int j = i - 1;
        	while (j >= 0 && students[j].id > key.id){
            		students[j + 1] = students[j];
            		students[j] = key;
            		j--;
        	}
        	students[j + 1] = key;
    	}
}


void selectionSort(struct Student students[], int n){
	for (int i = 0; i < n - 1; i++){
        	int small = i;
        	for (int j = i + 1; j < n; j++){
            		if (students[j].id < students[small].id){
                		small = j;
            		}
        	}
        	struct Student temp = students[small];
        	students[small] = students[i];
        	students[i] = temp;
    	}
}

int main() {
	int n;

    	printf("Enter the number of students: ");
    	scanf("%d", &n);
		struct Student students[n];

    	for (int i = 0; i < n; i++){
        	printf("Enter details for student %d\n", i + 1);
        	printf("ID: ");
        	scanf("%d", &students[i].id);
        	printf("Name: ");
        	scanf("%s", students[i].name);
        	printf("EmailID: ");
        	scanf("%s", students[i].emailId);
    	}

	int c = choice();

    	printf("\nOriginal student database:\n");
    	display(students, n);
    	
	switch (c) {
		case 1 : bubbleSort(students, n);
    			 printf("Student database sorted using Bubble Sort:\n");
    			 display(students, n);
    			 break;
    			 
    		case 2: insertionSort(students, n);
    			printf("Student database sorted using Insertion Sort:\n");
    			display(students, n);
    			break;
    			
    		case 3: selectionSort(students, n);
    			printf("Student database sorted using Selection Sort:\n");
    			display(students, n); 
    			 break;
	}




return 0;
}
