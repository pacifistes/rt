/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_release_flst.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 13:49:56 by mlinhard          #+#    #+#             */
/*   Updated: 2017/02/04 13:49:57 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytra_gen.h"
#include "raystruct.h"

static void		call_clic(t_gen *d, t_mlx *m, t_flst *elem, enum e_menu menu)
{
	if (menu == LOAD_FILE)
		menu_load_clic(d, m, elem);
	else if (menu == LOAD_SCENE)
		menu_scene_clic(d, m, elem);
	else if (menu == LOAD_OBJECT)
		menu_object_clic(d, m, elem);
	else if (menu == LOAD_SPOT)
		menu_spot_clic(d, m, elem);
}

int				mouse_release_flst(t_gen *d, t_flst *elem, int x, int y)
{
	int		i;
	t_img	*img;

	if (d->mlx.scene == RT && d->mlx.flst && d->mlx.menu.draw == 1
	&& d->mlx.menu.id > NONE)
	{
		i = MENU_LOAD_X_MAX * MENU_LOAD_Y_MAX;
		img = &d->mlx.scene_img[d->mlx.scene][IMG_PREVIEW_CLIC];
		while (elem && --i >= 0)
		{
			if (area(NULL, elem, x, y))
			{
				img->pos[0] = elem->top[0];
				img->pos[1] = elem->top[1];
				layer_add(&d->mlx, layer(&d->mlx, 3, 0), img);
				call_clic(d, &d->mlx, elem, d->mlx.menu.id);
				if (d->mlx.menu.id == LOAD_FILE)
					d->mlx.menu.draw = -1;
				return (1);
			}
			elem = elem->n;
		}
	}
	return (0);
}
