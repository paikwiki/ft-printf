/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:54:26 by cbaek             #+#    #+#             */
/*   Updated: 2020/09/02 16:22:52 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	generate_str(char **str, unsigned long long arg, t_note *note)
{
	char	*temp;

	if (arg == 0 && note->is_dot && note->prcs == 0)
	{
		temp = ft_strdup("0x");
		*str = temp;
	}
	else
	{
		temp = ft_ultoa_base(arg, HEX_LOWER);
		*str = ft_strjoin("0x", temp);
		free(temp);
	}
	return (ft_strlen(*str));
}

static void	calc(int arg, t_note *note)
{
	note->cnt_arg = arg;
	note->cnt_zero = 0;
	if (note->width < 0)
	{
		note->flag = '-';
		note->width *= -1;
	}
	if (note->width != 0 && note->width > arg)
		note->cnt_space = note->width - arg;
	else
		note->cnt_space = 0;
	return ;
}

size_t		put_p_type(unsigned long arg, t_note *note)
{
	char	*str;
	int		proc_len;

	proc_len = generate_str(&str, arg, note);
	calc(proc_len, note);
	proc_len = note->cnt_arg;
	if (note->flag == '-')
	{
		proc_len += putnchar('0', note->cnt_zero);
		write(1, str, note->cnt_arg);
		proc_len += putnchar(' ', note->cnt_space);
	}
	else
	{
		proc_len += putnchar(' ', note->cnt_space);
		proc_len += putnchar('0', note->cnt_zero);
		write(1, str, note->cnt_arg);
	}
	free(str);
	return (proc_len);
}
