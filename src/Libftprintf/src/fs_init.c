/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:59:00 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:37:31 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	fs_init(t_fs *fs)
{
	fs->flags = NULL;
	fs->size = NULL;
	fs->precision = 0;
	fs->type = 0;
	fs->width = 0;
}
