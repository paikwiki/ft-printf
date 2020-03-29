/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:56:16 by cbaek             #+#    #+#             */
/*   Updated: 2020/03/29 17:39:04 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int len;

	// char *str = "idx: %d, str: %s, number: %.3f, percent char: %%\n";
	char *str = "third: %drd, second: %dnd, first: %dst\n";
	ft_printf(str, 3, 2, 1);
	return (0);
}
