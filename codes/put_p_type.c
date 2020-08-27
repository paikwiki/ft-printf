/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:54:26 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/27 20:20:25 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	calc(int arg, t_note *note)
{
	note->arg = (note->is_dot == 1 && note->prcs == 0) ? 2 : arg;
	note->zero = 0;
	if (note->width > 0 && note->width > arg)
		note->space = (note->is_dot == 1 && note->prcs == 0) ? note->width - 2 : note->width - arg;
	else
		note->space = 0;
	return ;
}

size_t	put_p_type(unsigned long arg, t_note *note)
{
	char	*str;
	char	*pre_str;
	int		proc_len;
	char 	*temp;

	temp = ft_ultoa_base(arg, HEX_LOWER);
	pre_str = ft_strdup(temp);
	str = ft_strjoin("0x", pre_str);
	proc_len = ft_strlen(str);
	calc(proc_len, note);
	proc_len = (note->is_dot == 1 && note->prcs == 0) ? 2 : note->arg;
	if (note->flag == '-') {
		proc_len += putnchar('0', note->zero);
		write(1, str, note->arg);
		proc_len += putnchar(' ', note->space);
	}
	else {
		proc_len += putnchar(' ', note->space);
		proc_len += putnchar('0', note->zero);
		write(1, str, note->arg);
	}
	free(str);
	free(pre_str);
	free(temp);
	return (proc_len);
}
