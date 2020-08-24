/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:56:16 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/21 16:44:53 by cbaek            ###   ########.fr       */
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

	// printf("================================= \n");
	// printf("== TEST SECTION 1: Type field  == \n");
	// printf("================================= \n\n");
	// /* test 01 - plain text */
	// printf("====== 01 - plain text ========== \n");
	// len01 = ft_printf("ft_printf : Andy is Free!");
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : Red is in a jail!");
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : Andy is Free!");
	// printf("\n");
	// len02 = printf("   printf : Red is in a jail!");
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// /* test 02 - s */
	// printf("====== test 02 - s ========== \n");
	// len01 = ft_printf("ft_printf : %s is %s", "Andy", "free!");
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : %s is %s", "Red", "in a jail!");
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : %s is %s", "Andy", "free!");
	// printf("\n");
	// len02 = printf("   printf : %s is %s", "Red", "in a jail!");
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// /* test 03 - d */
	// printf("====== test 03 - d ========== \n");
	// len01 = ft_printf("ft_printf : %s is %d", "Andy", 100);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : %s is %d", "Red", 98);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : %s is %d", "Andy", 100);
	// printf("\n");
	// len02 = printf("   printf : %s is %d", "Red", 98);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = ft_printf("ft_printf : %s is %d", "Andy", INT_MAX);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : %s is %d", "Red", INT_MIN);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : %s is %d", "Andy", INT_MAX);
	// printf("\n");
	// len02 = printf("   printf : %s is %d", "Red", INT_MIN);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// /* test 04 - c */
	// printf("====== test 04 - c ========== \n");
	// len01 = ft_printf("ft_printf : %c is %c", 'D', 'F');
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : %c is %c", 'C', 'J');
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : %c is %c", 'D', 'F');
	// printf("\n");
	// len02 = printf("   printf : %c is %c", 'C', 'J');
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// /* test 05 - % */
	// printf("====== test 05 - %% ========== \n");
	// len01 = ft_printf("ft_printf : %% is %%");
	// ft_printf("\nlen01: %d\n", len01);

	// len02 = printf("   printf : %% is %%");
	// printf("\nlen02: %d\n", len02);

	// /* test 06 - u */
	// printf("====== test 06 - u ========== \n");
	// len01 = ft_printf("ft_printf : u: %u", 1);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : u: %u", -1);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 =    printf("   printf : u: %u", 1);
	// printf("\n");
	// len02 =    printf("   printf : u: %u", -1);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// /* test 07 - p */
	// printf("====== test 07 - p ========== \n");
	// int temp = 0;
	// len01 = ft_printf("ft_printf : p: %p", &temp);
	// ft_printf("\nlen01: %d\n", len01);

	// len02 =    printf("   printf : p: %p", &temp);
	// printf("\nlen02: %d\n", len02);

	// /* test 08 - x */
	// printf("====== test 08 - x ========== \n");
	// len01 = ft_printf("ft_printf : x: %x", 255);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : x: %x", 4080);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 =    printf("   printf : x: %x", 255);
	// printf("\n");
	// len02 =    printf("   printf : x: %x", 4080);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// /* test 09 - X */
	// printf("====== test 09 - X ========== \n");
	// len01 = ft_printf("ft_printf : X: %X", 255);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : X: %X", 4080);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 =    printf("   printf : X: %X", 255);
	// printf("\n");
	// len02 =    printf("   printf : X: %X", 4080);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = ft_printf("ft_printf : X: %X", INT_MAX);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : X: %X", INT_MIN);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 =    printf("   printf : X: %X", INT_MAX);
	// printf("\n");
	// len02 =    printf("   printf : X: %X", INT_MIN);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	printf("================================= \n");
	printf("== TEMPORARY TEST == \n");
	printf("================================= \n");


	// ft_printf("%*.*s\n",10 ,6 ,"abcde");
	// printf("%*.*s\n",10 ,6 ,"abcde");
	// ft_printf("%*.*s\n",6 ,8 ,"abcde");
	// printf("%*.*s\n",6 ,8 ,"abcde");
	// ft_printf("%*.*s\n",10 ,4 ,"abcde");
	// printf("%*.*s\n",10 ,4 ,"abcde");
	// ft_printf("%*.*s\n",4 ,6 ,"abcde");
	// printf("%*.*s\n",4 ,6 ,"abcde");
	// ft_printf("%*.*s\n",4 ,3 ,"abcde");
	// printf("%*.*s\n",4 ,3 ,"abcde");
	// ft_printf("%*.*s\n",3 ,4 ,"abcde");
	// printf("%*.*s\n",3 ,4 ,"abcde");

	// ft_printf("%*.*d\n",10 ,6 ,23452);
	// printf("%*.*d\n",10 ,6 ,23452);
	// ft_printf("%*.*d\n",6 ,8 ,23452);
	// printf("%*.*d\n",6 ,8 ,23452);
	// ft_printf("%*.*d\n",10 ,4 ,23452);
	// printf("%*.*d\n",10 ,4 ,23452);
	// ft_printf("%*.*d\n",4 ,6 ,23452);
	// printf("%*.*d\n",4 ,6 ,23452);
	// ft_printf("%*.*d\n",4 ,3 ,23452);
	// printf("%*.*d\n",4 ,3 ,23452);
	// ft_printf("%*.*d\n",3 ,4 ,23452);
	// printf("%*.*d\n",3 ,4 ,23452);

	// ft_printf("%*.*u\n",10 ,6 ,23452);
	// printf("%*.*u\n",10 ,6 ,23452);
	// ft_printf("%*.*u\n",6 ,8 ,23452);
	// printf("%*.*u\n",6 ,8 ,23452);
	// ft_printf("%*.*u\n",10 ,4 ,23452);
	// printf("%*.*u\n",10 ,4 ,23452);
	// ft_printf("%*.*u\n",4 ,6 ,23452);
	// printf("%*.*u\n",4 ,6 ,23452);
	// ft_printf("%*.*u\n",4 ,3 ,23452);
	// printf("%*.*u\n",4 ,3 ,23452);
	// ft_printf("%*.*u\n",3 ,4 ,23452);
	// printf("%*.*u\n",3 ,4 ,23452);

	// 	ft_printf("%*.*x\n",10 ,6 ,23452);
	// printf("%*.*x\n",10 ,6 ,23452);
	// ft_printf("%*.*x\n",6 ,8 ,23452);
	// printf("%*.*x\n",6 ,8 ,23452);
	// ft_printf("%*.*x\n",10 ,4 ,23452);
	// printf("%*.*x\n",10 ,4 ,23452);
	// ft_printf("%*.*x\n",4 ,6 ,23452);
	// printf("%*.*x\n",4 ,6 ,23452);
	// ft_printf("%*.*x\n",4 ,3 ,23452);
	// printf("%*.*x\n",4 ,3 ,23452);
	// ft_printf("%*.*x\n",3 ,4 ,23452);
	// printf("%*.*x\n",3 ,4 ,23452);

	// ft_printf("%*.*X\n",10 ,6 ,23452);
	// printf("%*.*X\n",10 ,6 ,23452);
	// ft_printf("%*.*X\n",6 ,8 ,23452);
	// printf("%*.*X\n",6 ,8 ,23452);
	// ft_printf("%*.*X\n",10 ,4 ,23452);
	// printf("%*.*X\n",10 ,4 ,23452);
	// ft_printf("%*.*X\n",4 ,6 ,23452);
	// printf("%*.*X\n",4 ,6 ,23452);
	// ft_printf("%*.*X\n",4 ,3 ,23452);
	// printf("%*.*X\n",4 ,3 ,23452);
	// ft_printf("%*.*X\n",3 ,4 ,23452);
	// printf("%*.*X\n",3 ,4 ,23452);

	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	if (
		a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && f == 0 && h == 0 && i == 0 && j == 0 && k == 0 && l == 0 && m == 0 && n == 0 && o == 0 && p == 0 && q == 0 && r == 0 && s == 0 && t == 0 && u == 0)
		;

	// ft_printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d);
	// ft_printf("%*.d", 0, l);
	// printf("$%0d$\n", l);
	// printf("$%0.d$\n", l);
	// printf("$%03d$\n", l);
	// ft_printf("$%0d$\n", l);
	// ft_printf("$%0.d$\n", l);
	// ft_printf("$%03d$\n", l);

	// // printf("$%*d$", -3, 1);
	// int idx = -5;
	// while (idx < 6)
	// {
	// 	printf("$%*d$\n", idx, 1);
	// 	ft_printf("$%*d$\n", idx, 1);
	// 	idx++;
	// }

	// printf("$%.5i$\n", 2);
	// ft_printf("$%.5i$\n", 2);
	// printf("$%.6d$\n", -3);
	// ft_printf("$%.6d$\n", -3);
	// printf("$%8.6d$\n", -3);
	// ft_printf("$%8.6d$\n", -3);
	// printf("$%-8.6d$\n", -3);
	// ft_printf("$%-8.6d$\n", -3);


	// ft_printf("ft_printf : Andy is $%12.6d$\n", 100);
	//    printf("   printf : Andy is $%12.6d$\n", 100);
	// ft_printf("ft_printf : Andy is $%-12.6d$\n", 100);
	//    printf("   printf : Andy is $%-12.6d$\n", 100);
	// ft_printf("ft_printf : Andy is $%012.6d$\n", 100);
	//    printf("   printf : Andy is $%012.6d$\n", 100);

	// /* test 00 - d */
	// printf("====== test 00 - d ========== \n");
	// len01 = ft_printf("ft_printf : %s is %4d", "Andy", 100);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : %s is %6d", "Red", 98);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : %s is %4d", "Andy", 100);
	// printf("\n");
	// len02 = printf("   printf : %s is %6d", "Red", 98);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// /* test 00 - % */
	// printf("====== test 00 - %% ========== \n");
	// len01 = ft_printf("ft_printf : %-8% is %8%");
	// ft_printf("\nlen01: %d\n", len01);

	// len02 = printf("   printf : %-8% is %8%");
	// printf("\nlen02: %d\n", len02);

	// printf("====== test 00 - width, c ========== \n");
	// len01 = ft_printf("ft_printf : $%-8c$", 'a');
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : $%c$", 'a');
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : $%-8c$", 'a');
	// printf("\n");
	// len02 = printf("   printf : $%c$", 'a');
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// printf("====== test 00 - width, p ========== \n");

	// int temp = 0;
	// len01 = ft_printf("ft_printf : $%20p$", &temp);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : $%-20p$", &temp);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : $%20p$", &temp);
	// printf("\n");
	// len02 = printf("   printf : $%-20p$", &temp);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = ft_printf("ft_printf : Andy is $%*.*d$", 123, 456, 100);
	// ft_printf("\n");
	// len01 = ft_printf("ft_printf : Andy is $%123.456d$", 100);
	// ft_printf("\n");
	// len01 = ft_printf("ft_printf : Andy is $%-123.456d$", 100);
	// ft_printf("\n");
	// len01 = ft_printf("ft_printf : Andy is $%0123.456d$", 100);
	// ft_printf("\n");
	// // c,p,%는 그냥 출력
	// // s는 0으로 정밀도를 맞추는 경우만 제외
	// // d,i,u,xX 는 동일하게 동작
	// len01 =    printf("   printf : u: $%20.20u$\n", 1);
	// len01 =    printf("   printf : u: $%20.10u$\n", 1);
	// len01 =    printf("   printf : u: $%10.20u$\n", 1);
	// // len01 = ft_printf("ft_printf : x: $%20.20x$", 255);
	// ft_printf("\n");

	// printf("Test section 1 is ended. Press any key to continue...\n");
	// scanf("lorem");


	// printf("================================= \n");
	// printf("== TEST SECTION 2: Width Field == \n");
	// printf("================================= \n");

	// /* test 01 - d */
	// printf("====== test 03 - d ========== \n");
	// len01 = ft_printf("ft_printf : Andy is $%6d$", 100);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : Red  is $%6d$", 98);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : Andy is $%6d$", 100);
	// printf("\n");
	// len02 = printf("   printf : Red  is $%6d$", 98);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = ft_printf("ft_printf : Andy is $%-6d$", 100);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : Red  is $%-6d$", 98);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : Andy is $%-6d$", 100);
	// printf("\n");
	// len02 = printf("   printf : Red  is $%-6d$", 98);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = ft_printf("ft_printf : Andy is $%06d$", 100);
	// ft_printf("\n");
	// len02 = ft_printf("ft_printf : Red  is $%06d$", 98);
	// ft_printf("\nlen01: %d | len02: %d\n", len01, len02);

	// len01 = printf("   printf : Andy is $%06d$", 100);
	// printf("\n");
	// len02 = printf("   printf : Red  is $%06d$", 98);
	// printf("\nlen01: %d | len02: %d\n", len01, len02);


	// printf("$%05%$\n");
	// ft_printf("$%05%$\n");
	// printf("this %s is empty\n", "");
	// ft_printf("this %s is empty\n", "");

	// printf("$%32s$\n", "abc");
	// ft_printf("$%32s$\n", "abc");
	// printf("$%16s$\n", "nark nark");
	// ft_printf("$%16s$\n", "nark nark");
	// printf("$%.3s$\n", "hello");
	// ft_printf("$%.3s$\n", "hello");
	// printf("$%.0s$\n", "hello");
	// ft_printf("$%.0s$\n", "hello");
	// printf("$hello, %20s.$\n", NULL);
	// ft_printf("$hello, %20s.$\n", NULL);
	// printf("$hello, %s.$\n", NULL);
	// ft_printf("$hello, %s.$\n", NULL);
	// ft_printf("%.5s%7s$", "yo", "boi");
	// ft_printf("$%3.s$", "hi low\0don't print me lol\0");
	// int aa = printf("%.5s%7s", "yo", "boi");
	// int bb = ft_printf("%.5s%7s", "yo", "boi");
	// printf("\n%d, %d\n", aa, bb);

	// printf("$%-8.5x$", 34);
	// printf("$%08.5x$\n", 34);
	// printf("$%0-8.5x$", 0);
	// printf("$%0-8.3x$", 8375);
	// printf("%0-2.7x", 3267);

	// printf("%.0x", 0);
	// printf("%.x", 0);
	// printf("%5.0x", 0);
	// printf("%5.x", 0);
	// printf("%-5.0x", 0);
	// printf("%-5.x", 0);

	ft_printf("%5.p", NULL);
	// printf("%2.9p\n", 1234);
	// printf("%.5p", 0);
	return (0);
}
