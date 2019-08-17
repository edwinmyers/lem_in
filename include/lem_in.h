/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:45:31 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/16 18:11:18 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

short   g_toggle;
int	    g_flags[4];
#define STATE g_flags[0]
#define LINKS_COUNT g_flags[1]
#define MANDATORY_COMMANDS g_flags[2]
#define IDX g_flags[3]

# include "../src/Libftprintf/libftprintf.h"
# include "../src/vector/include/vector.h"
# include "../src/queue/include/queue.h"
# include "../src/pair/include/pair.h"
# include "../src/dictionary/include/dictionary.h"
# include "../src/graph/include/graph.h"
# include "../src/output/include/output.h"
# include "../src/pair_dict/include/p_dict.h"
# include "../src/parsing/include/parse.h"


#endif
