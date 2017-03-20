/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_scene_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 13:50:22 by mlinhard          #+#    #+#             */
/*   Updated: 2017/02/04 13:50:22 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytra_gen.h"
#include "raystruct.h"

void			scene_input(t_gen *d, t_mlx *m, int i)
{
	t_img	*lay;

	if (m->menu.draw == -1 || m->scene != RT)
		return ;
	lay = layer(m, 5, 1);
	while (++i < GET_APP_MAX)
	{
		if (m->get[i].menu != m->menu.id || m->get[i].menu == NONE)
			continue ;
		if (m->get[i].status == GET_FOCUS)
		{
			if (m->get[i].i > (int)ft_strlen(m->get[i].data))
				m->get[i].i = (int)ft_strlen(m->get[i].data);
			scene_input_action(d, m, &m->get[i], lay);
		}
		scene_input_draw_box(d, m, &m->get[i], lay);
	}
	if (m->getfocus)
		scene_input_draw_cursor(m, m->getfocus, lay);
	(void)d;
}
