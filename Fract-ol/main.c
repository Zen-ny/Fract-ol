/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadam <naadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:25:22 by naadam            #+#    #+#             */
/*   Updated: 2023/11/03 15:22:24 by naadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	double	one;
	double	two;

	if (ac != 2 && ac != 4)
	{
		write(1, "Number of arguments are not valid\n", 34);
		exit(1);
	}
	if (ac == 2 && 
		(ft_strncmp(av[1], "Mandelbrot", ft_strlen(av[1]))) == 0)
		mandel();
	if (ft_strncmp(av[1], "Julia", ft_strlen(av[1])) == 0)
	{
		if (ac == 4)
		{
			one = float_conversion(av[2]);
			two = float_conversion(av[3]);
			printf("One and two %f  %f\n", one, two);
			if ((one >= -2.0 && one <= 2.0) && (two >= -2.0 && two <= 2.0))
				julia(one, two);
			else
				printf("Julia takes two arguments\n");
		}
	}
	return (0);
}
