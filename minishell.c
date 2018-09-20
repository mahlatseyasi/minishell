/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:36:58 by mkhoza            #+#    #+#             */
/*   Updated: 2018/09/20 13:13:46 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_command_in(char line[], char cmd[], char *par[])
{
	char	*pch;
	char	*array[100];
	int		i;
	int		j;

	i = 0;
	j = 0;
	pch = strtok(line, " \"\n");
	while (pch != NULL)
	{
		array[i++] = ft_strdup(pch);
		pch = strtok(NULL, " \"\n");
	}
	ft_strcpy(cmd, array[0]);
	if (ft_strcmp(cmd, "ls") == 0)
		i = i_val(i);
	while (j < i)
	{
		par[j] = array[j];
		j++;
	}
	par[i] = NULL;
}

void	read_command(char cmd[], char *par[])
{
	char	line[1024];
	int		count;
	int		c;

	count = 0;
	while (1)
	{
		c = fgetc(stdin);
		line[count++] = (char)c;
		if (c == '\n')
			break ;
	}
	if (count == 1)
		return ;
	read_command_in(line, cmd, par);
}

void	type_prompt(int first_time)
{
	const char	*clear_screen;

	if (first_time == 0)
	{
		clear_screen = " \e[1;1H\e[2J";
		write(STDOUT_FILENO, clear_screen, 12);
	}
	printf("$> ");
}

void	minishell(char command[], char *parameters[], char **envp)
{
	char	cmd[100];
	int		error;

	if (ft_strcmp(command, "echo") == 0)
		echo_command(parameters);
	else if (ft_strcmp(command, "unsetenv") == 0 ||
			ft_strcmp(command, "setenv") == 0 ||
			ft_strcmp(command, "env") == 0)
		ft_env(command, parameters, envp);
	else if (ft_strcmp(command, "cd") == 0)
		cd_command(parameters);
	else if (ft_strcmp(command, "emacs") == 0)
		ft_emacs(envp, parameters);
	else if (ft_strcmp(command, "exit") == 0)
		return ;
	else
	{
		ft_strcpy(cmd, "/bin/");
		ft_strcat(cmd, command);
		error = execve(cmd, parameters, envp);
		if (error == -1)
			printf("command not found: %s\n", cmd);
	}
}

int		main(int ac, char **av, char **envp)
{
	char		command[100];
	char		*parameters[20];
	static int	prompt;
	int			mini;

	mini = 1;
	prompt = 0;
	while (1)
	{
		type_prompt(prompt++);
		read_command(command, parameters);
		mini++;
		if (fork() != 0)
			wait(NULL);
		else
		{
			if (ft_strcmp(command, "clear") == 0)
				write(STDOUT_FILENO, " \e[1;1H\e[2J", 12);
			else
				minishell(command, parameters, envp);
		}
		if (ft_strcmp(command, "exit") == 0)
			break ;
	}
	return (0);
}
