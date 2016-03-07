/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head)
{
	struct node *t,*pos,*t1;
	t = head;
	t1 = head;
	int min,temp;
	while (head != NULL)
	{
		min = head->data;
		pos = head;
		while (head != NULL)
		{
			head = head->next;
			if ((head!=NULL)&&((head->data) < min))
			{
				min = head->data;
				pos = head;
			}
		}
		temp = t->data;
		t->data = pos->data;
		pos->data = temp;
		t = t->next;
		head = t;
	}
	head = t1;
}