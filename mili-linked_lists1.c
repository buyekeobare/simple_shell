#include "shell.h"

/**
 * add_separ_list_end - A function that adds a separator found at the end
 * of a separ_list
 * @head_list: head of the linked list.
 * @separ: separator found (; | &).
 * Return: address of the head
 */
separ_list *add_separ_list_end(separ_list **head_list, char separ)
{
	separ_list *newNode, *tempNode;

	newNode = malloc(sizeof(separ_list));
	if (newNode == NULL)
		return (NULL);

	newNode->separator = separ;
	newNode->nextNode = NULL;
	tempNode = *head_list;

	if (tempNode == NULL)
	{
		*head_list = newNode;
	}
	else
	{
		while (tempNode->nextNode != NULL)
			tempNode = tempNode->nextNode;
		tempNode->nextNode = newNnode;
	}

	return (*head_list);
}

/**
 * free_separ_list - It frees a separ_list
 * @head_list: head of the linked list
 */
void free_separ_list(separ_list **head_list)
{
	separ_list *tempNode;
	separ_list *curtNode;

	if (head_list != NULL)
	{
		curt = *head_list;
		while ((tempNode = curtNode) != NULL)
		{
			curtNode = curtNode->nextNode;
			free(tempNode);
		}
		*head_list = NULL;
	}
}

/**
 * add_line_list_end - It adds a command line at the end
 * of a line_lst.
 * @head_list: head of the linked list.
 * @line_cmd: command line.
 * Return: address of the head.
 */
line_lst *add_line_list_end(line_lst **head_list, char *line_cmd)
{
	line_lst *newNode, *tempNode;

	newNode = malloc(sizeof(line_lst));
	if (newNode == NULL)
		return (NULL);

	newNode->line = line_cmd;
	newNode->nextNode = NULL;
	tempNode = *head_list;

	if (tempNode == NULL)
	{
		*head_list = newNode;
	}
	else
	{
		while (tempNode->nextNode != NULL)
			tempNode = tempNode->nextNode;
		tempNode->nextNode = newNode;
	}

	return (*head_list);
}

/**
 * free_line-lst - It frees a line_lst
 * @head_list: head of the linked list.
 */
void free_line_lst(line_lst **head_list)
{
	line_lst *tempNode;
	line_lst *curtNode;

	if (head_list != NULL)
	{
		curtNode = *head_list;
		while ((tempNode = curtNode) != NULL)
		{
			curtNode = curtNode->nextNode;
			free(tempNode);
		}
		*head_list = NULL;
	}
}