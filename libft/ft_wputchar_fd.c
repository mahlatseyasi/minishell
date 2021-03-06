/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 12:31:20 by mkhoza            #+#    #+#             */
/*   Updated: 2018/08/23 14:36:57 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_wputchar_fd(wchar_t chr, int fd)
{
	ft_putchar_fd(chr, fd);
}
