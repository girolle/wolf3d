/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:08:01 by rczarfun          #+#    #+#             */
/*   Updated: 2020/11/01 14:08:06 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	error_malloc(void)
{
	write(1, "error malloc\n", 13);
	exit(1);
}

void	error_arg(void)
{
	write(1, "error argv\n", 12);
	write(1, "<filename> <map>\n", 18);
	exit(1);
}

void	error_map(void)
{
	write(1, "error map\n", 10);
	exit(1);
}

void	error_er(void)
{
	write(1, "error\n", 6);
	exit(0);
}
