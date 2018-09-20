/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:06:08 by mkhoza            #+#    #+#             */
/*   Updated: 2018/09/19 16:20:12 by mkhoza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"

int		i_val(int i);
void	read_command(char cmd[], char *par[]);
void	ft_env(char command[], char *par[], char **envp);
void	cd_command(char *par[]);
void	echo_command(char *par[]);
void	ft_emacs(char **envp, char *av[]);
char	**setenv_cmd(char **args, char **env);

#endif
