#include "shell.h"
/**
 * add_var_end - function that adds a variable at the end
 * of a variable list
 * @head_list: head of the linked list
 * @varlen: length of the variable
 * @varval: value of the variable
 * @vallen: length of the value
 * Return: address of the head
 */
mili_variables *add_var_end(mili_variables **head_list, int varlen, char *varval, int vallen)
{
	mili_variables *newNode, *tempNode;

	newNode = malloc(sizeof(mili_variables));
	if (newNode == NULL)
		return (NULL);

	newNode->var_length = varlen;
	newNode->var_value = varval;
	newNode->val_length = vallen;

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
 * free_var_list
 * @head_list: head of the linked list
 */
void free_var_list(mili_variables **head_list)
{
	mili_variables *tempNode;
	mili_variables *curtNode;

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

