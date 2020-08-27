/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_xx_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:16:33 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/27 23:05:53 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	calc(int arg, t_note *note)
{
	if (arg >= note->width)
	{
		note->cnt_space = 0;
		note->cnt_arg = arg;
		note->cnt_zero = arg >= note->prcs ? 0 : note->prcs - arg;
	}
	else
	{
		note->cnt_arg = (note->is_dot == 1 && note->prcs == 0) ? 0 : arg;
		if (arg >= note->prcs)
		{
			note->cnt_zero = 0;
			note->cnt_space = (note->is_dot == 1 && note->prcs == 0) ?
					note->width : note->width - arg;
		}
		else
		{
			note->cnt_zero = note->prcs - arg;
			note->cnt_space = note->width >= note->prcs ?
					note->width - note->prcs : 0;
		}
	}
	return ;
}

size_t		put_xx_type(unsigned int arg, char *base, t_note *note)
{
	int		proc_len;
	char	*str;
	char	pad_char;
	char	*temp;

	temp = ft_uitoa_base(arg, base);
	str = ft_strdup(temp);
	proc_len = ft_strlen(str);
	calc(proc_len, note);
	proc_len = note->is_dot == 1 && note->prcs == 0 ? proc_len - 1 : proc_len;
	if (note->is_dot == 1 && note->width == 0 && note->prcs == 0)
		return (0);
	pad_char = note->flag == '0' && note->is_dot == 0 ? '0' : ' ';
	if (note->flag == '-')
	{
		proc_len += putnchar('0', note->cnt_zero);
		write(1, str, note->cnt_arg);
		proc_len += putnchar(pad_char, note->cnt_space);
	}
	else
	{
		proc_len += putnchar(pad_char, note->cnt_space);
		proc_len += putnchar('0', note->cnt_zero);
		write(1, str, note->cnt_arg);
	}
	free(str);
	free(temp);
	return (proc_len);
}
