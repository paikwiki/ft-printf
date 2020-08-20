/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_xx_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:16:33 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/20 12:18:29 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	put_xx_type(unsigned int arg, char *base)
{
	char *str;
	str = ft_strdup(ft_uitoa_base(arg, base));
	ft_putstr_fd(str , 1);
	return (ft_strlen(str));
}
