/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:23:01 by ddecourt          #+#    #+#             */
/*   Updated: 2021/09/23 13:23:02 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

int	get_player_position(t_env *env);
int	move_player_up(t_env *env);
int	move_player_west(t_env *env);
int	move_player_down(t_env *env);
int	move_player_east(t_env *env);

#endif
