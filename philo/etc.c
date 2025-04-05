/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 04:44:24 by jaehylee          #+#    #+#             */
/*   Updated: 2025/04/06 00:44:09 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	now(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

size_t	rel_now(t_philo *p)
{
	return (now() - *p->genesis);
}

size_t	atm_meal(t_philo *p)
{
	size_t	m;

	pthread_mutex_lock(&p->guard);
	m = p->meals;
	pthread_mutex_unlock(&p->guard);
	return (m);
}

_Bool	all_enough(t_philosopher *p)
{
	size_t	i;
	_Bool	e;

	if (p->time.enough == NULL)
		return (0);
	i = 0;
	e = 1;
	while (i < p->num)
	{
		e &= (atm_meal(p->philos + i) >= *p->time.enough);
		i++;
	}
	return (e);
}
