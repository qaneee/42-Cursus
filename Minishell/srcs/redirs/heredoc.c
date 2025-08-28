/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:46:32 by arvardan          #+#    #+#             */
/*   Updated: 2025/08/20 17:33:23 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	write_content_in_tmp(t_command *cmd)
{
	int	fd;

	if (!cmd->heredoc_content)
		return (FALSE);
	fd = open(TMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("minishell");
		return (FALSE);
	}
	if (write(fd, cmd->heredoc_content, ft_strlen(cmd->heredoc_content)) == -1)
	{
		perror("minishell");
		close(fd);
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}
