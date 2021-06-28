//insertion at the end of the LinkedList
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// A linked list node
struct Node
{
	int data;
	struct Node *next;
};

struct Node* push(struct Node *head_ref, int new_data)								//insertion in the beginning of the LinkedList
{
	struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
	if (new_node == NULL)
		printf("\nStack overflow");
	else
	{
		new_node->data = new_data;
		new_node->next = head_ref;
		head_ref = new_node;
	}
	return head_ref;
}

struct Node* append(struct Node *head_ref, int new_data)							//insertion at the end of the LinkedList
{
	struct Node *head_ref2 = head_ref;

	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	if (new_node == NULL)
		printf("\nStack overflow");
	else
	{
		new_node->data = new_data;
		new_node->next = NULL;
		while (head_ref2->next != NULL)
			head_ref2 = head_ref2->next;
		head_ref2->next = new_node;
	}
	return head_ref;
}

void printList(struct Node *node)	// This function prints contents of linked list starting from head
{
	while (node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}

int main()
{
	struct Node *head = NULL, *first = NULL;
	head = push(head, 9);
	first = push(head, 7);
	first = push(first, 5);

	printf("\n Created Linked list (head) is: ");
	printList(head);
	printf("\n Created Linked list (first) is: ");
	printList(first);

	head = append(head, 11);
	head = append(head, 13);

#if 0				// for commenting a section of code, use ( #if 0 ... #endif )
	 while (1)		//	 - for checking Stack overflow condition
	 first = append(first, 15);
#endif

#if 1				// for uncommenting a section of code, use ( #if 1 ... #endif )
	first = append(first, 15);
#endif

	printf("\n\n Created Linked list (head) is: ");
	printList(head);
	printf("\n Created Linked list (first) is: ");
	printList(first);

	_getch();
} 