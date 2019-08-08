/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admonds_carp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 13:01:55 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/08 16:26:05 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

static void	bfs_init(t_graph *g)
{
	size_t	i;

	i = 0;
	while (i < vert_vector_size(g->nodes))
	{
		vert_vector_at(g->nodes, i)->color = 0;
		vert_vector_at(g->nodes, i)->prev = -1;
		vert_vector_at(g->nodes, i)->weight = 2147483648;
		++i;
	}
	vert_vector_at(g->nodes, g->start_idx)->color = 1;
	vert_vector_at(g->nodes, g->start_idx)->weight = 0;
}

static void		bfs(t_graph *g, t_vector *vec)
{
	t_int_queue	*q;
	t_vertex	*v;
	t_vertex	*u;
	size_t		i;
	int			curr;

	q = int_queue_create();
	bfs_init(g);
	int_queue_push(q, g->start_idx);
	while (!int_queue_isempty(q))
	{
		curr = int_queue_pop(q);
		v = vert_vector_at(g->nodes, curr);
		i = -1;
		while (++i < vector_pair_len(v->adj))
		{
			if (vec->data[curr] == 1 && vector_pair_second(v->adj, i) != -1)
				continue ;
			u = vert_vector_at(g->nodes, vector_pair_first(v->adj, i));
			if (u->color == 0)
			{
				u->color = 1;
				u->weight = v->weight + 1;
				u->prev = curr;
				int_queue_push(q, vector_pair_first(v->adj, i));
			}
		}
		v->color = 2;
	}
	int_queue_destroy(&q);
}

static void	change_weight(t_graph *g, t_vector *vec)
{
	int			idx;
	t_vertex	*v;

	idx = g->end_idx;
	v = vert_vector_at(g->nodes, idx);
	while (v->prev != -1 && v->prev != g->start_idx)
	{
		if (vert_vector_at(g->nodes, v->prev)->adj->data[idx].second == -1)
		{
			vec->data[idx] = 0;
			graph_set_weight(g, idx, v->prev, 1);
		}
		else
		{
			graph_set_weight(g, idx, v->prev, -1);
			vec->data[idx] = 1;
		}
			
		graph_del_dir_edge(g, v->prev, idx);
		idx = v->prev;
		v = vert_vector_at(g->nodes, v->prev);
	}
	if (v->prev != -1)
	{
		graph_del_dir_edge(g, v->prev, idx);
		graph_set_weight(g, idx, v->prev, -1);
	}
}

void		admonds_carp(t_graph *g, int num_path)
{
	t_vector	*v;

	v = vector_create(vert_vector_size(g->nodes));
	while (num_path > 0)
	{
		bfs(g, v);
		if (vert_vector_at(g->nodes, g->end_idx)->weight == 2147483648)
			break ;
		change_weight(g, v);
		vector_print(v);
		ft_printf("\n");
		--num_path;
	}
	vector_destroy(&v);
}
