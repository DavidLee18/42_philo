/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 01:27:20 by jaehylee          #+#    #+#             */
/*   Updated: 2025/04/06 00:13:48 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	_sleep(t_philo *p)
{
	size_t	t;

	if (atm_dead(p))
		return ;
	if (rel_now(p) - atm_last_eaten(p) >= p->time->die)
	{
		atm_die(p);
		return ;
	}
	atm_print(p, "is sleeping");
	t = rel_now(p);
	while (rel_now(p) - t < p->time->sleep)
	{
		usleep(PLANCK_TIME);
		if (rel_now(p) - atm_last_eaten(p) >= p->time->die)
		{
			atm_die(p);
			return ;
		}
		if (atm_dead(p))
			return ;
	}
}

void	*_do(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (p->n % 2 == 0)
		usleep(2 * PLANCK_TIME);
	while (1)
	{
		usleep(PLANCK_TIME);
		if (atm_dead(p))
			break ;
		eat(p);
		usleep(PLANCK_TIME);
		if (atm_dead(p))
			break ;
		_sleep(p);
		usleep(PLANCK_TIME);
		if (atm_dead(p))
			break ;
		atm_print(p, "is thinking");
	}
	return (NULL);
}
