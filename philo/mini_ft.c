/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:16:40 by jaehylee          #+#    #+#             */
/*   Updated: 2025/04/06 01:23:40 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

void
	*ft_calloc(size_t count, size_t size)
{
	void				*ptr;
	unsigned long long	t_size;
	unsigned long long	i;

	t_size = (unsigned long long) count * (unsigned long long) size;
	if (t_size > 4294967295)
		return (NULL);
	ptr = (void *)malloc((unsigned long)t_size);
	if (!ptr)
		return (NULL);
	i = -1;
	while (++i < t_size)
		*(char *)(ptr + i) = 0;
	return (ptr);
}

void
	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (!dst || !src)
		return (NULL);
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dst);
}

ssize_t	*lparse(t_list **dyn, const char *str)
{
	ssize_t		*res;
	size_t		i;
	int			sign;

	res = (ssize_t *)gc_calloc(dyn, 1, sizeof(ssize_t));
	if (res == NULL)
		return (NULL);
	*res = 0;
	if ((*str < '0' || *str > '9') && *str != '-' && *str != '+')
		return (NULL);
	if ((*str == '-' || *str == '+') && str[1] == '\0')
		return (NULL);
	sign = (*str != '-') * 2 - 1;
	i = (*str == '-' || *str == '+');
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (NULL);
		*res = *res * 10 + sign * (str[i] - '0');
		i++;
	}
	return (res);
}

size_t	umin(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}
