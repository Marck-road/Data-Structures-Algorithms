#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL, *current, *temp;

void addNode();
void printList();
void InsertNode();
void DeleteNode();
void EditNode();

int main()
{
    int option, i;

    printf("\n\nMenu\n ");
    printf("1. Add New Node at the end of the list.\n ");
    printf("2. Show all Data\n ");
    printf("3. Insert Node\n ");
    printf("4. Delete Node\n ");
    printf("5. Edit Node\n ");
    printf("6. Exit\n\n");
    printf("Choose action: ");
    scanf("%d",&option);

    switch(option)
    {
        case 1:
            addNode();
            break;
        case 2:
            printList();
            break;
        case 3:
            InsertNode();
            break;
        case 4:
            DeleteNode();
            break;
        case 5:
            EditNode();
            break;
        case 6:
            return 0;
    }
    main();
}

void addNode()
{
    int itemData;
    printf("Enter the data of the Node: ");
    scanf("%d",&itemData);

    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = itemData;
    temp->next = NULL;

    if(head == NULL)
    {
        head=temp;
        current = head;
    }
    else
    {
        current->next = temp;
        current = current->next;
    }
}

void printList()
{
    int nodeCount=0;
    printf("\nList Content\n");
    current = head;
    printf("Node (%d) : %d\n", nodeCount, current->data);
    while(current->next != NULL){
        current = current->next;
        nodeCount++;
        printf("Node (%d) : %d\n", nodeCount, current->data);
    }
}

void InsertNode()
{
    int itemData, location, nodeCount=0;

    if(head==NULL)
        printf("# of nodes: 0");
    else
    {
        current = head;
        while(current->next != NULL)
        {
            current = current->next;
            nodeCount++;
        }
        nodeCount++;
        printf("# of nodes: %d\n", nodeCount);
        printf("Data at the last nodes: %d\n\n", current->data);
    }
    
    printf("Enter the data of the Node: ");
    scanf("%d",&itemData);
    printf("Enter the location of the Node: ");
    scanf("%d",&location);

    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = itemData;
    temp->next = NULL;

    if(location > nodeCount)
    {
        //go the end node
        printf("The location you have selected will insert the data at the end of the list.\n");
        current->next = temp;
        current = current->next;
    }
    else
    {

        if(location ==0)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            current = head;
            nodeCount=1;
            while(current->next != NULL)
            {
                if(nodeCount == location)
                    break;
                current = current->next;
                nodeCount++;
            }
            temp->next = current->next;
            current->next = temp;
        }
    }
}


void DeleteNode()
{
    int location, nodeCount=0;

    printf("Enter the location of the Node: ");
    scanf("%d",&location);

    current = head;
    nodeCount = 0;
    if(location == 0)
    {
        temp = head;
        head = head->next;
    }
    else
    {
        while(current->next != NULL)
        {
            if(nodeCount == (location-1))
                break;
            current = current->next;
            nodeCount++;
        }
        temp = current->next;
        current->next = current->next->next;
    }
    free(temp);
}

void EditNode(){
    int location, nodeCount=0, itemData;

    printf("Enter the location of the Node you want to edit: ");
    scanf("%d",&location);
    printf("Enter the new value of the node: ");
    scanf("%d",&itemData);

    current = head;
    nodeCount = 0;
    if(location == 0)
    {
        head->data = itemData;
    }
    else
    {
        while(current->next != NULL)
        {
            if(nodeCount == (location))
                break;
            current = current->next;
            nodeCount++;
        }
        current->data = itemData;
    }
    printf("Data has successfully been updated.\n");
}
