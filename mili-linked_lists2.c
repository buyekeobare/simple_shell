#include "shell.h"
/**
 * add_rVar_node - adds a variable at the end
 * of a rVar list
 * @hd: head of the linked list
 * @varlen: length of the variable
 * @varval: value of the variable
 * @vallen: length of the value
 * Return: address of the head
 */
rVar *add_rVar_node(rVar **hd, int varlen, char *varval, int vallen)
{
	rVar *nw, *tmp;

	nw = malloc(sizeof(rVar));
	if (nw == NULL)
		return (NULL);

	nw->var_length = varlen;
	nw->var_value = varval;
	nw->val_length = vallen;

	nw->nxtNode = NULL;
	tmp = *hd;

	if (tmp == NULL)
	{
		*hd = nw;
	}
	else
	{
		while (tmp->nxtNode != NULL)
			tmp = tmp->nxtNode;
		tmp->nxtNode = nw;
	}
	return (*hd);
}

/**
 * free_rVar_list
 * @hd: head of the linked list
 */
void free_rVar_list(rVar **hd)
{
	rVar *tmp;
	rVar *curt;

	if (hd != NULL)
	{
		curt = *hd;
		while ((tmp = curt) != NULL)
		{
			curt = curt->nxtNode;
			free(tmp);
		}
		*hd = NULL;
	}
}