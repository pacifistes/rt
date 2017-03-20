/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 13:48:44 by mlinhard          #+#    #+#             */
/*   Updated: 2017/02/04 13:48:44 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytra_gen.h"
#include "raystruct.h"

static int		hexa_to_dec(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	else if (ft_isalpha(c))
	{
		if (c >= 'a' && c <= 'f')
			return (10 + c - 'a');
		if (c >= 'A' && c <= 'F')
			return (10 + c - 'A');
	}
	return (0);
}

static void		input_valid_hexa_to_double(t_gen *d, t_mlx *m, t_get *g, int i)
{
	*g->target.ptr_double = 0;
	while (--i > -1)
		*g->target.ptr_double = *g->target.ptr_double
						+ hexa_to_dec(g->data[i]) * (pow(16, 5 - i));
	notif2(m, N_NORMAL, NOTIF_INPUT_SAVE, g->data);
	input_set_focus(d, m, (t_get *)NULL, -1);
}

static void		input_valid_hexa(t_gen *d, t_mlx *m, t_get *g, int i)
{
	*g->target.ptr_int = 0;
	while (--i > -1)
		*g->target.ptr_int = *g->target.ptr_int
						+ hexa_to_dec(g->data[i]) * (pow(16, 5 - i));
	notif2(m, N_NORMAL, NOTIF_INPUT_SAVE, g->data);
	input_set_focus(d, m, (t_get *)NULL, -1);
}

static int		input_size_min(t_mlx *m, t_get *g)
{
	char		*sizemin;

	if ((int)ft_strlen(g->data) < g->size_min)
	{
		sizemin = ft_itoa(g->size_min);
		notif2(m, N_NORMAL, NOTIF_INPUT_SIZE_MIN, sizemin);
		ft_strdel(&sizemin);
		return (1);
	}
	return (0);
}

void			input_valid(t_gen *d, t_mlx *m, t_get *g)
{
	if (input_size_min(m, g))
		return ;
	else if (g->mode == MODE_STRING_FILE)
		input_valid_string(d, m, g);
	else if (g->mode == MODE_STRING)
		input_valid_string(d, m, g);
	else if (g->mode == MODE_DOUBLE)
		input_valid_double(d, m, g);
	else if (g->mode == MODE_DOUBLE_BUT_INT)
		input_valid_double_but_int(d, m, g);
	else if (g->mode == MODE_INT)
		input_valid_int(d, m, g);
	else if (g->mode == MODE_HEXA_TO_DOUBLE)
		input_valid_hexa_to_double(d, m, g, 6);
	else if (g->mode == MODE_HEXA)
		input_valid_hexa(d, m, g, 6);
	if (g->send)
		g->send(d, m, g);
}
