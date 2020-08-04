/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdio_print02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 16:40:22 by cbaek             #+#    #+#             */
/*   Updated: 2020/03/20 16:42:12 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	char *pszData = "Test string!";

	printf("%s\n", pszData);
	printf("%p\n", pszData);
	printf("%p\n", &pszData);
}

// Result
// Test string!
// 0x105e2ff9e
// 0x7ffee9dd05c8
