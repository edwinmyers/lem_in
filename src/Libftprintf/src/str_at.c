/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:07:29 by nparker           #+#    #+#             */
/*   Updated: 2019/04/30 17:38:42 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	str_at(t_string *s, int idx)
{
	return (s->data[idx]);
}