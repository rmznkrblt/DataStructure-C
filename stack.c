#include<stdio.h> 
#include<stdlib.h> 

struct stackNode 
{ 
	int data; 
	struct stackNode* next; 
}; 

int isItPrime; //1 asal 0 degil

void printMiddle(struct stackNode *head) //Ortadaki elemaný yazdýran fonksiyon
{ 
	struct stackNode *slow_ptr = head; 
	struct stackNode *fast_ptr = head; 

	if (head!=NULL) 
	{ 
		while (fast_ptr != NULL && fast_ptr->next != NULL) 
		{ 
			fast_ptr = fast_ptr->next->next; 
			slow_ptr = slow_ptr->next; 
		} 
		printf("\nortadaki eleman : %d\n\n", slow_ptr->data); 
	} 
} 
int r=0;
void push(struct stackNode** head_ref, int new_data) 
{ 
	struct stackNode* new_stackNode = 
		(struct stackNode*) malloc(sizeof(struct stackNode)); 
	new_stackNode->data = new_data; 
	new_stackNode->next = (*head_ref); 
	(*head_ref) = new_stackNode; 
} 

void printList(struct stackNode *ptr) 
{ 
	while (ptr != NULL) 
	{ 
		printf("%d", ptr->data); 
		ptr = ptr->next;
		if(ptr != NULL){
			printf("->"); 
		}

	} 
} 

int main() 
{ 
	srand(time(NULL));
	struct stackNode* head = NULL; 
	int i,number=0; 

	for (i=0; i<5; i++) 
	{ 
		flag:
			isItPrime=1;
		number = rand()%100;
		while(isItPrime){
			CheckPrime(number);	
			if(isItPrime==0)
			goto flag;
			else break;
		}
		if(isItPrime){
			push(&head, number); 
			
		}else
			goto flag;
			
	} 
	printf("Stack :"); 
	printList(head); 
	printMiddle(head); 
	return 0; 
} 

int CheckPrime(int number){
	int i;
	if(number==0 || number ==1){
		isItPrime=0;
	}
	else{
		for(i=2;i<number;i++){
		if(number%i==0){
			isItPrime=0;
			break;
		}
			
		else isItPrime=1;
		}
	}
	
}

