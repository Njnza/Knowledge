#pragma once
#include <stdint.h>

typedef struct myData
{
	//uint16_t number[100];
	uint16_t value;
	uint16_t index;

} myData_t;

typedef struct Node
{
	myData_t data;
	struct Node* next;

} Node_t;

void Insert (myData_t data, Node_t** head, uint16_t idx)
{
	Node_t* temp = (Node_t*)malloc(sizeof(Node_t));
	temp->data.value = data.value;
	temp->data.index = data.index;
	temp->next = NULL;
	temp->next = *head;
	*head = temp;
}

void Print(Node_t* head)
{
	std::cout << "List is: ";
	while (head != NULL )
	{
		//printf(" %d", temp->data.value);
		std::cout << head->data.value << " ";
		head = head->next;
	}
	printf("\n");
}
