/* 
##Question

Given pointer to the head node of a linked list, the task is to reverse the linked list.

Input:
You need to complete a method reverse() that takes head as argument and returns new head.
There are multiple test cases. For each test case, this method will be called individually.  The first line of input contains number of test cases.  Every test case has two lines, number of nodes first line and data values in next line.

Output:
Reverse the linked list and return head of the modified list.


Example:
Input:
1
6
1 2 3 4 5 6

Output:
6 5 4 3 2 1

Source: http://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
*/

/*
Author: Chaitanya Reddy (@chaitanyachavali)
Date: 10/04/2017
*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *ptr;
struct node *header;
struct node *temp;
int makenode(int num) //adds new node in the end of the current linked list
{
	temp = (struct node *)malloc(sizeof(struct node));
	ptr = header;
	if(ptr->next == -999)
	{
		ptr->data = num;
		ptr->next = NULL;
	}
	else
	{
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		temp->data = num;
		ptr->next = temp;
		temp->next =NULL;	
	}
	return 0;
}
int display()
{
	ptr = header;
	printf("%d -> ", ptr->data);
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
		printf("%d -> ", ptr->data);
	}
	printf("NULL");
	return 0;
}
int reverse()
{
	struct node *prev, *curr, *nxt;
	prev = (struct node *)malloc(sizeof(struct node));
	curr = (struct node *)malloc(sizeof(struct node));
	nxt = (struct node *)malloc(sizeof(struct node));
	curr = header;
	prev = NULL;
	nxt = NULL;
	while(curr != NULL)
	{
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}
	header = prev;
	return 0;
}
int main()
{
	int a;
	header = (struct node *) malloc(sizeof(struct node));
	header->data = -999;
	header->next = -999;
	makenode(1);
	makenode(2);
	makenode(3);
	makenode(4);
	makenode(5);
	makenode(6);
	makenode(7);
	makenode(8);
	makenode(9);
	display();
	printf("\n");
	reverse();
	display();
	return 0;
}