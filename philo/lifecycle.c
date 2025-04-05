/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:37:30 by jaehylee          #+#    #+#             */
/*   Updated: 2025/04/06 00:39:13 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

_Bool	start_philos(t_philosopher *p)
{
	size_t	i;
	t_list	*node;

	i = 0;
	node = &p->forks;
	while (i < p->num)
	{
		p->philos[i].n = i + 1;
		p->philos[i].time = &p->time;
		p->philos[i].display = &p->display;
		p->philos[i].fork = node;
		p->philos[i].genesis = &p->genesis;
		p->philos[i].dead = 0;
		if (pthread_mutex_init(&p->philos[i].guard, NULL)
			|| pthread_create(&p->philos[i].id, NULL, _do, p->philos + i))
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

_Bool	watch_philos(t_list **dyn, t_philosopher *p)
{
	size_t	i;

	i = 0;
	while (!all_enough(p))
	{
		if (atm_dead(&p->philos[i]))
			break ;
		usleep(PLANCK_TIME);
		i = (i + 1) % p->num;
	}
	return (philocide(dyn, p));
}

_Bool	philocide(t_list **dyn, t_philosopher *p)
{
	size_t	i;

	i = 0;
	while (i < p->num)
	{
		atm_die(p->philos + i);
		i++;
	}
	i = 0;
	while (i < p->num)
	{
		if (pthread_join(p->philos[i].id, NULL)
			|| pthread_mutex_destroy(&p->philos[i].guard))
			return (0);
		i++;
	}
	if (pthread_mutex_destroy(&p->display) || pthread_mutex_destroy(&p->guard)
		|| !drop_forks(p))
		return (0);
	gc_free_all(*dyn);
	return (1);
}

_Bool	drop_forks(t_philosopher *p)
{
	size_t	i;

	i = 0;
	while (i < p->num)
	{
		if (pthread_mutex_destroy(p->philos[i].fork->content))
			return (0);
		i++;
	}
	return (1);
}

void	eat(t_philo *p)
{
	if (atm_dead(p))
		return ;
	if (p->last_eaten == 0)
		p->last_eaten = rel_now(p);
	pthread_mutex_lock(p->fork->content);
	atm_print(p, "has taken a fork");
	if (p->fork->next != NULL)
		(pthread_mutex_lock(p->fork->next->content),
			atm_print(p, "has taken a fork"));
	else
		usleep(p->time->die * MS);
	if (rel_now(p) - p->last_eaten >= p->time->die)
	{
		if (p->fork->next != NULL)
			pthread_mutex_unlock(p->fork->next->content);
		pthread_mutex_unlock(p->fork->content);
		atm_die(p);
		return ;
	}
	atm_eat(p);
	if (p->fork->next != NULL)
		pthread_mutex_unlock(p->fork->next->content);
	pthread_mutex_unlock(p->fork->content);
}
