/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:03:48 by eleleux           #+#    #+#             */
/*   Updated: 2023/01/24 10:37:03 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	red(void)
{
	printf("\033[1;31m");
}

void	cyan(void)
{
	printf("\033[1;36m");
}

void	green(void)
{
	printf("\033[1;32m");
}

void	yellow(void)
{
	printf("\033[1;33m");
}

void	reset(void)
{
	printf("\033[0m");
}
