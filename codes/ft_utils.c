/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 10:08:33 by cbaek             #+#    #+#             */
/*   Updated: 2020/09/02 17:44:56 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void		init_note(t_note *note)
{
	note->flag = 0;
	note->type = 0;
	note->width = 0;
	note->prcs = 0;
	note->is_dot = 0;
	note->cnt_space = 0;
	note->cnt_zero = 0;
	note->cnt_arg = 0;
}

char		*itoa_abs(int arg)
{
	unsigned int	value;

	value = arg > 0 ? (unsigned int)arg : (unsigned int)arg * -1;
	return (ft_uitoa_base(value, DECIMAL));
}

size_t		putnchar(char chr, size_t len)
{
	size_t			idx;

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
