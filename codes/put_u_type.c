/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_u_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:14:52 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/27 20:31:39 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	calc(int arg, t_note *note, int is_negative)
{
	if (arg >= note->width) // 456
	{
		note->cnt_space = 0;
		note->cnt_arg = note->is_dot == 1 && note->prcs == 0 ? 0 : arg;
		note->cnt_zero = arg >= note->prcs ? 0 : note->prcs - arg; // 56
	}
	else // 123
	{
		note->cnt_arg = note->is_dot == 1 && note->prcs == 0 ? 0 : arg;
		if (arg >= note->prcs) // 3
		{
			note->cnt_zero = 0;
			note->cnt_space = note->width - arg - is_negative;
		}
		else // 12
		{
			note->cnt_zero = note->prcs - arg;
			note->cnt_space = note->width >= note->prcs ? note->width - note->prcs - is_negative : 0;
		}
		note->cnt_space += note->is_dot == 1 && note->prcs == 0 ? 1 : 0;
	}
	return ;
}

size_t		put_u_type(unsigned int arg, t_note *note)
{
	int		proc_len;
	char	*str;
	int		is_negative;
	char 	*temp;

	is_negative = arg < 0 ? 1 : 0;
	temp = ft_uitoa_base(arg, DECIMAL);
	str = ft_strdup(temp);
	proc_len = ft_strlen(str);
	calc(proc_len, note, is_negative);
	proc_len = note->cnt_arg;
	if (note->flag == '-')
	{
		proc_len += is_negative > 0 ? putnchar('-', 1) : 0;
		proc_len += putnchar('0', note->cnt_zero);
		write(1, str, note->cnt_arg);
		proc_len += putnchar(' ', note->cnt_space);
	}
	else if (note->flag == '0')
	{
		proc_len += note->is_dot == 0 ? putnchar('-', is_negative) : 0;
		proc_len += note->is_dot == 1 ? putnchar(' ', note->cnt_space) : putnchar('0', note->cnt_space);
		proc_len += note->is_dot == 1 ? putnchar('-', is_negative) : 0;
		proc_len += putnchar('0', note->cnt_zero);
		write(1, str, note->cnt_arg);
	}
	else
	{
		proc_len += putnchar(' ', note->cnt_space);
		proc_len += is_negative > 0 ? putnchar('-', 1) : 0;
		proc_len += putnchar('0', note->cnt_zero);
		write(1, str, note->cnt_arg);
	}
	free(str);
	free(temp);
	return (proc_len);
}
