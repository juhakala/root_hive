/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 21:45:42 by jhakala           #+#    #+#             */
/*   Updated: 2020/02/10 22:40:26 by jhakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burningship_calc(t_ev *ev)
{
	ev->zr = 0;
	ev->zi = 0;
	ev->cr = ev->x / (ev->zoom);
	ev->ci = ev->y / (ev->zoom);
	if (ev->x + WIN_W / 2 + ev->x_offset >= 20 && ev->x + WIN_W / 2 +
		ev->x_offset < WIN_W - 20 && ev->y + WIN_H / 2 + ev->y_offset >= 20
		&& ev->y + WIN_H / 2 + ev->y_offset < WIN_H - 20)
	{
		while (ev->zr * ev->zr + ev->zi * ev->zi < R && ev->iter < ev->iter_max)
		{
			ev->tmp = ev->zr;
			ev->zr = ev->zr * ev->zr - ev->zi * ev->zi + ev->cr;
			ev->zr *= ev->zr < 0 ? -1 : 1;
			ev->zi = 2 * ev->zi * ev->tmp + ev->ci;
			ev->zi *= ev->zi < 0 ? -1 : 1;
			ev->iter++;
		}
		if (ev->iter == ev->iter_max)
			ft_put_pixel(ev, ev->x, ev->y, 0x000000);
		else
			ft_put_pixel(ev, ev->x, ev->y, (ev->color * ev->iter));
	}
}
