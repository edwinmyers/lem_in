/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vert_vec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:58:09 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/15 17:07:07 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void		vert_vector_print(t_vert_vector *v)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	while (i < v->size)
	{
		if (v->data[i].prev == -1)
			s = NULL;
		else
			s = v->data[v->data[i].prev].name;
		ft_printf("(Name: %10s Prev: %10s Dist: %5lld Adj: ", v->data[i].name, s, v->data[i].weight);
		j = 0;
		while (v->data[i].adj != NULL && j < v->data[i].adj->size)
		{
			ft_printf("(%s: %lld) ", v->data[v->data[i].adj->data[j].first].name, v->data[i].adj->data[j].second);
			++j;
		}
		ft_printf(")\n");
		++i;
	}
}
