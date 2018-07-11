#include <stdio.h>
#include <stdlib.h>
#include "lst.h"

t_list		*add_first(t_list *lst, int val)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->val = val;
	new->next = lst;
	return (new);
}

t_list		*add_last(t_list *lst, int val)
{
	t_list	*new;
	t_list	*tmp;

	new = (t_list *)malloc(sizeof(t_list));
	new->val = val;
	new->next = NULL;
	if (lst == NULL)
		return (new);
	else
	{
		tmp = lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		return (lst);
	}
}

void		show_list(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%d -> ", lst->val);
		lst = lst->next;
	}
	printf("NULL\n");
}

int			is_empty(t_list *lst)
{
	return (lst == NULL ? 1 : 0);
}

t_list		*delete_first(t_list *lst)
{
	t_list	*new;

	if (lst != NULL)
	{
		new = lst->next;
		free(lst);
		return (new);
	}
	else
		return (NULL);
}

t_list		*delete_last(t_list *lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (lst == NULL || lst->next == NULL)
		return (NULL);
	tmp = lst;
	tmp2 = lst;
	while (tmp->next != NULL)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp2->next = NULL;
	free(tmp);
	return (lst);
}

t_list		*seek_val(t_list *lst, int val)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->val == val)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int			data_occurence(t_list *lst, int val)
{
	int i;

	i = 0;
	if (lst == NULL)
		return (0);
	while ((lst = seek_val(lst, val)) != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list		*data_i(t_list *lst, int indice)
{
	int i;

	i= 0;
	while (i < indice && lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (lst == NULL ? NULL : lst);
}

int			nbr_links(t_list *lst)
{
	if (lst == NULL)
		return (0);
	return (nbr_links(lst->next) + 1);
}

t_list		*delete_list(t_list *lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = lst;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	return (NULL);
}

t_list		*delete_dupli(t_list *lst, int val)
{
	t_list	*tmp;


	if (lst == NULL)
		return (NULL);
	if (lst->val == val)
	{
		tmp = lst->next;
		free(lst);
		tmp = delete_dupli(tmp, val);
		return (tmp);
	}
	else
	{
		lst->next = delete_dupli(lst->next, val);
		return (lst);
	}
}

int			main(int argc, char **argv)
{
	t_list *lst;
	t_list	*tmp;
	int		i;
	int		j;

	(void)argc;
	(void)argv;
	i = 1;
	lst = NULL;
	while (i <= 10)
	{
		lst = add_first(lst, i);
		lst = add_last(lst, i);
		i++;
	}
	tmp = lst;
	lst = delete_last(lst);
	show_list(lst);
	lst = seek_val(lst, 1);
	show_list(lst);
	j = 1;
	printf("%d occurences of '%d'\n", data_occurence(lst, j), j);
	tmp = data_i(tmp, 4);
	show_list(tmp);
	printf("%d links\n", nbr_links(tmp));
	tmp = delete_dupli(lst, j);
	show_list(tmp);
	if (delete_list(tmp) == NULL)
		printf("list deleted !\n");
	return (0);
}
