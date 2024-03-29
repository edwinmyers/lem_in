/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 09:39:30 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/16 18:19:23 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"

void	vector_destroy(t_vector **v)
{
	free((*v)->data);
	(*v)->data = NULL;
	free(*v);
	*v = NULL;
}

void vectors_destroy(t_vector ***v, int size)
{
	int i;

	i = 0;
	while (i < size)
		vector_destroy(&(*v)[i++]);
	free(*v);
	*v = NULL;
}