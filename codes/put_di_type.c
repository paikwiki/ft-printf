/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_di_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:13:28 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/20 16:48:23 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	put_di_type(int arg, t_struct *fields)
{
	char	*str;
	size_t proc_len;

	str = ft_strdup(ft_itoa(arg));
	proc_len = ft_strlen(str);
	while (fields->width > (int)proc_len)
	{
		ft_putchar_fd(' ', 1);
		proc_len++;
	}
	ft_putstr_fd(str, 1);
	return (proc_len);
}
