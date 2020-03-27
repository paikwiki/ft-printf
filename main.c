/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:56:16 by cbaek             #+#    #+#             */
/*   Updated: 2020/03/27 20:58:43 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int len;

	char *str = "idx: %d, str: %s, number: %.3f, percent char: %%\n";
	// printf(str, 123, "test", 2.345);
	ft_printf(str, 123, "test", 2.345);
	return (0);
}
