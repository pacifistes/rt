/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_menu_load_btn_nav.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 13:49:14 by mlinhard          #+#    #+#             */
/*   Updated: 2017/02/04 13:49:14 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raystruct.h"

void			menu_load_btn_next(void *gen, void *mlx)
{
	t_mlx	*m;
	int		target;

	m = mlx;
	target = m->flst->id + (MENU_LOAD_X_MAX * MENU_LOAD_Y_MAX);
	if (target > (1 + m->total_file - (MENU_LOAD_X_MAX * MENU_LOAD_Y_MAX)))
		target = 1 + m->total_file - (MENU_LOAD_X_MAX * MENU_LOAD_Y_MAX);
	while (m->flst->id != target)
		m->flst = m->flst->n;
	(void)gen;
	(void)mlx;
}

void			menu_load_btn_prev(void *gen, void *mlx)
{
	t_mlx	*m;
	int		target;

	m = mlx;
	target = m->flst->id - (MENU_LOAD_X_MAX * MENU_LOAD_Y_MAX);
	if (target < 1)
		target = 1;
	while (m->flst->id != target)
		m->flst = m->flst->p;
	(void)gen;
	(void)mlx;
}
