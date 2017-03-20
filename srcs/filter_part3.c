/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_part3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <bbrunell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 17:57:13 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/18 17:41:16 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raystruct.h"

void	browni(char *data, int index)
{
	unsigned char	col[3];
	double			nbr[3][4];

	nbr[0][0] = 0.6;
	nbr[0][1] = 0.346;
	nbr[0][2] = -0.27;
	nbr[0][3] = 47.432;
	nbr[1][0] = -0.04;
	nbr[1][1] = 0.861;
	nbr[1][2] = 0.151;
	nbr[1][3] = -36.968;
	nbr[2][0] = 0.241;
	nbr[2][1] = -0.074;
	nbr[2][2] = 0.45;
	nbr[2][3] = -7.562;
	while ((index += 4) < W_Y * W_X * 4)
	{
		col[0] = data[index + 2];
		col[1] = data[index + 1];
		col[2] = data[index + 0];
		data[index + 2] = change_col(col, nbr[0]);
		data[index + 1] = change_col(col, nbr[1]);
		data[index + 0] = change_col(col, nbr[2]);
	}
}

void	vintage(char *data, int index)
{
	unsigned char	col[3];
	double			nbr[3][4];

	nbr[0][0] = 0.628;
	nbr[0][1] = 0.32;
	nbr[0][2] = -0.04;
	nbr[0][3] = 9.651;
	nbr[1][0] = 0.026;
	nbr[1][1] = 0.644;
	nbr[1][2] = -0.03;
	nbr[1][3] = 7.463;
	nbr[2][0] = 0.047;
	nbr[2][1] = -0.085;
	nbr[2][2] = 0.524;
	nbr[2][3] = 5.159;
	while ((index += 4) < W_Y * W_X * 4)
	{
		col[0] = data[index + 2];
		col[1] = data[index + 1];
		col[2] = data[index + 0];
		data[index + 2] = change_col(col, nbr[0]);
		data[index + 1] = change_col(col, nbr[1]);
		data[index + 0] = change_col(col, nbr[2]);
	}
}

void	black_and_white(char *data, int index)
{
	unsigned char	col[3];
	double			nbr[3][4];

	nbr[0][0] = 0.299;
	nbr[0][1] = 0.587;
	nbr[0][2] = 0.114;
	nbr[0][3] = 0;
	nbr[1][0] = 0.299;
	nbr[1][1] = 0.587;
	nbr[1][2] = 0.114;
	nbr[1][3] = 0;
	nbr[2][0] = 0.299;
	nbr[2][1] = 0.587;
	nbr[2][2] = 0.114;
	nbr[2][3] = 0;
	while ((index += 4) < W_Y * W_X * 4)
	{
		col[0] = data[index + 2];
		col[1] = data[index + 1];
		col[2] = data[index + 0];
		data[index + 2] = change_col(col, nbr[0]);
		data[index + 1] = change_col(col, nbr[1]);
		data[index + 0] = change_col(col, nbr[2]);
	}
}

void	lsd(char *data, int index)
{
	unsigned char	col[3];
	double			nbr[3][4];

	nbr[0][0] = 2;
	nbr[0][1] = -0.4;
	nbr[0][2] = 0.5;
	nbr[0][3] = 0;
	nbr[1][0] = -0.5;
	nbr[1][1] = 2;
	nbr[1][2] = -0.4;
	nbr[1][3] = 0;
	nbr[2][0] = -0.4;
	nbr[2][1] = -0.5;
	nbr[2][2] = 3;
	nbr[2][3] = 0;
	while ((index += 4) < W_Y * W_X * 4)
	{
		col[0] = data[index + 2];
		col[1] = data[index + 1];
		col[2] = data[index + 0];
		data[index + 2] = change_col(col, nbr[0]);
		data[index + 1] = change_col(col, nbr[1]);
		data[index + 0] = change_col(col, nbr[2]);
	}
}

void	abstract(char *data, int index)
{
	unsigned char	col[3];
	double			nbr[3][4];

	nbr[0][0] = 1;
	nbr[0][1] = 0;
	nbr[0][2] = 0;
	nbr[0][3] = 0;
	nbr[1][0] = 0;
	nbr[1][1] = 1;
	nbr[1][2] = 0;
	nbr[1][3] = 0;
	nbr[2][0] = 0;
	nbr[2][1] = 0;
	nbr[2][2] = 1;
	nbr[2][3] = 0;
	while ((index += 4) < W_Y * W_X * 4)
	{
		col[0] = data[index + 2];
		col[1] = data[index + 1];
		col[2] = data[index + 0];
		data[index + 2] = change_col(col, nbr[0]);
		data[index + 1] = change_col(col, nbr[1]);
		data[index + 0] = change_col(col, nbr[2]);
	}
}
