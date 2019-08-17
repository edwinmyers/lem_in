/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:45:00 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/16 18:20:58 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int				main(void)
{
	int			num_roads;
	t_graph		*g;
	t_graph		*new_g;
	t_vector	**roads;
	t_vector	*distribution;
	t_string 	output_str;

	g = graph_create();
	parse_main(g, &output_str) == -1 ? error_exit("ERROR", &g) : 0;
	new_g = graph_copy(g);
	int a = analysis(new_g);
	graph_destroy(&new_g);
	a == 0 ? error_exit("ERROR", &g) : 0;
	admonds_carp(g, a);
	num_roads = get_num_roads(g);
	roads = get_all_roads(g, num_roads);
	distribution = get_distribution(roads, g->num_ants, num_roads);
	str_print(&output_str);
	str_destroy(&output_str);
	output(g, roads, distribution, num_roads);
	vector_destroy(&distribution);
	vectors_destroy(&roads, num_roads);
	graph_destroy(&g);
	return (0);
}
