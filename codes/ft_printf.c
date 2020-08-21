/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:23:23 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/21 16:42:24 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		setzero_fields(t_struct *fields)
{
	fields->flag = 0;
	fields->prcs = 0;
	fields->type = 0;
	fields->width = 0;
}

static void		*parse_fields(const char *fmt, int *idx, t_struct *fields,
		va_list ap)
{
	int	len;

	len = 1;
	if (fmt[*idx + len] == '-' || fmt[*idx + len] == '0')
		fields->flag = fmt[*idx + len++];
	if (fmt[*idx + len] == '*' && ++len)
	{
		fields->width = va_arg(ap, int);
		if (fields->width < 0)
		{
			fields->width = fields->width * -1;
			fields->flag = '-';
		}
	}
	else if (ft_isdigit(fmt[*idx + len]))
		while (ft_isdigit(fmt[*idx + len]) && ++len)
			fields->width = (fields->width * 10) + (fmt[*idx + len - 1] - '0');
	if (fmt[*idx + len] == '.' && ++len)
	{
		fields->is_dot = 1;
		if (fmt[*idx + len] == '*' && ++len)
			fields->prcs = va_arg(ap, int);
		else
		{
			while (ft_isdigit(fmt[*idx + len]) && ++len)
				fields->prcs = (fields->prcs * 10) + (fmt[*idx + len - 1] - '0');
		}
	}
	fields->type = fmt[*idx + len];
	*idx = *idx + len;
	return (0);
}

static size_t	proc_placeholder(char ph_type, va_list ap, t_struct *fields)
{
	if (ph_type == 'c')
		return (put_c_type(va_arg(ap, int), fields));
	else if (ph_type == '%')
		return (put_percent_type(fields));
	else if (ph_type == 'p')
		return (put_p_type(va_arg(ap, unsigned long), fields));
	else if (ph_type == 's')
		return (put_s_type(va_arg(ap, char *), fields));
	else if (ph_type == 'd' || ph_type == 'i')
		return (put_di_type(va_arg(ap, int), fields));
	else if (ph_type == 'u')
		return (put_u_type(va_arg(ap, unsigned int), fields));
	else if (ph_type == 'x')
		return (put_xx_type(va_arg(ap, unsigned int), HEX_LOWER, fields));
	else if (ph_type == 'X')
		return (put_xx_type(va_arg(ap, unsigned int), HEX_UPPER, fields));
	else
		return (0);
}

static int		proc_ft_printf(const char *format, va_list ap)
{
	int			idx;
	size_t		proc_len;
	size_t		total_len;
	t_struct	fields;

	idx = 0;
	total_len = 0;
	while (format[idx] != '\0')
	{
		if (format[idx] != '%' && ++total_len)
			write(1, &format[idx], 1);
		else
		{
			setzero_fields(&fields);
			parse_fields(format, &idx, &fields, ap);
			proc_len = proc_placeholder(fields.type, ap, &fields);
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
	len = proc_ft_printf(format, ap);
	va_end(ap);
	return (len);
}
