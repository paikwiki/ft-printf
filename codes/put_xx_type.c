/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_xx_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:16:33 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/27 16:07:24 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	calc(int arg, t_struct *note)
{
	if (arg >= note->width) // 456
	{
		note->space = 0;
		note->arg = arg;
		note->zero = arg >= note->prcs ? 0 : note->prcs - arg; // 56
	}
	else // 123
	{
		note->arg = (note->is_dot == 1 && note->prcs == 0) ? 0 : arg;
		if (arg >= note->prcs) // 3
		{
			note->zero = 0;
			note->space = (note->is_dot == 1 && note->prcs == 0) ? note->width : note->width - arg;
		}
		else // 12
		{
			note->zero = note->prcs - arg;
			note->space = note->width >= note->prcs ? note->width - note->prcs : 0;
		}

	}
	return ;
}

size_t		put_xx_type(unsigned int arg, char *base, t_struct *note)
{
	int		proc_len;
	char	*str;
	char	pad_char;
	char 	*temp;

	temp = ft_uitoa_base(arg, base);
	str = ft_strdup(temp);
	proc_len = ft_strlen(str);
	calc(proc_len, note);
	proc_len = note->is_dot == 1 && note->prcs == 0 ? proc_len - 1 : proc_len;
	if (note->is_dot == 1 && note->width == 0 && note->prcs == 0)
		return (0);
	pad_char = note->flag == '0' && note->is_dot == 0 ? '0' : ' ';
	if (note->flag == '-') {
		proc_len += putnchar('0', note->zero);
		write(1, str, note->arg);
		proc_len += putnchar(pad_char, note->space);
	}
	else {
		proc_len += putnchar(pad_char, note->space);
		proc_len += putnchar('0', note->zero);
		write(1, str, note->arg);
	}
	free(str);
	free(temp);
	return (proc_len);
}
