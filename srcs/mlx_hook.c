/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 13:48:12 by mlinhard          #+#    #+#             */
/*   Updated: 2017/02/04 13:48:12 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytra_gen.h"
#include "raystruct.h"

static void		keyr_hook_mid(int key, t_gen *d)
{
	if (key == 261 && (d->mlx.menu.draw *= -1) && d->mlx.menu.draw == 1)
	{
		menu_list_free(&d->mlx, d->mlx.flst, (t_flst *)NULL);
		layer(&d->mlx, 1, 1);
		scene_init_1_rt_menu(&d->mlx);
		if (d->mlx.menu.id == LOAD_SCENE)
			menu_scene_open_order(d, &d->mlx);
		else if (d->mlx.menu.id == LOAD_FILE)
			menu_load_btn_open(d, &d->mlx);
		else if (d->mlx.menu.id == LOAD_OBJECT)
			menu_object_btn_open(d, &d->mlx);
		else if (d->mlx.menu.id == LOAD_SPOT)
			menu_spot_btn_open(d, &d->mlx);
	}
	else if (key == 261 && d->mlx.menu.draw == -1)
		input_set_focus(d, &d->mlx, (t_get *)NULL, -1);
}

int				keyr_hook(int key, t_gen *d)
{
	if (key == 53)
		exit(0);
	else if (d->mlx.scene > INTRO && (!d->sc || (d->sc && d->sc->data)))
	{
		(key == 15) ? (menu_reset_cam(d)) : 0;
		keyr_hook_mid(key, d);
		(key == 123) ? d->mlx.input.key.left = 0 : 0;
		(key == 124) ? d->mlx.input.key.right = 0 : 0;
		(key == 125) ? d->mlx.input.key.down = 0 : 0;
		(key == 126) ? d->mlx.input.key.up = 0 : 0;
		(key == 51) ? d->mlx.input.key.backspace = 0 : 0;
		(key == 117) ? d->mlx.input.key.suppr = 0 : 0;
		if (key == 49)
		{
			if ((d->mlx.menu.edit_mode ^= EDIT_BOOL) & EDIT_BOOL)
				notif(&d->mlx, N_NORMAL, "Edit mode: direction");
			else
				notif(&d->mlx, N_NORMAL, "Edit mode: position");
		}
		if (d->mlx.getfocus)
			input_catch_char(d, &d->mlx, d->mlx.getfocus, key);
	}
	return (0);
}

int				keyp_hook(int key, t_gen *d)
{
	(key == 123) ? d->mlx.input.key.left = 1 : 0;
	(key == 124) ? d->mlx.input.key.right = 1 : 0;
	(key == 125) ? d->mlx.input.key.down = 1 : 0;
	(key == 126) ? d->mlx.input.key.up = 1 : 0;
	(key == 51) ? d->mlx.input.key.backspace = 1 : 0;
	(key == 117) ? d->mlx.input.key.suppr = 1 : 0;
	keyp_hook_keyboard(key, d, new_vector(0, 0, 0));
	return (0);
}

int				mousep_hook(int btn, int x, int y, t_gen *d)
{
	if (d->sc && !d->sc->data)
		return (0);
	(btn == 1) ? d->mlx.input.mouse.left = 1 : 0;
	(btn == 2) ? d->mlx.input.mouse.right = 1 : 0;
	return (0);
	(void)x;
	(void)y;
}

int				mouser_hook(int btn, int x, int y, t_gen *d)
{
	if (d->sc && !d->sc->data)
		return (0);
	(btn == 1) ? d->mlx.input.mouse.left = 0 : 0;
	(btn == 2) ? d->mlx.input.mouse.right = 0 : 0;
	d->mlx.input.mouse.release_x = x;
	d->mlx.input.mouse.release_y = y;
	if (d->mlx.getfocus && btn == 2 && (d->mlx.getfocus->action = GET_RESET)
	&& !(d->mlx.getfocus->i = 0))
		return (0);
	mouse_release(d, btn, x, y);
	return (0);
}
