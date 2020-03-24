/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pholderfinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 17:40:37 by cbaek             #+#    #+#             */
/*   Updated: 2020/03/24 13:51:13 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

ph_list *ft_phlstnew(void *content, int len)
{
	ph_list *lst;

	if((lst = (ph_list *)malloc(sizeof(ph_list))) == 0)
		return (0);
	lst->content = content;
	lst->len = len;
	lst->next = 0;
	return (lst);
}

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

void ft_phlstadd_back(ph_list **phlst, ph_list *new)
{
	ph_list	*last;

	if (!phlst)
		return ;
	if (*phlst == 0)
		*phlst = new;
	else
	{
		last = *phlst;
		while(last->next != 0)
			last = last->next;
		last->next = new;
	}
}

int	ft_phlstsize(ph_list *phlst)
{
	size_t size;
	ph_list *temp;

	size = 0;
	temp = phlst;
	while (temp != 0)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

int		pholderfinder(const char *str)
{
	int		idx;
	int		len;
	ph_list	*ph_item;
	ph_list	**ph_list;

	*ph_list = 0;
	len = ft_strlen(str);
	idx = 0;
	while (idx < len)
	{
		if (str[idx] == '%')
		{
			ph_item = ft_phlstnew(getpholder(str, idx, "diouxXfFeEgGaAcsb%"), ft_strlen(getpholder(str, idx, "diouxXfFeEgGaAcsb%")));
			printf("placeholder: %%%s\n", ph_item->content);
			idx += ph_item->len;
			if (!(*ph_list))
				*ph_list = ph_item;
			else
				ft_phlstadd_back(ph_list, ph_item);
		}
		idx++;
	}
	printf("ph_list size: %d\n", ft_phlstsize(*ph_list));
	printf("the first %% is not included placeholder. Just print.\n");
	free(ph_item);
	return (0);
}

// int main(void)
// {
// 	char *str = "idx: %d, str: %s, number: %.3f, percent char: %%\n";
// 	pholderfinder(str);
// 	return (0);
// }
