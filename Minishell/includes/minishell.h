/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvardan <arvardan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:01:35 by arvardan          #+#    #+#             */
/*   Updated: 2025/09/08 15:01:55 by arvardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define INIT_SHLVL 1
# define MAX_SHLVL 999

# define TMP_FILE "/tmp/heredoc_minishell.tmp"

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <errno.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>     // fork, execve, pipe, dup2, getcwd, chdir, unlink
# include <dirent.h>     // opendir, readdir, closedir
# include <sys/stat.h>   // stat, lstat, fstat
# include <sys/ioctl.h>  // Terminal Control
# include <termcap.h>    // tgetent, tgetstr, ...
# include <termios.h>    // Teminal Settings
# include <curses.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stddef.h>   
# include <readline/readline.h>
# include <readline/history.h>

# include "commands.h"
# include "structs.h"
# include "execute.h"
# include "signals.h"
# include "builtins.h"
# include "path.h"
# include "environment.h"

extern int	g_signal_status;

int		print_error(char *msg, int exit_code);

// print_error_placeholder
int		placeholder(char *placeholder, char *msg, int exit_code);
t_bool	apply_redirection(t_command *cmd);
t_bool	write_content_in_tmp(t_command *cmd);

void	cleanup(
			char *buffer,
			t_token_vector *tokens,
			t_command_vector *commands);

void	idk(char **content, char *line);

#endif
