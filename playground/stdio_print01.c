/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdio_print01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 16:26:46 by cbaek             #+#    #+#             */
/*   Updated: 2020/03/20 16:40:04 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	int nData = 0x41;

	printf("%d\n", nData);
	printf("%X\n", nData);
	printf("%c\n", nData);
	printf("%c\n", nData + 1);
	printf("%c\n", 'A' + 2);
	printf("%c\n", 'A' + 3);
	printf("%s, %d\n", "Hello", 10);
}

// Result
// 65
// 41
// A
// B
// C
// D
// Hello, 10
