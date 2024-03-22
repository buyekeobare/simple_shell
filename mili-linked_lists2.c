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
<<<<<<< HEAD
mili_variables *add_var_end(mili_variables **head_list, int varlen, char *varval, int vallen)
{
	mili_variables *newNode, *tempNode;

	newNode = malloc(sizeof(mili_variables));
=======
rVar *add_var_end(rVar **head_list, int varlen, char *varval, int vallen)
{
	rVar *newNode, *tempNode;

	newNode = malloc(sizeof(rVar));
>>>>>>> f3e94a838e36ede334658cc4a0fee47ca440322a
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
<<<<<<< HEAD
void free_var_list(mili_variables **head_list)
{
	mili_variables *tempNode;
	mili_variables *curtNode;
=======
void free_var_list(rVar **head_list)
{
	rVar *tempNode;
	rVar *curtNode;
>>>>>>> f3e94a838e36ede334658cc4a0fee47ca440322a

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

