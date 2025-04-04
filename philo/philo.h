/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:48:42 by jaehylee          #+#    #+#             */
/*   Updated: 2025/04/05 05:02:11 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

typedef struct s_time
{
	size_t	eat;
	size_t	sleep;
	size_t	die;
	size_t	*enough;
}	t_time;

typedef struct s_philo
{
	size_t			n;
	pthread_t		id;
	pthread_mutex_t	guard;
	pthread_mutex_t	*display;
	t_list			*fork;
	_Bool			dead;
	size_t			meals;
	size_t			last_eaten;
	t_time			*time;
}	t_philo;

typedef struct s_philosopher
{
	size_t			num;
	t_philo			*philos;
	t_list			forks;
	t_time			time;
	pthread_mutex_t	display;
	pthread_mutex_t	guard;
	_Bool			finished;
}	t_philosopher;

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*gc_calloc(t_list **head, const size_t count,
					const size_t size);
_Bool			gc_add_to_list(t_list **head, void *new);
void			gc_free_all(t_list *head);
size_t			*uparse(t_list **dyn, const char *str);
size_t			umin(size_t a, size_t b);

_Bool			init_philos(t_list **dyn, t_philosopher *p, int argc,
					char **argv);
_Bool			place_forks(t_list **dyn, t_philosopher *p);
_Bool			set_time(t_list **dyn, t_philosopher *p, size_t argc,
					char **argv);
_Bool			start_philos(t_philosopher *p);
_Bool			watch_philos(t_list **dyn, t_philosopher *p);
void			*_do(void *philo);
_Bool			philocide(t_list **dyn, t_philosopher *p);
_Bool			drop_forks(t_philosopher *p);
size_t			now(void);
void			eat(t_philo *p);
void			_sleep(t_philo *p);
void			think(t_philo *p);

void			atm_print(t_philo *p, char *str);
void			atm_die(t_philo *p);
_Bool			atm_dead(t_philo *p);
void			atm_eat(t_philo *p);

#endif
