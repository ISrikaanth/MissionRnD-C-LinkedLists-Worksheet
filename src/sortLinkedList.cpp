/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
typedef struct node * lptr;
int check(struct node *head);
struct node * sortLinkedList(struct node *head) 
{
	int n;
	lptr t=head;
	while (check(head)==0)
	{
		if ((head->num) > (head->next->num))
		{
			n = head->num;
			head->num = head->next->num;
			head->next->num = n;
			head = head->next;
			if (head == NULL)
				head = t;
		}
		else
			head = head->next;
	}
	return head;
}
int check(struct node *head)
{
	while (head != NULL)
	{
		if (((head->num) > (head->next->num)) && (head->next!=NULL))
			break;
		head = head->next;
	}
	if (head == NULL)
		return 1;
	else
		return 0;
}