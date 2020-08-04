/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:56:16 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/05 00:54:27 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int	len;

	len = 0;

	/* test 01 */
	len = ft_printf("ft_printf : Doby is Free!");
	ft_printf("\nlen: ");
	ft_putnbr_fd(len, 1);
	ft_printf("\n");
	len = printf("printf    : Doby is Free!");
	printf("\nlen: %d\n", len);

	/* test 02 */
	len = ft_printf("ft_printf : %s is %s", "Doby", "free!");
	ft_printf("\nlen: ");
	ft_putnbr_fd(len, 1);
	ft_printf("\n");
	len = printf("printf    : %s is %s", "Doby", "free!");
	printf("\nlen: %d\n", len);

	/* test 03 */
	len = ft_printf("ft_printf : %s is %s", "Cbaek", "in a jail!");
	ft_printf("\nlen: ");
	ft_putnbr_fd(len, 1);
	ft_printf("\n");
	len = printf("printf    : %s is %s", "Cbaek", "in a jail!");
	printf("\nlen: %d\n", len);

	return (0);
}
