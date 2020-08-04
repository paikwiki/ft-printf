/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdio_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 15:15:14 by cbaek             #+#    #+#             */
/*   Updated: 2020/03/20 15:15:41 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// StdioString.c    p.121.
#include <stdio.h>

int  main(void)
{
    char szBuffer[128] = {0};
    printf("Input your name: ");
    gets(szBuffer);

    printf("Your name is ");
    puts(szBuffer);
	return (0);
}

// Result
// Input your name: cbaek
// Your name is cbaek
