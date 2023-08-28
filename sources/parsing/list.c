/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:51:00 by aducobu           #+#    #+#             */
/*   Updated: 2023/08/25 13:32:51 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/exec.h"
#include "../../libft/libft.h"

void	ft_lstadd_back_cmd_line(cmd_line **lst, cmd_line *new)
{
	cmd_line	*list;

	list = *lst;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
	else
		*lst = new;
}

cmd_line	*ft_lstnew_cmd_line(int len)
{
	cmd_line	*elem;

	elem = malloc(sizeof(cmd_line));
	if (!elem)
		return (NULL);
	elem->cmd = malloc(sizeof(char) * len);
	if (!elem->cmd)
		return (NULL);
	elem->next = NULL;
	return (elem);
}

cmd_line	*ft_lstlast_cmd_line(cmd_line *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

token	*ft_lstnew_token(cmd_line *list, int start, int end)
{
	token	*elem;

	elem = malloc(sizeof(token));
	if (!elem)
		return (NULL);
	elem->word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!elem->word)
		return (NULL);
	ft_strcpy_pos(elem->word, list->cmd, start, end);
	elem->type = get_type_meta(elem->word);
	elem->next = NULL;
	elem->previous = NULL;
	return (elem);
}

void	ft_lstadd_back_token(token **lst, token *new)
{
	token	*list;

	list = *lst;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = new;
		list->next->previous = list;
	}
	else
		*lst = new;
}
