/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt@student.42.fr <ddecourt>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:11:44 by ddecourt          #+#    #+#             */
/*   Updated: 2021/06/30 14:10:00 by ddecourt@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H

int	check_file_extension(char *map);
int	get_nb_of_line(char *map);
int	check_map(char *map);
int store_map(char **map, int width, int height, char* file);

#endif 
