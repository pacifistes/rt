/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 17:09:09 by ocarta-l          #+#    #+#             */
/*   Updated: 2017/02/18 19:04:57 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytra_gen.h"
#include "raystruct.h"

int			main(void)
{
	t_gen	s;

	ft_bzero(&s, sizeof(t_gen));
	s.view_angle[0] = 0;
	s.view_angle[1] = 0;
	s.view_angle[2] = 0;
	mlx_start(&s, &s.mlx);
	return (0);
}
