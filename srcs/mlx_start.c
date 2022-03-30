/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 13:50:35 by mlinhard          #+#    #+#             */
/*   Updated: 2017/02/18 18:48:47 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raystruct.h"
#include "raytra_gen.h"

int				red_cross(void)
{
	exit(0);
	return (0);
}

static void		init_project(t_mlx *m)
{
	layer(m, 1, 2);
	layer(m, 2, 2);
	loop(m, 1);
}

static void	init_struct(t_gen *s)
{
	texture_earth(0, 0, "oui", s->mlx.mlx);
	texture_fire(0, 0, "oui", s->mlx.mlx);
	texture_ol(0, 0, "oui", s->mlx.mlx);
	texture_black(0, 0, "oui", s->mlx.mlx);
	texture_ice(0, 0, "oui", s->mlx.mlx);
	s->sc = NULL;
	s->sc_off = NULL;
	s->nb = 0;
	s->rep = 0;
}

void			mlx_start(t_gen *d, t_mlx *m)
{
	ft_bzero(m, sizeof(t_mlx));
	m->winx = W_X;
	m->winy = W_Y;
	if (!(m->mlx = mlx_init()))
		error(2, "mlx_init()");
	if (!(m->win = mlx_new_window(m->mlx, m->winx, m->winy, WIN_TITLE, 0)))
		error(2, "mlx_new_window()");
	init_struct(d);
	mlx_hook(m->win, 2, (1L << 0), keyp_hook, d);
	mlx_hook(m->win, 3, (1L << 1), keyr_hook, d);
	mlx_hook(m->win, 4, (1L << 2), mousep_hook, d);
	mlx_hook(m->win, 5, (1L << 3), mouser_hook, d);
	mlx_hook(m->win, 6, (1L << 0), mouseo_hook, d);
	mlx_hook(m->win, 17, (1L << 17), &red_cross, d);
	mlx_loop_hook(m->mlx, loop_hook, d);
	init_project(m);
	mlx_loop(m->mlx);
}
