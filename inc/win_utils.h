/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:50:40 by ddecourt          #+#    #+#             */
/*   Updated: 2021/06/28 16:08:29 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIN_UTILS_H
# define WIN_UTILS_H

int	quit_program(t_env *env);
int	keypress(int key, t_env *env);
int	move_1(int key, t_env *env);
int	move_2(int key, t_env *env);

#endif
