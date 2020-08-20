/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 22:23:23 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/20 10:13:31 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		*parse_fields(const char *format, int *idx, t_struct *fields, va_list ap)
{
	int		len;

	len = 1;
	if (format[*idx + len] == '-' || format[*idx + len] == '0')
		fields->flag = format[*idx + len++];
	if (format[*idx + len] == '*' && len++)
		fields->width = va_arg(ap, int);
	else if (ft_isdigit(format[*idx + len]))
	{
		while(ft_isdigit(format[*idx + len]))
		{
			fields->width = (fields->width * 10) + (format[*idx + len] - '0');
			len++;
		}
	}
	if (format[*idx + len] == '.')
	{
		len++;
		if (format[*idx + len] == '*' && len++)
			fields->precision = va_arg(ap, int);
		else {
			while(ft_isdigit(format[*idx + len]))
			{
				fields->precision = (fields->precision * 10) + (format[*idx + len] - '0');
				len++;
			}
		}
	}
	fields->type = format[*idx + len];
	*idx = *idx + len;
	return (0);
}

static char		*get_typed_arg(char ph_type, va_list ap)
{
	char	*str;

	if (ph_type == 'c')
	{
		if ((str = (char *)malloc(sizeof(char) * 2)) == NULL)
			return (0);
		str[0] = (char)va_arg(ap, int);
		str[1] = '\0';
	}
	else if (ph_type == 's')
		str = ft_strdup(va_arg(ap, char *));
	else if (ph_type == 'd' || ph_type == 'i')
		str = ft_strdup(ft_itoa(va_arg(ap, int)));
	else if (ph_type == '%')
	{
		if ((str = (char *)malloc(sizeof(char) * 2)) == NULL)
			return (0);
		str = "%\0";
	}
	else if (ph_type == 'p')
	{
		str = ft_strdup(ft_ultoa_base(va_arg(ap, unsigned long), HEX_LOWER));
		str = ft_strjoin("0x", str);
	}
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
	return (str);
}

static void		init_fields(t_struct *fields)
{
	fields->flag = 0;
	fields->precision = 0;
	fields->type = 0;
	fields->width = 0;
}

static int		proc_ft_printf(const char *format, va_list ap)
{
	char		*str;
	int			idx;
	int			total_len;
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
			init_fields(&fields);
			parse_fields(format, &idx, &fields, ap);
			str = get_typed_arg(fields.type, ap);
			total_len = total_len + ft_strlen(str);
		}
		++idx;
	}
	return (total_len);
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = proc_ft_printf(format, ap);
	va_end(ap);
	return (len);
}
