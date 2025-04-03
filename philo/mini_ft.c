/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:16:40 by jaehylee          #+#    #+#             */
/*   Updated: 2025/04/04 01:50:29 by jaehylee         ###   ########.fr       */
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

size_t	*uparse(t_list **dyn, const char *str)
{
	unsigned long long	temp;
	size_t				*res;
	size_t				i;

	i = 0;
	res = (size_t *)gc_calloc(dyn, 1, sizeof(size_t));
	if (res == NULL)
		return (NULL);
	temp = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (NULL);
		temp = temp * 10 + str[i] - '0';
		i++;
	}
	if (temp > 4294967295)
		return (NULL);
	*res = (size_t)temp;
	return (res);
}
