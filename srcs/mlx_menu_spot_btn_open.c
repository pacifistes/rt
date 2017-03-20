/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_menu_spot_btn_open.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 13:49:47 by mlinhard          #+#    #+#             */
/*   Updated: 2017/02/04 13:49:47 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raystruct.h"

static void		build_list(t_mlx *m, t_flst *new, t_spot *spot)
{
	while (spot)
	{
		if (!(new = (t_flst *)ft_memalloc(sizeof(t_flst))))
			error(2, "malloc t_flst struct");
		if (!spot->name || ft_strlen(spot->name) == 0)
			new->path = ft_strdup("Unknow..");
		else
			new->path = ft_strdup(spot->name);
		if (!m->flst && (m->flst = new)
			&& (!(new->p = (t_flst *)NULL)))
			new->n = (t_flst *)NULL;
		else if ((m->flst->p = new)
		&& (new->n = m->flst)
		&& (!(new->p = NULL)))
			m->flst = new;
		m->flst->spot = spot;
		spot = spot->next;
	}
}

void			menu_spot_open_order(t_gen *d, t_mlx *m)
{
	t_flst	*lst;
	int		total;

	menu_list_free(m, m->flst, (t_flst *)NULL);
	m->flst = NULL;
	build_list(m, m->flst, d->sc->spot);
	lst = m->flst;
	total = 0;
	while (++total && lst && (lst->id = total))
		lst = lst->n;
	m->total_file = total;
	m->menu.id = LOAD_SPOT;
}

void			menu_spot_btn_open(void *gen, void *mlx)
{
	t_gen	*d;
	t_mlx	*m;

	d = gen;
	m = mlx;
	if (!m->menu.spot)
		menu_spot_open_order(d, m);
	else
	{
		m->menu.id = LOAD_SPOT;
		menu_edit_mod_btn_open(gen, mlx);
	}
}
