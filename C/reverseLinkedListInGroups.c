/* 
##Question

Given a linked list, write a function to reverse every k nodes (where k is an input to the function).If a linked list is given as 1->2->3->4->5->6->7->8->NULL and k = 3 then output will be 3->2->1->6->5->4->8->7->NULL.

Input:
In this problem, method takes two argument: the head of the linked list and int k. You should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:
Reverse the linked list in the group of given size and return the reference of starting node(head) of the reversed Linked list .

Note: If you use "Test" or "Expected Output Button" use below example format
Example:
Input:
1
8
1 2 2 4 5 6 7 8
4

Output:
4 2 2 1 8 7 6 5

Source: http://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
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
int reverseGroup(int val)
{
	int count = 0;
	int headval;
	struct node *prev, *curr, *nxt, *temp1;
	prev = (struct node *)malloc(sizeof(struct node));
	curr = (struct node *)malloc(sizeof(struct node));
	nxt = (struct node *)malloc(sizeof(struct node));
	curr = header;
	prev = NULL;
	nxt = NULL;
	while(curr !=NULL && count<val)
	{
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
		count++;
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
	printf("Enter a number to reverse in group\n");
	scanf("%d", &a);
	reverseGroup(a);
	display();
	return 0;
}