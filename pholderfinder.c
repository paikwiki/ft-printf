/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pholderfinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 17:40:37 by cbaek             #+#    #+#             */
/*   Updated: 2020/03/27 21:28:00 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*getpholder	(const char *str, int s_idx, const char *fchars)
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

static t_pholder	*phlodernew(char *str, int len)
{
	t_pholder *placeholder;

	if((placeholder = (t_pholder *)malloc(sizeof(t_pholder))) == 0)
		return (0);
	placeholder->str = str;
	placeholder->len = len;
	return (placeholder);
}

int					pholderfinder(t_list **ph_list, const char *str, int len)
{
	int			idx;
	t_pholder	*placeholder;

	idx = 0;
	while (idx < len)
	{
		if (str[idx] == '%')
		{
			placeholder = phlodernew(getpholder(str, idx, "diouxXfFeEgGaAcsb%"),
					ft_strlen(getpholder(str, idx, "diouxXfFeEgGaAcsb%")));
			idx += (placeholder->len);
			if (!((*ph_list)->content))
				*ph_list = ft_lstnew(placeholder);
			else
				ft_lstadd_back(ph_list, ft_lstnew(placeholder));
		}
		idx++;
	}
	free(placeholder);
	return (idx);
}
