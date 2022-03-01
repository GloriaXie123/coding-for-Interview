/*In this problem, we continue our study of linked lists.
Let the nodes in the list have the following structure

struct node
{
	int data;
	struct node* next;
};
Use the template in Lec06 to add elements to the list.
(a) Write the function void display(struct node* head) that displays all
the elements of the list.
(b) Write the function struct node * addback(struct node* head,int data) that
adds an element to the end of the list. The function should return the new
head node to the list.
(c) Write the function struct node* find(struct node* head,int data) that returns
a pointer to the element in the list having the given data. The function should
return NULL if the item does not exist.*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

/*
@function nalloc
@desc allocates a new node elements
@returns pointer to the new element on sucess, NULL on failure
@param data [IN] payload of the new element
*/
struct node *nollac(int data)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	/*if allocation is sucessful, p is not NULL*/
	if (p != NULL)
	{
		p->data = data;
		p->next = NULL;
	}
	return p;
}

/*
@function addfront
@desc add node to the front of the list
@param head [IN] current head of the list
@param data [IN] data to be inserted
@return updated head of the list
*/
struct node *addfront(struct node *head, int data)
{
	struct node *p;
	p = nollac(data);
	if (p == NULL)
	{
		return head;
	}
	else
	{
		p->next = head;
		return p;
	}
}
/*
@function display
@desc displays the nodes in the list
@param head [IN] pointer to the head node of the list
*/
void display(struct node *head)
{
	struct node *p;
	p = head;
	while (p != NULL)
	{
		printf("the list element is: %d\t ", p->data);
		p = p->next; /*access the member `next` of the structure*/
		printf("\n");
	}
}

/*Write the function struct node *addback(struct node *head, int data) which add data to the
end of the list,the function should return the new head of the linkedlist.*/
/*
@function addback
@desc adds node to the back of the list
@param head [IN] current head of the list
@param data [IN] data to be inserted into current node
@return updated head of the list
*/
struct node *addback(struct node *head, int data)
{
	struct node *p = nollac(data);
	struct node *curr = NULL;
	if (p == NULL)
	{
		return head;
	}
	if (head == NULL)
	{
		head = p;
		return p;
	}
	else
	{
		for (curr = head; curr->next != NULL; curr = curr->next)
			;
		curr->next = p;
		return head;
	}
}

/*Write a function struct node *find(struct node *head, int data) that 
returns a pointer to a node in the linkedlist that having the given
data. the function should return NULL if the item doesn't exist.*/
/*
@function find
@desc find the node that having the given data or returning NULL if doesn't exist
@param head [IN] the head of the linkedlist
@param data [IN] the data to be found
@return the pointer to the node that having the data or NULL
*/
struct node *find(struct node *head, int data)
{
	struct node *p = NULL;
	for (p = head; p != NULL; p = p->next)
	{
		if (p->data == data)
		{
			return p;
		}
	}
	return p;
}

/*Write the function struct node *delnode(struct node *head, struct node *pelement) delete the
element pointed to by pelement(obtained using find), The function should return the updated
head node,make sure you consider the case when pelement points to the head node*/
struct node *delnode(struct node *head, struct node *pelement)
{
	struct node *p = NULL;
	struct node *q = NULL;
	for (p = head; p != pelement && p != NULL; p = p->next)
	{
		q = p;
	}
	if (p == NULL)
	{
		return head;
	}
	if (q == NULL)
	{
		head = head->next;
		free(p);
		return head;
	}
	else
	{
		q->next = p->next;
		free(p);
		return head;
	}
}

/*write the function void freelist(struct node *head) that deletes all the element of the list
Make sure you do not use pointer after it's freed.*/
/*
@function freelist
@desc deletes all the element of the linkedlist
@param head [IN] the head of the linked list
@return void
*/
void freelist(struct node *head)
{
	struct node *p = NULL;

	while (head)
	{
		p = head;
		head = head->next;
		free(p);
	}
}

/*Write test code to illustrate the working of the each function of the above*/
int main()
{
	struct node *head = NULL;
	struct node *p = NULL;
	/*test add front*/
	head = nollac(20);
	addfront(head, 10);
	addfront(head, 0);
	puts("display the list:0 10 20");
	display(head);

	/*test freelist*/
	freelist(head);
	head = NULL;
	puts("should display empty");
	display(head);

	/*test addback*/
	addback(head, 10);
	addback(head, 20);
	puts("the list should display: 10 20");
	display(head);

	/*test find*/
	p = find(head, 10)
			puts("should display:10,20");
	display(p);

	p = find(head, -10);
	puts("should display empty");
	display(p);

	/*test delnode*/
	p = nalloc(20);
	head = delnode(head, p);
	puts("should display:10");
	display(head);

	p = nalloc(-10);
	head = delnode(head, p);
	puts("should display:10");
	display(head);

	/*clean up*/
	freelist(head);
	puts("should display empty");
	display(head);

	return 0;
}
