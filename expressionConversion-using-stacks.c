#include<stdio.h> 
#include<stdbool.h>
#include<string.h>

int size = 5;
int top = -1;
char stack[25];

bool isempty() {
	return (top == -1);
}

bool isfull() {
	return (top == size-1);
}

void inputstr(char str[20]) {
	printf("enter the string: ");
	scanf("%s", str);
}

void push(char stack[25], char j){
	top++;
	stack[top] = j;
}

char pop(char stack[25]) {
	char elem  = stack[top];
	top--;
	return elem;
}

void display(char stack[5]) {
	if(!isempty()) {
		for(int i=0; i<=top; i++) {
			printf(" %c ", stack[i]);
		}
		printf("\n");
	}
	else printf("stack is empty");
}

void reverseStr(char str[20], char rstr[20]) {
	char temp[20];
	int l1 = strlen(str);
	for(int i=0; i<l1;i++) {
		push(temp, str[i]);
	}
	int l2 = strlen(temp);
	for(int i=0; i<l2; i++) {
		char elem = pop(temp);
		rstr[i] = elem;
	}
}

int icp(char c) {
	if(c == '(') return 5;
	else if(c == '^') return 4;
	else if(c =='*' || c == '/' || c == '%') return 2;
	else if(c == '+' || c == '-') return 1;
	else return 404;
}

int isp(char c){
	if(c == '(') return 0;
	else if(c == '^') return 3;
	else if(c =='*' || c == '/' || c == '%') return 2;
	else if(c == '+' || c == '-') return 1;
	else return 404;
}

bool operand(char c) {
	if (c=='(' || c==')' || c=='/' || c=='*' || c=='^' ||  c=='%' || c=='+' || c=='-') return false;
	else return true;
}

void infix_postfix(char infix[25], char postfix[25]) {
	int i = 0, k = 0;
	char tkn = infix[i];
	while(tkn != '\0') {
		if (operand(tkn)) {
			postfix[k] = tkn;
			k++;
		}
		
		else if (tkn == '(') {
			push(stack, '(');
		}
		
		else if (tkn == ')') {
			while(tkn = pop(stack) != '(') {
				postfix[k] = tkn;
				k++;
			}
		}
		
		else if (!operand(tkn)) {
			while(!isempty() && icp(tkn) <= isp(stack[top])) {
				postfix[k] = pop(stack);
				k++;
			}
			push(stack, tkn);
		}			
		else printf("error");
		
		i++;
		tkn = infix[i];
	}
	while (!isempty()) {
		postfix[k] = pop(stack);
		k++;
	}
}

int main() {
	char stack[5];
	int choice;
	printf("\nwhich operation you want");
	printf("\n1. Stack operations.");
	printf("\n2. String reversal.");
	printf("\n3. Expression Conversion.");
	printf("\n-> Your choice: ");
	scanf("%d", &choice);
	int ch, ch1;
	char str[25], revstr[256], j, elem, infix[25], postfix[25];
	switch (choice){
		case 1:  while(1) {
			  	printf("\n---Stack Operations---");
			  	printf("\n1. push element");
			 	printf("\n2. pop element");
			 	printf("\n3. Display stack");
			 	printf("\n4. exit program");
			  	printf("\nEnter your choice: ");
			  	scanf("%d",&ch);

				switch (ch) {
					case 1: if(!isfull()) {
							printf("enter the element: ");
							scanf("%s", &j);
							push(stack,j);
						}
						else printf("stack is full");
						break;
				
					case 2: if(!isempty()) {
							elem = pop(stack);
							printf("deleted element is %c", elem);
						}
						else printf("stack is empty");
						break;
				
					case 3: display(stack);
				 		break;
				 
					case 4: printf("Program ended successfully");
						return 0;
				
					default: printf("Invalid choice");
						break;
				}	
			}	
		case 2:  inputstr(str);
			  reverseStr(str, revstr);
			  printf("\nreversed string is: %s\n", revstr);
			  break;
			  
		case 3:   printf("\n--Expression Conversion--\n1. infix to postfix conversion\n2. postfix to infix conversionss");
			  printf("\n-> Your Choice: ");
			  scanf("%d", &ch1);
			  switch (ch1) {
			  	case 1: printf("\nenter the infix expression: ");
			  		 scanf("%s", infix);
			  		 printf("\nyour infix expression is: %s", infix);
			  		 infix_postfix(infix, postfix);
			  		 printf("\nyour postfix expression is: %s\n", postfix);
			  		 break;
			  }
	}
		
return 0;
}
