/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 20:28:16 by cbaek             #+#    #+#             */
/*   Updated: 2020/03/09 21:32:22 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void	printfnstr(int max, ...)
{
	va_list	arg_ptr;
	int		args;
	char	*str;

	va_start(arg_ptr, max);
	args = 0;
	while (args < max)
	{
		str = va_arg(arg_ptr, char *);
		printf("%s\n", str);
		args++;
	}
	va_end(arg_ptr);
}
int		main(void)
{
	printfnstr(3, "Hello", "Hi", "Bye");
	printfnstr(5, "Hey", "Hi", "Yo", "Yeh", "Bye");
	return (0);
}
