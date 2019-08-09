/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:56:10 by vice-wra          #+#    #+#             */
/*   Updated: 2019/08/09 16:39:15 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lem_in.h"

int main()
{
	char *str = "hey-yo";
	t_dict *dict;
	int i;

	dict = dict_create();
	i = 0;

	while (i < 1000)
		dict_insert(dict, str, i++);
	i = 0;
	while (i++ < 1000)
		dict_at(dict, str);
}