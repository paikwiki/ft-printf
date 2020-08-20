/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:54:26 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/20 11:57:03 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	put_p_type(unsigned long arg)
{
	char *str;
	str = ft_strdup(ft_ultoa_base(arg, HEX_LOWER));
	str = ft_strjoin("0x", str);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
