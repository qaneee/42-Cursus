/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:37:06 by arvardan          #+#    #+#             */
/*   Updated: 2025/08/29 20:43:36 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal_status = 0;

void	cleanup(
	char *buffer, t_token_vector *tokens, t_command_vector *commands)
{
	if (buffer)
	{
		free(buffer);
	}
	if (tokens)
	{
		clear_tokens(tokens);
	}
	if (commands)
	{
		clear_commands(commands);
	}
}

static void	cleanup_exit(
	char *buffer,
	t_env **env,
	int exit_code
)
{
	printf("exit\n");
	cleanup(buffer, 0, 0);
	if (env && *env)
		clean_env(env);
	rl_clear_history();
	exit(exit_code);
}

static void	main_inner(
	char **line,
	t_token_vector *tokens,
	t_env **env,
	t_command_vector *commands)
{
	int	error_code;

	error_code = parse_line(*line, tokens, *env);
	if (error_code)
	{
		cleanup(*line, tokens, 0);
		return ;
	}
	add_history(*line);
	error_code = parse_tokens(tokens, commands, *env);
	cleanup(*line, tokens, 0);
	if (!error_code)
		execute_commands(commands, env);
	cleanup(0, 0, commands);
}

int	main(int argc, char **argv, char **envp)
{
	char				*line;
	t_token_vector		tokens;
	t_command_vector	commands;
	t_env				*env;

	(void)(argv + argc);
	env = init_env(envp);
	while (1)
	{
		shell_signals();
		line = readline("\033[1;32mminishell$ \033[0m");
		if (!line)
			cleanup_exit(line, &env, EXIT_SUCCESS);
		if (ft_strlen(line))
			main_inner(&line, &tokens, &env, &commands);
		else
			cleanup(line, 0, 0);
	}
}
