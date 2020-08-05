/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:56:16 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/05 20:22:50 by cbaek            ###   ########.fr       */
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

	/* test 01 - plain text */
	len01 = ft_printf("ft_printf : Doby is Free!");
	ft_printf("\n");
	len02 = ft_printf("ft_printf : Cbaek is in a jail!");
	ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 = printf("   printf : Doby is Free!");
	printf("\n");
	len02 = printf("   printf : Cbaek is in a jail!");
	printf("\nlen01: %d | len02: %d\n", len01, len02);

	/* test 02 - s */
	len01 = ft_printf("ft_printf : %s is %s", "Doby", "free!");
	ft_printf("\n");
	len02 = ft_printf("ft_printf : %s is %s", "Cbaek", "in a jail!");
	ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 = printf("   printf : %s is %s", "Doby", "free!");
	printf("\n");
	len02 = printf("   printf : %s is %s", "Cbaek", "in a jail!");
	printf("\nlen01: %d | len02: %d\n", len01, len02);

	/* test 03 - d */
	len01 = ft_printf("ft_printf : %s is %d", "Doby", 100);
	ft_printf("\n");
	len02 = ft_printf("ft_printf : %s is %d", "Cbaek", 98);
	ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 = printf("   printf : %s is %d", "Doby", 100);
	printf("\n");
	len02 = printf("   printf : %s is %d", "Cbaek", 98);
	printf("\nlen01: %d | len02: %d\n", len01, len02);

	/* test 04 - c */
	len01 = ft_printf("ft_printf : %c is %c", 'D', 'F');
	ft_printf("\n");
	len02 = ft_printf("ft_printf : %c is %c", 'C', 'J');
	ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 = printf("   printf : %c is %c", 'D', 'F');
	printf("\n");
	len02 = printf("   printf : %c is %c", 'C', 'J');
	printf("\nlen01: %d | len02: %d\n", len01, len02);

	/* test 05 - % */
	len01 = ft_printf("ft_printf : %% is %%");
	ft_printf("\nlen01: %d\n", len01);

	len02 = printf("   printf : %% is %%");
	printf("\nlen02: %d\n", len02);

	/* test 06 - u */
	len01 = ft_printf("ft_printf : u: %u", 1);
	ft_printf("\n");
	len02 = ft_printf("ft_printf : u: %u", -1);
	ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 =    printf("   printf : u: %u", 1);
	printf("\n");
	len02 =    printf("   printf : u: %u", -1);
	printf("\nlen01: %d | len02: %d\n", len01, len02);

	/* test 07 - p */
	int temp = 0;
	len01 = ft_printf("ft_printf : p: %p", &temp);
	ft_printf("\nlen01: %d\n", len01);

	len02 =    printf("   printf : p: %p", &temp);
	printf("\nlen02: %d\n", len02);

	return (0);
}
