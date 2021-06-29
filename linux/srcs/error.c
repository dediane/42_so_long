/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:18:10 by ddecourt          #+#    #+#             */
/*   Updated: 2021/06/29 20:17:08 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		ft_putstr("Error\nUnvalid map.\nThe map should be surrounded by walls\n");
		exit(2);
	}
	if (error == 4)
	{
		ft_putstr("Error\nUnvalid map.\nMap should be rectangular\n");
		exit(2);
	}
	return (0);
}
