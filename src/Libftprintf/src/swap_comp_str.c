/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_comp_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:34:04 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:53 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			swap_comp_str(t_string *s1, t_string *s2)
{
	t_string	tmp;

	if (str_len(s1) < str_len(s2))
	{
		tmp = *s1;
		*s1 = *s2;
		*s2 = tmp;
	}
}
