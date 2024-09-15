#include<stdio.h>
#include<stdbool.h>
#include<string.h>

struct data {			//declaring structure
	int jobs;
	char name[10];
};
// initializing front and rear for linear queue 
int front = -1;
int rear = -1;
// initializing front and rear for circular queue 
int c_front = 0;
int c_rear = 0;
int size = 5;  //storing size of the queue in a global variable size

bool isfull() {		//checking full condition for linear queue
	if(rear == size-1) return true;
	return false;
}

bool isempty() {	//checking empty condition for linear queue
	if(rear == front) return true;
	return false;
}

bool circ_isfull() {	//checking full condition for circular queue
	if((c_rear+1)%size == c_front) return true;
	return false;
}

bool circ_isempty() {	//checking empty condition for circular queue
	if(c_rear == c_front) return true;
	return false;
}

void input(int *j,char n[10]) {		//taking input for adding element 
	printf("\nenter the job number:  ");
	scanf("%d",j);
	printf("enter the job name:  ");
	scanf("%s",n);
}

void circ_enqueue(struct data q[]) {	//add element - circular queue
	if(!circ_isfull()) {
		int j;
		char n[10];
		input(&j,n);
		c_rear = (c_rear+1)%size;
		q[c_rear].jobs = j;
		strcpy(q[c_rear].name, n);
		printf("job added succesfully\n");
	}
	else printf("queue is full\n");
}

void circ_dequeue(struct data q[]) {	//delete element - circular queue
	if(!circ_isempty()) {
		c_front= (c_front+1)%size;
		printf("deleting element (%d, %s)\n", q[c_front].jobs, q[c_front].name);
	}
	else printf("queue is empty\n");
}

void enqueue(struct data q[]) { 	//add element = linear queue
	if(!isfull()) {
		int j;
		char n[10];
		input(&j,n);
		rear++;
		q[rear].jobs = j;
		strcpy(q[rear].name, n);
		printf("job added succesfully\n ");
	}
	else printf("queue is full\n");
}

void dequeue(struct data q[]) {		//delete element - circular queue
	if(!isempty()) {
		front++;
		printf("deleting element (%d, %s)\n", q[front].jobs, q[front].name);
		q[front].jobs = 0;
		strcpy(q[front].name,"");
	}
	else printf("queue is empty\n");
}

void circ_display(struct data q[]) { 	//display elements - circular queue
	printf("\n");
	if(!circ_isempty()) {
		printf("the queue is: ");
		int i = c_front+1;
		while (i != (c_rear+1)%size) {
			printf(" (%d, %s) ",q[i].jobs,q[i].name);
			i = (i+1)%size;
		}
		printf("\n");
	}
	else printf("queue is empty \n");
}


void display(struct data q[]) {		//display elements - linear queue
	printf("\n");
	if(!isempty()) {
		printf("the queue is: ");
		for (int i = front+1;i<=rear;i++) {
			printf(" (%d, %s) ",q[i].jobs,q[i].name);
		}
		printf("\n");
	}
	else printf("queue is empty \n");
}



int main() {
	struct data q[5];				//initialized structure for storing jobs
	int ch;
	int choice;
	printf("\nwhich program do you want: \n1. Linear queue operations \n2. Circular queue operations\n");
	scanf("%d",&choice);
	if (choice == 1) {
		while (true) {
			printf("\n---Linear Queue Operations---");
			printf("\n1. Add element");
			printf("\n2. Delete element");
			printf("\n3. Display queue");
			printf("\n4. exit program");
			printf("\nEnter your choice: ");
			scanf("%d",&ch);
			
			switch (ch) {
				case 1: enqueue(q);
						break;
				case 2: dequeue(q);
						break;
				case 3: display(q);
						break;
				case 4: printf("Program ended successfully");
						return 0;
				default: printf("Invalid choice");
						break;
			}
		}
	}
	 
	else {
		while (true) {
			printf("\n---Circular Queue Operations---");
			printf("\n1. Add element");
			printf("\n2. Delete element");
			printf("\n3. Display queue");
			printf("\n4. exit program");
			printf("\nEnter your choice: ");
			scanf("%d",&ch);
	
			switch (ch) {
				case 1: circ_enqueue(q);
						break;
				case 2: circ_dequeue(q);
						break;
				case 3: circ_display(q);
						break;
				case 4: printf("Program ended successfully\n");
						return 0;
				default: printf("Invalid choice");
						break;
			}
		}
				
	}	
}
