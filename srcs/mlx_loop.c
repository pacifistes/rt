/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 13:48:50 by mlinhard          #+#    #+#             */
/*   Updated: 2017/02/04 13:48:50 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raystruct.h"

int		loop(t_mlx *m, char etat)
{
	if (m->loop && m->loopstop != 0)
		return (1);
	else if (m->loop != etat)
		m->loop = etat;
	return (1);
}

int		loopstop(t_mlx *m, char total)
{
	m->loopstop = total;
	if (m->loopstop && !m->loop)
		loop(m, 1);
	return (1);
}

int		loop_hook(t_gen *d)
{
	t_mlx *m;

	m = &d->mlx;
	if (USLEEP_BOOL && m->loop == 0 && !usleep(USLEEP_TIME))
		return (0);
	if (m->loopstop != 0 && --m->loopstop < 1 && m->loop != 0)
		loop(&d->mlx, 0);
	scene_img_load(d, &d->mlx);
	if (m->menu.next > NONE && (m->menu.id = m->menu.next))
	{
		menu_list_free(m, m->flst, (t_flst *)NULL);
		m->menu.next = NONE;
	}
	scene_input(d, m, -1);
	scene_btn(d, m, (t_img *)NULL, &m->menu);
	menu_filter(m, -1);
	scene_build(d, m, layer(m, 1, 0), (t_img *)NULL);
	notif_draw(m, m->notif, (t_notif *)NULL);
	scene(d, m);
	return (0);
}
