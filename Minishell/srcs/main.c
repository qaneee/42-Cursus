/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:37:06 by arvardan          #+#    #+#             */
/*   Updated: 2025/08/28 14:47:07 by ipogodae         ###   ########.fr       */
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
	t_token_vector *tokens,
	t_command_vector *commands,
	t_env **env,
	int exit_code
)
{
	printf("exit\n");
	cleanup(buffer, tokens, commands);
	if (env && *env)
		clean_env(env);
	rl_clear_history();
	exit(exit_code);
}

int	main(int argc, char **argv, char **envp)
{
	char				*line;
	t_token_vector		tokens;
	t_command_vector	commands;
	t_env				*env;
	int					error_code;

	(void)(argv + argc);
	env = init_env(envp);
	shell_signals();
	while (1)
	{
		line = readline("\033[1;32mminishell$ \033[0m");
		if (!line)
			cleanup_exit(line, 0, 0, &env, EXIT_SUCCESS);
		if (ft_strlen(line))
		{
			parse_line(line, &tokens, env);
			add_history(line);
			error_code = parse_tokens(&tokens, &commands, env);
			cleanup(line, &tokens, 0);
			if (!error_code)
				execute_commands(&commands, &env);
			cleanup(0, 0, &commands);
		}
		else
			cleanup(line, 0, 0);
	}
}
