#include <stdio.h> 
#include <stdlib.h> 

struct linkedNode { 
    int data; 
    struct linkedNode* next; 
}; 
  
int isItPrime; //1 asal 0 degil

void printMiddle(struct linkedNode* head) 
{ 
    int count = 0; 
    struct linkedNode* mid = head; 
  
    while (head != NULL) { 
        if (count & 1) 
            mid = mid->next; 
  
        ++count; 
        head = head->next; 
    } 
    if (mid != NULL) 
        printf("\nortadaki eleman : %d\n\n", mid->data); 
} 

void insert(struct linkedNode** head_ref, int new_data) 
{ 
    struct linkedNode* new_linkedNode 
        = (struct linkedNode*)malloc(sizeof(struct linkedNode)); 
    new_linkedNode->data = new_data; 
    new_linkedNode->next = (*head_ref); 
    (*head_ref) = new_linkedNode; 
} 

void printList(struct linkedNode* ptr) 
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
	struct linkedNode* head = NULL; 
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
			insert(&head, number); 
			
		}else
			goto flag;
			
	} 
	printf("LinkedList :"); 
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
