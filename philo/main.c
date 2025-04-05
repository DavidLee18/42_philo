/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 01:51:22 by jaehylee          #+#    #+#             */
/*   Updated: 2025/04/05 22:21:06 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philosopher	p;
	t_list			*dyn;

	if (argc != 5 && argc != 6)
		return (printf("usage: %s <number of philosophers> <time to die> <time"
				" to eat> <time to sleep> [number of times each philosopher mus"
				"t eat]\n", argv[0]), 1);
	dyn = NULL;
	p = (t_philosopher){.philos = NULL, .num = 0, .genesis = 0,
		.time = (t_time){.sleep = 0, .enough = NULL, .eat = 0, .die = 0},
		.forks = (t_list){.content = NULL, .next = NULL}};
	if (!init_philos(&dyn, &p, argc, argv))
		return (gc_free_all(dyn), printf("failed to parse arguments\n"), 1);
	if (!start_philos(&p))
		return (gc_free_all(dyn), printf("failed to start philo\n"), 1);
	return (!watch_philos(&dyn, &p));
}
