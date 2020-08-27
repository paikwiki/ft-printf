/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:23:23 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/27 22:50:25 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		setzero_note(t_note *note)
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

static void		*parse_note(const char *fmt, int *idx, t_note *note, va_list ap)
{
	int	len;

	len = 1;
	note->flag = ft_strchr("-0", fmt[*idx + len]) ? fmt[*idx + len++] : 0;
	if (ft_strchr("-0", fmt[*idx + len]) && len++)
		note->flag = note->flag != '-' ? fmt[*idx + len - 1] : note->flag;
	if (fmt[*idx + len] == '*' && ++len)
		note->width = va_arg(ap, int);
	note->flag = note->width < 0 ? '-' : note->flag;
	note->width = note->width < 0 ? note->width * -1 : note->width;
	if (ft_isdigit(fmt[*idx + len]))
		while (ft_isdigit(fmt[*idx + len]) && ++len)
			note->width = (note->width * 10) + (fmt[*idx + len - 1] - '0');
	if (fmt[*idx + len] == '.' && ++len)
		note->is_dot = 1;
	if (note->is_dot == 1 && fmt[*idx + len] == '*' && ++len)
		note->prcs = va_arg(ap, int);
	else if (note->is_dot == 1)
		while (ft_isdigit(fmt[*idx + len]) && ++len)
			note->prcs = (note->prcs * 10) + (fmt[*idx + len - 1] - '0');
	note->type = fmt[*idx + len];
	*idx = *idx + len;
	return (0);
}

static size_t	proc_placeholder(char ph_type, va_list ap, t_note *note)
{
	if (ph_type == 'c')
		return (put_c_type(va_arg(ap, int), note));
	else if (ph_type == '%')
		return (put_percent_type(note));
	else if (ph_type == 'p')
		return (put_p_type(va_arg(ap, unsigned long), note));
	else if (ph_type == 's')
		return (put_s_type(va_arg(ap, char *), note));
	else if (ph_type == 'd' || ph_type == 'i')
		return (put_di_type(va_arg(ap, int), note));
	else if (ph_type == 'u')
		return (put_u_type(va_arg(ap, unsigned int), note));
	else if (ph_type == 'x')
		return (put_xx_type(va_arg(ap, unsigned int), HEX_LOWER, note));
	else if (ph_type == 'X')
		return (put_xx_type(va_arg(ap, unsigned int), HEX_UPPER, note));
	else
		return (0);
}

static int		proc_ft_printf(const char *format, va_list ap)
{
	int			idx;
	size_t		proc_len;
	size_t		total_len;
	t_note		note;

	idx = 0;
	total_len = 0;
	proc_len = 0;
	while (format[idx] != '\0')
	{
		if (format[idx] != '%' && ++total_len)
			write(1, &format[idx], 1);
		else
		{
			setzero_note(&note);
			parse_note(format, &idx, &note, ap);
			if ((proc_len = proc_placeholder(note.type, ap, &note)) == 0 &&
					ft_strchr("diusxX", note.type) == 0)
				return (ERROR);
			total_len = total_len + proc_len;
		}
		++idx;
	}
	return (total_len);
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	len;

	va_start(ap, format);
	if ((len = proc_ft_printf(format, ap)) == ERROR)
		return (ERROR);
	va_end(ap);
	return (len);
}
