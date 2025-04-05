/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atomic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 01:27:11 by jaehylee          #+#    #+#             */
/*   Updated: 2025/04/05 22:36:02 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	atm_print(t_philo *p, char *str)
{
	pthread_mutex_lock(p->display);
	printf("%zu %zu %s\n", rel_now(p), p->n, str);
	pthread_mutex_unlock(p->display);
}

void	atm_die(t_philo *p)
{
	pthread_mutex_lock(&p->guard);
	if (!p->dead)
	{
		p->dead = 1;
		atm_print(p, "died");
	}
	pthread_mutex_unlock(&p->guard);
}

_Bool	atm_dead(t_philo *p)
{
	_Bool	d;

	pthread_mutex_lock(&p->guard);
	d = p->dead;
	pthread_mutex_unlock(&p->guard);
	return (d);
}

void	atm_eat(t_philo *p)
{
	pthread_mutex_lock(&p->guard);
	atm_print(p, "is eating");
	p->last_eaten = rel_now(p);
	p->meals++;
	pthread_mutex_unlock(&p->guard);
}

size_t	atm_last_eaten(t_philo *p)
{
	size_t	t;

	pthread_mutex_lock(&p->guard);
	t = p->last_eaten;
	pthread_mutex_unlock(&p->guard);
	return (t);
}
