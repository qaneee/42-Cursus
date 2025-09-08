/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:53:25 by arvardan          #+#    #+#             */
/*   Updated: 2025/08/20 11:14:35 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_redirs(t_command *cmd)
{
	if (!cmd)
		return ;
	clear_tokens(&cmd->arguments);
	free(cmd->command_path);
	free(cmd->out_file);
	free(cmd->err_file);
	free(cmd->in_file);
	free(cmd->heredoc);
	free(cmd->heredoc_content);
	if (cmd->heredoc)
		unlink(TMP_FILE);
	init_command(cmd);
}
