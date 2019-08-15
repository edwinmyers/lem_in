/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 10:13:18 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/14 17:21:37 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/graph.h"

static void		get_roads_len(t_vector *lens, t_graph *g, int counter, int vertex_idx)
{
	t_vertex	*v;
	size_t		i;

	if (vertex_idx == g->start_idx)
	{
		vector_push_back(lens, counter);
		return ;
	}
	i = 0;
	v = vert_vector_at(g->nodes, vertex_idx);
	while (i < vector_pair_len(v->adj))
	{
		if (vector_pair_second(v->adj, i) == -1)
			get_roads_len(lens, g, counter + 1, vector_pair_first(v->adj, i));
		++i;
	}
}

static void		get_attitude_roads(t_vector *lens, t_vector *attitude_roads, int num_roads)
{
	int			i;
	int			len_big_road;

	i = num_roads - 1;
	len_big_road = vector_get_elem(lens, i);
	vector_set_elem(attitude_roads, i, 1);
	while (--i >= 0)
		vector_set_elem(attitude_roads, i, len_big_road - vector_get_elem(lens, i) + 1);
}

static int		get_num_lines(t_vector *attitude_roads, t_vector *lens, int num_ants)
{
	int			distribution;
	int			add_val;
	int			rem_val;

	distribution = num_ants >= attitude_roads->data[0] ? attitude_roads->data[0] : num_ants;
	num_ants -= vector_get_sum(attitude_roads, 0, attitude_roads->size);
	add_val = num_ants / attitude_roads->size;
	rem_val = num_ants % attitude_roads->size;
	distribution += add_val;
	if (rem_val > 0)
		distribution += rem_val;
	return (distribution + lens->data[0] - 1);
}

static void analysis_item(t_graph *g, int num_path, int *min_num_lines, int *min_num_path)
{
	int			new_num_lines;
	t_vector 	*attitude_roads;
	t_vector	*roads_len;
	
	attitude_roads = vector_create(num_path);
	roads_len = vector_create(0);
	get_roads_len(roads_len, g, 0, g->end_idx);
	vector_quick_sort(roads_len);
	get_attitude_roads(roads_len, attitude_roads, num_path);
	new_num_lines = get_num_lines(attitude_roads, roads_len, g->num_ants);
	if (new_num_lines < *min_num_lines)
	{
		*min_num_lines = new_num_lines;
		*min_num_path = num_path;
	}
	vector_destroy(&attitude_roads);
	vector_destroy(&roads_len);
}

int analysis(t_graph *g)
{
	int			min_num_path;
	int			min_num_lines;
	int			num_path;
	t_vector	*visited;

	visited = vector_create(vert_vector_size(g->nodes));
	min_num_lines = 2000000000;
	min_num_path = ft_min(g->nodes->data[g->start_idx].adj->size,
										g->nodes->data[g->end_idx].adj->size) + 1;
	num_path = 1;
	while (1)
	{
		bfs(g, visited);
		if (vert_vector_at(g->nodes, g->end_idx)->weight == 2147483648)
			break ;
		change_weight(g, visited);
		analysis_item(g, num_path, &min_num_lines, &min_num_path);
		++num_path;
	}
	vector_destroy(&visited);
	return (num_path == 1 ? 0 : min_num_path);
}
