/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 13:41:01 by ddecourt          #+#    #+#             */
/*   Updated: 2021/09/24 13:41:04 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_MAP_H
# define PARSING_MAP_H

int	check_sprites(char **map);
int	check_unique_object(char **map, char c);
int	check_valid_map_char(char **map);
int	check_walls_side(char *line, int size, int i);

#endif