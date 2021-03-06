/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/
#include <stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};
struct node * removeEveryKthNode(struct node *head, int K) 
{
	int count = 0;
	if ((head == NULL) || (K <= 1))
		return NULL;
	struct node * prev, *t;
	t = head;
	prev = head;
	while (head != NULL)
	{
		if ((head->num) % K == 0)
		{
			prev = head->next;
			head->num = head->next->num;
			head->next = head->next->next;
			head = prev;
		}
		else
		{
			if (((head->next != NULL) && ((head->next->num) % K == 0)))
			{
				prev = head->next;
				head->next = head->next->next;
				free(prev);
			}
		}

		head = head->next;
	}
	head = t;
	return head;
}