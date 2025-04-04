/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atomic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 01:27:11 by jaehylee          #+#    #+#             */
/*   Updated: 2025/04/05 04:50:54 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	atm_print(t_philo *p, char *str)
{
	pthread_mutex_lock(p->display);
	printf("%zu %zu %s\n", now(), p->n, str);
	pthread_mutex_unlock(p->display);
}

void	atm_die(t_philo *p)
{
	pthread_mutex_lock(&p->guard);
	p->dead = 1;
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
	p->last_eaten = now();
	p->meals++;
	pthread_mutex_unlock(&p->guard);
}
