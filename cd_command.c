/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:33:33 by mkhoza            #+#    #+#             */
/*   Updated: 2018/09/20 09:17:43 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_command(char *parameters[])
{
	int error;

	if (parameters[1] == NULL)
		parameters[1] = "/goinfre/mkhoza";
	error = chdir((const char *)parameters[1]);
	if (error == -1)
		printf("no such file or directory: %s\n", parameters[1]);
}
