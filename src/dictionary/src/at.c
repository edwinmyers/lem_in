/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 12:15:44 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/09 18:38:32 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dictionary.h"
int		dict_at(t_dict *dict, const char *key)
{
	size_t	i;
	size_t	hash_val;

	i = -1;
	while (++i < dict->capacity)
	{
		hash_val = hash(key, dict->capacity, i);
		
		if (dict->data[hash_val].status == BLANK)
		{
			return (-2147483648);
		}
		if (dict->data[hash_val].status == DELETE)
		{
			continue ;
		}
		if (dict->data[hash_val].key == NULL)
			continue ;
		if (dict->data[hash_val].status == EXIST && ft_strcmp(dict->data[hash_val].key, key) == 0)
		{
			return (dict->data[hash_val].val);
		}
	}

	return (-2147483648);
}
