#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};
struct Node* st=NULL;
//Insert at front
void Insert_Front(){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL)   printf("Memory has not Space");
    else{
        int val;
        printf("Enter Data for Insert : ");
        scanf("%d",&val);
        newnode->data = val;
        newnode->prev = NULL;
        newnode->next = st;
        if(st != NULL){
            st->prev=newnode;
        }
        st=newnode;
    }
}
//Insert at end
void Insert_End(){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL)   printf("Memory has not Space");
    else{
        if(st==NULL)
            Insert_Front();
        else{
            int val;
            printf("Enter Data for Insert : ");
            scanf("%d",&val);
            struct Node* ptr = st;
            newnode->data = val;
            newnode->next = NULL;
            while(ptr->next != NULL)
                ptr=ptr->next;
            newnode->prev = ptr;
            ptr->next = newnode;
        }
    }
}
//Insert at After a node
void Insert_After_Node(){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL)   printf("Memory has not Space\n");
    else{
        if(st==NULL)
            printf("We need atleat 1 node!\n");
        else{
            int val,sval;
            printf("Enter the node value after which you wanna insert:  ");
            scanf("%d",&sval);
            struct Node* ptr = st;
            while(ptr->data != sval){
                if(ptr->next != NULL)
                    ptr=ptr->next; 
                else {
                    printf("Value is Not present!\n");
                    return;
                }  
            }
            if(ptr->next == NULL)
                Insert_End();
            else{
                printf("Enter Data for Insert : ");
                scanf("%d",&val);
                newnode->data = val;
                newnode->next = ptr->next;
                newnode->prev = ptr;
                ptr->next = newnode;
            } 
        }
    }
}
// Insert Before a Node 
void Insert_Before_Node(){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL)   printf("Memory has not Space\n");
    else{
        if(st==NULL)    printf("We need atleat 1 node!\n");
            
        else{
            int val,sval;
            printf("Enter the node value before which you wanna insert:  ");
            scanf("%d",&sval);
            struct Node* ptr = st; 
            if(ptr->data == sval)
                Insert_Front();
            
            else{
                while(ptr->next->data != sval){
                    if(ptr->next != NULL)
                        ptr=ptr->next;
                    else {
                        printf("Value is Not present!\n");
                        return;
                    }
                }
                printf("Enter Data for Insert : ");
                scanf("%d",&val);
                newnode->data = val;
                newnode->next=ptr->next;
                newnode->prev=ptr;
                ptr->next=newnode; 
            }
        }
    }
}
//Function to delete 1st node...
void Delete1stNode(){
    struct Node* ptr=st;
    if(st==NULL)    return ;
    else if(st->next == NULL)   {
        st = NULL;
    } 
    else{
        st=st->next;
        st->prev =NULL;
        //OR
        // st->next->prev = st->prev;
        // st=st->next;  
    }
    free(ptr);
}
//Function to delete last node...
void deleteLastNode(){
    struct Node* ptr=st;
    if(st==NULL)    return ;
    else if(st->next == NULL)   st = NULL;
    else{
        struct Node* pre;
        while(ptr->next != NULL){
            pre=ptr;
            ptr=ptr->next;
        } 
        pre->next=ptr->next;
    }
    free(ptr);
}
// Function to delete after a node..
void DeleteAfterNode(){
	if(st == NULL)  return ;
    else if(st->next == NULL)   printf("please Insert a Node!\n");
    else{
        struct Node* temp;
        int val;
        printf("Enter the node value after which you wanna delete: ");
        scanf("%d",&val);
        if(st->data == val){        //If value is present in 1st node
            temp = st->next;
            if(temp->next != NULL)
                temp->next->prev=temp->prev;
            st->next = temp->next;
        }
        else{
            struct Node* ptr=st;
            while(ptr->next->data != val){
                ptr=ptr->next;
                if(ptr->next == NULL){
                    printf("Value is Not Present!\n");
                    return;
                } 
            }
            temp=ptr->next->next;
            if(temp == NULL)     printf("Last Node!\n");
            else if(temp->next == NULL){
                ptr->next->next = NULL;
            }
            else{
                temp->next->prev = ptr->next;
                ptr->next->next = temp->next;
            }
        }
        free(temp);
    }
}
//Function to delete before a node...
void DeleteBeforeNode(){
    if(st == NULL)  return ;
    else if(st->next == NULL)   printf("Please Insert a Node!\n");
    else{
        struct Node* temp;
        int val;
        printf("Enter the node value before which you wanna delete: ");
        scanf("%d",&val);
        if(st->data == val){        //If value is present in 1st node
            printf("This is 1st Node.\n");
        }
        else{
            
            if(st->next->data == val){
                temp=st->next->prev;        //temp = st;
                st->next->prev = st->prev;
                st=temp->next;
            }
            else{
                struct Node* ptr=st;
                struct Node* pre;
                while(ptr->next->data != val){
                    pre =ptr;
                    ptr=ptr->next;
                    if(ptr->next == NULL){
                        printf("Value is Not Present!\n");
                        return;
                    }
                }
                temp=ptr;
                pre->next = temp->next;
                ptr->next->prev = pre;      // = temp->prev
            }
            free(temp);
        }
    }    
}
//List Printing...
void display(){
    if(st==NULL)    printf("List is Empty!");
    else{
        struct Node* ptr=st;
        while(ptr != 0){
            printf("(%p %d %p)",ptr->prev,ptr->data,ptr->next);
            ptr=ptr->next;
            if(ptr!=NULL)  printf(" , ");
        }
    }
}
int main(){
    int ch;
    while(1){
        printf("\n\n**Main Menu For Double List**\n");
		printf("1.Insert at beginning \n2.Insert at Ending \n3.Insert After a Node \n4.Insert Before a Node\n5.Delete 1st Node \n");
        printf("6.Delete Last Node \n7.Delete After a Node\n8.Delete Before a Node\n9.Display \n");
		printf("10.Exit \n");
		printf("Enter Your Option: ");
		scanf("%d",&ch);
		switch (ch){
			case 1: Insert_Front();
					display();
					break;
			 case 2: Insert_End();
					display();
					break;
			case 3: Insert_After_Node();
					display();
					break;
			case 4: Insert_Before_Node();
					display();	
					break;
            case 5: Delete1stNode();
                    display();
					break;
            case 6: deleteLastNode();
                    display();
					break;
			case 7: DeleteAfterNode();
                    display();
					break;
			case 8: DeleteBeforeNode();
                    display();
					break;
            case 9: if(st!=NULL)	display();
					 else	printf("\nList is Empty!\n");
					 break;
			case 10: exit(0);
			default: printf("Invalid choice");
		}
	}
    return 0;
}