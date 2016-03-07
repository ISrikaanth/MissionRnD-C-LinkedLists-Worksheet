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
struct node * sortLinkedList(struct node *head) 
{
	struct node *t, *pos, *t1;
	t = head;
	t1 = head;
	int min, temp;
	while (head != NULL)
	{
		min = head->num;
		pos = head;
		while (head != NULL)
		{
			head = head->next;
			if ((head != NULL) && ((head->num) < min))
			{
				min = head->num;
				pos = head;
			}
		}
		temp = t->num;
		t->num = pos->num;
		pos->num = temp;
		t = t->next;
		head = t;
	}
	head = t1;
	return head;
}