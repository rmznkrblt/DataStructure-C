#include<stdio.h> 
#include<stdlib.h> 

struct queueNode 
{ 
	int data; 
	struct queueNode* next; 
}; 

struct queueNode* front=NULL;
struct queueNode* rear=NULL;
int isItPrime; //1 asal 0 degil

void printMiddle(struct queueNode *front)
{ 
	struct queueNode *slow_ptr = front; 
	struct queueNode *fast_ptr = front; 

	if (front!=NULL) 
	{ 
		while (fast_ptr != NULL && fast_ptr->next != NULL) 
		{ 
			fast_ptr = fast_ptr->next->next; 
			slow_ptr = slow_ptr->next; 
		} 
		printf("\nortadaki eleman : %d\n\n", slow_ptr->data); 
	} 
} 
void enqueue(struct queueNode** head_ref, int new_data) 
{ 
	struct queueNode* new_queueNode = 
		(struct queueNode*) malloc(sizeof(struct queueNode)); 
	new_queueNode->data = new_data; 
	new_queueNode->next = (*head_ref); 
	(*head_ref) = new_queueNode; 
} 

void printList(struct queueNode *ptr) 
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
	struct queueNode* head = NULL; 
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
			enqueue(&head, number); 
			
		}else
			goto flag;
			
	} 
	printf("Queue :"); 
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

