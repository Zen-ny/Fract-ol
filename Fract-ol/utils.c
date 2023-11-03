/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:31:28 by naadam            #+#    #+#             */
/*   Updated: 2023/11/01 22:57:42 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] == s2[i]) && s1[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_atoi(char *str)
{
	int			i;
	int			sign;
	int			result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	ft_isdigit(int a)
{
	if (a >= 48 && a <= 57)
		return (0);
	else
		return (1);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*s1;

	if (size > 0 && count > SIZE_MAX / size)
		return (NULL);
	s1 = malloc(count * size);
	if (!s1)
		return (NULL);
	ft_memset(s1, 0, count * size);
	return (s1);
}

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)str)[i] = (unsigned char)c;
		i++;
	}
	return ((void *)str);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != 0)
		write(fd, s, ft_strlen(s));
}
