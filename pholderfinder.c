/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pholderfinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 17:40:37 by cbaek             #+#    #+#             */
/*   Updated: 2020/03/24 20:40:17 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static char	*getpholder	(const char *str, int s_idx, const char *fchars)
{
	char *fstr;
	int idx;
	int start;
	int len;

	start = s_idx;
	idx = 0;
	s_idx++;
	while (!(ft_strchr(fchars, str[s_idx])))
		s_idx++;
	len = (s_idx - start) + 1;
	if ((fstr = (char *)calloc(len, sizeof(char))) == 0)
		return (0);
	while (len > 1)
	{
		fstr[idx++] = str[++start];
		len--;
	}
	fstr[idx] = 0;
	return (fstr);
}

int			pholderfinder(const char *str)
{
	int		idx;
	int		len;
	t_placeholder	*placeholder;
	t_list			*ph_list_first;

	if((ph_list_first = (t_list *)malloc(sizeof(t_list))) == 0)
		return (0);
	ph_list_first->content = 0;
	len = ft_strlen(str);
	idx = 0;
	while (idx < len)
	{
		if (str[idx] == '%')
		{
			if((placeholder = (t_placeholder *)malloc(sizeof(t_placeholder))) == 0)
				return (0);
			placeholder->str = getpholder(str, idx, "diouxXfFeEgGaAcsb%");
			placeholder->len = ft_strlen(placeholder->str);
			printf("placeholder: %%%s\n", (placeholder->str));
			idx += (placeholder->len);
			if (!(ph_list_first->content))
				ph_list_first = ft_lstnew(placeholder);
			else
				ft_lstadd_back(&ph_list_first, ft_lstnew(placeholder));
		}
		idx++;
	}
	len = ft_lstsize(ph_list_first);
	printf("ph_list size: %d\n", len);
	printf("the first %% is not included placeholder. Just print.\n");
	free(placeholder);
	free(ph_list_first);
	return (len);
}
