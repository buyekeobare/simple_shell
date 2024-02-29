#include "shell.h"

/**
 * addSep_ndEnd - A function that adds a separator found at the end
 * of a sepLst
 * @hd: head of the linked list.
 * @sep: separator found (; | &).
 * Return: address of the head.
 */
sepLst *addSep_ndEnd(sepLst **hd, char sep)
{
	sepLst *nw, *tmp;

	nw = malloc(sizeof(sepLst));
	if (nw == NULL)
		return (NULL);

	nw->separ = sep;
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
 * free_SepLst - It frees a sepLst
 * @hd: head of the linked list
 */
void free_SepLst(sepLst **hd)
{
	sepLst *tmp;
	sepLst *curt;

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

/**
 * addLine_ndEnd - It adds a command line at the end
 * of a lineLst.
 * @hd: head of the linked list.
 * @ln: command line.
 * Return: address of the head.
 */
lineLst *addLine_ndEnd(lineLst **hd, char *ln)
{
	lineLst *nw, *tmp;

	nw = malloc(sizeof(lineLst));
	if (nw == NULL)
		return (NULL);

	nw->line = ln;
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
 * free_lineLst - It frees a lineLst
 * @hd: head of the linked list.
 */
void free_lineLst(lineLst **hd)
{
	lineLst *tmp;
	lineLst *curt;

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