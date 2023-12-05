#include<stdio.h>
#include<stdlib.h>

//Define a structure for a node of Linked List
struct Node{
    int data;
    struct Node* link;
};
struct Node* head=NULL;
int data;
  
////FUNCTION CREATE A NODE
struct Node* createNode(){
		printf("\nEnter the data for Insert In a Node: ");
		scanf("%d",&data);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}
//Function To Display List..........
void  printLinkedList(){
	printf("\nNow Your  List : \n");
    struct Node* ptr = head;
    while (ptr!=NULL){
        printf("(%d , %p), ", ptr->data,ptr->link);
        ptr = ptr->link;
    }
}
//FUNCTION INSERTING AT FRONT
void InsertAtFront(){
	struct Node* newNode = createNode();
    newNode->link = head;
    head = newNode;
}
//FUNCTION INSERTING AT END
void InsertAtEnd()
{
	struct Node *newNode = createNode();
	struct Node *ptr = head;
	
	while (ptr->link != NULL)
	{
		ptr=ptr->link;
		if (head == NULL)
		{
			head = newNode;
			return;
		}
	}
	ptr->link = newNode;
}

//Function To Insert After a Node..... 
void AfterNode(){
	
	int val;
	struct Node* newNode = createNode();
	printf("Enter The Searching Value :");
	scanf("%d",&val);
	struct Node* ptr=head;
	while(ptr->data !=val){
		ptr=ptr->link;
		if (head==NULL)
		{
			printf("There is No Node. Please First Insert a Node !");
			return ;
		}
		
		if(ptr==NULL){
			printf("Searching Value is Not present Here");
			return ;
		}
		else	continue;
	}
	newNode->link=ptr->link;
	ptr->link=newNode;
}
//Function To Insert Before a Node.....
void BeforeNode(){
	if(head==NULL){
		printf("There is No Node. Please First Insert a Node !");
		return ;
	}
	
	int val;
	if(head->link==NULL){
		InsertAtFront();
	}
	struct Node* newNode = createNode();
	printf("Enter the node value after which you wanna insert:  ");
	scanf("%d",&val);
	struct Node* ptr=head;
	if(ptr->data == val){
		 newNode->link=ptr;
		 head=newNode;
		 return ;
	}
	else{	
		struct Node* prev;
		while(ptr->data !=val){
			prev=ptr;
			ptr=ptr->link;
			if(ptr==NULL)
				printf("Value is Not present!\n");
			
			else	continue;
		}
			newNode->link=ptr;
			prev->link=newNode;
	}
}

//Function To Delete a Node From Front.....
void DeleteFirstNode(){
	if(head==NULL){
	 	printf("List Empty\n");
		return ;
	}
    struct Node* temp=head;
    head=head->link;
    free(temp);
}
//Function To Delete a Node From End.....
void DeleteLastNode(){
	struct Node* ptr=head;
    struct Node* prev;
    if(head==NULL){
	 	printf("List Empty");
		 return ;
	}
    else if(head->link == NULL){
        head=NULL;
		free(ptr);
		return ;
    }
    while(ptr->link != NULL){
        prev=ptr;
        ptr=ptr->link;
    }
    prev->link=NULL;
    free(ptr);
}

//Function For Delete After A Node....
void DeleteAfterNode(){
	if(head==NULL){
	 	printf("List Empty\n");
		return ;
	}
	else if(head->link == NULL)	{
		printf("Please First Insert a Node!");
		return ;
	}	
	else{
		int val;
		printf("Enter the node value after which you wanna delete:  ");
		scanf("%d",&val);
		struct Node* ptr = head;
		struct Node* temp;
		while(ptr->data != val){
			ptr=ptr->link;
			if(ptr==NULL){
				printf("Value is Not Present!\n");
				return ;
			}	
		}
		temp=ptr->link;
		if(temp != NULL){
			ptr->link=temp->link;
			free(temp);
			return ;
		}
		else{
			printf("It is Last Node!\n");
			return;
		}	
	}
}

//Function For Delete Before A Node....
void DeleteBeforeNode(){
	if(head==NULL){
	 	printf("List Empty");
		return ;
	}
	else if(head->link == NULL)	{
		printf("Please First Insert a Node!");
		return ;
	}
	else{
		int val;
		printf("Enter the node value before which you wanna delete:  ");
		scanf("%d",&val);
		struct Node* ptr = head;
		if(ptr->link->data == val){
			head=ptr->link;
			free(ptr);
			return ;
		}
		else{
			struct Node* temp;
			while(ptr->link->data != val){
				temp = ptr;
				ptr=ptr->link;
				if(ptr->link == NULL){
					printf("Value is Not Present!\n");
					return;
				}
			}
			temp->link = ptr->link;
			free(ptr);
		}
	}
}
		
int main(){
	int choice;
	
	while(1){
		printf("\n\n1.Insert at beginning \n");
		printf("2.Insert at Ending \n");
		printf("3.Insert After a Node \n");
		printf("4.Insert Before a Node\n");
        printf("5.Delete 1st Node \n");
        printf("6.Delete Last Node \n");
		printf("7.Delete After a Node\n");
		printf("8.Delete Before a Node\n");
		printf("9.Display the List\n");
        printf("10.Exit \n");
		printf("\nEnter Your Option: ");
		scanf("%d",&choice);
		switch (choice){
			case 1: InsertAtFront();
					printLinkedList();
					break;
			case 2: InsertAtEnd();
					printLinkedList();
					break;
			case 3: AfterNode();
					if(head != NULL)printLinkedList();
					break;
			case 4: BeforeNode();
					if(head!=NULL)	printLinkedList();	
					break;
            case 5: DeleteFirstNode();
                    printLinkedList();
					break;
            case 6: DeleteLastNode();
                    printLinkedList();
					break;
			case 7: DeleteAfterNode();
                    printLinkedList();
					break;
			case 8: DeleteBeforeNode();
                    printLinkedList();
					break;	
            case 9: if(head!=NULL)	printLinkedList();
					 else	printf("\nList is Empty!\n");
					 break;
			case 10: exit(0);
			default: printf("Invalid choice");
		}
	}
	return 0;
}