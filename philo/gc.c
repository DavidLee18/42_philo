/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:20:47 by jaehylee          #+#    #+#             */
/*   Updated: 2025/04/03 20:36:35 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	gc_free_all(t_list *head)
{
	t_list	*curr;
	t_list	*next;

	curr = head;
	while (curr)
	{
		next = curr->next;
		if (curr->content)
			free(curr->content);
		free(curr);
		curr = next;
	}
}

_Bool	gc_add_to_list(t_list **head, void *new)
{
	t_list	*node;
	t_list	*tmp;

	node = ft_calloc(1, sizeof(t_list));
	if (!node)
		return (0);
	node->content = new;
	node->next = NULL;
	if (!(*head))
	{
		(*head) = node;
		return (1);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (1);
}

void	*gc_calloc(t_list **head, const size_t count, const size_t size)
{
	void	*new;

	new = ft_calloc(count, size);
	if (!new)
		return (NULL);
	if (!gc_add_to_list(head, new))
	{
		free(new);
		return (NULL);
	}
	return (new);
}
