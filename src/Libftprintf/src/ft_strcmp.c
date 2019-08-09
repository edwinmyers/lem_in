/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:29:18 by nparker           #+#    #+#             */
/*   Updated: 2019/08/09 18:37:28 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;

	if (!s1 || !s2)
	{
		ft_printf("s1 %s : s2 %s", s1, s2);
		ft_printf("ERRORRRR");
		exit(0);
	}
	while (s1[i] && s1[i] == s2[i])
		i++;


	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}
