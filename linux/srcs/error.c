/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt@student.42.fr <ddecourt>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:18:10 by ddecourt          #+#    #+#             */
/*   Updated: 2021/07/02 12:48:20 by ddecourt@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	usage_error(void)
{
	ft_putstr("Error\nUsage: so_long.c [map.ber]\n");
	exit(2);
}

int	map_error(int error)
{
	if (error == 1)
	{
		ft_putstr("Error\nWrong map file extension.\n");
		exit(2);
	}
	if (error == 2)
	{
		ft_putstr("Error\nCannot open the map.\n");
		exit(2);
	}
	if (error == 3)
	{
		ft_putstr("Error\nUnvalid map.\n");
		exit(2);
	}
	return (0);
}

void	ft_clear_tab(char ***s)
{
	int	i;

	i = 0;
	while ((*s)[i])
	{
		free((*s)[i]);
		i++;
	}
	free(*s);
}
