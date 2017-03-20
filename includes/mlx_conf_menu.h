/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytra_gen.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 17:12:41 by ocarta-l          #+#    #+#             */
/*   Updated: 2017/02/04 09:37:01 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_CONF_MENU_H
# define MLX_CONF_MENU_H

/*
** le fade est calculé sur MENU_MODALE_FADE et pas sur la couleur
*/
# define MENU_MODALE_COLOR_BLUE 0XFF000070
# define MENU_MODALE_COLOR 0XFF000000
# define MENU_MODALE_FADE 75

# define MENU_FADE_CADRE_INTERFACE 140

# define MENU_FADE_ADD_SCENE 50

# define MENU_LOAD_X_MAX 4
# define MENU_LOAD_Y_MAX 3
# define MENU_LOAD_START_X W_X * 0.10
# define MENU_LOAD_START_Y W_Y * 0.08
# define MENU_LOAD_END_X W_X * 0.90
# define MENU_LOAD_END_Y W_Y * 0.90

# define MENU_LOAD_SIZE_X MENU_LOAD_END_X - MENU_LOAD_START_X
# define MENU_LOAD_SIZE_Y MENU_LOAD_END_Y - MENU_LOAD_START_Y
# define MENU_LOAD_TEXT_MARGIN_X 5
# define MENU_LOAD_TEXT_MARGIN_Y 5
# define MENU_LOAD_PREVIEW_NAME_SIZE_MAX 18
# define MENU_LOAD_PREVIEW_PATH "./resources/menu_load_preview/"
# define MENU_LOAD_WAIT_BEFORE_LOAD 40

# define MENU_LOAD_MARGIN_X 20
# define MENU_LOAD_MARGIN_Y 20

#endif
