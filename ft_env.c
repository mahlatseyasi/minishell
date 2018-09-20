/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 08:48:10 by mkhoza            #+#    #+#             */
/*   Updated: 2018/09/20 13:13:36 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char command[100], char *parameters[100], char **envp)
{
	int	i;

	i = 0;
	if (ft_strcmp(command, "unsetenv") == 0)
	{
		unsetenv(parameters[1]);
	}
	else if (ft_strcmp(command, "setenv") == 0)
	{
		while (*envp++)
			i++;
		envp[i] = (char *)malloc(sizeof(char));
		putenv(parameters[1]);
	}
	else if (ft_strcmp(command, "env") == 0)
	{
		while (*envp)
			printf("%s\n", *envp++);
	}
}
