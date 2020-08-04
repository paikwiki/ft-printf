/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 15:50:12 by cbaek             #+#    #+#             */
/*   Updated: 2020/03/19 16:16:12 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
    int rtn;

    printf("====%%c TEST====\n");
    //t1
    printf("\n===========\n");
    printf("t1 / fmt : %%c / char : a\n");
    printf("result :");
	rtn = printf("%c", 'a');
    printf(":\nreturn: %d\n", rtn);

    //t2
    printf("\n===========\n");
    printf("t2 / fmt : %%5c / char : a\n");
    printf("result :");
	rtn = printf("%5c", 'a');
    printf(":\nreturn: %d\n", rtn);

    //t3
    printf("\n===========\n");
    printf("t3 / fmt : %%-5c / char : a\n");
    printf("result :");
	rtn = printf("%-5c", 'a');
    printf(":\nreturn: %d\n", rtn);

    //t4
    printf("\n===========\n");
    printf("t4 / fmt : %%-.5c / char : a\n");
    printf("result :");
	rtn = printf("%-.5c", 'a');
    printf(":\nreturn: %d\n", rtn);

    //t5
    printf("\n===========\n");
    printf("t5 / fmt : %%5.5c / char : a\n");
    printf("result :");
	rtn = printf("%5.5c", 'a');
    printf(":\nreturn: %d\n", rtn);

    //t6
    printf("\n===========\n");
    printf("t6 / fmt : %% c / char : a\n");
    printf("result :");
	rtn = printf("% c", 'a');
    printf(":\nreturn: %d\n", rtn);

    //t7
    printf("\n===========\n");
    printf("t7 / fmt : %%0c / char : a\n");
    printf("result :");
	rtn = printf("%0c", 'a');
    printf(":\nreturn: %d\n", rtn);

    //t8
    printf("\n===========\n");
    printf("t8 / fmt : %%1c / char : a\n");
    printf("result :");
	rtn = printf("%1c", 'a');
    printf(":\nreturn: %d\n", rtn);
	return (0);
}
