/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 18:57:05 by vice-wra          #+#    #+#             */
/*   Updated: 2019/08/09 18:57:07 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

int count;
static void vertex_copy(t_vertex *v1, t_vertex *v2)
{
	size_t	i;

	i = 0;
	v1->name = ft_strdup(v2->name);
	v1->prev = v2->prev;
	v1->weight = v2->weight;
	while (i < v2->adj->size)
	{
		vector_pair_push_back(v1->adj, v2->adj->data[i].first, v2->adj->data[i].second);
		++i;
	}
	if (!v2->adj->size)
		v1->adj = vector_pair_create(0);

}

static void copy(t_vertex *dst, t_vertex *src, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		vertex_copy(&dst[i], &src[i]);
}

static void grow(t_vert_vector *v)
{
	t_vertex	*new_data;

	new_data = (t_vertex *)malloc(sizeof(t_vertex) * v->capacity * 2);
	copy(new_data, v->data, v->size);
	v->capacity *= 2;
	vertexes_destroy(&v->data, v->size);
	free(v->data);
	v->data = new_data;
}

void		vert_vector_push_back(t_vert_vector *v, char *name)
{
	if (v->size == v->capacity)
	{
		count++;
		grow(v);
	}
	vertex_init(&v->data[v->size], name, -1, 2147483648);
	++v->size;
}
