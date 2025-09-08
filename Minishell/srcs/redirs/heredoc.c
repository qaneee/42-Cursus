/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvardan <arvardan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:46:32 by arvardan          #+#    #+#             */
/*   Updated: 2025/09/07 21:17:48 by arvardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	write_content_in_tmp(t_command *cmd)
{
	int	fd;
	int	len;

	if (!cmd || !cmd->heredoc_content)
		return (FALSE);
	fd = open(TMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("minishell");
		return (FALSE);
	}
	len = ft_strlen(cmd->heredoc_content);
	if (write(fd, cmd->heredoc_content, len) == -1)
	{
		perror("minishell");
		close(fd);
		return (FALSE);
	}
	if (len == 0 || cmd->heredoc_content[len - 1] != '\n')
		write(fd, "\n", 1);
	close(fd);
	return (TRUE);
}
