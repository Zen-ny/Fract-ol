/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:56:12 by naadam            #+#    #+#             */
/*   Updated: 2023/11/02 00:14:07 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_handling(char *str)
{
	int	i;

	i = 0;
	check_dots(str);
	if ((str[i] == '+' || str[i] == '-') && (ft_isdigit(str[i + 1]) == 0))
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1 && (!(str[i] == '.')))
			exit (1); 
		i++;
	}
}

void	check_dots(char *str)
{
	int	i;
	int	k;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			k = i + 1;
			while (str[k])
			{
				if (str[k] == '.')
					exit(1);
				k++;
			}
		}
		i++;
	}
}
