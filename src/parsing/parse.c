/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:20:59 by vice-wra          #+#    #+#             */
/*   Updated: 2019/08/07 11:24:18 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"
#define STATE flags[0]
#define LINKS_COUNT flags[1]
#define MANDATORY_COMMANDS flags[2]
#define IDX flags[3]

static void parse_rooms_into_graph(t_graph *graph, char *line, int flag, int *mandatory_commands)
{
	char **str;

	if (!ft_strchr(line, ' '))
		return ;
	str = ft_strsplit(line, ' ');
	if (flag == 1)
	{
		graph_add_start_vert(graph, str[0]);
		(*mandatory_commands)++;
	}
	else if (flag == 2)
	{
		graph_add_end_vert(graph, str[0]);
		(*mandatory_commands)++;
	}
	else
		graph_add_vert(graph, str[0]);
	ft_strdel(str);
}

static int parse_links(t_graph *graph, t_dict *rooms, char *line, int *links_count)
{
	char **str;
	int idx0;
	int idx1;
	
	if (!ft_strchr(line, '-'))
		return (0);
	str = ft_strsplit(line, '-');
	idx0 = dict_at(rooms, str[0]);
	idx1 = dict_at(rooms, str[1]);
	if (idx0 == -2147483648 || idx1 == -2147483648)
		return -1;
	graph_add_edge(graph, idx0, idx1);
	ft_strdel(str);
	(*links_count)++;
	return (0);
}

static int parse_into_dict(t_dict *rooms, char *line, int idx)
{
	char **str;

	if (!ft_strchr(line, ' '))
		return (0);
	str = ft_strsplit(line, ' ');
	if (dict_at(rooms, str[0]) != -2147483648)
	{
		ft_strdel(str);
		return (-1);
	}
	dict_insert(rooms, str[0], idx);
	ft_strdel(str);
	return (0);
}

static int read_line(char **line, t_graph *graph)
{
	int flag;

	if (get_next_line(0, line) == 0)
		return (5);
	flag = check_line(*line);
	if (flag == -1)
		return (-1);
	else if (flag == 1 || flag == 2)
	{
		if(get_next_line(0, line) != 1)
			return (5);
		if ((check_line(*line) == -1 || (flag == 2 && graph->end_idx != -1) || (graph->start_idx != -1 && flag == 1)))
		{
			graph_destroy(&graph);	
			return (-1);
		}
	}
	return(flag);
}

int parse_main(t_graph *graph)
{
	t_dict *rooms;
	int flags[4];
	char *line;
	
	if ((graph->num_ants = get_ants_count()) <= 0)
		error_exit("Error");
	rooms = dict_create();
	init_flags_lem(flags);
	while ((STATE = read_line(&line, graph)) != -1)
	{
		if (STATE == 5)
			break;
		parse_into_dict(rooms, line, IDX) == -1 ? error_exit("Error") : 0;
		parse_rooms_into_graph(graph, line, STATE, &MANDATORY_COMMANDS);
		parse_links(graph, rooms, line, &LINKS_COUNT) == -1 ? error_exit("Error") : 0;
		IDX++;
	}
	if (STATE == -1 || !LINKS_COUNT || MANDATORY_COMMANDS != 2)
		return (-1);
	return (0);
}
