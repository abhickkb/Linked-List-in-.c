

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node of Linked List
struct Node
{
    int data;
    struct Node *link;
};
struct Node *head = NULL;
int data, pos;

////FUNCTION CREATE A NODE
struct Node *createNode()
{
    printf("\nEnter the data for Insert In a Node: ");
    scanf("%d", &data);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    return newNode;
}
// FUNCTION INSERTING AT FRONT
struct Node *InsertAtFront()
{
    struct Node *newNode = createNode();
    if (head == NULL)
    {
        newNode->link = newNode;
    }
    else
    {
        struct Node *ptr = head;
        while (ptr->link != head)
            ptr = ptr->link;
        ptr->link = newNode;
        newNode->link = head;
    }
    head = newNode;
    return head;
}
// FUNCTION INSERTING AT END
struct Node *InsertAtEnd()
{
    struct Node *newNode = createNode();
    if (head == NULL)
    {
        head = newNode;
        newNode->link = head;
    }
    else
    {
        struct Node *ptr = head;
        while (ptr->link != head)
            ptr = ptr->link;
        ptr->link = newNode;
        newNode->link = head;
    }

    return head;
}
// Function To Insert After a Node.....
struct Node *InsertAfterNode()
{
    if (head == NULL)
    {
        printf("There is No Node. Please First Insert a Node !");
        return head;
    }
    int val;
    struct Node *newNode = createNode();
    printf("Enter The Searching Value :");
    scanf("%d", &val);
    struct Node *ptr = head;
    while (ptr->data != val)
    {
        ptr = ptr->link;
        if (ptr == head)
        {
            printf("Searching Value is Not present Here");
            return head;
        }
        else
            continue;
    }
    newNode->link = ptr->link;
    ptr->link = newNode;
    return head;
}
// Function To Insert Before a Node.....
struct Node *InsertBeforeNode()
{
    if (head == NULL)
    {
        printf("There is No Node. Please First Insert a Node !\n");
        return head;
    }
    int val;
    if (head->link == head)
    {
        head = InsertAtFront();
        return head;
    }
    else
    {
        struct Node *newNode = createNode();
        printf("Enter The Searching Value:");
        scanf("%d", &val);
        struct Node *ptr = head;
        if (ptr->data == val)
        {
            // struct Node* ptr=head;
            while (ptr->link != head)
                ptr = ptr->link;
            ptr->link = newNode;
            newNode->link = head;
            head = newNode;
            return head;
        }
        else
        {
            struct Node *prev;
            while (ptr->data != val)
            {
                prev = ptr;
                ptr = ptr->link;
                if (ptr == head)
                {
                    printf("Searching Value is Not present Here");
                    return head;
                }
                else
                    continue;
            }
            newNode->link = ptr;
            prev->link = newNode;
        }
    }
    return head;
}

// FUNCTION INSERTING AT ANY WHERE
struct Node *InsertAtAnyWhere()
{
    printf("\nEnter Position: ");
    scanf("%d", &pos);

    if (head == NULL && pos > 1)
        printf("\nWrong Position!\n");

    else if (pos == 1)
    {
        struct Node *newNode = createNode();

        if (head == NULL && pos == 1)
        {
            head = newNode;
            newNode->link = newNode;
        }
        else if (head->link == head)
        {
            head->link = newNode;
            newNode->link = head;
            head = newNode;
        }
        else
        {
            struct Node *ptr = head;
            while (ptr->link != head)
                ptr = ptr->link;
            ptr->link = newNode;
            newNode->link = head;
            head = newNode;
        }
    }
    else
    {
        struct Node *ptr = head;
        int count = 1;
        while (count != pos - 1)
        {
            if (ptr->link != head)
            {
                ptr = ptr->link;
                count++;
            }
            else
                printf("\nWrong Position\n");
        }
        struct Node *newNode = createNode();
        newNode->link = ptr->link;
        ptr->link = newNode;
    }
    return head;
}
// Function To Delete 1st Node .....
struct Node *DeleteFirstNode()
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        struct Node *temp = head;
        struct Node *ptr = head;
        if (head->link == head)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            while (ptr->link != head)
                ptr = ptr->link;
            ptr->link = head->link;
            head = head->link;
            free(temp);
        }
    }
    return head;
}
// Function To Delete a Node From End.....
struct Node *DeleteLastNode()
{
    struct Node *ptr = head;
    struct Node *prev;
    if (head == NULL)
    {
        printf("List is Empty !\n");
    }
    else if (head->link == head)
    {
        head = NULL;
    }
    else
    {
        while (ptr->link != head)
        {
            prev = ptr;
            ptr = ptr->link;
        }
        prev->link = head;
    }
    free(ptr);
    return head;
}

// Function For Delete After A Node....
struct Node *DeleteAfterNode()
{
    if (head == NULL)
        return 0;
    else if (head->link == head)
        printf("Plese First Insert a Node!\n");
    else
    {
        int val;
        printf("Enter The Searching Value :");
        scanf("%d", &val);
        struct Node *ptr = head;
        struct Node *temp;
        while (ptr->data != val)
        {
            ptr = ptr->link;
            if (ptr == head)
            {
                printf("Searching Value is Not Present!\n");
                return head;
            }
        }
        temp = ptr->link;
        if (temp != head)
        {
            ptr->link = temp->link;
            free(temp);
        }
        else
            printf("It is Last Node!");
    }
    return head;
}

// Function For Delete Before A Node....
struct Node *DeleteBeforeNode()
{
    if (head == NULL)
        return head;
    else if (head->link == head)
        printf("Please First Insert a Node!");
    else
    {
        int val;
        printf("Enter The Searching Value :");
        scanf("%d", &val);
        struct Node *ptr = head;
        struct Node *temp = head;
        if (ptr->link->data == val)
        {
            while (temp->link != head)
                temp = temp->link;
            head = ptr->link;
            temp->link = head;
            free(ptr);
            return head;
        }
        else if (head->data == val)
        {
            printf("No note present before this Node.This is 1st Node!\n");
        }
        else
        {
            struct Node *temp;
            while (ptr->link->data != val)
            {
                if (ptr->link == head)
                {
                    printf("Searching Value is Not Present!");
                    return head;
                }
                temp = ptr;
                ptr = ptr->link;
            }
            temp->link = ptr->link;
            free(ptr);
        }
    }
    return head;
}
// Function to delete any where ....
struct Node *DeleteAnyWhere()
{
    if (head == NULL)
    {
        printf("Please First Insert a Node!\n");
        return 0;
    }
    printf("\nEnter Position: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        if (head->link == head)
        {
            struct Node *temp = head;
            head = NULL;
            free(temp);
        }
        else
        {
            struct Node *ptr = head;
            while (ptr->link != head)
                ptr = ptr->link;
            ptr->link = head->link;
            head = head->link;
        }
    }
    else
    {
        struct Node *ptr = head;
        struct Node *prev;
        int count = 0;
        while (count != pos - 1)
        {
            if (ptr->link != head)
            {
                prev = ptr;
                ptr = ptr->link;
                count++;
            }
            else
            {
                printf("Wrong Position\n");
                return head;
            }
        }
        prev->link = ptr->link;
    }
    return head;
}
// Function To Display List..........
void printLinkedList()
{
    printf("Now Your  List : \n");
    struct Node *ptr = head;
    if (head != NULL)
    {
        do
        {
            printf("(%d , %p),", ptr->data, ptr->link);
            ptr = ptr->link;
        } while (ptr != head);
    }
    else
        printf("NULL!\n");
}

// Counting Function.....
int counting()
{
    int c = 0;
    struct Node *ptr = head;
    if (head != NULL)
    {
        do
        {
            c++;
            printf("(%d , %p),", ptr->data, ptr->link);
            ptr = ptr->link;
        } while (ptr != head);
    }
    return c;
}
int main()
{
    int ch;
    while (1)
    {
        printf("\n\n****Main Menu For Circular Linked List**\n");
        printf("...INERTION OPERATION...\n");
        printf("1.Insert at beginning \n");
        printf("2.Insert at Any Where \n");
        printf("3.Insert at Ending \n");
        printf("4.Insert After a Node \n");
        printf("5.Insert Before a Node\n");
        printf("...DELETE OPERATION...\n");
        printf("6.Delete 1st Node \n");
        printf("7.Delete Last Node \n");
        printf("8.Delete After a Node\n");
        printf("9.Delete Before a Node\n");
        printf("10.Delete at Any Where \n");
        printf("11.Display \n");
        printf("12.How Many Nodes are present in List \n");
        printf("13.Exit \n");
        printf("\nEnter Your Option: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = InsertAtFront();
            printLinkedList();
            break;
        case 2:
            head = InsertAtAnyWhere();
            printLinkedList();
            break;
        case 3:
            head = InsertAtEnd();
            printLinkedList();
            break;
        case 4:
            head = InsertAfterNode();
            printLinkedList();
            break;
        case 5:
            head = InsertBeforeNode();
            printLinkedList();
            break;
        case 6:
            head = DeleteFirstNode();
            printLinkedList();
            break;
        case 7:
            head = DeleteLastNode();
            printLinkedList();
            break;
        case 8:
            head = DeleteAfterNode();
            printLinkedList();
            break;
        case 9:
            head = DeleteBeforeNode();
            printLinkedList();
            break;
        case 10:
            head = DeleteAnyWhere();
            printLinkedList();
            break;
        case 11:
            if (head != NULL)
                printLinkedList();
            else
                printf("\nList is Empty!\n");
            break;
        case 12:
            if (head == NULL)
                printf("There are no notes here!");
            else
            {
                int c = counting();
                if (c == 1)
                    printf("\n%d node present in List", c);
                else
                    printf("\n%d nodes are present in List", c);
            }
            break;
        case 13:
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}