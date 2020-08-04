/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:56:16 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/05 01:33:24 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int	len01;
	int len02;

	len01 = 0;
	len02 = 0;

	/* test 01 */
	len01 = ft_printf("ft_printf : Doby is Free!");
	ft_printf("\n");
	len02 = ft_printf("ft_printf : Cbaek is in a jail!");
	ft_printf("\nlen01: ");
	ft_putnbr_fd(len01, 1);
	ft_printf(" | len02: ");
	ft_putnbr_fd(len02, 1);
	ft_printf("\n");
	len01 = printf("   printf : Doby is Free!");
	printf("\n");
	len02 = printf("   printf : Cbaek is in a jail!");
	printf("\nlen01: %d", len01);
	printf(" | len02: %d\n", len02);

	/* test 02 */
	len01 = ft_printf("ft_printf : %s is %s", "Doby", "free!");
	ft_printf("\n");
	len02 = ft_printf("ft_printf : %s is %s", "Cbaek", "in a jail!");
	ft_printf("\nlen01: ");
	ft_putnbr_fd(len01, 1);
	ft_printf(" | len02: ");
	ft_putnbr_fd(len02, 1);
	ft_printf("\n");
	len01 = printf("   printf : %s is %s", "Doby", "free!");
	printf("\n");
	len02 = printf("   printf : %s is %s", "Cbaek", "in a jail!");
	printf("\nlen01: %d", len01);
	printf(" | len02: %d\n", len02);

	/* test 03 */
	len01 = ft_printf("ft_printf : %s is %d", "Doby", 100);
	ft_printf("\n");
	len02 = ft_printf("ft_printf : %s is %d", "Cbaek", 98);
	ft_printf("\nlen01: ");
	ft_putnbr_fd(len01, 1);
	ft_printf(" | len02: ");
	ft_putnbr_fd(len02, 1);
	ft_printf("\n");
	len01 = printf("   printf : %s is %d", "Doby", 100);
	printf("\n");
	len02 = printf("   printf : %s is %d", "Cbaek", 98);
	printf("\nlen01: %d", len01);
	printf(" | len02: %d\n", len02);


	return (0);
}
