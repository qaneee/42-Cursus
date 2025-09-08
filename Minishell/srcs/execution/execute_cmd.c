/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:07:48 by arvardan          #+#    #+#             */
/*   Updated: 2025/08/27 22:15:07 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**generate_helper(t_command *cmd, char **argv, size_t i, size_t j)
{
	while (i < cmd->arguments.size)
	{
		if (cmd->arguments.data[i].type == TOKEN_ARG
			&& cmd->arguments.data[i].value != NULL)
		{
			argv[j] = ft_strdup(cmd->arguments.data[i].value);
			j++;
		}
		i++;
	}
	return (argv);
}

static char	**generate_argv(t_command *cmd)
{
	size_t	argc;
	char	**argv;
	size_t	i;

	argc = 0;
	i = 0;
	while (i < cmd->arguments.size)
	{
		if (cmd->arguments.data[i].type == TOKEN_ARG
			&& cmd->arguments.data[i].value != NULL)
			argc++;
		i++;
	}
	argv = malloc(sizeof(char *) * (argc + 1));
	if (!argv)
		return (NULL);
	generate_helper(cmd, argv, 0, 0);
	if (!argv)
		return (NULL);
	argv[argc] = NULL;
	return (argv);
}

static void	free_argv(char **argv)
{
	size_t	i;

	i = 0;
	if (!argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

t_bool	execute_one_command(
	t_command *cmd, t_env **env, t_command_vector *commands)
{
	char	**argv;

	argv = generate_argv(cmd);
	if (!argv)
		return (FALSE);
	identify_command(cmd, argv[0]);
	check_command(cmd, argv, env, commands);
	free_argv(argv);
	return (TRUE);
}
