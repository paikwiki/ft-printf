/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_di_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:13:28 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/28 17:54:10 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	proc_with_flag(char *str, t_note *note, int is_negative)
{
	int		len;

	len = 0;
	if (note->flag == '-')
	{
		len += is_negative > 0 ? putnchar('-', 1) : 0;
		len += putnchar('0', note->cnt_zero);
		write(1, str, note->cnt_arg);
		len += putnchar(' ', note->cnt_space);
	}
	else if (note->flag == '0')
	{
		len += note->is_dot == 0 ? putnchar('-', is_negative) : 0;
		len += note->is_dot == 1 ? putnchar(' ', note->cnt_space) :
			putnchar('0', note->cnt_space);
		len += note->is_dot == 1 ? putnchar('-', is_negative) : 0;
		len += putnchar('0', note->cnt_zero);
		write(1, str, note->cnt_arg);
	}
	return (len);
}

static void	calc(int len_arg, t_note *note, int is_negative, int arg)
{
	if (len_arg >= note->width)
	{
		note->cnt_space = 0;
		note->cnt_arg = len_arg;
		note->cnt_arg = note->is_dot == 1 && note->prcs == 0 && arg
		 == 0 ? 0 : len_arg;
		note->cnt_zero = len_arg >= note->prcs ? 0 : note->prcs - len_arg;
	}
	else
	{
		note->cnt_arg = note->is_dot == 1 && note->prcs == 0 && arg
		 == 0 ? 0 : len_arg;
		if (len_arg >= note->prcs)
		{
			note->cnt_zero = 0;
			note->cnt_space = note->width - len_arg;
		}
		else
		{
			note->cnt_zero = note->prcs - len_arg;
			note->cnt_space = note->width >= note->prcs ?
					note->width - note->prcs : 0;
		}
		note->cnt_space += note->is_dot == 1 && note->prcs == 0 && arg
		 == 0 ? 1 : 0;
		note->cnt_space -= is_negative == 1 && note->cnt_space > 0 ? 1 : 0;
	}
	return ;
}

size_t		put_di_type(int arg, t_note *note)
{
	size_t	proc_len;
	char	*str;
	int		is_negative;

	is_negative = arg < 0 ? 1 : 0;
	str = itoa_abs(arg);
	proc_len = ft_strlen(str);
	calc(proc_len, note, is_negative, arg);
	proc_len = note->cnt_arg;
	if (note->flag != 0)
		proc_len += proc_with_flag(str, note, is_negative);
	else
	{
		proc_len += putnchar(' ', note->cnt_space);
		proc_len += is_negative > 0 ? putnchar('-', 1) : 0;
		proc_len += putnchar('0', note->cnt_zero);
		write(1, str, note->cnt_arg);
	}
	free(str);
	return (proc_len);
}
