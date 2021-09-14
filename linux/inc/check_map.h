/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt@student.42.fr <ddecourt>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:11:44 by ddecourt          #+#    #+#             */
/*   Updated: 2021/07/01 18:45:52 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H

int	check_file_extension(char *map);
int	get_nb_of_line(char *map);
int	check_map(char *map);
char **store_map(char **map, int width, int height, char* file);
int	check_last_line(char **map, int height);

#endif 
