#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int num;                    //Data of the node
    struct node *nextptr;       //Address of the node
};

void createNodeList(struct node ** stnode_p, int n)
{
    struct node *stnode, *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));
    *stnode_p = stnode;
    if(stnode == NULL) //check whether the stnode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
			// reads data for the node through keyboard
			printf(" Input data for node 1 : ");
			scanf("%d", &num);
			stnode-> num = num;      
			stnode-> nextptr = NULL; //Links the address field to NULL
			tmp = stnode;
			//Creates n nodes and adds to linked list
			for(i=2; i<=n; i++)
			{
					fnNode = (struct node *)malloc(sizeof(struct node));
					if(fnNode == NULL) //check whether the fnnode is NULL and if so no memory allocation
					{
							printf(" Memory can not be allocated.");
							break;
					}
					else
					{
							printf(" Input data for node %d : ", i);
							scanf(" %d", &num);

							fnNode->num = num;      // links the num field of fnNode with num
							fnNode->nextptr = NULL; // links the address field of fnNode with NULL

							tmp->nextptr = fnNode; // links previous node i.e. tmp to the fnNode
							tmp = tmp->nextptr;
					}
			}
    }
} 

void displayList(struct node * stnode)
{
    struct node *tmp;
    if(stnode == NULL)
    {
        printf(" No data found in the empty list.");
    }
    else
    {
        tmp = stnode;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->num);   // prints the data of current node
            tmp = tmp->nextptr;                 // advances the position of current node
        }
    }
} 

struct node* split(struct node* head, int x) {
    struct node* small = malloc(sizeof(struct node));
    struct node* smallHead = small;
    struct node* large = malloc(sizeof(struct node));
    struct node* largeHead = large;
    while (head != NULL) {
        if (head->num < x) {
            small->nextptr = head;
            small = small->nextptr;
        } else {
            large->nextptr = head;
            large = large->nextptr;
        }
        head = head->nextptr;
    }
    large->nextptr = NULL;
    small->nextptr = largeHead->nextptr;
    return smallHead->nextptr;
}

int main() {
    int n, x;
    struct node *l;
	
    printf(" Input the number of nodes (3 or more): ");
    scanf("%d", &n);
    createNodeList(&l, n);
    printf("\n Data entered in the list l1 are : \n");		
    displayList(l);

    printf("\n Input the number of x: ");
    scanf("%d", &x);

    printf("\n The list after partition is : \n");
    l = split(l, x);
    displayList(l);
    
    return 0;
}