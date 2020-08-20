/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:47:52 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/20 16:07:07 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t put_c_type(int arg, t_struct *fields)
{
	size_t proc_len;

	proc_len = 1;
	while (fields->width > (int)proc_len)
	{
		ft_putchar_fd(' ', 1);
		proc_len++;
	}

	ft_putchar_fd((char)arg, 1);
	return (proc_len);
}
