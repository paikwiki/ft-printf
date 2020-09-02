/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 10:08:33 by cbaek             #+#    #+#             */
/*   Updated: 2020/09/02 18:56:32 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			proc_with_flag(char *str, t_note *note, int is_negative)
{
	int	len;

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

void		parse_prcs(int *len, const char *fmt, int *idx, t_note *note)
{
	int	sign;

	sign = 1;
	if (fmt[*idx + *len] == '-' && ++(*len))
		sign = -1;
	while (ft_isdigit(fmt[*idx + *len]) && ++(*len))
		note->prcs = (note->prcs * 10) + (fmt[*idx + *len - 1] - '0');
	note->prcs *= sign;
}

int			parse_flag(const char *fmt, int *idx, t_note *note)
{
	int	len;

	len = 1;
	while (ft_strchr("-0", fmt[*idx + len]) && fmt[*idx + len] != '\0')
	{
		note->flag = note->flag != '-' ? fmt[*idx + len] : note->flag;
		len++;
	}
	return (len);
}

char		*itoa_abs(int arg)
{
	unsigned int	value;

	value = arg > 0 ? (unsigned int)arg : (unsigned int)arg * -1;
	return (ft_uitoa_base(value, DECIMAL));
}

size_t		putnchar(char chr, size_t len)
{
	size_t	idx;

	idx = 0;
	if (len == 0)
		return (0);
	while (len > idx)
	{
		write(1, &chr, 1);
		idx++;
	}
	return (idx);
}
