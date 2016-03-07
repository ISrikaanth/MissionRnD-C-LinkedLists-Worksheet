/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int digit1;
	int digit2;
	struct node *next;
};
typedef struct node * lptr;
int convert_sll_2digit_to_int(struct node *head)
{
	char str[20];
	int i = 0, num=0, j = 0;
	lptr t;
	t = head;
	while (t != NULL)
	{
		str[i] = t->digit1+'0';
		i++;
		str[i] = t->digit2+'0';
		i++;
		t = t->next;
	}
	for (j = 0; j < i;j++)
	  num = (num*10)+(str[j]- '0');
	return num;
}
