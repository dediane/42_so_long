/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:18:10 by ddecourt          #+#    #+#             */
/*   Updated: 2021/06/29 18:43:52 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_error(int error)
{
	if (error == 2)
		perror("Error\n Wrong map file extension.");
	if (error == 3)
		perror("Error\n Map error.");
	return (0);
}
