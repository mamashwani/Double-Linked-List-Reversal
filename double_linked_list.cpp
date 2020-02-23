#include <iostream> 

using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node *prev;
};

/* Function to reverse a Doubly Linked List */
void reverse(Node **head_ref)
{
	Node *temp = NULL;
	Node *current = *head_ref;
	
	while (current != NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	if (temp != NULL)
	{
		*head_ref = temp->prev;
	}
}



void insert_at_beg(Node** head_ref, int new_data)
{
	Node* new_node = new Node();

	new_node->data = new_data;

	//previous of first node is always null
	new_node->prev = NULL;

	new_node->next = (*head_ref);

	if ((*head_ref) != NULL)
	{
		(*head_ref)->prev = new_node;
	}

	(*head_ref) = new_node;
}

/* Function to print nodes in a given doubly linked list*/
void printList(Node *node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}


int main()
{
	
	Node* head = NULL;

	
	insert_at_beg(&head, 2);
	insert_at_beg(&head, 4);
	insert_at_beg(&head, 8);
	insert_at_beg(&head, 10);

	cout << "Original Linked list" << endl;
	printList(head);

	
	reverse(&head);

	cout << endl << "Reversed Linked list" << endl;
	printList(head);

	system("pause");
	return 0;
}