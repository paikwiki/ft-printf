/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:56:16 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/20 16:52:55 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int	len01;
	int len02;

	len01 = 0;
	len02 = 0;

	printf("================================= \n");
	printf("== TEST SECTION 1: Type field  == \n");
	printf("================================= \n\n");
	/* test 01 - plain text */
	printf("====== 01 - plain text ========== \n");
	len01 = ft_printf("ft_printf : Andy is Free!");
	ft_printf("\n");
	len02 = ft_printf("ft_printf : Red is in a jail!");
	ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 = printf("   printf : Andy is Free!");
	printf("\n");
	len02 = printf("   printf : Red is in a jail!");
	printf("\nlen01: %d | len02: %d\n", len01, len02);

	/* test 02 - s */
	printf("====== test 02 - s ========== \n");
	len01 = ft_printf("ft_printf : %s is %s", "Andy", "free!");
	ft_printf("\n");
	len02 = ft_printf("ft_printf : %s is %s", "Red", "in a jail!");
	ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 = printf("   printf : %s is %s", "Andy", "free!");
	printf("\n");
	len02 = printf("   printf : %s is %s", "Red", "in a jail!");
	printf("\nlen01: %d | len02: %d\n", len01, len02);

	/* test 03 - d */
	printf("====== test 03 - d ========== \n");
	len01 = ft_printf("ft_printf : %s is %d", "Andy", 100);
	ft_printf("\n");
	len02 = ft_printf("ft_printf : %s is %d", "Red", 98);
	ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 = printf("   printf : %s is %d", "Andy", 100);
	printf("\n");
	len02 = printf("   printf : %s is %d", "Red", 98);
	printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 = ft_printf("ft_printf : %s is %d", "Andy", INT_MAX);
	ft_printf("\n");
	len02 = ft_printf("ft_printf : %s is %d", "Red", INT_MIN);
	ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 = printf("   printf : %s is %d", "Andy", INT_MAX);
	printf("\n");
	len02 = printf("   printf : %s is %d", "Red", INT_MIN);
	printf("\nlen01: %d | len02: %d\n", len01, len02);

	/* test 04 - c */
	printf("====== test 04 - c ========== \n");
	len01 = ft_printf("ft_printf : %c is %c", 'D', 'F');
	ft_printf("\n");
	len02 = ft_printf("ft_printf : %c is %c", 'C', 'J');
	ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 = printf("   printf : %c is %c", 'D', 'F');
	printf("\n");
	len02 = printf("   printf : %c is %c", 'C', 'J');
	printf("\nlen01: %d | len02: %d\n", len01, len02);

	/* test 05 - % */
	printf("====== test 05 - %% ========== \n");
	len01 = ft_printf("ft_printf : %% is %%");
	ft_printf("\nlen01: %d\n", len01);

	len02 = printf("   printf : %% is %%");
	printf("\nlen02: %d\n", len02);

	/* test 06 - u */
	printf("====== test 06 - u ========== \n");
	len01 = ft_printf("ft_printf : u: %u", 1);
	ft_printf("\n");
	len02 = ft_printf("ft_printf : u: %u", -1);
	ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 =    printf("   printf : u: %u", 1);
	printf("\n");
	len02 =    printf("   printf : u: %u", -1);
	printf("\nlen01: %d | len02: %d\n", len01, len02);

	/* test 07 - p */
	printf("====== test 07 - p ========== \n");
	int temp = 0;
	len01 = ft_printf("ft_printf : p: %p", &temp);
	ft_printf("\nlen01: %d\n", len01);

	len02 =    printf("   printf : p: %p", &temp);
	printf("\nlen02: %d\n", len02);

	/* test 08 - x */
	printf("====== test 08 - x ========== \n");
	len01 = ft_printf("ft_printf : x: %x", 255);
	ft_printf("\n");
	len02 = ft_printf("ft_printf : x: %x", 4080);
	ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 =    printf("   printf : x: %x", 255);
	printf("\n");
	len02 =    printf("   printf : x: %x", 4080);
	printf("\nlen01: %d | len02: %d\n", len01, len02);

	/* test 09 - X */
	printf("====== test 09 - X ========== \n");
	len01 = ft_printf("ft_printf : X: %X", 255);
	ft_printf("\n");
	len02 = ft_printf("ft_printf : X: %X", 4080);
	ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 =    printf("   printf : X: %X", 255);
	printf("\n");
	len02 =    printf("   printf : X: %X", 4080);
	printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 = ft_printf("ft_printf : X: %X", INT_MAX);
	ft_printf("\n");
	len02 = ft_printf("ft_printf : X: %X", INT_MIN);
	ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 =    printf("   printf : X: %X", INT_MAX);
	printf("\n");
	len02 =    printf("   printf : X: %X", INT_MIN);
	printf("\nlen01: %d | len02: %d\n", len01, len02);

	printf("================================= \n");
	printf("== TEMPORARY TEST == \n");
	printf("================================= \n");

	/* test 00 - d */
	printf("====== test 00 - d ========== \n");
	len01 = ft_printf("ft_printf : %s is %4d", "Andy", 100);
	ft_printf("\n");
	len02 = ft_printf("ft_printf : %s is %6d", "Red", 98);
	ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 = printf("   printf : %s is %4d", "Andy", 100);
	printf("\n");
	len02 = printf("   printf : %s is %6d", "Red", 98);
	printf("\nlen01: %d | len02: %d\n", len01, len02);

	/* test 00 - % */
	printf("====== test 00 - %% ========== \n");
	len01 = ft_printf("ft_printf : %8% is %8%");
	ft_printf("\nlen01: %d\n", len01);

	len02 = printf("   printf : %8% is %8%");
	printf("\nlen02: %d\n", len02);

	printf("====== test 00 - width, c ========== \n");
	len01 = ft_printf("ft_printf : $%8.10c$", 'a');
	ft_printf("\n");
	len02 = ft_printf("ft_printf : $%c$", 'a');
	ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 = printf("   printf : $%8.10c$", 'a');
	printf("\n");
	len02 = printf("   printf : $%c$", 'a');
	printf("\nlen01: %d | len02: %d\n", len01, len02);

	printf("====== test 00 - width, p ========== \n");

	int temp = 0;
	len01 = ft_printf("ft_printf : $%20p$", &temp);
	ft_printf("\n");
	len02 = ft_printf("ft_printf : $%p$", &temp);
	ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 = printf("   printf : $%20p$", &temp);
	printf("\n");
	len02 = printf("   printf : $%p$", &temp);
	printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 = ft_printf("ft_printf : Andy is $%*.*d$", 123, 456, 100);
	ft_printf("\n");
	len01 = ft_printf("ft_printf : Andy is $%123.456d$", 100);
	ft_printf("\n");
	len01 = ft_printf("ft_printf : Andy is $%-123.456d$", 100);
	ft_printf("\n");
	len01 = ft_printf("ft_printf : Andy is $%0123.456d$", 100);
	ft_printf("\n");
	// c,p,%는 그냥 출력
	// s는 0으로 정밀도를 맞추는 경우만 제외
	// d,i,u,xX 는 동일하게 동작
	len01 =    printf("   printf : u: $%20.20u$\n", 1);
	len01 =    printf("   printf : u: $%20.10u$\n", 1);
	len01 =    printf("   printf : u: $%10.20u$\n", 1);
	// len01 = ft_printf("ft_printf : x: $%20.20x$", 255);
	ft_printf("\n");

	printf("Test section 1 is ended. Press any key to continue...\n");
	scanf("lorem");


	printf("================================= \n");
	printf("== TEST SECTION 2: Width Field == \n");
	printf("================================= \n");

	/* test 01 - d */
	printf("====== test 03 - d ========== \n");
	len01 = ft_printf("ft_printf : Andy is $%6d$", 100);
	ft_printf("\n");
	len02 = ft_printf("ft_printf : Red  is $%6d$", 98);
	ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 = printf("   printf : Andy is $%6d$", 100);
	printf("\n");
	len02 = printf("   printf : Red  is $%6d$", 98);
	printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 = ft_printf("ft_printf : Andy is $%-6d$", 100);
	ft_printf("\n");
	len02 = ft_printf("ft_printf : Red  is $%-6d$", 98);
	ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 = printf("   printf : Andy is $%-6d$", 100);
	printf("\n");
	len02 = printf("   printf : Red  is $%-6d$", 98);
	printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 = ft_printf("ft_printf : Andy is $%06d$", 100);
	ft_printf("\n");
	len02 = ft_printf("ft_printf : Red  is $%06d$", 98);
	ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	len01 = printf("   printf : Andy is $%06d$", 100);
	printf("\n");
	len02 = printf("   printf : Red  is $%06d$", 98);
	printf("\nlen01: %d | len02: %d\n", len01, len02);

	return (0);
}
