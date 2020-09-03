/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:09:45 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/28 11:17:07 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	calc(int arg, t_note *note)
{
	if (arg >= note->width)
	{
		if (note->is_dot == 1 && arg >= note->prcs)
		{
			note->cnt_arg = note->prcs < 0 ? arg : note->prcs;
			note->cnt_space = note->width >= note->prcs && note->prcs >= 0 ?
					note->width - note->prcs : 0;
		}
		else
			note->cnt_arg = arg;
	}
	else
	{
		note->cnt_arg = (arg >= note->prcs) && note->prcs > 0 ?
				note->prcs : arg;
		if (note->prcs < 0)
			note->cnt_space = note->width - note->cnt_arg;
		else
			note->cnt_space = (arg >= note->prcs) && note->is_dot != 0 ?
					note->width - note->prcs : note->width - arg;
	}
	return ;
}

size_t		put_s_type(char *arg, t_note *note)
{
	int		proc_len;
	char	*str;

	str = arg == NULL ? ft_strdup(PRINT_NULL) : ft_strdup(arg);
	proc_len = ft_strlen(str);
	calc(proc_len, note);
	note->cnt_arg = (note->is_dot == 1 && note->prcs == 0) ? 0 : note->cnt_arg;
	proc_len = note->cnt_arg;
	if (note->is_dot == 1 && note->width == 0 && note->prcs == 0)
		return (0);
	if (note->flag == '-')
	{
		write(1, str, note->cnt_arg);
		proc_len += putnchar(' ', note->cnt_space);
	}
	else
	{
		proc_len += putnchar(' ', note->cnt_space);
		write(1, str, note->cnt_arg);
	}
	free(str);
	return (proc_len);
}
