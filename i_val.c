/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_val.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:14:10 by mkhoza            #+#    #+#             */
/*   Updated: 2018/09/19 17:20:26 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	i_val(int i)
{
	if (i == 3)
	{
		i = i - 1;
		return (i);
	}
	else if (i == 4)
	{
		i = i - 2;
		return (i);
	}
	else if (i == 5)
	{
		i = i - 3;
		return (i);
	}
	else
		return (i);
}
