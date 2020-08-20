/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_percent_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:51:33 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/20 16:09:36 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t put_percent_type(t_struct *fields)
{
	size_t proc_len;

	proc_len = 1;
	while (fields->width > (int)proc_len)
	{
		ft_putchar_fd(' ', 1);
		proc_len++;
	}

	ft_putchar_fd('%', 1);
	return (proc_len);
}
