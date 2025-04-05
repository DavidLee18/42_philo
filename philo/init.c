/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 02:53:08 by jaehylee          #+#    #+#             */
/*   Updated: 2025/04/06 01:27:12 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

_Bool	init_philos(t_list **dyn, t_philosopher *p, int argc, char **argv)
{
	ssize_t	*n;

	n = lparse(dyn, argv[1]);
	if (n == NULL || *n <= 0)
		return (0);
	p->num = *n;
	p->philos = (t_philo *)gc_calloc(dyn, *n, sizeof(t_philo));
	if (p->philos == NULL || !place_forks(dyn, p) || !set_time(dyn, p, argc - 2,
			argv + 2) || pthread_mutex_init(&p->display, NULL))
		return (0);
	p->genesis = now();
	return (1);
}

_Bool	set_time(t_list **dyn, t_philosopher *p, size_t argc, char **argv)
{
	ssize_t	*i;

	i = lparse(dyn, argv[0]);
	if (i == NULL || *i <= 0)
		return (0);
	p->time.die = *i;
	i = lparse(dyn, argv[1]);
	if (i == NULL || *i <= 0)
		return (0);
	p->time.eat = *i;
	i = lparse(dyn, argv[2]);
	if (i == NULL || *i <= 0)
		return (0);
	p->time.sleep = *i;
	if (argc == 3)
		p->time.enough = NULL;
	else
	{
		i = lparse(dyn, argv[3]);
		if (i == NULL || *i <= 0)
			return (0);
		*i = (size_t)(*i);
		p->time.enough = (size_t *)i;
	}
	return (1);
}

_Bool	place_forks(t_list **dyn, t_philosopher *p)
{
	size_t	i;
	t_list	*curr;

	i = 0;
	curr = &p->forks;
	while (++i < p->num)
	{
		curr->content = gc_calloc(dyn, 1, sizeof(pthread_mutex_t));
		curr->next = (t_list *)gc_calloc(dyn, 1, sizeof(t_list));
		if (curr->content == NULL || curr->next == NULL
			|| pthread_mutex_init((pthread_mutex_t *)curr->content, NULL))
			return (0);
		curr = curr->next;
	}
	curr->content = gc_calloc(dyn, 1, sizeof(pthread_mutex_t));
	if (p->num != 1)
		curr->next = &p->forks;
	if (curr->content == NULL
		|| pthread_mutex_init((pthread_mutex_t *)curr->content, NULL))
		return (0);
	return (1);
}
