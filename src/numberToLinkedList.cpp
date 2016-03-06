/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>
struct node {
	int num;
	struct node *next;
};
typedef struct node *lptr;

struct node * numberToLinkedList(int N) 
{
	lptr t,first;
	first = NULL;
	int a[10],i = 0,j=0;
	if (N < 0)
		N = -N;
	if (N == 0)
	{
		t = (lptr)malloc(sizeof(struct node));
		t->num = 0;
		t->next = NULL;
		first = t;
		return first;
	}
	while (N != 0)
	{
		a[i] = N % 10;
		N = N / 10;
		i++;
	}
	while ((j < i))
	{
		t = (lptr)malloc(sizeof(struct node));
		t->num = a[j];
		t->next = first;
		first = t;
		j++;
	}
	return first;
}