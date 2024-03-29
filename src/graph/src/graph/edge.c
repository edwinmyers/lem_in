/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:16:53 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/13 15:46:11 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

void			graph_add_dir_edge(t_graph *g, int id1, int id2)
{
	t_vertex	*v1;

	v1 = vert_vector_at(g->nodes, id1);
	vector_pair_push_back(v1->adj, id2, 1);
}

void			graph_del_dir_edge(t_graph *g, int id1, int id2)
{
	t_vertex	*v1;

	v1 = vert_vector_at(g->nodes, id1);
	vector_pair_del(v1->adj, id2);
}

void				graph_add_edge(t_graph *g, int id1, int id2)
{
	graph_add_dir_edge(g, id1, id2);
	graph_add_dir_edge(g, id2, id1);
}

void				graph_del_edge(t_graph *g, int id1, int id2)
{
	graph_del_dir_edge(g, id1, id2);
	graph_del_dir_edge(g, id2, id1);
}
