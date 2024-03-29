/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vert_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:20:32 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/15 20:10:09 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

t_vert_vector		*vert_vector_create(int size)
{
	t_vert_vector	*v;

	v = (t_vert_vector *)malloc(sizeof(t_vert_vector));
	if (size == 0)
	{
		v->data = (t_vertex *)malloc(sizeof(t_vertex) * 10);
		v->size = 0;
		v->capacity = 10;
	}
	else
	{
		v->data = (t_vertex *)malloc(sizeof(t_vertex) * size * 2);
		v->size = size;
		v->capacity = size * 2;
	}
	vertexes_init(v->data, v->capacity);
	return (v);
}

void				vert_vector_destroy(t_vert_vector **v)
{
	vertexes_destroy((*v)->data, (*v)->capacity);
	free((*v)->data);
	free(*v);
	*v = NULL;
}
