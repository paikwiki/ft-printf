/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:23:23 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/20 11:26:44 by cbaek            ###   ########.fr       */
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

static void		*parse_fields(const char *fmt, int *idx, t_struct *fields, va_list ap)
{
	int		len;

	len = 1;
	if (fmt[*idx + len] == '-' || fmt[*idx + len] == '0')
		fields->flag = fmt[*idx + len++];
	if (fmt[*idx + len] == '*' && len++)
		fields->width = va_arg(ap, int);
	else if (ft_isdigit(fmt[*idx + len]))
	{
		while(ft_isdigit(fmt[*idx + len]) && len++)
			fields->width = (fields->width * 10) + (fmt[*idx + len] - '0');
	}
	if (fmt[*idx + len] == '.' && len++)
	{
		if (fmt[*idx + len] == '*' && len++)
			fields->prcs = va_arg(ap, int);
		else {
			while(ft_isdigit(fmt[*idx + len]) && len++)
				fields->prcs = (fields->prcs * 10) + (fmt[*idx + len] - '0');
		}
	}
	fields->type = fmt[*idx + len];
	*idx = *idx + len;
	return (0);
}

static size_t	proc_placeholder(char ph_type, va_list ap)
{
	char	*str;
	size_t	proc_len;

	if (ph_type == 'c')
	{
		ft_putchar_fd((char)va_arg(ap, int), 1);
		proc_len = 1;
		return (proc_len);
	}
	else if (ph_type == '%')
	{
		ft_putchar_fd('%', 1);
		proc_len = 1;
		return (proc_len);
	}
	else if (ph_type == 'p')
	{
		str = ft_strdup(ft_ultoa_base(va_arg(ap, unsigned long), HEX_LOWER));
		str = ft_strjoin("0x", str);
	}
	else if (ph_type == 's')
		str = ft_strdup(va_arg(ap, char *));
	else if (ph_type == 'd' || ph_type == 'i')
		str = ft_strdup(ft_itoa(va_arg(ap, int)));
	else if (ph_type == 'u')
		str = ft_strdup(ft_uitoa_base(va_arg(ap, unsigned int), DECIMAL));
	else if (ph_type == 'x')
		str = ft_strdup(ft_uitoa_base(va_arg(ap, unsigned int), HEX_LOWER));
	else if (ph_type == 'X')
		str = ft_strdup(ft_uitoa_base(va_arg(ap, unsigned int), HEX_UPPER));
	else
	{
		if ((str = (char *)malloc(sizeof(char) * 1)) == NULL)
			return (0);
		str[0] = '\0';
	}
	ft_putstr_fd(str, 1);
	proc_len = ft_strlen(str);
	return (proc_len);
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
		if (format[idx] != '%')
		{
			ft_putchar_fd(format[idx], 1);
			total_len = total_len + 1;
		}
		else
		{
			setzero_fields(&fields);
			parse_fields(format, &idx, &fields, ap);
			proc_len = proc_placeholder(fields.type, ap);
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
