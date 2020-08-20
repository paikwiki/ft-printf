/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:54:26 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/20 15:41:55 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	put_p_type(unsigned long arg, t_struct *fields)
{
	char *str;
	size_t proc_len;

	str = ft_strdup(ft_ultoa_base(arg, HEX_LOWER));
	str = ft_strjoin("0x", str);
	proc_len = ft_strlen(str);
	while (fields->width > (int)proc_len)
	{
		ft_putchar_fd(' ', 1);
		proc_len++;
	}
	ft_putstr_fd(str, 1);
	return (proc_len);
}
