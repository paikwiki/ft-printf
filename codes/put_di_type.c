/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_di_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:13:28 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/27 20:04:54 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	calc(int arg, t_note *note, int is_negative)
{
	if (arg >= note->width) // 456
	{
		note->space = 0;
		note->arg = note->is_dot == 1 && note->prcs == 0 ? 0 : arg;
		note->zero = arg >= note->prcs ? 0 : note->prcs - arg; // 56
	}
	else // 123
	{
		note->arg = note->is_dot == 1 && note->prcs == 0 ? 0 : arg;
		if (arg >= note->prcs) // 3
		{
			note->zero = 0;
			note->space = note->width - arg - is_negative;
		}
		else // 12
		{
			note->zero = note->prcs - arg;
			note->space = note->width >= note->prcs ? note->width - note->prcs - is_negative : 0;
		}
		note->space += note->is_dot == 1 && note->prcs == 0 ? 1 : 0;
	}
	return ;
}

size_t		put_di_type(int arg, t_note *note)
{
	size_t	proc_len;
	char	*str;
	int		is_negative;
	char 	*temp;

	is_negative = arg < 0 ? 1 : 0;
	temp = itoa_abs(arg);
	str = ft_strdup(temp);
	proc_len = ft_strlen(str);
	calc(proc_len, note, is_negative);
	proc_len = note->arg;
	if (note->flag == '-')
	{
		proc_len += is_negative > 0 ? putnchar('-', 1) : 0;
		proc_len += putnchar('0', note->zero);
		write(1, str, note->arg);
		proc_len += putnchar(' ', note->space);
	}
	else if (note->flag == '0')
	{
		proc_len += note->is_dot == 0 ? putnchar('-', is_negative) : 0;
		proc_len += note->is_dot == 1 ? putnchar(' ', note->space) : putnchar('0', note->space);
		proc_len += note->is_dot == 1 ? putnchar('-', is_negative) : 0;
		proc_len += putnchar('0', note->zero);
		write(1, str, note->arg);
	}
	else
	{
		proc_len += putnchar(' ', note->space);
		proc_len += is_negative > 0 ? putnchar('-', 1) : 0;
		proc_len += putnchar('0', note->zero);
		write(1, str, note->arg);
	}
	free(str);
	free(temp);
	return (proc_len);
}
